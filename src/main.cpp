#include<iostream>
using namespace std;

#include<GL/freeglut.h>

#include"main.h"
#include"items.h"
#include"tools.h"
#include"io.h"
#include"menus.h"

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
int lives = MAX_LIVES;

//global state indicator
//2 implies current game over and success
//3 implies current game over and failure
int state = GAME_ACTIVE;

//menu grouping handler
extern menuGroup mainMg;

//game screen graphics
void displayMe(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  /*BACKGROUND COLOR
  glBegin(GL_QUADS);
  glColor4f(0.5f, 0.0f, 1.0f, 0.7); // (0.5, 0, 1) is half red and full blue, giving dark purple.
  //menu rectangle
  glVertex2f(-1, -1);
  glVertex2f(-1, 1);
  glVertex2f(1, 1);
  glVertex2f(1, -1);
  glEnd();
  */

  glColor4f(1,1,1,0.5);

  displayScore(lives);  
  p.drawPaddle();
  b.drawBall();
  m.drawMap();

  //if paused aka main menu is displayed
  if(state == GAME_PAUSED){
    mainMenu(); 
  }
  else{
    p.movePaddle(mouseX,0);
    b.moveBall(p, &m, lives);
  }

  //glFlush();
  glutSwapBuffers();
}


void timer(int t){
  glutTimerFunc(1, timer, 1);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_ALPHA);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("OpenBall");
  glClearColor(0.0,0.0,0.0,0.0);
  //hide cursor
  glutSetCursor(GLUT_CURSOR_NONE);


  //map formula hardcoded here for now  
  for(int i = 0;i < 10;i++)
    for(int j = 0;j < 10;j++)
      if (i == j) main_map[i][j] = 1;
      else main_map[i][j] = 0;

  m.createMap(main_map,0.2, 0.1);

  //dumb way to load the group menu option
  //now works only because there is only one menu
  mainMg.setMenuGroup(mainmenusSize);

  glutDisplayFunc(displayMe);
  glutIdleFunc(displayMe);
  glutTimerFunc(1, timer, 1);

  glutPassiveMotionFunc(handleMouseMovements);
  glutMouseFunc(handleMouseClick);
  glutKeyboardFunc(handleKeyboardInputs);
  glutSpecialFunc(handleSpecialKeyboardInputs);


  glutMainLoop();
  return 0;
}

