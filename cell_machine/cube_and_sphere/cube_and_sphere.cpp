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


#define PI                (3.14159265359)
#define SPHERE_RADIUS              (0.09)

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void drawSphere(float centerX, float centerY, float centerZ, float radius){
    glPushMatrix(); 
    glTranslatef(centerX, centerY, centerZ);
    glutWireSphere(radius, 20, 10);
    //glutSolidSphere(radius, 20, 10);
    glPopMatrix(); 
}

/*
float debug_rad;
float debus_sin;
float debug_cos;*/

void display(void);
void display(void){
    
    float x = 0;
    float z = 0;
    float y = 0;
    float cameraRotationRadius = 5;
    float cubeSide = 0;
    float sphereRad = SPHERE_RADIUS;
        
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();   

    // calculate camera position  
    /*debus_sin = sin(alpha);
    debug_cos = cos(alpha);*/
    x = cos(alpha)*cameraRotationRadius;
    z = sin(alpha)*cameraRotationRadius;
    //y = cos(alpha)*cameraRotationRadius;
    //debug_rad=sqrt(x*x+z*z);
    gluLookAt(x, y ,z, 0, 0, 0, 0, 1, 0); // view matrix

    glPushMatrix(); 

    // draw cube in the origin
    glColor3b(242, 179, 61);
    cubeSide =(float)0.4/sqrt((float)3);
    // glutSolidCube(cubeSide);

    // draw sphere
    glColor3b(197, 96, 63);  
    drawSphere(0, 0, 0, sphereRad);

    /*
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
           drawSphere((float)sphereRad*2*i-(float)sphereRad*2*5, (float)sphereRad*2*j-(float)sphereRad*2*5, 0, sphereRad);
        }
    }*/
    glFlush();
}

float fovy = 0;
void reshape(int w, int h){
 //   float fovy = 0;
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho ((float)w/(float)h, (float)-w/(float)h, -1, 1, 0.8, 100);
    fovy = 180*2*atan((SPHERE_RADIUS/5))/PI;
    gluPerspective((float)fovy, (float)w/(float)h, 0.1, 5);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc(void)
{
    alpha+=0.001;
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



