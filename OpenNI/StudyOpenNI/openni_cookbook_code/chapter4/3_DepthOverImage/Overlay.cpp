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

int window_w = 600;
int window_h = 450;
OniRGB888Pixel* gl_texture;
VideoStream depthSensor;
VideoStream colorSensor;
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

void gl_KeyboardCallback(unsigned char key, int x, int y)
{
	if (key == 27) // ESC Key
	{
		depthSensor.destroy();
		colorSensor.destroy();
		device.close();
		OpenNI::shutdown();
		exit(0);
	}
	else if (key == 82 || key == 114) // R or r key
	{
		if (device.isValid())
			if (device.getImageRegistrationMode() == 
					IMAGE_REGISTRATION_DEPTH_TO_COLOR)
				device.setImageRegistrationMode(
					IMAGE_REGISTRATION_OFF);
			else
				device.setImageRegistrationMode(
					IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	}
}

void gl_IdleCallback()
{
	glutPostRedisplay();
}

void gl_DisplayCallback()
{
	if (depthSensor.isValid() && colorSensor.isValid())
	{
		Status status = STATUS_OK;
		VideoStream* streamPointer = &depthSensor;
		int streamReadyIndex;
		status = OpenNI::waitForAnyStream(&streamPointer, 1,
			&streamReadyIndex, 500);
		if (status == STATUS_OK && streamReadyIndex == 0)
		{
			VideoFrameRef depthFrame;
			status = depthSensor.readFrame(&depthFrame);
			VideoFrameRef colorFrame;
			if (status == STATUS_OK)
				status = colorSensor.readFrame(&colorFrame);
			if (status == STATUS_OK && 
				depthFrame.isValid() &&
				colorFrame.isValid() &&
				depthFrame.getHeight() == colorFrame.getHeight()
				&& depthFrame.getWidth() == colorFrame.getWidth())
			{
				// Clear the OpenGL buffers
				glClear (
					GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
				// Setup the OpenGL viewpoint
				glMatrixMode(GL_PROJECTION);
				glPushMatrix();
				glLoadIdentity();
				glOrtho(0, window_w, window_h, 0, -1.0, 1.0);

				// UPDATING TEXTURE (DEPTH 1MM AND RGB888 TO RGB888)

				unsigned short maxDepth =
					depthSensor.getMinPixelValue();
				for	(int y = 0; y < depthFrame.getHeight(); ++y)
				{
					DepthPixel* depthCell = (DepthPixel*)(
						(char*)depthFrame.getData() + 
						(y * depthFrame.getStrideInBytes())
						);
					for	(int x = 0; x < depthFrame.getWidth();
						++x, ++depthCell)
						if (maxDepth < *depthCell)
							maxDepth = *depthCell;
				}

				double resizeFactor = min(
					(window_w / (double)depthFrame.getWidth()),
					(window_h / (double)depthFrame.getHeight()));
				unsigned int texture_x = (unsigned int)(window_w - 
					(resizeFactor * depthFrame.getWidth())) / 2;
				unsigned int texture_y = (unsigned int)(window_h - 
					(resizeFactor * depthFrame.getHeight())) / 2;

				for	(unsigned int y = 0;
					y < (window_h - 2 * texture_y); ++y)
				{
					OniRGB888Pixel* texturePixel = gl_texture + 
						((y + texture_y) * window_w) + texture_x;
					for	(unsigned int x = 0;
						x < (window_w - 2 * texture_x);
						++x, ++texturePixel)
					{
						DepthPixel* depthPixel = 
							(DepthPixel*)(
								(char*)depthFrame.getData() + 
								((int)(y / resizeFactor) * 
									depthFrame.getStrideInBytes())
							) +	(int)(x / resizeFactor);
						RGB888Pixel* colorPixel = 
							(RGB888Pixel*)(
								(char*)colorFrame.getData() + 
								((int)(y / resizeFactor) * 
									colorFrame.getStrideInBytes())
							) +	(int)(x / resizeFactor);
						if (*depthPixel != 0)
						{
							float depthValue = 
								1 - ((float)*depthPixel / maxDepth);
								texturePixel->b = ceil((double)
									(colorPixel->b * depthValue));
								texturePixel->g = ceil((double)
									(colorPixel->g * depthValue));
								texturePixel->r = ceil((double)
									(colorPixel->r * depthValue));
						}
						else
						{
							texturePixel->b = 0;
							texturePixel->g = 0;
							texturePixel->r = 0;
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
	vmod.setResolution(window_w, window_h);
	status = depthSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = depthSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Image Stream --------------------------\r\n");
	printf("Checking if stream is supported ...\r\n");
	if (!device.hasSensor(SENSOR_COLOR))
	{
		printf("Stream not supported by this device.\r\n");
		return 1;
	}

	printf("Asking device to create a color stream ...\r\n");
	status = colorSensor.create(device, SENSOR_COLOR);
	if (!HandleStatus(status)) return 1;

	printf("Setting video mode to 640x480x30 RGB888 ...\r\n");
	vmod.setFps(30);
	vmod.setPixelFormat(PIXEL_FORMAT_RGB888);
	vmod.setResolution(window_w, window_h);
	status = colorSensor.setVideoMode(vmod);
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("Starting stream ...\r\n");
	status = colorSensor.start();
	if (!HandleStatus(status)) return 1;
	printf("Done.\r\n");

	printf("\r\n---------------------- Sync and Register --------------------------\r\n");
	printf("Enabling Depth-Image frames sync\r\n");
	status = device.setDepthColorSyncEnabled(true);
	if (!HandleStatus(status)) return 1;

	printf("Enabling Depth to Image mapping\r\n");
	status = device.setImageRegistrationMode(
				IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	if (!HandleStatus(status)) return 1;

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
	printf("Press R to toggle depth to color registration.\r\n");
	glutMainLoop();

	return 0;
}

