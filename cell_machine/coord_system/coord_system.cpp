// coord_system.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gl\glut.h"

void reshape(int w, int h){
    glViewPort(0, 0, (GLsizei)w, 0.0, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int _tmain(int argc, char** argv)
{
	return 0;
}

