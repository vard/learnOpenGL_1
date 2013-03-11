// project_template.cpp: определяет точку входа для консольного приложения.
//

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


void init(void){
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glBlendFunc(GL_ONE, GL_ONE);
    glEnable(GL_BLEND);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glRectf(-0.5, -0.5, 0.5, 0.5);
    
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-7.5, 7.5, -7.5*(GLfloat)h/(GLfloat)w, 7.5*(GLfloat)h/(GLfloat)w, -10, 10 );
    else
        glOrtho(-7.5*(GLfloat)w/(GLfloat)h, -7.5*(GLfloat)w/(GLfloat)h, -7.5, 10.5, -10, 10 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'a': case 'A':
            // Цвета складываются
            // (0,0,1) + (1,1,0) = (1,1,1);
            // После ограниченяи получается (0,0,1)
            glBlendEquation(GL_FUNC_ADD);
            break;

        case 's': case 'S':
            // Цвета вычитаются
            // (0,0,1) - (1,1,0) = (-1,-1,1);
            // После ограниченяи получается (0,0,1)
            glBlendEquation(GL_FUNC_SUBTRACT);
            break; 

        case 'r': case 'R':
            // Цвета вычитаются
            // (1,1,0) - (0,0,1) = (1,1,-1);
            // После ограниченяи получается (1,1,0)
            glBlendEquation(GL_FUNC_REVERSE_SUBTRACT);
            break;

        case 'm': case 'M':
            // [min(1, 0), min(1, 0), min(0, 1) -> (0, 0, 0)]
            glBlendEquation(GL_MIN);
            break;

        case 'x': case 'X':
            // [max(1, 0), max(1, 0), max(0, 1) -> (1, 1, 1)]
            glBlendEquation(GL_MAX);
            break;
        

        default:
            break;
    }
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