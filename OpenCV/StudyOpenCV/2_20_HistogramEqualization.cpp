// https://docs.opencv.org/4.x/d4/d1b/tutorial_histogram_equalization.html

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    CommandLineParser parser( argc, argv, "{@input | lena.jpg | input image}" );
    Mat src = imread( samples::findFile( parser.get<String>( "@input" ) ), IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor( src, src, COLOR_BGR2GRAY );
    Mat dst;
    equalizeHist( src, dst );
    imshow( "Source image", src );
    imshow( "Equalized Image", dst );
    waitKey();
    return 0;
}