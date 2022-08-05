#include <iostream>
#include <string>
#include <vector> 
// OpenCV头文件
#include <opencv2/photo.hpp>
#include <opencv2/highgui.hpp> 
#include <opencv2/improc>

// OpenNI头文件
#include <OpenNI.h> 
typedef unsigned char uint8_t;
// namespace
using namespace std;
using namespace openni;
using namespace cv;
// using namespace pcl;

void CheckOpenNIError( Status result, string status )  
{   
    if( result != STATUS_OK )   
        cerr << status << " Error, open is not correct: " << OpenNI::getExtendedError() << endl;  
} 

int main( int argc, char **argv )
{
	Status result = STATUS_OK;
	int i,j;
	float x=0.0,y=0.0,z=0.0,xx=0.0;  

	char filename[20] = {0};


	//opencv image
	Mat cvBGRImg; 
	Mat cvDepthImg;  

	//OpenNI2 image  
    VideoFrameRef oniDepthImg;  
    VideoFrameRef oniColorImg;

	namedWindow("depth");  
    namedWindow("image"); 

	char key=0;

	// 初始化OpenNI  
    result = OpenNI::initialize();
	CheckOpenNIError( result, "initialize context" ); 
	
    // open device    
    Device device;  
    result = device.open( openni::ANY_DEVICE ); 
	CheckOpenNIError( result, "open device" );


    // create depth stream   
    VideoStream oniDepthStream;  
    result = oniDepthStream.create( device, openni::SENSOR_DEPTH );
	CheckOpenNIError( result, "create depth stream" );
  
    // set depth video mode  
    VideoMode modeDepth;  
    modeDepth.setResolution( 640, 480 );  
    modeDepth.setFps( 30 );  
    modeDepth.setPixelFormat( PIXEL_FORMAT_DEPTH_1_MM );  
    oniDepthStream.setVideoMode(modeDepth);  
    // start depth stream  
    result = oniDepthStream.start(); 
	CheckOpenNIError( result, "start depth stream" );
   
    // create color stream  
    VideoStream oniColorStream;  
    result = oniColorStream.create( device, openni::SENSOR_COLOR );  
	CheckOpenNIError( result, "create color stream" );
    // set color video mode  
    VideoMode modeColor;  
    modeColor.setResolution( 640, 480 );  
    modeColor.setFps( 30 );  
    modeColor.setPixelFormat( PIXEL_FORMAT_RGB888 );  
    oniColorStream.setVideoMode( modeColor); 
	// start color stream  
    result = oniColorStream.start(); 
	CheckOpenNIError( result, "start color stream" );

	if (device.isImageRegistrationModeSupported(IMAGE_REGISTRATION_DEPTH_TO_COLOR)){
		device.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	}
	
	int count = 0;
	while(true)
	{
		// read frame  
        if( oniColorStream.readFrame( &oniColorImg ) == STATUS_OK )  
        {  
            // convert data into OpenCV type  
            Mat cvRGBImg( oniColorImg.getHeight(), oniColorImg.getWidth(), CV_8UC3, (void*)oniColorImg.getData() );  
            cvtColor( cvRGBImg, cvBGRImg, CV_RGB2BGR );  
            imshow( "image", cvBGRImg );  
        }  

		if( oniDepthStream.readFrame( &oniDepthImg ) == STATUS_OK )  
        {  
            Mat cvRawImg16U( oniDepthImg.getHeight(), oniDepthImg.getWidth(), CV_16UC1, (void*)oniDepthImg.getData() );  
            cvRawImg16U.convertTo( cvDepthImg, CV_8U, 255.0/(oniDepthStream.getMaxPixelValue()));    
            imshow( "depth", cvDepthImg );  
            cvDepthImg = cvRawImg16U;
        } 

	char input = waitKey(1); 
		// quit
        if( input == 'q' )      
            break;
		// capture  depth and color data   
        if( input == 'c' )
		{
			//get data
			DepthPixel *pDepth = (DepthPixel*)oniDepthImg.getData();

			sprintf(filename,"./data/color_%d.png",count);
			imwrite(filename,cvBGRImg);
			cerr<<"Saved data"<<endl;
			sprintf(filename,"./data/depth_%d.png",count++);
			imwrite(filename,cvDepthImg);
			
		}
	}
}
