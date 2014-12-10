//function for io - mouse and keyboard
#include<GL/freeglut.h>
#include"tools.h"

#include"main.h"
#include"items.h"

#include"keymap.h"

extern ball b;

void handleMouseClick(int button, int state, int x, int y){
  if(button ==  GLUT_LEFT_BUTTON){
    //handling left clicks
    //for both states
    b.launchBall();
  }

  return;
}

void handleKeyboardInputs(unsigned char key, int x, int y){
  switch(key){
    case MAIN_MENU: //escape key => display main menu
                    exit(0); 
                    break; 
    default: //any other key		    
             break;
  }
  return;
}
