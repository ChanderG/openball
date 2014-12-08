#include<iostream>
using namespace std;

#include<GL/freeglut.h>

#include"main.h"
#include"items.h"
#include"tools.h"
#include"io.h"

// Main Paddle 
paddle p(-0.15, -0.9, 0.15, -0.95);

//x coordinate of mouse
int mouseX;

//main ball
ball b(0, 0, 0.05); 

//Main map
//matrix representation of a map
int main_map[10][10];
//actual map object
map m;    

//lives left
int lives = 3;

//global state indicator
//0 implies in paused state
int state = 0;

//game screen graphics
void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  displayScore(lives);  

  p.movePaddle(mouseX,0);
  p.drawPaddle();

  b.moveBall(p, &m, lives);
  b.drawBall();

  m.drawMap();

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

  //hide cursor
  glutSetCursor(GLUT_CURSOR_NONE);

  //map formula hardcoded here for now  
  for(int i = 0;i < 10;i++)
    for(int j = 0;j < 10;j++)
      if (i == j) main_map[i][j] = 1;
      else main_map[i][j] = 0;

  m.createMap(main_map,0.2, 0.1);

  glutDisplayFunc(displayMe);
  glutIdleFunc(displayMe);
  glutTimerFunc(1, timer, 1);

  glutPassiveMotionFunc(getMouseCoordinates);
  glutMouseFunc(handleMouseClick);

  glutMainLoop();
  return 0;
}

