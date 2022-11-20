
#include <CppLinuxSerial/SerialPort.hpp>
#include "easylogging++.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <zbar.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>

#include "paddle_api.h"
#include <fstream>
#include <arm_neon.h>
#include <stdio.h>
#include <sys/time.h>
#include <numeric>
#include <functional>

INITIALIZE_EASYLOGGINGPP
using namespace mn::CppLinuxSerial;
using namespace std;
using namespace cv;
using namespace zbar;

int REPEAT_COUNT = 1;
const int CPU_THREAD_NUM = 2;
const paddle::lite_api::PowerMode CPU_POWER_MODE =
    paddle::lite_api::PowerMode::LITE_POWER_HIGH;

struct RESULT
{
    cv::Rect rec;
    int class_id;
    float prob;
};

inline int64_t get_current_us()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return 1000000LL * (int64_t)time.tv_sec + (int64_t)time.tv_usec;
}

std::vector<std::string> load_labels(const std::string &path)
{
    std::ifstream file;
    std::vector<std::string> labels;
    file.open(path);
    while (file)
    {
        std::string line;
        std::getline(file, line);
        labels.push_back(line);
    }
    file.clear();
    file.close();
    return labels;
}

void new_preprocess(cv::Mat &img, float *data)
{
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    img.convertTo(img, CV_32F, 1.0 / 255, 0);
    img = (img - 0.5) / 0.5;
    int rows = img.rows;
    int cols = img.cols;
    int chs = img.channels();
    for (int i = 0; i < chs; ++i)
    {
        cv::extractChannel(img, cv::Mat(rows, cols, CV_32FC1, data + i * rows * cols), i);
    }
}

cv::Mat Array2Mat(unsigned char *array, int row, int col)
{

    unsigned char DimsArray[720][1280];
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            DimsArray[i][j] = array[i * col + j];
        }
    }

    cv::Mat img(row, col, CV_8UC1, (unsigned char *)DimsArray);
    return img;
}

cv::Mat process(cv::Mat &input_image,
                std::shared_ptr<paddle::lite_api::PaddlePredictor> &predictor)
{

    std::unique_ptr<paddle::lite_api::Tensor> input_tensor0(std::move(predictor->GetInput(0)));
    input_tensor0->Resize({1, 3, 720, 1280});
    auto *input_data0 = input_tensor0->mutable_data<float>();
    new_preprocess(input_image, input_data0);
    // repeat to obtain the average time, set REPEAT_COUNT=1 in actual products
    double prediction_time;
    double max_time_cost = 0.0f;
    double min_time_cost = std::numeric_limits<float>::max();
    double total_time_cost = 0.0f;
    for (int i = 0; i < REPEAT_COUNT; i++)
    {
        auto start = get_current_us();
        predictor->Run();
        auto end = get_current_us();
        double cur_time_cost = (end - start) / 1000.0f;
        if (cur_time_cost > max_time_cost)
        {
            max_time_cost = cur_time_cost;
        }
        if (cur_time_cost < min_time_cost)
        {
            min_time_cost = cur_time_cost;
        }
        total_time_cost += cur_time_cost;
        prediction_time = total_time_cost / REPEAT_COUNT;
        printf("iter %d cost: %f ms\n", i, cur_time_cost);
    }

    std::unique_ptr<const paddle::lite_api::Tensor> output_tensor(
        std::move(predictor->GetOutput(0)));
    std::vector<int64_t> output_shape = output_tensor->shape();
    auto *outputData = output_tensor->data<int64_t>();
    int64_t out_num = 921600;
    std::vector<int64_t> out_data(out_num);
    for (int64_t i = 0; i < out_num; i++)
    {
        out_data[i] = outputData[i];
    }
    unsigned char out_data_u8[out_num];
    int notzero = 0;
    for (int64_t i = 0; i < out_num; i++)
    {
        out_data_u8[i] = static_cast<unsigned char>(out_data[i]);
        if (outputData[i] > 0)
        {
            notzero++;
            out_data_u8[i] = 255;
        }
    }
    printf("not zero %d", notzero);
    cv::Mat out_gray_img(720, 1280, CV_8UC1, out_data_u8);
    return out_gray_img;
}

void barcode_identify(ImageScanner &scanner, Mat &frame)
{
    Mat frame_grayscale;
    cvtColor(frame, frame_grayscale, COLOR_RGB2GRAY);
    int width = frame_grayscale.cols;
    int height = frame_grayscale.rows;
    uchar *raw = (uchar *)(frame_grayscale.data);
    Image image(width, height, "Y800", raw, width * height);
    scanner.scan(image);
    int counter = 0;
    for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
    {
        time_t now;
        tm *current;
        now = time(0);
        current = localtime(&now);

        // do something useful with results
        cout << "[" << current->tm_hour << ":" << current->tm_min << ":" << setw(2) << setfill('0') << current->tm_sec << "] " << counter << " "
             << "decoded " << symbol->get_type_name()
             << " symbol \"" << symbol->get_data() << '"' << endl;
        counter++;
    }
    if (counter == 0)
    {
        LOG(INFO) << "No Barcode indentify";
    }
}

int main(int argc, char **argv)
{
    /*
        Logger INIT
    */
    time_t t = time(0);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&t), "%F %X");
    el::Configurations defaultConf;
    defaultConf.setToDefault();
    defaultConf.setGlobally(
        el::ConfigurationType::Filename, ss.str());
    el::Loggers::reconfigureLogger("default", defaultConf);
    el::Logger *defaultLogger = el::Loggers::getLogger("default");

    /*
        Barcode Camera INIT
    */
    int cam_barcode_idx = -1;
    if (argc == 6)
    {
        cam_barcode_idx = atoi(argv[4]);
    }
    VideoCapture cap_barcode(cam_barcode_idx);
    cap_barcode.set(CAP_PROP_FOURCC, VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap_barcode.set(CAP_PROP_FPS, 30);
    cap_barcode.set(CAP_PROP_FRAME_WIDTH, 1600);
    cap_barcode.set(CAP_PROP_FRAME_HEIGHT, 1200);
    if (!cap_barcode.isOpened())
    {
        cerr << "Barcode Cam Could not be opened." << endl;
        exit(EXIT_FAILURE);
    }
        /*
        Barcode function INIT
    */
    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
    cv::Mat frame;

    /*
        Detect Camera INIT
    */
    int cam_detect_idx = -1;
    if (argc == 6)
    {
        cam_detect_idx = atoi(argv[5]);
    }
    VideoCapture cap_detect(cam_detect_idx);
    cap_detect.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap_detect.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cv::Mat input_image;
    if (!cap_detect.isOpened())
    {
        cerr << "Detect Cam Could not be opened." << endl;
        exit(EXIT_FAILURE);
    }

    if (argc != 5 && argc != 6)
    {
        printf(
            "Usage: \n"
            "./yolov3_detection_demo model_dir label_path [input_image_path] [output_image_path]"
            "use images from camera if input_image_path and output_image_path are not provided.");
        return -1;
    }

    std::string model_path = argv[1];
    paddle::lite_api::MobileConfig config;
    config.set_model_from_file(model_path);
    config.set_threads(CPU_THREAD_NUM);
    config.set_power_mode(CPU_POWER_MODE);
    std::shared_ptr<paddle::lite_api::PaddlePredictor> predictor =
        paddle::lite_api::CreatePaddlePredictor<paddle::lite_api::MobileConfig>(config);



    /*
        Serial INIT

        Create serial port object and open serial port at 57600 buad, 8 data bits, no parity bit, and one stop bit (8n1)
        Use SerialPort serialPort("/dev/ttyACM0", 13000); instead if you want to provide a custom baud rate
    */

    SerialPort serialPort("/dev/ttyS2", BaudRate::B_115200, NumDataBits::EIGHT, Parity::NONE, NumStopBits::ONE);
    serialPort.SetTimeout(-1); // Block when reading until any data is received
    serialPort.Open();
    vector<uint8_t> write_buffer = {0x88, 0x1D, 0x2D, 0x3D, 0x4D, 0x01, 0xCC, 0x10, 0x20, 0xDA, 0xDA, 0x01, 0x02};
    vector<uint8_t> read_buffer;
    serialPort.WriteBinary(write_buffer);

    /*
        GO TO THE MAIN LOOP
    */
    LOG(INFO) << "Programm Start";
    while (1)
    {
        LOG(INFO) << " jump in Loop";
        serialPort.ReadBinary(read_buffer);
        printf("num [5] %d", (int)read_buffer[5]);
        printf("size %d", (int)read_buffer.size());
        if (read_buffer.size() != 13)
        {
            LOG(INFO) << "buffer size is not 13";
        }
        if (read_buffer[5] == 0x01)
        {
            cap_barcode >> frame;
            barcode_identify(scanner, frame);
            printf("jump to func 1");
        }
        else if (read_buffer[5] == 0x02)
        {
            printf("jump to func2");
            cap_detect >> input_image;
            cv::Mat output_image = process(input_image, predictor);
        }
        else if (read_buffer[5] == 0x03)
        {
            printf("jump to debug");
            namedWindow("captured", 0);
            resizeWindow("captured", 800, 600);
            while (1)
            {
                cap_barcode >> frame;
                imshow("captured", frame);
            }
        }
        else if (read_buffer[5] == 0x04)
        {
            string input_image_path = argv[2];
            string output_image_path = argv[3];
            Mat input_image = imread(input_image_path, IMREAD_COLOR);
            Mat output_image = process(input_image, predictor);
            imwrite(output_image_path, output_image);
        }

        read_buffer.clear();
    }

    // Close the serial port
    serialPort.Close();
}
