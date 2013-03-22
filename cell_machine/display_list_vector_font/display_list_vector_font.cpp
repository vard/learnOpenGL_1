#include "stdafx.h"
#include <cmath>
#include <cstring>

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

#define PT 1
#define STROKE 2
#define END 3

typedef struct CharPoint_{
    GLfloat x, y;
    int type;
} CharPoint;

// 'A' char
CharPoint Adata[] = {
    {0 , 0, PT},
    {0 , 9, PT},
    {1 , 10, PT},
    {4 , 10, PT},
    {5 , 9, PT},
    {5 , 0, STROKE},
    {0 , 5, PT},
    {5 , 5, END}
};

// 'E' char
CharPoint Edata[] = {
    {5 , 0, PT},
    {0 , 0, PT},
    {0 , 10, PT},
    {5 , 10, STROKE},
    {0 , 5, PT},
    {4 , 5, END}
};

// 'P' char
CharPoint Pdata[] = {
    {0 , 0, PT},
    {0 , 10, PT},
    {4 , 10, PT},
    {5 , 9, PT},
    {5 , 6, PT},
    {4 , 5, PT},
    {0 , 5, END}
};

// 'R' char
CharPoint Rdata[] = {
    {0 , 0, PT},
    {0 , 10, PT},
    {4 , 10, PT},
    {5 , 9, PT},
    {5 , 6, PT},
    {4 , 5, PT},
    {0 , 5, STROKE},
    {3 , 5, PT},
    {5 , 0, END}
};

// 'S' char
CharPoint Sdata[] = {
    {0 , 1, PT},
    {1 , 0, PT},
    {4 , 0, PT},
    {5 , 1, PT},
    {5 , 4, PT},
    {4 , 5, PT},
    {1 , 5, PT},
    {0 , 6, PT},
    {0 , 9, PT},
    {1 , 10, PT},
    {4 , 10, PT},
    {5 , 9, END}
};

static void drawLetter(CharPoint *l){
    glBegin(GL_LINE_STRIP);
    while(1){
        switch(l->type){
            case PT:
                glVertex2fv(&l->x);
                break;
            case STROKE:
                glVertex2fv(&l->x);
                glEnd();
                glBegin(GL_LINE_STRIP);
                break;
            case END:
                glVertex2fv(&l->x);
                glEnd();
                glTranslatef(8.0, 0.0, 0.0);
                return;
            default:
                break;
        }
        l++;
    }
}

void init(void){
    GLuint base;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    base = glGenLists(128);
    glListBase(base);

    glNewList(base+'A', GL_COMPILE);
    drawLetter(Adata);
    glEndList();

    glNewList(base+'E', GL_COMPILE);
    drawLetter(Edata);
    glEndList();

    glNewList(base+'P', GL_COMPILE);
    drawLetter(Pdata);
    glEndList();

    glNewList(base+'R', GL_COMPILE);
    drawLetter(Rdata);
    glEndList();

    glNewList(base+'S', GL_COMPILE);
    drawLetter(Sdata);
    glEndList();

    glNewList(base+' ', GL_COMPILE);
    glTranslatef(8.0, 0.0, 0.0);
    glEndList();

}

char* test1 = "A SPARE SEPARE APEEARS AS";
char* test2 = "APES PREPARE RARE PEPPERS";

static void printStrokedString(char* s){
    GLsizei len = strlen(s);
    glCallLists(len, GL_BYTE, (GLbyte*)s);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(10.0, 30.0, 0.0);
    printStrokedString(test1);
    glPopMatrix();
    glPushMatrix();
    glScalef(2.0, 2.0, 2.0);
    glTranslatef(10.0, 13.0, 0.0);
    printStrokedString(test2);
    glPopMatrix();


    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLfloat)w, 0.0,(GLfloat)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case ' ':
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