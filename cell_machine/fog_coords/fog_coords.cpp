

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

static GLfloat f1, f2, f3;

/*
*  Fog initialization
*/
void init(void){
    GLfloat fogColor[4] = {0.0, 0.25, 0.25, 1.0};
    f1 = 1.0f;
    f2 = 5.0f;
    f3 = 10.0f;
    glEnable(GL_FOG); // enable fog
    glFogi(GL_FOG_MODE, GL_EXP); // set fog mode
    glFogfv(GL_FOG_COLOR, fogColor); // set fog color
    glFogf(GL_FOG_DENSITY, 0.25); // set fog denisty
    glHint(GL_FOG_HINT, GL_DONT_CARE); // set fog hint
    glFogi(GL_FOG_COORDINATE_SOURCE, GL_FOG_COORDINATE); // режим явного указания координат тумана
    glClearColor(0.0, 0.25, 0.25, 1.0); // same as fog color
    //glClearColor(0.0, 0.0, 0.0, 1.0); // same as fog color
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.75f, 0.0f);
    glBegin(GL_TRIANGLES);
    {
        glFogCoordf(f1);
        glVertex3f(2.0f, -2.0f, 0.0f);
        glFogCoordf(f2);
        glVertex3f(-2.0f, 0.0f, -5.0f);
        glFogCoordf(f3);
        glVertex3f(0.0f, 2.0f, -10.0f);
    }
    glEnd();    

    //glutSwapBuffers();
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w, 2.5*(GLfloat)h/(GLfloat)w, -10, 10 );
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h, -2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10, 10 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'C':
            glFogi(GL_FOG_COORDINATE_SOURCE, GL_FRAGMENT_DEPTH);
            glutPostRedisplay();
            break;
        case 'D':
            glFogi(GL_FOG_COORDINATE_SOURCE, GL_FOG_COORDINATE);
            glutPostRedisplay();
            break; 
        case '1':
            f1 = f1 + 0.25;
            glutPostRedisplay();
            break; 
        case '2':
            f2 = f2 + 0.25;
            glutPostRedisplay();
            break; 
        case '3':
            f3 = f3 + 0.25;
            glutPostRedisplay();
            break; 
        case '8':
            if(f1 > 0.25){
                f1 = f1 - 0.25;
                glutPostRedisplay();
            }            
            break;
        case '9':
            if(f2 > 0.25){
                f2 = f2 - 0.25;
                glutPostRedisplay();
            }            
            break; 
        case '0':
            if(f3 > 0.25){
                f3 = f3 - 0.25;
                glutPostRedisplay();
            }            
            break; 
        case 'b':
            glMatrixMode(GL_MODELVIEW);
            glTranslatef(0.0, 0.0, -0.25);
            glutPostRedisplay();
            break;
        case 'f':
            glMatrixMode(GL_MODELVIEW);
            glTranslatef(0.0, 0.0, 0.25);
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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
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