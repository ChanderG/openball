#include<iostream>
using namespace std;

#include<GL/freeglut.h>

#include"items.h"

// Main Paddle 
paddle p(-0.15, -0.9, 0.15, -0.95);
//x coordinate of mouse
int mouseX;

//game screen graphics
void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();

  p.movePaddle(mouseX,0);
  p.drawPaddle();

  glFlush();
}

void getMouseCoordinates(int x, int y){
  mouseX = x-600;
}

void timer(int t){
  glutTimerFunc(1, timer, 1);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(1200, 700);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenBall");

  glutDisplayFunc(displayMe);
  glutIdleFunc(displayMe);
  glutTimerFunc(1, timer, 1);
  glutPassiveMotionFunc(getMouseCoordinates);
  //glutMouseFunc(getMouseCoordinates);

  glutMainLoop();
  return 0;
}
