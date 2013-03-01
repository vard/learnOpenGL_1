// cutting_off_planes.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

// cube_and_sphere.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"

#if defined  _WIN32
#include "gl\glew.h"
#include "gl\glut.h"
#include <cmath>
#endif

#ifdef _WIN64
#include "stdafx.h"
#include "gl\glut.h"
#include "gl\glew.h"
#endif

#ifdef __linux__
#include "GL/glew.h"
#include "GL/glut.h"
#endif


void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}


void display(void){
    GLdouble eqn0[4] = {0.0, 1.0, 0.0, 0.0}; // plane y = 0
    GLdouble eqn1[4] = {1.0, 1.0, 0.0, 0.0}; // plane x + y = 0
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);

    // �������� ������ �������� y < 0
    glClipPlane(GL_CLIP_PLANE0, eqn0);
    glEnable(GL_CLIP_PLANE0);
   
    // �������� ������ �������� x < 0
    glClipPlane(GL_CLIP_PLANE1, eqn1);
    glEnable(GL_CLIP_PLANE1);

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireSphere(1.0, 20, 16);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

#ifdef _WIN32
int _tmain(int argc, char** argv)
#endif
#ifdef _WIN64
int _tmain(int argc, char** argv)
#endif

#ifdef __linux__
int main(int argc, char** argv)
#endif
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(2000, 100);
    //glutInitWindowPosition(200, 100);
    glutCreateWindow(argv[0]);
    glewInit();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}



