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
#include <math.h>

int window_w = 640;
int window_h = 480;
OniRGB888Pixel* gl_texture;
VideoStream selectedSensor;
Device device;
bool isInCropping = false;
bool isMouseDown = false;
int mouseDownX = 0;
int mouseDownY = 0;

void gl_MouseCallback(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN && !isMouseDown)
		{
			isMouseDown = true;
			mouseDownX = x;
			mouseDownY = y;
		}
		else if (state == GLUT_UP && isMouseDown)
		{
			isMouseDown = false;

			if (isInCropping)
			{
				printf("Cropping is still active, "
					"press R to reset it first.\r\n");
				return;
			}

			GLint m_viewport[4];
			glGetIntegerv( GL_VIEWPORT, m_viewport );

			int sizeX = ((float)window_w / m_viewport[2])
				* abs(x - mouseDownX);
			int sizeY = ((float)window_h / m_viewport[3])
				* abs(y - mouseDownY);
			int offsetX = ((float)window_w / m_viewport[2])
				* min(x, mouseDownX);
			int offsetY = ((float)window_h / m_viewport[3])
				* min(y, mouseDownY);

			sizeX = floor((float)sizeX / 4) * 4;
			sizeY = floor((float)sizeY / 4) * 4;
			offsetX = floor((float)offsetX / 4) * 4;
			offsetY = floor((float)offsetY / 4) * 4;

			if (sizeX >= 128 && sizeY >= 128)
			{
				printf("\r\nRequest cropping from %d,%d "
					"with size of %dx%d pixel: \r\n",
					offsetX, offsetY,
					sizeX, sizeY);

				Status status;
				status = selectedSensor.setCropping(
					offsetX, offsetY,
					sizeX,
					sizeY);
				if (status != STATUS_OK)
				{
					printf("Failed. %s\r\n",
						OpenNI::getExtendedError());
				}
				else
				{
					printf("Done. Press R to reset.\r\n");
					memset(gl_texture,0,
						window_w * window_h *
						sizeof(OniRGB888Pixel));
					isInCropping = true;
				}
			}
		}
	}
}

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
		printf("Stop and destry old stream.\r\n");
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


void gl_KeyboardCallback(unsigned char key, int x, int y)
{
	if (key == 27) // ESC Key
	{
		selectedSensor.destroy();
		device.close();
		OpenNI::shutdown();
		exit(0);
	}
	else if (key == 99 || key == 67) // C or c key
	{
		if (device.isValid())
		{
			printf("\r\n-->Setting active sensor to COLOR\r\n");
			SetActiveSensor(SENSOR_COLOR, &device);
			isInCropping = false;
		}
	}
	else if (key == 105 || key == 73) // I or i key
	{
		if (device.isValid())
		{
			printf("\r\n-->Setting active sensor to IR\r\n");
			SetActiveSensor(SENSOR_IR, &device);
			isInCropping = false;
		}
	}
	else if (key == 82 || key == 114) // R or r key
	{
		// Reset Cropping
		if (selectedSensor.isValid())
		{
			Status status;
			status = selectedSensor.setCropping(0, 0,
				selectedSensor.getVideoMode().getResolutionX(),
				selectedSensor.getVideoMode().getResolutionY());
			if (status == STATUS_OK)
				isInCropping = false;
		}
	}
	else if (key == 77 || key == 109) // M or m key
	{
		// Toogle Mirroring
		if (selectedSensor.isValid())
			selectedSensor.setMirroringEnabled(
			!selectedSensor.getMirroringEnabled());
	}
}

void gl_IdleCallback()
{
	glutPostRedisplay();
}

void gl_DisplayCallback()
{
	if (selectedSensor.isValid())
	{
		Status status = STATUS_OK;
		VideoStream* streamPointer = &selectedSensor;
		int streamReadyIndex;
		status = OpenNI::waitForAnyStream(&streamPointer, 1,
			&streamReadyIndex, 500);
		if (status == STATUS_OK && streamReadyIndex == 0)
		{
			VideoFrameRef newFrame;
			status = selectedSensor.readFrame(&newFrame);
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
						++x, ++texturePixel)
					{
						OniRGB888Pixel* streamPixel = 
							(OniRGB888Pixel*)(
								 	 (char*)newFrame.getData() + 
								 	 ((int)(y / resizeFactor) * 
										newFrame.getStrideInBytes())
								) + (int)(x / resizeFactor);
						memcpy(texturePixel, streamPixel,
							sizeof(OniRGB888Pixel));
					}
				}

	
				// Create the OpenGL texture map
				glTexParameteri(GL_TEXTURE_2D,
					0x8191, GL_TRUE);
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

	printf("\r\n---------------------- OpenGL -------------------------\r\n");
	printf("Initializing OpenGL ...\r\n");
	gl_texture = (OniRGB888Pixel*)malloc(
		window_w * window_h * sizeof(OniRGB888Pixel));
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow ("OpenGL | OpenNI 2.x CookBook Sample");
	glutKeyboardFunc(gl_KeyboardCallback);
	glutMouseFunc(gl_MouseCallback);
	glutDisplayFunc(gl_DisplayCallback);
	glutIdleFunc(gl_IdleCallback);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	printf("Starting OpenGL rendering process ...\r\n");
	SetActiveSensor(SENSOR_COLOR, &device);
	printf("Press C for color and I for IR.\r\n");
	printf("Use mouse to crop output and press R to reset cropping.\r\n");
	printf("By pressing M key you can toggle mirroring.\r\n");
	glutMainLoop();

	return 0;
}

