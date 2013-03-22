

#include "stdafx.h"
#include <cmath>

#if defined  _WIN32
#include "gl\glew.h"
#include "gl\glut.h"

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

GLuint theTorus;

#define M_PI 3.1415926535

// Torus drawing
static void torus(int numc, int numt){
    int i = 0, j = 0, k = 0;
    double s, t, x, y, z, twopi;

    twopi = 2*(double)M_PI;
    for(i=0; i<numc; i++){
        glBegin(GL_QUAD_STRIP);
        for(j = 0; j < numt; j++){
            for(k=1; k>=0; k--){
                s = (i + k) % numc + 0.5;
                t = j % numt;
                x = (1+.1*cos(s*twopi/numc))*cos(t*twopi/numt);
                y = (1+.1*cos(s*twopi/numc))*sin(t*twopi/numt);
                z = .1 * sin(s*twopi/numc);
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }

}

void init(void){
    theTorus = glGenLists(1);
    glNewList(theTorus, GL_COMPILE);
    torus(8, 25);
    glEndList();
    glShadeModel(GL_FLAT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glCallList(theTorus);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'x':
        case 'X':
            glRotatef(30.0, 1.0, 0.0, 0.0);
            glutPostRedisplay();
            break;
        case 'y':
        case 'Y':
            glRotatef(30.0, 0.0, 1.0, 0.0);
            glutPostRedisplay();
            break;
        case 'i':
        case 'I':
            glLoadIdentity();
            gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
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
    //glutInitWindowPosition(100, 100);
    glutInitWindowPosition(2000, 100);
    glutCreateWindow(argv[0]);
    glewInit();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}