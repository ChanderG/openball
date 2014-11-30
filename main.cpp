#include<iostream>
using namespace std;

#include<GL/freeglut.h>

#include"items.h"

void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();

  paddle p(-0.15, -0.50, 0.15, -0.6);
  p.drawPaddle();

  glFlush();
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(1200, 700);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenBall");

  glutDisplayFunc(displayMe);

  glutMainLoop();
  return 0;
}
