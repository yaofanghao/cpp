#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src, src_gray;
int maxCorners = 23;
int maxTrackbar = 100;
RNG rng(12345);
const char* source_window = "Image";
void goodFeaturesToTrack_Demo( int, void* );
int main( int argc, char** argv )
{
    CommandLineParser parser( argc, argv, "{@input | pic3.png | input image}" );
    src = imread( samples::findFile( parser.get<String>( "@input" ) ) );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( source_window );
    createTrackbar( "Max corners:", source_window, &maxCorners, maxTrackbar, goodFeaturesToTrack_Demo );
    imshow( source_window, src );
    goodFeaturesToTrack_Demo( 0, 0 );
    waitKey();
    return 0;
}
void goodFeaturesToTrack_Demo( int, void* )
{
    maxCorners = MAX(maxCorners, 1);
    vector<Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3, gradientSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;
    Mat copy = src.clone();
    goodFeaturesToTrack( src_gray,
                         corners,
                         maxCorners,
                         qualityLevel,
                         minDistance,
                         Mat(),
                         blockSize,
                         gradientSize,
                         useHarrisDetector,
                         k );
    cout << "** Number of corners detected: " << corners.size() << endl;
    int radius = 4;
    for( size_t i = 0; i < corners.size(); i++ )
    {
        circle( copy, corners[i], radius, Scalar(rng.uniform(0,255), rng.uniform(0, 256), rng.uniform(0, 256)), FILLED );
    }
    namedWindow( source_window );
    imshow( source_window, copy );
}