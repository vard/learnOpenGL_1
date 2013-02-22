// cube.cpp: ���������� ����� ����� ��� ����������� ����������.
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
    glShadeModel(GL_FLAT);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity(); // �������� �������, ����� ������� �� ���������
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // ������� ��������������
    glScalef(1.0, 2.0, 1.0); // ��������� ��������������, ����������� ������, � ������ ������ ��� � 2 ���� ����� ��� y, ��� � ���������� ������������� � 2 ����
    glutWireCube(1.0);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
  //  glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0); // ������������� ��������
    gluPerspective(50.0, 1.0, 1.5, 20);
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

