// #include <pcl/io/pcd_io.h>
// #include <pcl/io/ply_io.h>
// #include <pcl/point_types.h>
// 标准库头文件
#include <iostream>
#include <string>
#include <vector> 
// OpenCV头文件
#include <opencv2/photo.hpp>
#include <opencv2/highgui.hpp> 
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
        cerr << status << " Error: " << OpenNI::getExtendedError() << endl;  
} 

int main( int argc, char **argv )
{
	Status result = STATUS_OK;
	int i,j;
	float x=0.0,y=0.0,z=0.0,xx=0.0;  
	//IplImage *test,*test2;
	IplImage *test2;
	char filename[20] = {0};

	//point cloud 
	// PointCloud<PointXYZ> cloud;
	// PointCloud<PointXYZRGB> color_cloud;

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
        } 

	char input = waitKey(1); 
		// // quit
  //       if( input == 'q' )      
  //           break;
		// // capture  depth and color data   
  //       if( input == 'c' )
		// {
		// 	//get data
		// 	DepthPixel *pDepth = (DepthPixel*)oniDepthImg.getData();
		// 	//create point cloud
		// 	cloud.width = oniDepthImg.getWidth();
		// 	cloud.height = oniDepthImg.getHeight();
		// 	cloud.is_dense = false;
		// 	cloud.points.resize(cloud.width * cloud.height);
		// 	color_cloud.width = oniDepthImg.getWidth();
		// 	color_cloud.height = oniDepthImg.getHeight();
		// 	color_cloud.is_dense = false;
		// 	color_cloud.points.resize(color_cloud.width * color_cloud.height);

		// 	//test = cvCreateImage(cvSize(cloud.width,cloud.height),IPL_DEPTH_8U,3);
		// 	IplImage temp11 = (IplImage)cvBGRImg;
		// 	//test2 = &IplImage(cvBGRImg);
		// 	test2 = &temp11;			

		// 	for(i=0;i<oniDepthImg.getHeight();i++)
		// 	{
		// 		 for(j=0;j<oniDepthImg.getWidth();j++)
		// 		 {
		// 			 float k = i;  
		// 			 float m = j; 
		// 			 xx = pDepth[i*oniDepthImg.getWidth()+j];
		// 			 CoordinateConverter::convertDepthToWorld (oniDepthStream,m,k,xx,&x,&y,&z); 
		// 			 cloud[i*cloud.width+j].x = x/1000;
		// 			 cloud[i*cloud.width+j].y = y/1000;
		// 			 cloud[i*cloud.width+j].z = z/1000;

		// 			 color_cloud[i*cloud.width+j].x = x/1000;
		// 			 color_cloud[i*cloud.width+j].y = y/1000;
		// 			 color_cloud[i*cloud.width+j].z = z/1000;
		// 			 color_cloud[i*cloud.width+j].b = (uint8_t)test2->imageData[i*test2->widthStep+j*3+0];
		// 			 color_cloud[i*cloud.width+j].g = (uint8_t)test2->imageData[i*test2->widthStep+j*3+1];
		// 			 color_cloud[i*cloud.width+j].r = (uint8_t)test2->imageData[i*test2->widthStep+j*3+2];
		// 			/* test->imageData[i*test->widthStep+j*3+0] = test2->imageData[i*test2->widthStep+j*3+0];
		// 			 test->imageData[i*test->widthStep+j*3+1] = test2->imageData[i*test2->widthStep+j*3+1];
		// 			 test->imageData[i*test->widthStep+j*3+2] = test2->imageData[i*test2->widthStep+j*3+2];*/
		// 		 }
	 //   		 }
			
			//cvSaveImage("test.jpg",test);
			//pcl::io::savePLYFileBinary("test_plyc.ply",cloud);
			// cout<<"the "<<count<<" is saved"<<endl;
			// sprintf(filename,"./data/%d.pcd",count);
			// pcl::io::savePCDFileBinaryCompressed(filename,cloud);
			// cerr<<"Saved "<<cloud.points.size()<<" data points to xyz pcd."<<endl;
			// sprintf(filename,"./data/color_%d.pcd",count);
			// pcl::io::savePCDFileBinaryCompressed(filename,color_cloud);
			// cerr<<"Saved "<<color_cloud.points.size()<<" data points to xyzrgb pcd."<<endl;
			// sprintf(filename,"./data/color_%d.jpg",count);
			// imwrite(filename,cvBGRImg);
			// sprintf(filename,"./data/depth_%d.jpg",count++);
			// imwrite(filename,cvDepthImg);
			/*for(size_t i=0;i<cloud.points.size();++i)
			cerr<<"    "<<cloud.points[i].x<<" "<<cloud.points[i].y<<" "<<cloud.points[i].z<<endl;*/
		}
	}
