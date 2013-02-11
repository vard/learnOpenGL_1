// lines.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#if defined  _WIN32
#include "gl\glew.h"
#include "gl\glut.h"
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


inline void drawOneLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {


    glClear(GL_COLOR_BUFFER_BIT);
    // color
    glColor3f(1.0, 1.0, 1.0);

    /************************************ glLineStipple ************************************/

    /*
    int i;
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x0101);
    drawOneLine(50.0, 125.0, 150.0, 125.0);
    glLineStipple(1, 0x00FF);
    drawOneLine(150.0, 125.0, 250.0, 125.0);
    glLineStipple(1, 0x1C47);
    drawOneLine(250.0, 125.0, 350.0, 125.0);

    glLineWidth(5.0);
    glLineStipple(1, 0x0101);
    drawOneLine(50.0, 100.0, 150.0, 100.0);
    glLineStipple(1, 0x00FF);
    drawOneLine(150.0, 100.0, 250.0, 100);
    glLineStipple(1, 0x1C47);
    drawOneLine(250.0, 100.0, 350.0, 100.0);
    glLineWidth(1.0);

    glLineStipple(1, 0x1C47);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < 7; i++) {
    glVertex2f(50.0 + ((GLfloat) i * 50), 75.0);
    }
    glEnd();

    for (i = 0; i < 6; i++) {
    drawOneLine(50.0 + ((GLfloat) i * 50.0), 50.0,
    50.0 + ((GLfloat) (i + 1)*50.0), 50);
    }

    glLineStipple(5, 0x1C47);
    drawOneLine(50.0, 25.0, 350.0, 25.0);
    glDisable(GL_LINE_STIPPLE);*/

    /************************************ draw polygons ************************************/
    /*
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2f(20,200);   
    glVertex2f(50,385);
    glVertex2f(100,380);
    glVertex2f(140,350);
    glVertex2f(120,210);
    glEnd();

    glEnable(GL_CULL_FACE);
    // glFrontFace(GL_CW);
    // glCullFace(GL_BACK);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex2f(220,200);    
    glVertex2f(250,385);
    glVertex2f(300,380);
    glVertex2f(310,350);
    glVertex2f(320,210);    
    glEnd();
    glDisable(GL_CULL_FACE);*/

    /************************************ glPolygonStipple ************************************/

    /*
    const GLubyte factureBitmap[4*32] = { 
    0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF,
    0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x00 ,0x00,
    0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF,
    0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x00 ,0x00,
    0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF,
    0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x00 ,0x00,
    0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF,
    0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF, 0x0, 0x0, 0xFF ,0xFF
    };

    glPolygonStipple(factureBitmap);
    glEnable(GL_POLYGON_STIPPLE);
    glRectd(20, 300, 150, 400);
    glDisable(GL_POLYGON_STIPPLE);
    */


    /************************************ glArrayElement ************************************/

    /*
    GLfloat vertices[18] = {
    100.0, 200.0,
    200.0, 324.0,
    300.0, 336.0,
    400.0, 248.0,
    450.0, 360.0,
    300.0, 272.0
    };

    GLfloat colors[18] = {
    0.5, 0.5, 0.5,
    0.5, 0.5, 1.0,
    0.5, 1.0, 0.5,
    1.0, 0.5, 0.5,
    1.0, 0.0, 0.0,
    0.0, 0.0, 1.0
    };

    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    glBegin(GL_TRIANGLES);
    glArrayElement(0);
    glArrayElement(2);
    glArrayElement(4);
    glEnd();
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);*/



    /************************************ glDrawElements ************************************/

    /*

    GLfloat vertices[26] = {
    100.0, 200.0,
    200.0, 324.0,
    300.0, 336.0,
    400.0, 248.0,
    450.0, 360.0,
    300.0, 272.0,
    50.0, 100.0,
    150.0, 50.0,
    100.0, 248.0,
    150.0, 360.0,
    200.0, 272.0,
    250.0, 100.0,
    350.0, 50.0
    };

    static GLsizei count[] = {7, 6};

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);

    static GLubyte oneIndices[] = {0, 1, 2, 3, 4, 5, 6};
    static GLubyte twoIndices[] = {7, 1, 8, 9, 10, 11};

    static const GLvoid* indices[2] = {oneIndices, twoIndices};
    //static const GLvoid* indices[1] = {oneIndices};


    // glDrawElements
    glDrawElements(GL_LINE_STRIP, 7, GL_UNSIGNED_BYTE, oneIndices);
    glDrawElements(GL_LINE_STRIP, 6, GL_UNSIGNED_BYTE, twoIndices);

    // glMultiDrawElements
    glMultiDrawElements(GL_LINE_STRIP, count, GL_UNSIGNED_BYTE, indices, 2);

    GLenum err;
    err = glGetError();
    glDisableClientState(GL_VERTEX_ARRAY);*/

    /************************************ glDrawArrays ************************************/

    /*
    GLfloat vertices[26] = {
    100.0, 200.0,
    200.0, 324.0,
    300.0, 336.0,
    400.0, 248.0,
    450.0, 360.0,
    300.0, 272.0,
    50.0, 100.0,
    150.0, 50.0,
    100.0, 248.0,
    150.0, 360.0,
    200.0, 272.0,
    250.0, 100.0,
    350.0, 50.0
    };

    glEnableClientState(GL_VERTEX_ARRAY);    
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    GLint first = 0;
    GLsizei count  = 9;
    glDrawArrays(GL_TRIANGLES, first, count);
    glDisableClientState(GL_VERTEX_ARRAY);*/

    /********************************* glMultiDrawArrays ************************************/
    /*
    GLfloat vertices[26] = {
    100.0, 200.0,
    200.0, 324.0,
    300.0, 336.0,
    400.0, 248.0,
    450.0, 360.0,
    300.0, 272.0,
    50.0, 100.0,
    150.0, 50.0,
    100.0, 248.0,
    150.0, 360.0,
    200.0, 272.0,
    250.0, 100.0,
    350.0, 50.0
    };

    glEnableClientState(GL_VERTEX_ARRAY);    
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    GLint first[2] = {0, 3};
    GLsizei count[2]  = {3, 6};
    glMultiDrawArrays(GL_TRIANGLES, first, count, 3);
    glDisableClientState(GL_VERTEX_ARRAY);*/


    /********************************* glInterleavedArrays ************************************/
    /*
    GLfloat intertwined[] = {
        1.0, 0.2, 1.0, 100.0, 200.0, 0.0,
        0.5, 0.2, 1.0, 200.0, 324.0, 0.0,
        1.0, 0.7, 1.0, 300.0, 336.0, 0.0,
        0.3, 0.2, 1.0, 400.0, 248.0, 0.0, 
        1.0, 0.5, 1.0, 450.0, 360.0, 0.0,
        1.0, 0.1, 0.2, 300.0, 272.0, 0.0,
        1.0, 0.2, 0.4, 50.0, 100.0, 0.0, 
        0.4, 0.2, 0.6, 150.0, 50.0, 0.0, 
        0.6, 0.7, 0.6, 100.0, 248.0, 0.0, 
        1.0, 0.2, 0.6, 150.0, 360.0, 0.0, 
        0.7, 0.5, 0.6, 200.0, 272.0, 0.0, 
        0.8, 0.2, 0.6, 250.0, 100.0, 0.0, 
        1.0, 0.1, 0.6, 350.0, 50.0, 0.0 
    };

    glInterleavedArrays(GL_C3F_V3F, 0, intertwined);
    GLint first = 0;
    GLsizei count  = 12;
    glDrawArrays(GL_TRIANGLES, first, count);
    */

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
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
    //   init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

