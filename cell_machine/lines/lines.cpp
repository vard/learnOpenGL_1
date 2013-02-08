// lines.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gl\glut.h"

inline void drawOneLine(float x1,float y1, float x2, float y2){
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    // color
    glColor3f(1.0,1.0,1.0);
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
    for(i=0; i <7; i++){
        glVertex2f(50.0+((GLfloat)i*50), 75.0);
    }
    glEnd();

    for(i=0; i < 6; i++){
        drawOneLine(50.0 + ((GLfloat)i*50.0), 50.0,
            50.0 + ((GLfloat)(i+1)*50.0), 50);
    }

    glLineStipple(5, 0x1C47);
    drawOneLine(50.0, 25.0, 350.0, 25.0);
    glDisable(GL_LINE_STIPPLE);

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

    // Polygon stripple
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

    GLfloat vertices[18] = {
        10.0, 12.0, 12.0,
        30.0, 24.0, 10.0,
        40.0, 36.0, 12.0,
        50.0, 48.0, 10.0,
        60.0, 60.0, 12.0,
        70.0, 72.0, 10.0,
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
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glVertexPointer(3, GL_FLOAT, 0, colors);

    glBegin(GL_TRIANGLES);
    glArrayElement(0);
  /*  glArrayElement(2);
    glArrayElement(4);*/
    glEnd();



    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int _tmain(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(2000, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

