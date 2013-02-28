// cube_and_sphere.cpp: определяет точку входа для консольного приложения.
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

static float alpha = 0;
float cubeSide = 0;
float sinus = 0;

#define PI  (3.14159265359)

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void display(void);
void display(void){
    
    float x = 0;
    float z = 0;
    float y = 0;
    float radius = 2;
    

    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(1.0, 1.0, 1.0);
    

    glLoadIdentity();
    

    x = sin(alpha)*radius;
    y = z = cos(alpha)*radius;
    
    
    //gluOrtho2D(-1.5, 1.5, -5, 10);
    
    gluLookAt(x, y ,z, 0, 0, 0, 0, 1, 0);
    glColor3b(242, 179, 61);
    sinus = sin((float)PI/4);
    cubeSide = (float)(0.4)* sinus;
    cubeSide =(float)0.4/sqrt((float)3);
    glutSolidCube(cubeSide);
    glColor3b(197, 96, 63);
    glutWireSphere(0.2, 20, 10);
    
    
  
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho ((float)w/(float)h, (float)-w/(float)h, -1, 1, 0.8, 100);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc(void)
{
    alpha+=0.001;
    if(alpha>=360)
        alpha=0;
    display();
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
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}



