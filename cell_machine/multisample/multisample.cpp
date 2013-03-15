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

static int bgtoggle = 1;

/*
*   print state parameters, captiveted to multisample
*   Create display list with wheel of lines and triangles   
*/
void init(void){
    GLint buf, sbuf;
    int i, j;
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_MULTISAMPLE);
    glGetIntegerv(GL_SAMPLE_BUFFERS, &buf);
    printf("Sample buffers count GL_SAMPLE_BUFFERS = %d\n", buf);
    glGetIntegerv(GL_SAMPLES, &sbuf);
    printf("Sample elements count GL_SAMPLES = %d\n", sbuf);
    glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, &buf);
    printf("Sample buffers count GL_SAMPLE_BUFFERS_ARB = %d\n", buf);
    glGetIntegerv(GL_SAMPLES_ARB, &sbuf);
    printf("Sample elements count GL_SAMPLES_ARB = %d\n", sbuf);

    glNewList(1, GL_COMPILE);
    for(int i = 0; i < 19; i++){
        glPushMatrix();
        glRotatef(360.0*(float)i/19.0, 0.0, 0.0, 1.0);
        glColor3f(1.0, 1.0, 1.0);
        glLineWidth((i%3)+1.0);
        glBegin(GL_LINES);
        glVertex2f(0.25,0.05);
        glVertex2f(0.9, 0.2);
        glEnd();
        glColor3f(0.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.25, 0.0);
        glVertex2f(0.9, 0.0);
        glVertex2f(0.875, 0.10);
        glEnd();
        glPopMatrix();
    }
    glEndList();

    glNewList(2, GL_COMPILE);
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    for(i = 0; i < 16; i++){
        for(j=0; j < 16; j++){
            if(((i+j)%2)==0){
                glVertex2f(-2.0+(i*0.25), -2.0+(j*0.25));
                glVertex2f(-2.0+(i*0.25), -1.75+(j*0.25));
                glVertex2f(-1.75+(i*0.25), -1.75+(j*0.25));
                glVertex2f(-1.75+(i*0.25), -2.0+(j*0.25));
            }
        }
    }
    glEnd();
    glEndList();

}
/*
 * Draw two primitives sets to compare the results between using multisample and not using.
 * This code turns on smoothing and drwas first display list
 * then turns off smoothing and draws second display list
 */
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);

    if(bgtoggle)
        glCallList(2);

    glEnable(GL_MULTISAMPLE_ARB);
    glPushMatrix();
    glTranslatef(-1.0, 0.0, 0.0);
    glCallList(1);
    glPopMatrix();

    glDisable(GL_MULTISAMPLE_ARB);
    glPushMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glCallList(1);
    glPopMatrix();
    glutSwapBuffers();


    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w, 2.5*(GLfloat)h/(GLfloat)w, -3, 3 );
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h, -2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -3, 3 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'b':
        case 'B':
            bgtoggle = !bgtoggle;
            glutPostRedisplay();


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
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_MULTISAMPLE);
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