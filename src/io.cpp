//function for io - mouse and keyboard
#include<GL/freeglut.h>

#include"tools.h"
#include"main.h"
#include"items.h"
#include"keymap.h"
#include"menus.h"

extern ball b;
extern int state;

void handleMouseClick(int button, int state, int x, int y){
  if(button ==  GLUT_LEFT_BUTTON){
    //handling left clicks
    //for both PUSHDOWN and RELEASE
    b.launchBall();
  }

  return;
}

void handleKeyboardInputs(unsigned char key, int x, int y){
  switch(key){
    case MAIN_MENU: //escape key => display main menu
		    if(state == 1){
		      state = 0;
		    }
		    else{
		      state = 1;
                    } 
                    break; 
    default: //any other key		    
             break;
  }
  return;
}
