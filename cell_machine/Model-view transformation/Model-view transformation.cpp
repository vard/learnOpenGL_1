// Model-view transformation.cpp: определяет точку входа для консольного приложения.
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
   // glShadeModel(GL_SMOOTH);
}

void drawTriangle(){
    glBegin(GL_LINE_LOOP);
    glVertex3f( 0.5, 0, 0);  // Вверх
    glVertex3f( 0, 0.5, 0);  // Слева снизу
    glVertex3f(-0.5, 0, 0);  // Справа снизу*/
    glEnd();
}

void display(void){
    /*
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // очищение матрицы, сброс матрицы на единичную
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(-1.5f,0.0f,-6.0f); 
    //gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // видовое преобразование
    drawTriangle();    
    glFlush();*/

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    drawTriangle();

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xF0F0);
    glLoadIdentity();
    glTranslatef(-0.1, 0.0, 0.0);
    drawTriangle();

    glLineStipple(1, 0xF00F);
    glLoadIdentity();
    glScalef(1.5, 0.5, 1.0);
    drawTriangle();

    glLineStipple(1, 0x8888);
    glLoadIdentity();
    glRotatef(270.0, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
   // glRotatef(270.0, 0.0, 0.0, 1.0);
    drawTriangle();



    /*
    glBegin(GL_TRIANGLES);
    glVertex3f( 0.1, 0.0, 0.0);  // Вверх
    glVertex3f( 0.0, 0.2, 0.0);  // Слева снизу
    glVertex3f( 0.2, 0.0, 0.0);  // Справа снизу
    glVertex3d(100,0, 0);   
    glVertex3d(0,200, 0);
    glVertex3d(200,0, 0);
    glEnd();*/

    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
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


