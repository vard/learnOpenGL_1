

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

GLuint listName;

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    listName = glGenLists(1);
    glNewList(listName, GL_COMPILE);  // GL_COMPILE - команды OpenGL в списке обрабаываются во время из размещения в списке
                                      // GL_COMPILE_AND_EXECUTE - команды до помещения в список выполняются в непосредственном режиме
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glTranslatef(1.5, 0.0, 0.0);
    glEndList();
    glShadeModel(GL_FLAT);
}

static void drawLine(void){
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(15.0, 0.5);
    glEnd();
}

void display(void){
    GLuint i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    for(i=0; i < 10; i++){
        glCallList(listName);
    }
    drawLine();


    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-17.5, 17.5, -17.5*(GLfloat)h/(GLfloat)w, 17.5*(GLfloat)h/(GLfloat)w, -3, 3 );
    else
        glOrtho(-17.5*(GLfloat)w/(GLfloat)h, 17.5*(GLfloat)w/(GLfloat)h, -17.5, 17.5, -3, 3 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        

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