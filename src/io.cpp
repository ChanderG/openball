//function for io - mouse and keyboard
#include<GL/freeglut.h>

#include"main.h"
#include"tools.h"
#include"items.h"
#include"keymap.h"
#include"menus.h"

extern ball b;
extern int state;
extern int mouseX;

void handleMouseClick(int button, int state, int x, int y){
  if(button ==  GLUT_LEFT_BUTTON){
    //handling left clicks
    //for both PUSHDOWN and RELEASE
    b.launchBall();
  }

  return;
}

void handleKeyboardInputs(unsigned char key, int x, int y){
  if(state == GAME_ACTIVE){
    switch(key){
      case MAIN_MENU: //escape key => display main menu
                      state = GAME_PAUSED;
                      break; 
      default: //others
               break;      
    }
  }
  else if(state == GAME_PAUSED){
    switch(key){
      case MAIN_MENU: //escape key => display main menu
                      state = GAME_ACTIVE;
                      break; 
      default: //others
               break;      
    }
  }
  else;

  return;
}

void handleMouseMovements(int x, int y){
  //send mouse coordinates to paddle
  mouseX = x-WIDTH/2;
}
