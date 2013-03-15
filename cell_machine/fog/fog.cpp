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

static GLint fogMode;

void init(void){
    GLfloat position[] = {0.5, 0.5, 3.0, 0.0};

    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        GLfloat mat1[3] = {0.1745, 0.01175, 0.01175};
        GLfloat mat2[3] = {0.61424, 0.04136, 0.04136};
        GLfloat mat3[3] = {0.727811, 0.626959, 0.626959};
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat1);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat2);
        glMaterialfv(GL_FRONT, GL_SPECULAR, mat3);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
    }

    glEnable(GL_FOG);
    {
        GLfloat fogColor[4] = {0.5, 0.5, 0.5, 1.0};
        fogMode = GL_EXP;
        glFogi(GL_FOG_MODE, fogMode);
        glFogfv(GL_FOG_COLOR, fogColor);
        glFogf(GL_FOG_DENSITY, 0.35);
        glHint(GL_FOG_HINT, GL_DONT_CARE);
        glFogf(GL_FOG_START, 1.0);
        glFogf(GL_FOG_END, 5.0);
    }


    glClearColor(0.5, 0.5, 0.5, 1.0); // fog color
}

static void renderSphere(GLfloat x, GLfloat y, GLfloat z){
    glPushMatrix();
    glTranslatef(x,y,z);
    glutSolidSphere(0.4, 16, 16);
    glPopMatrix();
};

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderSphere(-2., -0.5, -1.0);
    renderSphere(-1., -0.5, -2.0);
    renderSphere(0, -0.5, -3.0);
    renderSphere(1, -0.5, -4.0);
    renderSphere(2, -0.5, -5.0);

    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w, 2.5*(GLfloat)h/(GLfloat)w, -6, 6 );
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h, -2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -6, 6 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'f':
        case 'F':
            if(fogMode == GL_EXP){
                fogMode = GL_EXP2;
                printf("Fog mode GL_EXP2\n");
            }
            else if(fogMode == GL_EXP2){
                fogMode = GL_LINEAR;
                printf("Fog mode GL_LINEAR\n");
            }
            else if(fogMode == GL_LINEAR){
                fogMode = GL_EXP;
                printf("Fog mode GL_EXP\n");
            }
            glFogi(GL_FOG_MODE, fogMode);
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