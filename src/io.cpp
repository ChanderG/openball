//function for io - mouse and keyboard
#include<GL/freeglut.h>
#include"tools.h"

#include"main.h"
#include"items.h"
extern ball b;

void handleMouseClick(int button, int state, int x, int y){
  if(button ==  GLUT_LEFT_BUTTON){
    //handling left clicks
    //for both states
    b.launchBall();
  }

  return;
}
