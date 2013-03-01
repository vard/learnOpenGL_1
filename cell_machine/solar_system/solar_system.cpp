// solar_system.cpp: определяет точку входа для консольного приложения.
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


void drawplanet(float orbitRadius, float planetRadius, float daysInYear, float hoursInDay){
    static float year = 0;
    static float days = 0;
    static float hours = 0;
    glPushMatrix();
    glRotatef(year, 0, 1, 0);
    glTranslatef(orbitRadius, 0 ,0);
    glRotatef(days, 0, 1, 0);
    glutWireSphere(planetRadius, 20, 16);
    glPopMatrix();
    hours++;
    days = hours/hoursInDay;
    year=days/daysInYear;
}

void display(void){
    

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glLoadIdentity();
    gluLookAt(0,0,5, 0, 0, 0, 0 ,1, 0);
    glColor3b(197, 96, 63);  
    drawplanet(2, 0.2, 50, 12);
    drawplanet(1, 0.15, 30, 15);
   // drawplanet(3, 0.3, 20, 24);
   // drawplanet(5, 0.4, 30, 10);
    glColor3f(1.0, 0.647059, 0.00);
    //glColor3b(1.0, 1.0, 1.0);
    glutSolidSphere(0.5, 20, 16);

    


    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void idleFunc(void)
{
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





