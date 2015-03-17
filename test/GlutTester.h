#pragma once
#include "stdafx.h"
#include "GL/glut.h"
#include <iostream>

class GlutTester
{
public:
	//
	GlutTester(int w, int h,int win_pos_x, int win_pos_y, float left_fov, float right_fov, float top_fov, float bottom_fov, float azimuth_offset);
	virtual ~GlutTester();
	void setupGlutCallbacks(GlutTester* instance, int iteration);
	void Display();
	void Reshape(int w, int h);
	void KeyboardSpecialKeysListener(unsigned char touche, int x, int y);
	void mouseListener(int bouton, int state,int x, int y);
	void mouseMotionListener(int x, int y);
	static void DrawDisk();
	void reDisplay();
	static const float Degrees;
private:
	void initRendering();
	int _g_nWindowID;
	static int _coordinate_x;
	static int _coordinate_y;
	static int _coordinate_z;
	static int _coordinate_size;
    int _width;
	int _height;
	int _step;
	static float _x_translations_offset;
	static float _y_translations_offset;
	float _y_mouse;
	float _x_mouse;
	class FOV
	{
	public:
		FOV(){left = 0.f;right = 0.f; top=0.f; bottom=0.f;};
		float left;
		float right;
		float top;
		float bottom;
	};
	FOV _fov;
	float _azimuth_offset;
};
int GlutTester::_coordinate_x = 0;
int GlutTester::_coordinate_y = 0;
int GlutTester::_coordinate_z = 0;
int GlutTester::_coordinate_size = 0;
float GlutTester::_x_translations_offset = 0.;
float GlutTester::_y_translations_offset = 0.;
const float GlutTester::Degrees = 57.295779;

GlutTester* GlobalGlutTesterCurrentInstance1;
GlutTester* GlobalGlutTesterCurrentInstance2;
GlutTester* GlobalGlutTesterCurrentInstance3;

extern "C"
{
	void GlobalReDisplay(){GlobalGlutTesterCurrentInstance1->reDisplay();GlobalGlutTesterCurrentInstance2->reDisplay();GlobalGlutTesterCurrentInstance3->reDisplay();}
	//window 1
	void DisplayCallback1(){	GlobalGlutTesterCurrentInstance1->Display();}
	void ReshapeCallback1(int w, int h){	GlobalGlutTesterCurrentInstance1->Reshape(w,h);GlobalReDisplay();}
	void KeyboardSpecialKeysCallback1(int key, int x, int y){ GlobalGlutTesterCurrentInstance1->KeyboardSpecialKeysListener(key, x, y);GlobalReDisplay();}
	void MouseCallback1(int button, int state, int x, int y){ GlobalGlutTesterCurrentInstance1->mouseListener(button, state, x, y);GlobalReDisplay();}
	void MouseMotionCallback1(int x, int y){ GlobalGlutTesterCurrentInstance1->mouseMotionListener(x, y);GlobalReDisplay();}
	//window 2
	void DisplayCallback2(){	GlobalGlutTesterCurrentInstance2->Display();}
	void ReshapeCallback2(int w, int h){	GlobalGlutTesterCurrentInstance2->Reshape(w,h);GlobalReDisplay();}
	void KeyboardSpecialKeysCallback2(int key, int x, int y){ GlobalGlutTesterCurrentInstance2->KeyboardSpecialKeysListener(key, x, y);GlobalReDisplay();}
	void MouseCallback2(int button, int state, int x, int y){ GlobalGlutTesterCurrentInstance2->mouseListener(button, state, x, y);GlobalReDisplay();}
	void MouseMotionCallback2(int x, int y){ GlobalGlutTesterCurrentInstance2->mouseMotionListener(x, y);GlobalReDisplay();}
	//window 3
	void DisplayCallback3(){	GlobalGlutTesterCurrentInstance3->Display();}
	void ReshapeCallback3(int w, int h){	GlobalGlutTesterCurrentInstance3->Reshape(w,h);GlobalReDisplay();}
	void KeyboardSpecialKeysCallback3(int key, int x, int y){ GlobalGlutTesterCurrentInstance3->KeyboardSpecialKeysListener(key, x, y);GlobalReDisplay();}
	void MouseCallback3(int button, int state, int x, int y){ GlobalGlutTesterCurrentInstance3->mouseListener(button, state, x, y);GlobalReDisplay();}
	void MouseMotionCallback3(int x, int y){ GlobalGlutTesterCurrentInstance3->mouseMotionListener(x, y);GlobalReDisplay();}
}


GlutTester::GlutTester(int w, int h, int win_pos_x, int win_pos_y, float left_fov, float right_fov, float top_fov, float bottom_fov, float azimuth_offset)
{
	_width = w;
	_height = h;
	//initializing glut
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(w,h);
	glutInitWindowPosition (win_pos_x, win_pos_y);
	_g_nWindowID = glutCreateWindow("Hello World");
	initRendering();

	_coordinate_x = 5;
	_coordinate_y = 10;
	_coordinate_z = 10;
	_coordinate_size = 10;
	_step = 1;
	_x_translations_offset = 0.0;
	_y_translations_offset = 0.0;
	_fov.left = left_fov;
	_fov.right = right_fov;
	_fov.top = top_fov;
	_fov.bottom = bottom_fov;
	_azimuth_offset = azimuth_offset;
}

GlutTester::~GlutTester(void)
{
}
void GlutTester::initRendering()
{
	glClearColor(0,0,0,0);
}
void GlutTester::Display()
{
	glPushMatrix();     	//saves the current matrix on the top of the matrix stack
    glTranslatef(0,0,-150); //translates the current matrix 0 in x, 0 in y and -100 in z
	//glRotatef(_x_mouse,0,1,0); //translates the current matrix by _x_translations_offset arround y axis
	//glRotatef(_y_mouse,1,0,0); //translates the current matrix by _x_translations_offset arround y 
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//gluLookAt(0.0, 30.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(1,1,1);
	glBegin(GL_LINES);  //tells OpenGL that we're going to start drawing triangles
	  glColor3f(1,0,0);   	//sets the current colour to red
	  glVertex3f(0,0,0);  //specifies the first vertex of our triangle
	  glVertex3f(_coordinate_size,0,0);  //specifies the first vertex of our triangle
	glEnd();    
	glBegin(GL_LINES);  //tells OpenGL that we're going to start drawing triangles
	  glColor3f(0,1,0);   	//sets the current colour to green
	  glVertex3f(0,0,0);   //specifies the second vertex of our triangle
	  glVertex3f(0,_coordinate_size,0);   //specifies the second vertex of our triangle
	glEnd();  
    glBegin(GL_LINES);  //tells OpenGL that we're going to start drawing triangles
	  glColor3f(0,0,1);   	//sets the current colour to blue
	  glVertex3f(0,0,0);   //specifies the second vertex of our triangle
	  glVertex3f(0,0,-_coordinate_size);   //specifies the third vertex of our triangle
	glEnd();
	glPopMatrix();
	std::cout<<"================="<<std::endl;
	std::cout<<"_coordinate_x="<<_coordinate_x<<std::endl;
	std::cout<<"_coordinate_y="<<_coordinate_y<<std::endl;
	std::cout<<"_coordinate_z="<<_coordinate_z<<std::endl;
	std::cout<<"(+P,-M):_coordinate_size="<<_coordinate_size<<std::endl;
	std::cout<<"_x_translations_offset="<<_x_translations_offset<<std::endl;
    //glutStrokeCharacter(GLUT_STROKE_ROMAN, 80);
	DrawDisk();
	glutSwapBuffers();
	Reshape(_width, _height);
}
void GlutTester::DrawDisk()
{
	glPushMatrix();
	glTranslatef(0,0,-_y_translations_offset); //translates the current matrix 0 in x, 0 in y and -100 in z
	glRotatef(_x_translations_offset,0,1,0); //translates the current matrix 0 in x, 0 in y and -100 in z
	glTranslatef(0,0,_y_translations_offset); //translates the current matrix 0 in x, 0 in y and -100 in z
	//glTranslatef(_y_translations_offset,0,0); //translates the current matrix 0 in x, 0 in y and -100 in z
	GLUquadric* params;
	params = gluNewQuadric();
	gluQuadricDrawStyle(params,GLU_LINE);
	gluDisk(params,0,25,_coordinate_x,_coordinate_y);
	gluDeleteQuadric(params);
	glPopMatrix();
}

void GlutTester::Reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluPerspective(45., (GLdouble)w /(GLdouble)h, 1.0, 4000.);
	float znear=1.;
	float zfar=200.;
	glFrustum(_fov.left,_fov.right,_fov.bottom,_fov.top, znear,zfar);
	glRotatef(_azimuth_offset*Degrees,0,1,0); //translates the current matrix by _y_fov_angle arround y axis
}
void GlutTester::KeyboardSpecialKeysListener(unsigned char touche, int x, int y)

{
	switch(touche)
	{
		case GLUT_KEY_UP:
			_coordinate_y += _step;
			break;
		case GLUT_KEY_DOWN:
			_coordinate_y -= _step;
			break;
		case GLUT_KEY_RIGHT:
			_coordinate_x += _step;
			break;
		case GLUT_KEY_LEFT:
			_coordinate_x -= _step;
			break;
		case GLUT_KEY_PAGE_UP:
			_coordinate_size += _step;
			break;
		case GLUT_KEY_PAGE_DOWN:
			_coordinate_size -= _step;
			break;
		case GLUT_KEY_HOME:
			_x_translations_offset += _step;
			break;
		case GLUT_KEY_END:
			_x_translations_offset -= _step;
			break;
		case GLUT_KEY_INSERT:
			_y_translations_offset -= _step;
			break;
		case GLUT_KEY_F12:
			_y_translations_offset += _step;
			break;
		default:
			std::cout<<"touche="<<touche;
	}
	reDisplay();
}
void
GlutTester::reDisplay()
{
	glutSetWindow(_g_nWindowID);
	glutPostRedisplay();
}
void GlutTester::mouseListener(int button, int state, int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  {
	  _x_mouse = x;
	  _y_mouse = y;
  }
  reDisplay();
}
void GlutTester::mouseMotionListener(int x, int y)
{
	_x_mouse = x;
	_y_mouse = y;
	reDisplay();
}
void GlutTester::setupGlutCallbacks(GlutTester* instance, int iteration)
{
	switch (iteration)
	{
	case 1:
		{
			::GlobalGlutTesterCurrentInstance1 = instance;
			::glutDisplayFunc(::DisplayCallback1);
			::glutReshapeFunc(::ReshapeCallback1);
			::glutSpecialFunc(::KeyboardSpecialKeysCallback1);
			::glutMouseFunc(::MouseCallback1);
			::glutMotionFunc(::MouseMotionCallback1);
		}
		break;
	case 2:
	   {
			::GlobalGlutTesterCurrentInstance2 = instance;
			::glutDisplayFunc(::DisplayCallback2);
			::glutReshapeFunc(::ReshapeCallback2);
			::glutSpecialFunc(::KeyboardSpecialKeysCallback2);
			::glutMouseFunc(::MouseCallback2);
			::glutMotionFunc(::MouseMotionCallback2);
		}
		break;
	case 3:
	   {
			::GlobalGlutTesterCurrentInstance3 = instance;
			::glutDisplayFunc(::DisplayCallback3);
			::glutReshapeFunc(::ReshapeCallback3);
			::glutSpecialFunc(::KeyboardSpecialKeysCallback3);
			::glutMouseFunc(::MouseCallback3);
			::glutMotionFunc(::MouseMotionCallback3);
		}
		break;
	default:
		break;
	}
	
	
}