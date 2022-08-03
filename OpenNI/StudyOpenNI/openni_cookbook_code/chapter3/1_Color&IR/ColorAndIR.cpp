// OpenNI2Project.cpp : Defines the entry point for the console application.

#include "stdafx.h"
// General headers
#include <stdio.h>
// OpenNI2 headers
#include <OpenNI.h> 
using namespace openni;
// GLUT headers
#include "glut.h"

int window_w = 640;
int window_h = 480;

// 定义存储的格式为3byte的结构体 在传给opengl之前暂时是存储在buffer的RGB
OniRGB888Pixel* gl_texture;  
VideoStream selectedSensor;

Device device;

char ReadLastCharOfLine()
{
	int newChar = 0;
	int lastChar;
	fflush(stdout);
	do 
	{
		lastChar = newChar;
		newChar = getchar();
	}
	while ((newChar != '\n') 
		&& (newChar != EOF));
	return (char)lastChar;
}

bool HandleStatus(Status status)
{
	if (status == STATUS_OK)
		return true;
	printf("ERROR: #%d, %s", status,
		OpenNI::getExtendedError());
	ReadLastCharOfLine();
	return false;
}

// 检查并切换模式 color or IR 
void SetActiveSensor(SensorType sensorType, Device* device)
{
	Status status = STATUS_OK;
	if (sensorType == SENSOR_DEPTH)
	{
		printf("Not supported with this example.\r\n");
		return;
	}
	printf("Checking if stream is supported ...\r\n");
	if (!device->hasSensor(sensorType))
	{
		printf("Stream not supported by this device.\r\n");
		return;
	}
	if (selectedSensor.isValid())
	{
		printf("Stop and destroy old stream.\r\n");
		selectedSensor.stop();
		selectedSensor.destroy();
	}
	printf("Asking device to create a stream ...\r\n");
	status = selectedSensor.create(*device, sensorType);
	if (!HandleStatus(status)) return;

	printf("Setting video mode to 640x480x30 RGB24 ...\r\n");
	VideoMode vmod;
	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_RGB888);
	vmod.setResolution(640, 480);
	status = selectedSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = selectedSensor.start();
	if (!HandleStatus(status)) return;
	printf("Done.\r\n");
}

// 用户按键反馈 esc退出，C/c设置为color模式，I/i设置为IR模式
void gl_KeyboardCallback(unsigned char key, int x, int y)
{
	if (key == 27) // ESC Key
	{
		selectedSensor.destroy();
		device.close();
		OpenNI::shutdown();
		exit(0);
	}
	else if (key == 'C' || key == 'c') // C or c key
	{
		if (device.isValid())
		{
			printf("\r\n-->Setting active sensor to COLOR\r\n");
			SetActiveSensor(SENSOR_COLOR, &device);
		}
	}
	else if (key == 'I' || key == 'i') // I or i key
	{
		if (device.isValid())
		{
			printf("\r\n-->Setting active sensor to IR\r\n");
			SetActiveSensor(SENSOR_IR, &device);
		}
	}
}

// 更新opengl输出而不阻塞的方法是使用 idle 回调函数
void gl_IdleCallback()
{
	glutPostRedisplay(); // call the display function once again, giving us the ability to update and redraw the output texture.
}

// 清除opengl缓冲区，写入新数据，设置opengl显示的信息
void gl_DisplayCallback()
{
	if (selectedSensor.isValid())
	{
		Status status = STATUS_OK;
		VideoStream* streamPointer = &selectedSensor;
		int streamReadyIndex;
		status = OpenNI::waitForAnyStream(&streamPointer, 1,
			&streamReadyIndex, 500);  // 500ms执行一次检查
		if (status == STATUS_OK && streamReadyIndex == 0)
		{
			VideoFrameRef newFrame;
			status = selectedSensor.readFrame(&newFrame);
			if (status == STATUS_OK && newFrame.isValid())
			{
				// 清除buffer Clear the OpenGL buffers
				glClear (
					GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
				// 设置opengl显示有关信息 Setup the OpenGL viewpoint
				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glLoadIdentity();
				glOrtho(0, window_w, window_h, 0, -1.0, 1.0);

				// 从传感器的输出填充至这个texture buffer部分
				// UPDATING TEXTURE (RGB888 TO RGB888)			
				double resizeFactor = min(
					(window_w / (double)newFrame.getWidth()),
					(window_h / (double)newFrame.getHeight()));
				unsigned int texture_x = (unsigned int)(window_w - 
					(resizeFactor * newFrame.getWidth())) / 2;
				unsigned int texture_y = (unsigned int)(window_h - 
					(resizeFactor * newFrame.getHeight())) / 2;

				for	(unsigned int y = 0;
					y < (window_h - 2 * texture_y); ++y)
				{
					OniRGB888Pixel* texturePixel = gl_texture + 
						((y + texture_y) * window_w) + texture_x;
					for	(unsigned int x = 0;
						x < (window_w - 2 * texture_x);
						++x)
					{
						OniRGB888Pixel* streamPixel = 
							(OniRGB888Pixel*)(
							(char*)newFrame.getData() + 
							((int)(y / resizeFactor) * newFrame.getStrideInBytes())
							) +	(int)(x / resizeFactor);
						memcpy(texturePixel, streamPixel,
							3);
						texturePixel+=1;
					}
				}

	
				// Create the OpenGL texture map 纹理映射图
				glTexParameteri(GL_TEXTURE_2D,
					0x8191, GL_TRUE); // 0x8191 = GL_GENERATE_MIPMAP
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
					window_w, window_h,	0, GL_RGB,
					GL_UNSIGNED_BYTE, gl_texture);

				// 定义 texture 位置
				glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(0.0f, (float)window_h, 0.0f);
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f((float)window_w,
					(float)window_h, 0.0f);
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f((float)window_w, 0.0f, 0.0f);
				glEnd();

				// tell OpenGL to swap buffers and move the current buffer to the front
				glutSwapBuffers();
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Status status = STATUS_OK;
	printf("\r\n---------------------- Init OpenNI --------------------------\r\n");
	printf("Scanning machine for devices and loading "
			"modules/drivers ...\r\n");
	
	status = OpenNI::initialize();
	if (!HandleStatus(status)) return 1;
	printf("Completed.\r\n");

	printf("\r\n---------------------- Open Device --------------------------\r\n");
	printf("Opening first device ...\r\n");
	status = device.open(ANY_DEVICE);
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	printf("\r\n---------------------- OpenGL -------------------------\r\n");
	printf("Initializing OpenGL ...\r\n");

	// allocate the required memory for our texture in RAM
	gl_texture = (OniRGB888Pixel*)malloc(
		window_w * window_h * sizeof(OniRGB888Pixel));
	
	// 初始化
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  // 设置为color和depth的double buffering
	
	// 初始化opengl window
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow ("OpenGL | OpenNI 2.x CookBook Sample");

	// 用户交互部分 调用相关函数
	glutKeyboardFunc(gl_KeyboardCallback);
	glutDisplayFunc(gl_DisplayCallback);
	glutIdleFunc(gl_IdleCallback);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	// 设置检测模式
	printf("Starting OpenGL rendering process ...\r\n");
	SetActiveSensor(SENSOR_COLOR, &device);

	printf("Press C for color sensor and I for IR sensor.\r\n");
	glutMainLoop(); // 循环读取，opengl开始工作

	return 0;
}

