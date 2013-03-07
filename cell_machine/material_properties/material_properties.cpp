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
    GLfloat scene_ambient[] = {0.2, 0.2, 0.2, 1.0};
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // Общее фоновое освещение
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, scene_ambient);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void){
    GLdouble eqn[4] = {+1.0, 0.0, -1.0, +2.25}; // plane 2.8x + z - 6.3 = 0
    GLfloat no_mat[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat mat_back[] = {0.1, 0.9, 0.1, 1.0};
    GLfloat mat_ambient[] = {0.7, 0.7, 0.7, 1.0};
    GLfloat mat_ambient_back[] = {0.1, 0.1, 0.7, 1.0};
    GLfloat mat_ambient_color[] = {0.8, 0.8, 0.2, 1.0};
    GLfloat mat_diffuse[] = {1.0, 0.5, 0.8, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat no_shininess[] = {0.0};
    GLfloat low_shininess[] = {5.0};
    GLfloat high_shininess[] = {100.0};
    GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Срежем часть сферы
    glClipPlane(GL_CLIP_PLANE0, eqn);
    glEnable(GL_CLIP_PLANE0);

    glPushMatrix();
    glTranslatef(1.25, -3.0, 0.0);
    
    // Внешняя поверхность
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);          // фоновый цвет материала
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);     // Рассеянный цвет материала
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // Отраженный цвет материала
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);// Коэффициент зеркального отражения
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);         // Излучаемый цвет материала

    // Внутренняя поверхность    
    glColorMaterial(GL_BACK, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.1, 0.1, 0.3);
    glDisable(GL_COLOR_MATERIAL);

    glMaterialfv(GL_BACK, GL_AMBIENT, mat_back);         // фоновый цвет материал
    //glMaterialfv(GL_BACK, GL_DIFFUSE, mat_ambient_back); // Рассеянный цвет материала
    glMaterialfv(GL_BACK, GL_SPECULAR, mat_specular);    // Отраженный цвет материала
    glMaterialfv(GL_BACK, GL_SHININESS, high_shininess); // Коэффициент зеркального отражения
    glMaterialfv(GL_BACK, GL_EMISSION, no_mat);          // Излучаемый цвет материала

    glutSolidSphere(3.5, 16, 16);
    glPopMatrix();
    glDisable(GL_CLIP_PLANE0);


    // Сфера с рассеянным диффузным цветом, без фонового или зеркального цвета
    glPushMatrix();
    glTranslatef(-3.75, 3.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);         // фоновый цвет материала
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);    // Рассеянный цвет материала
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);        // Отраженный цвет материала
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess); // Коэффициент зеркального отражения
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);        // Излучаемый цвет материала
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    // Сфера с диффузным и зеркальным цветом, с небольшим блеском без фонового цвета
    glPushMatrix();
    glTranslatef(-1.25, 3.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    // Сфера с диффузным и зеркальным цветом, ярким блеском, без фонового цвета
    glPushMatrix();
    glTranslatef(1.25, 3.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();

    // Сфера с диффузным цветом, излучением, без фонового и зеркального цвета
    glPushMatrix();
    glTranslatef(3.75, 3.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
    glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(1.0, 16, 16);
    glPopMatrix();
   

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
    glutMainLoop();
    return 0;
}







