
#if defined  _WIN32
#include "stdafx.h"
#include "gl\glew.h"
#include "gl\glut.h"
#include <cmath>
#endif

#ifdef _WIN64
#include "stdafx.h"
#include "gl\glut.h"
#include "gl\glew.h"
#include <cmath>
#endif

#ifdef __linux__
#include "GL/glew.h"
#include "GL/glut.h"
#include <cmath>
#endif


void init(void){
    

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

static float angle = 0;
static GLfloat light_position[] = {2.0, 0.0, 0.0, 1.0};

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glPushMatrix();
    glLoadIdentity();
    gluLookAt(0,0,-5, 0, 0, 0, 0, 1, 0);
    glPushMatrix();
    glRotatef(angle, 1,  0, 0);
    glutSolidTorus(0.278, 0.85, 40, 50);
    glPopMatrix();
    glPushMatrix();
    glRotatef(angle, 0, 1, 0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glPopMatrix();
    
    //glPopMatrix();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, -10, 10 );
    else
        glOrtho(-1.5*(GLfloat)w/(GLfloat)h, -1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10, 10 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idleFunc(){
    angle +=0.01;
    glutPostRedisplay();
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
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







