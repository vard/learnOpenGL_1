
#if defined  _WIN32
#include "stdafx.h"
#include "gl\glew.h"
#include "gl\glut.h"
#include <cmath>
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
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = {2.0, 2.0, 2.0, 0.0};
    GLfloat light_ambient[] = {0.0, 0.0, 1.0, 1.0};
    GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat lmodel_ambient[] = {0.1, 0.1, 0.1, 1.0};
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   //Lightfv(GL_LIGHT0, GL_SPECULAR, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    // 2nd lamp
    GLfloat light1_ambient[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat light1_diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light1_position[] = {-1.0, 0.0, -1.0, 1.0};
    GLfloat spot_direction[] = {1.0, 0.0, 1.0};           // Это вектор направления света, а не точка куда он будет направлен

    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);     // Цвет фонового освещения
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);     // Цвет рассеяного освещения
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);   // Цвет отраженного света
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);   // Координаты источника света
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);    // Ослабление интенсивности света вне зависимости от направления и расстояния
    glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);      // Линейное ослабление интенсивности света
    glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);   // Квадратичное затухание света

    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);               // Угол разброса световых лучей
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction); // Направление распространения света
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);              // Распределение интенсивности светового пучка по экспоненте

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);
}


void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(1.0, 100, 50);
    glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w, 1.5*(GLfloat)h/(GLfloat)w, 10, 10 );
    else
        glOrtho(-1.5*(GLfloat)w/(GLfloat)h, -1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, 10, 10 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
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
    glutInitWindowPosition(100, 100);
    //glutInitWindowPosition(200, 100);
    glutCreateWindow(argv[0]);
    glewInit();
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}






