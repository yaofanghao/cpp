// OpenNI2Project.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
// General headers
#include <stdio.h>
#include <math.h> 
#include <vector>
#include <sstream>
#include <iostream>
// OpenNI2 headers
#include <OpenNI.h> 
#include <NiTE.h>
using namespace openni;
// GLUT headers
#include "../gl/glut.h"
const float PI = 3.14;
struct PongBall{
	POINTFLOAT location;
	int speed;
	float angle;
	void init(int w, int h){
		srand(time(NULL));
		angle = (((float)rand() / RAND_MAX)
					 * PI * 2);
		location.x = (((float)rand() / RAND_MAX)
					 * (w - 40)) + 20;
		location.y = (((float)rand() / RAND_MAX)
					 * (h - 40)) + 20;
	}
};
PongBall mainBall;
class Line{
public:
	POINTFLOAT *a;
	POINTFLOAT *b;
	Line
		(float x1, float y1, float x2, float y2)
		: a (new POINTFLOAT), b (new POINTFLOAT) 
	{
		a->x = x1;
		a->y = y1;
		b->x = x2;
		b->y = y2;
	}
	~Line()
    {
		delete a;
		delete b;
    }
	float getAngle()
	{
		return atan2(
				(float)a->y - b->y, a->x - b->x);
	}
};

int window_w = 640;
int window_h = 480;
nite::UserTracker uTracker;
std::vector<Line*> lines;
int wallScore = 0;
int userScore = 0;
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

bool HandleStatus(nite::Status status)
{
	if (status == nite::STATUS_OK)
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
		uTracker.destroy();
		nite::NiTE::shutdown();
		exit(0);
	}
}

void gl_IdleCallback()
{
	glutPostRedisplay();
}

void drawText(int x, int y, const char *string)
{
	glColor3f(255, 255, 255);
	glRasterPos2f(x, y);
	for (int i = 0; i < strlen(string); i++){
		glutBitmapCharacter(
			GLUT_BITMAP_HELVETICA_12, string[i]);
	}
}

void drawLineBetweenJoints(nite::Skeleton skel,
		nite::JointType a, nite::JointType b)
{
		float posX1, posY1, posX2, posY2;
		nite::Status status1 = 
		uTracker.convertJointCoordinatesToDepth(
			skel.getJoint(a).getPosition().x,
			skel.getJoint(a).getPosition().y,
			skel.getJoint(a).getPosition().z,
			&posX1, &posY1);
		nite::Status status2 = 
			uTracker.convertJointCoordinatesToDepth(
			skel.getJoint(b).getPosition().x,
			skel.getJoint(b).getPosition().y,
			skel.getJoint(b).getPosition().z,
			&posX2, &posY2);
		if (status1 == nite::STATUS_OK && 
			status2 == nite::STATUS_OK ){
			glBegin(GL_LINES);
			glVertex2f(posX1,posY1);
			glVertex2f(posX2,posY2);
			glEnd();
			lines.push_back(new Line(posX1, posY1, posX2, posY2));
		}
}

void drawCircle(float x, float y, float r){
	glBegin(GL_LINE_LOOP); 
	for(int i = 0; i < 100; i++) {
        float angle = i*2*PI/100;
        glVertex2f(	x + (cos(angle) * r),
					y + (sin(angle) * r));
    } 
	glEnd();
}

bool IsBetween (float x, float b1, float b2)
{
   return (	((x >= (b1 - 0.1f)) && 
			 (x <= (b2 + 0.1f))) || 
			((x >= (b2 - 0.1f)) &&
			(x <= (b1 + 0.1f))));
}

bool IsSegmentsColliding(	POINTFLOAT lineA,
						POINTFLOAT lineB,
						POINTFLOAT line2A,
						POINTFLOAT line2B)
{
	float deltaX1 = lineB.x - lineA.x;
	float deltaX2 = line2B.x - line2A.x;
	float deltaY1 = lineB.y - lineA.y;
	float deltaY2 = line2B.y - line2A.y;

	if (abs(deltaX1) < 0.01f && 
		abs(deltaX2) < 0.01f) // Two vertical line
		return false;
	if (abs((deltaY1 / deltaX1) -
		(deltaY2 / deltaX2)) < 0.001f) // Two parallel line
		return false;

	float xCol = (	(	(deltaX1 * deltaX2) * 
						(line2A.y - lineA.y)) - 
					(line2A.x * deltaY2 * deltaX1) + 
					(lineA.x * deltaY1 * deltaX2)) / 
				 ((deltaY1 * deltaX2) - (deltaY2 * deltaX1));
	float yCol = 0;
	if (deltaX1 < 0.01f) // L1 is a vertical line
		yCol = ((xCol * deltaY2) + 
				(line2A.y * deltaX2) - 
				(line2A.x * deltaY2)) / deltaX2;
	else // L1 is acceptable
		yCol = ((xCol * deltaY1) +
				(lineA.y * deltaX1) -
				(lineA.x * deltaY1)) / deltaX1;

	return	IsBetween(xCol, lineA.x, lineB.x) &&
			IsBetween(yCol, lineA.y, lineB.y) &&
			IsBetween(xCol, line2A.x, line2B.x) &&
			IsBetween(yCol, line2A.y, line2B.y);
}

void ClearLines(){
	for(int i = 0; i < lines.size(); ++i)
		delete lines[i];
	lines.clear();
}

void gl_DisplayCallback()
{
	if (uTracker.isValid())
	{
		nite::Status status = nite::STATUS_OK;
		nite::UserTrackerFrameRef usersFrame;
		status = uTracker.readFrame(&usersFrame);
		if (status == nite::STATUS_OK && usersFrame.isValid())
		{
			VideoFrameRef depthFrame = usersFrame.getDepthFrame();
			if	(window_w != depthFrame.getWidth() ||
				window_h != depthFrame.getHeight())
			{
				window_w = depthFrame.getWidth();
				window_h = depthFrame.getHeight();
				glutReshapeWindow(window_w, window_h);
			}

			// Clear the OpenGL buffers
			glClear (
				GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
			// Setup the OpenGL viewpoint
			glMatrixMode(GL_PROJECTION);
			glPushMatrix();
			glLoadIdentity();
			glOrtho(0, window_w, window_h, 0, -1.0, 1.0);

			glLineWidth(5.0);
			ClearLines();
			lines.push_back(new Line(0, 0, 0, window_h));
			lines.push_back(new Line(0, 0, window_w, 0));
			lines.push_back(new Line(0, window_h,
									window_w, window_h));
			lines.push_back(new Line(window_w, 0,
									window_w, window_h));
			
			const nite::Array<nite::UserData>& users =
				usersFrame.getUsers();
			
			glColor3f( 0.f, 1.f, 0.f );
			for (int i = 0; i < users.getSize(); ++i)
			{
				if (users[i].isNew())
				{
					uTracker.startSkeletonTracking(
						users[i].getId());
					mainBall.init(window_w, window_h);
					wallScore = 0;
					userScore = 0;
				}
				nite::Skeleton user_skel = users[i].getSkeleton();
				if (user_skel.getState() == 
					nite::SKELETON_TRACKED)
				{
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_HAND, nite::JOINT_LEFT_ELBOW);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_SHOULDER, nite::JOINT_LEFT_ELBOW);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_SHOULDER, nite::JOINT_RIGHT_SHOULDER);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_RIGHT_HAND, nite::JOINT_RIGHT_ELBOW);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_RIGHT_SHOULDER, nite::JOINT_RIGHT_ELBOW);

					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_FOOT, nite::JOINT_LEFT_KNEE);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_HIP, nite::JOINT_LEFT_KNEE);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_HIP, nite::JOINT_RIGHT_HIP);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_RIGHT_FOOT, nite::JOINT_RIGHT_KNEE);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_RIGHT_HIP, nite::JOINT_RIGHT_KNEE);

					drawLineBetweenJoints(user_skel,
						nite::JOINT_NECK, nite::JOINT_HEAD);

					drawLineBetweenJoints(user_skel,
						nite::JOINT_RIGHT_HIP, nite::JOINT_RIGHT_SHOULDER);
					drawLineBetweenJoints(user_skel,
						nite::JOINT_LEFT_HIP, nite::JOINT_LEFT_SHOULDER);

					float posX, posY;
					status = 
					uTracker.convertJointCoordinatesToDepth(
						user_skel.getJoint(nite::JOINT_HEAD).getPosition().x,
						user_skel.getJoint(nite::JOINT_HEAD).getPosition().y,
						user_skel.getJoint(nite::JOINT_HEAD).getPosition().z,
						&posX, &posY);
					if (status == nite::STATUS_OK){
						drawCircle(posX, posY,
							(1 - (user_skel.getJoint(nite::JOINT_HEAD).getPosition().z / 5000)) * 35);
					}
				}
			}
			POINTFLOAT newPosition;
			newPosition.x = mainBall.speed * cos(mainBall.angle) + mainBall.location.x;
			newPosition.y = mainBall.speed * sin(mainBall.angle) + mainBall.location.y;
			for (int i = 0; i < lines.size(); ++i){
				if (IsSegmentsColliding(  *(lines[i]->a),
										*(lines[i]->b),
										mainBall.location,
										newPosition)){
					mainBall.angle = lines[i]->getAngle() - 
						(mainBall.angle - lines[i]->getAngle());
					if (i < 4)
						wallScore += 1;
					else
						userScore += 1;
				}
			}
			mainBall.location.x += mainBall.speed * cos(mainBall.angle);
			mainBall.location.y += mainBall.speed * sin(mainBall.angle);
			glPointSize(10);
			glColor3f( 1.f, 0.f, 0.f );
			glBegin( GL_POINTS );
			glVertex2f(	mainBall.location.x,
						mainBall.location.y);
			glEnd();

			std::ostringstream stringStream;
			stringStream << "User(s)' Hits: " << userScore;
			const std::string tmp = stringStream.str();
			drawText( 20, 20, tmp.c_str());

			stringStream.str("");
			stringStream << "Walls' Hits: " << wallScore;
			const std::string tmp2 = stringStream.str();
			drawText( 120, 20, tmp2.c_str());

			glutSwapBuffers();
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	mainBall.init(120, 240);
	mainBall.speed = 5;
	printf("\r\n----------------- NiTE & User Tracker -------------------\r\n");
	nite::Status status = nite::STATUS_OK;
	printf("Initializing NiTE ...\r\n");
	status = nite::NiTE::initialize();
	if (!HandleStatus(status)) return 1;

	printf("Creating a user tracker object ...\r\n");
	status = uTracker.create();
	if (!HandleStatus(status)) return 1;
	
	printf("\r\n---------------------- OpenGL -------------------------\r\n");
	printf("Initializing OpenGL ...\r\n");
	glutInit(&argc, (char**)argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(window_w, window_h);
	glutCreateWindow ("OpenGL | OpenNI 2.x CookBook Sample");
	
	glutKeyboardFunc(gl_KeyboardCallback);
	glutDisplayFunc(gl_DisplayCallback);
	glutIdleFunc(gl_IdleCallback);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_COLOR_MATERIAL);
	printf("Starting OpenGL rendering process ...\r\n");
	glutMainLoop();

	return 0;
}

