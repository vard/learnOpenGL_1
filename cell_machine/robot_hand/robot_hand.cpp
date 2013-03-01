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

static int shoulder = 30;
static int elbow = 30;
static int hand = 30;
static int fingers[4] = {0,0,0};

void display(void){


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();

    // shoulder
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.5, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0.1, -0.375);  
    glRotatef((GLfloat)fingers[0], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0);
    glScalef(0.5, 0.2, 0.25);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0.1, -0.125);  
    glRotatef((GLfloat)fingers[1], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0);
    glScalef(0.5, 0.2, 0.25);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0.1, 0.125);  
    glRotatef((GLfloat)fingers[2], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0);
    glScalef(0.5, 0.2, 0.25);
    glutWireCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0.1, 0.375);  
    glRotatef((GLfloat)fingers[3], 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0);
    glScalef(0.5, 0.2, 0.25);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (float)w/(float)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void idleFunc(void)
{
    display();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'h':
            hand = (hand + 5) % 360;
            glutPostRedisplay();
            break;
        case 'H':
            hand = (hand - 5) % 360;
            glutPostRedisplay();
            break;
        case 'z':
            fingers[3] = (fingers[3]+ 5) % 360;
            glutPostRedisplay();
            break;
        case 'Z':
            fingers[3] = (fingers[3] - 5) % 360;
            glutPostRedisplay();
            break;
        case 'x':
            fingers[2] = (fingers[2] + 5) % 360;
            glutPostRedisplay();
            break;
        case 'X':
            fingers[2] = (fingers[2] - 5) % 360;
            glutPostRedisplay();
            break;
        case 'c':
            fingers[1] = (fingers[1] + 5) % 360;
            glutPostRedisplay();
            break;
        case 'C':
            fingers[1] = (fingers[1] - 5) % 360;
            glutPostRedisplay();
            break;
        case 'v':
            fingers[0] = (fingers[0] + 5) % 360;
            glutPostRedisplay();
            break;
        case 'V':
            fingers[0] = (fingers[0] - 5) % 360;
            glutPostRedisplay();
            break;

        default:
            break;
    }
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
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}







