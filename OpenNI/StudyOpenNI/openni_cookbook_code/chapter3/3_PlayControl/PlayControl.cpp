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
PlaybackControl* playControl;
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
	else if (key == '<' || key == ',') 
	{
		if ((*playControl).isValid())
		{
			(*playControl).seek(depthSensor, 0);
			printf("Restarting from beginning.\r\n");
		}
	}
	else if (key == '+' || key == '=') 
	{
		if ((*playControl).isValid() && 
			(*playControl).getSpeed() < 5)
		{
			(*playControl).setSpeed(
				(*playControl).getSpeed() + 0.3);
			printf("Current Speed is %s\r\n",
				(*playControl).getSpeed());
		}
	}
	else if (key == '_' || key == '-')
	{
		if ((*playControl).isValid() && 
			(*playControl).getSpeed() > 0.3)
		{
			(*playControl).setSpeed(
				(*playControl).getSpeed() - 0.2);
			printf("Current Speed is %s\r\n",
				(*playControl).getSpeed());
		}
	}
	else if (key == 'R' || key == 'r') 
	{
		if ((*playControl).isValid())
		{
			(*playControl).setRepeatEnabled(
				!(*playControl).getRepeatEnabled());
			printf("Repeating: %d.\r\n",
				(*playControl).getRepeatEnabled());
		}
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
							char depthValue = ((float)*streamPixel / 
								maxDepth) * 255;
							texturePixel->b = 255 - depthValue;
							texturePixel->g = 255 - depthValue;
							texturePixel->r = 255 - depthValue;
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

	printf("\r\n---------------------- Open File --------------------------\r\n");
	printf("Opening oni file ...\r\n");
	status = device.open("MultipleHands_From_OpenNIorg.oni");
	if (!HandleStatus(status)) return 1;
	printf("%s Opened, Completed.\r\n",
		device.getDeviceInfo().getName());

	printf("Requesting play controller ...\r\n");
	playControl = device.getPlaybackControl();
	printf("Done.\r\n");

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
	printf("Use + key to increase and"
		" - to decrease speed.\r\n");
	printf("Use Enter and Space key to pause playback.\r\n");
	printf("Use < key to restart playback.\r\n");
	printf("Toogle repeating by R key.\r\n");
	glutMainLoop();

	return 0;
}

