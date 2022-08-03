// OpenNI2Project.cpp : Defines the entry point for the console application.
//

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
OniRGB888Pixel* gl_texture;
VideoStream depthSensor;
Device device;
bool histogram_enable = false;
bool color_enable = false;
bool blackfill_enable = false;
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

void gl_KeyboardCallback(unsigned char key, int x, int y)
{
	if (key == 27) // ESC Key
	{
		depthSensor.destroy();
		device.close();
		OpenNI::shutdown();
		exit(0);
	}
	else if (key == 72 || key == 104) // H or h key
	{
		histogram_enable = !histogram_enable;
		color_enable = false;
	}
	else if (key == 70 || key == 102) // F or f key
	{
		blackfill_enable = !blackfill_enable;
	}
	else if (key == 67 || key == 99) // C or c key
	{
		color_enable = !color_enable;
		histogram_enable = false;
	}
}

void gl_IdleCallback()
{
	glutPostRedisplay();
}

void gl_DisplayCallback()
{
	if (depthSensor.isValid())
	{
		Status status = STATUS_OK;
		VideoStream* streamPointer = &depthSensor;
		int streamReadyIndex;
		status = OpenNI::waitForAnyStream(&streamPointer, 1,
			&streamReadyIndex, 500);
		if (status == STATUS_OK && streamReadyIndex == 0)
		{
			VideoFrameRef newFrame;
			status = depthSensor.readFrame(&newFrame);
			if (status == STATUS_OK && newFrame.isValid())
			{
				// Clear the OpenGL buffers
				glClear (
					GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
				// Setup the OpenGL viewpoint
				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glLoadIdentity();
				glOrtho(0, window_w, window_h, 0, -1.0, 1.0);

				// UPDATING TEXTURE (DEPTH 1MM TO RGB888)
				unsigned short maxDepth =
					depthSensor.getMinPixelValue();
				unsigned short minDepth =
					depthSensor.getMaxPixelValue();

				// 遍历查找最大深度值 maxDepth 和最小深度值 minDepth
				for	(int y = 0; y < newFrame.getHeight(); ++y)
				{
					DepthPixel* depthCell = (DepthPixel*)(
						(char*)newFrame.getData() + 
						(y * newFrame.getStrideInBytes())
						);
					for	(int x = 0; x < newFrame.getWidth();
						++x, ++depthCell)
					{
						if (maxDepth < *depthCell)
						{
							maxDepth = *depthCell;
						}
						if (*depthCell != 0 &&
							minDepth > *depthCell)
						{
							minDepth = *depthCell;
						}
					}
				}

				int depthHistogram[65536];
				int numberOfPoints = 0;

				// 直方图归一化处理
				if (histogram_enable)
				{
					memset(depthHistogram, 0,
						sizeof(depthHistogram));
					for	(int y = 0;
							y < newFrame.getHeight(); ++y)
					{
						DepthPixel* depthCell = (DepthPixel*)(
							(char*)newFrame.getData() + 
							(y * newFrame.getStrideInBytes())
							);
						for	(int x = 0; x < newFrame.getWidth();
								++x, ++depthCell)
						{
							if (*depthCell != 0)
							{
								depthHistogram[*depthCell]++;
								numberOfPoints++;
							}
						}
					}
					for (int nIndex=1;
					nIndex < sizeof(depthHistogram) / sizeof(int);
					nIndex++)
					{
						depthHistogram[nIndex] +=
							depthHistogram[nIndex-1];
					}
				}

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
					DepthPixel lastPixel = 0;
					for	(unsigned int x = 0;
						x < (window_w - 2 * texture_x);
						++x, ++texturePixel)
					{
						DepthPixel* streamPixel = 
							(DepthPixel*)(
								(char*)newFrame.getData() + 
								((int)(y / resizeFactor) * 
									newFrame.getStrideInBytes())
							) +	(int)(x / resizeFactor);
						if (*streamPixel != 0)
						{
							lastPixel = *streamPixel;
						}
						else if (!blackfill_enable)
						{
							lastPixel = 0;
						}
						if (lastPixel != 0)
						{
							char depthValue = ((float)lastPixel / 
								maxDepth) * 255;
							// 转换色彩空间，获取更多细节
							if (color_enable)
							{
								float colorPaletteFactor = 
									(float)1024 / maxDepth;
								int colorCode = 
									(lastPixel - minDepth) * 
									colorPaletteFactor;
								texturePixel->b = ((colorCode > 0 && colorCode < 512) ? abs(colorCode - 256) : 255);
								texturePixel->g = ((colorCode > 128 && colorCode < 640) ? abs(colorCode - 384) : 255);
								texturePixel->r = ((colorCode > 512 && colorCode < 1024) ? abs(colorCode - 768) : 255);
							}
							else
							{
								if (histogram_enable)
								{
									depthValue = ((float)depthHistogram[lastPixel]  / numberOfPoints) * 255;
								}
								texturePixel->b = 255 - depthValue;
								texturePixel->g = 255 - depthValue;
								texturePixel->r = 255 - depthValue;
							}
						}
						else
						{
							texturePixel->b = lastPixel;
							texturePixel->g = lastPixel;
							texturePixel->r = lastPixel;
						}
					}
				}

	
				// Create the OpenGL texture map
				glTexParameteri(GL_TEXTURE_2D,
					0x8191, GL_TRUE); // 0x8191 = GL_GENERATE_MIPMAP
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
					window_w, window_h,	0, GL_RGB,
					GL_UNSIGNED_BYTE, gl_texture);

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

	printf("\r\n---------------------- Depth Stream --------------------------\r\n");
	printf("Checking if stream is supported ...\r\n");
	if (!device.hasSensor(SENSOR_DEPTH))
	{
		printf("Stream not supported by this device.\r\n");
		return 1;
	}

	printf("Asking device to create a depth stream ...\r\n");
	status = depthSensor.create(device, SENSOR_DEPTH);
	if (!HandleStatus(status)) return 1;

	printf("Setting video mode to 640x480x30 Depth 1MM ...\r\n");
	VideoMode vmod;
	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_DEPTH_1_MM);
	vmod.setResolution(640, 480);
	status = depthSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = depthSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- OpenGL -------------------------\r\n");
	printf("Initializing OpenGL ...\r\n");
	gl_texture = (OniRGB888Pixel*)malloc(
		window_w * window_h * sizeof(OniRGB888Pixel));
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow ("OpenGL | OpenNI 2.x CookBook Sample");
	glutKeyboardFunc(gl_KeyboardCallback);
	glutDisplayFunc(gl_DisplayCallback);
	glutIdleFunc(gl_IdleCallback);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	printf("Starting OpenGL rendering process ...\r\n");
	glutMainLoop();

	return 0;
}

