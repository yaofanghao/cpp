# fire detection / C++ / RaspberryPi-4B

2022.6.1-2022.12.31

## ���

**���淽��**

* ������1.0��
  * main.cpp
    * ����Ƶ���л�����
* Simple-RasberryPi
  * ������ͷ����ʵʱ���������ݮ�ɱ���汾---����ʹ��
  
**��������������**

* fireCascade.cpp 8.17����
  * ��Ҫ����fireDetection.hͷ�ļ���cascade.xmlģ��
  * ������������Ҫ�������͸�������������Haar��LBP�㷨
  * �������ɶ���򵥷�������һ����˳�������ɡ������е�ÿ���׶θ���С��ģ�������Ӽ�ȡ������ֵ���������������ֵ���ٵ��жϣ������ܾ���������Ŀ�ꡣ���ÿ���׶ε��ж϶�����һ���׶θ��Ӿ�ȷ��ʹ���ܵõ���������ǿ������ô��������������������ǿ��������������Ҫ�������ڣ�������ǰ��Ľ׶�ֻ����һЩ�򵥵Ĳ��ԣ����Կ����ų�����Щ���Բ�����ָ������ʵ���������ڽ׶ν������ų�����ͨ��ɨ��ͼ������ĳ������ʱ������������Ե��Ӵ��ڶ���������ָ��������������������������������ٶȡ�������ֻ������������Ҫ����ȫ���׶β��ܵõ����ܻ��ų��Ľ��ۡ�
  * OpenCV�ṩ��CascadeClassifier�࣬���ø����еķ���detectMultiScale������Ԥ����detections�����ο򼴿�

## ���ִ���˵��

* ��ʼ����־ģ�� -2022.8

```cpp
// log setting
// https://github.com/amrayn/easyloggingpp
el::Configurations defaultConf;
defaultConf.setToDefault();
el::Loggers::reconfigureLogger("default", defaultConf);
el::Logger* defaultLogger = el::Loggers::getLogger("default");
```

* ������ȡ������͹��������������ܳ���Բ�ζȡ�ƫ�Ķ����� -2022.11

```cpp
vector<vector<Point>>contours;
vector<Vec4i>hierarchy;
cv::findContours(mask, contours, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
//cv::drawContours(frame, contours, -1, Scalar(0, 0, 255), 3);
vector<vector<Point>>hull(contours.size()); 

int image_area = frame.rows * frame.cols;
for (size_t i = 0; i < contours.size(); i++)
{
 convexHull(contours[i], hull[i]);   // caculate convexhull

 double area = contourArea(contours[i]);
 double length = arcLength(contours[i], true);
 double roundIndex = 4 * 3.1415926 * area / (length * length + 0.00001);

 if ((area > contours_ratio * image_area) && (roundIndex > round_low) 
 && (length > cntlen_low) && (contours[i].size() > ellipse_low))
 {  
  Rect rect = boundingRect(contours[i]);
  //rectangle(frame, rect, (255, 0, 0), 5);

  RotatedRect box = fitEllipse(contours[i]);
  double ellipseA = box.size.height;
  double ellipseB = box.size.width;
  double eccIndex = sqrt(abs(pow(ellipseA, 2) - pow(ellipseB, 2))) / 2;  // ƫ�Ķ� 

  string text = "Warning!";
  cv::Point origin;
  origin.x = frame.cols / 2;
  origin.y = frame.rows / 2;
  putText(frame, text, origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 1);
  //putText(frame, std::to_string(ent.val[0]), origin, FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 1);
 }
}

// draw convexhull
for (size_t i = 0; i < contours.size(); i++)
{
//drawContours(mask, contours, (int)i, Scalar(0, 0, 255));
drawContours(frame, hull, (int)i, Scalar(255, 0, 0), 5);
}
```

* ����ͼ�����ֵ -2022.11.23

```cpp
//https://github.com/arnaudgelas/OpenCVExamples/blob/master/cvMat/Statistics/Entropy/Entropy.cpp
cv::Scalar Entropy(cv::Mat image)
{
 std::vector<cv::Mat> channels;
 cv::split(image, channels);
 int histSize = 256;
 float range[] = { 0, 256 };
 const float* histRange = { range };
 bool uniform = true;
 bool accumulate = false;
 cv::Mat hist0, hist1, hist2;
 cv::calcHist(&channels[0], 1, 0, cv::Mat(), hist0, 1, &histSize, &histRange, uniform, accumulate);
 cv::calcHist(&channels[1], 1, 0, cv::Mat(), hist1, 1, &histSize, &histRange, uniform, accumulate);
 cv::calcHist(&channels[2], 1, 0, cv::Mat(), hist2, 1, &histSize, &histRange, uniform, accumulate);

 //frequency
 float f0 = 0, f1 = 0, f2 = 0;
 for (int i = 0; i < histSize; i++)
 {
  f0 += hist0.at<float>(i);
  f1 += hist1.at<float>(i);
  f2 += hist2.at<float>(i); 
 }

 //entropy
 cv::Scalar e;
 e.val[0] = 0;
 e.val[1] = 0;
 e.val[2] = 0;
 // e0=0, e1=0, e2=0;
 float p0, p1, p2;

 for (int i = 0; i < histSize; i++)
 {
  p0 = abs(hist0.at<float>(i)) / f0;
  p1 = abs(hist1.at<float>(i)) / f1;
  p2 = abs(hist2.at<float>(i)) / f2;
  if (p0 != 0)
   e.val[0] += -p0 * log10(p0);
  if (p1 != 0)
   e.val[1] += -p1 * log10(p1);
  if (p2 != 0)
   e.val[2] += -p2 * log10(p2);
  }
return e;
}
```

* ����ͨ�ŵļ�ʵ�֣���ȡSTM32���͵��ĸ����ݣ����ݿո�ָ -2022.11.22

```cpp
WzSerialPort w;
if (w.open("/dev/ttyS0", 115200, 0, 8, 1))
{
 std::cout << "connect to STM32... wait for serial open" << std::endl;

 char buf[1024];   
 std::vector<double> receive_num; 
 while (true)
 {
 memset(buf, 0, 1024);
 w.receive(buf, 1024);
 // cout << buf;   
 char delims[] = " ";
 char* result = NULL;
 char* ptr;
 double ret;
 result = strtok(buf, delims); // �յ����ַ������ո���Ϊ��
 int i = 0;
 while (result != NULL) 
 {
  ret = strtod(result, &ptr);
  if (typeid(ret) == typeid(double)) 
  {
  receive_num.push_back(ret);
  i++;
  }
  result = strtok(NULL, delims);

  if (i == 4) 
  {
  // �����ĸ����رմ��ڣ����������Ż�    
  cout << "success received, close serial!" << endl;
  w.close();
  return receive_num;    
  }
  }
 }
}
```

## ʵ�ֹ���

* ��������ͷ����ݮ�ɳɹ����ӵ�����ͷ�豸���ܶ�ȡ����Ƶ��
* �ٶ�����Ϊ��ÿ��ȡ3֡ͼ�����ͼ����ģ��
* ����ͷ��ȡ����RGBͼ�񣬼������һ��ͨ������ֵ
* ͼ�����Ͳ���
* ��RGBת��ΪHSV��ɫ�ռ�
* ��Ի���������HSV�ռ���ֵ�ָ�ָ���ɺ��Ƕ�ֵ��ͼ��mask����Ĥ����h��Χ��0-50��s��Χ��0-80��v��Χ��250-255
* ͼ���������
* ������ȡ
* ������ȡ��������������ܳ���Բ�ζȣ��ж�������ܳ���Բ�ζȴ���ָ����ֵ��Ϊ��ѡ����
* ����ȡ�ĺ�ѡ������͹���������׶�
* ��͹���������������Ϊ��Բ������ƫ����
* ����ȡ�������������ͼ���ϲ�ʵʱ��ʾ
* �Ե���ͼ�м�⵽�����������ܳ���Բ�ζȡ�ƫ���ʡ���ֵȡƽ������Ϊһ������ֵ�����STM32�ɼ�������������ֵ���ݣ���������������������SVMģ��Ԥ�⡣����

## ����ɲ���

* -2022.08 ʵ��������ͷ����Ƶ��ͼ�����ּ��ģʽ��ѡ��
* -2022.08 ʵ���˽������־��ӡ�����浽myeasylog.log
  * �������������external_module
  * ������ӡ��־��ģ��easylogging++��  
* -2022.11 ʵ���˶Ի���ͼ��Բ�ζȡ�ƫ���ʡ���ֵ������ֵ�ļ���
* -2022.11.22 ʵ������ݮ������ԵĴ���ͨ��  
  * ʵ�ֹ������cpp/serial_demo�ļ���
* -2022.11.24 ʵ���˽���������ֵ���浽csv/excel�ļ���
* -2022.11.24 �޸�Ϊÿ��flag֡����һ��ͼ�񣬼��ټ���������֡����
* -2022.11.27 �����������Ŷ���������ֵ�����ݼ�
* -2022.11.28 ���������������ݼ�
* -2022.11.28 ������͸��������ݼ�����Ϊ����SVMѵ����ʽ��txt�ļ�
* -2022.11.29 ����SVMģ�ͣ�ʵ����������-->Ԥ���л�/�޻�
  * ʵ�ֹ������CppSVM�ļ���
* -2022.12.02 ���ü�ʱģ��
* -2022.12.02 ������ͨ�ż���ͼ����ģ�飬�������������л�
  * ��ݮ�ɶ˽��ߣ���-GND����-TX����-RX
  * STM32���ߣ���-GND����-TX����-RX
  ![1](demo2.jpg "���ʾ��")
	![2](demo3.jpg "���ʾ��")

* -2022.12.02 ����vector��������ÿ֡ͼ����ȡ����������ܳ���Բ�ζȡ�ƫ���ʡ���Ϣ�صľ�ֵ  
 ![3](demo1.png "���ʾ��")
 ![4](demo4.jpg "���ʾ��")

* -2022.12.15 ��ݮ�ɽ��STM32�����ݺ�ͼ���������������SVMģ��Ԥ��
* -2022.12.15 Ԥ������ֵ����STM32

## ����ɲ���

* ����

## �ο����� Acknowledgement

* <https://docs.opencv.org/4.x/df/d0d/tutorial_find_contours.html>
* <https://docs.opencv.org/4.x/d5/d04/samples_2cpp_2convexhull_8cpp-example.html#a12>
* <https://github.com/amrayn/easyloggingpp>
* <https://github.com/gbmhunter/CppLinuxSerial.git>
* <https://github.com/arnaudgelas/OpenCVExamples/blob/master/cvMat/Statistics/Entropy/Entropy.cpp>
* <https://www.csie.ntu.edu.tw/~cjlin/libsvm/>
* <https://blog.csdn.net/jsgaobiao/article/details/50202757>
* <https://www.bookstack.cn/read/Cpp_Concurrency_In_Action/README.md>
