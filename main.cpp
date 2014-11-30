#include<iostream>
using namespace std;

#include<GL/freeglut.h>

#include"items.h"

// Main Paddle 
paddle p(-0.15, -0.9, 0.15, -0.95);
//x coordinate of mouse
int mouseX;
// Main Ball
ball b(0, 0, 0.05); 

//game screen graphics
void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  p.movePaddle(mouseX,0);
  p.drawPaddle();

  b.moveBall();
  b.drawBall();

  glFlush();
}

void getMouseCoordinates(int x, int y){
  mouseX = x-WIDTH/2;
}

void timer(int t){
  glutTimerFunc(1, timer, 1);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenBall");

  glutDisplayFunc(displayMe);
  glutIdleFunc(displayMe);
  glutTimerFunc(1, timer, 1);
  glutPassiveMotionFunc(getMouseCoordinates);

  glutMainLoop();
  return 0;
}
