// cell_machine.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "game.h"
#include <iostream>
#include "gl\glut.h"
#include "gl\gl.h"

using namespace cell_machine;

/* начальная ширина и высота окна */
GLint Width = 512, Height = 512;

/* размер куба */
const int CubeSize = 200;

/* эта функция управляет всем выводом на экран */
void Display(void)
{
     static GLfloat pVerts[]= {-0.5f, -0.5f, 0.0f,
                          0.5f,  0.0f, 0.0f,
                         -0.5f , 0.5f, 0.0f};

     static GLushort ind[] = {0,1,2};


    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);    

    glColor3ub(255,0,0);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT,0, pVerts);

    glDrawElements(GL_POINTS, 3, GL_UNSIGNED_SHORT, ind);
   // glDrawArrays(GL_POINTS, 0, 3);

/*
    glBegin(GL_QUADS);
      glVertex2f(left,bottom);
      glVertex2f(left,top);
      glVertex2f(right,top);
      glVertex2f(right,bottom);
    glEnd();*/

    glFlush();
    glFinish();
}

/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h)
{
    Width = w;
    Height = h;

    /* устанавливаем размеры области отображения */
    glViewport(0, 0, w, h);

    /* ортографическая проекция */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int _tmain(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);    
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Life");

    CellMachineGame newCellGame;
    CellMachineGame newCellGame2 = newCellGame;
    newCellGame.start();

    glutDisplayFunc(Display);
    //glutReshapeFunc(Reshape);
    glutMainLoop();

	//return 0;
}

