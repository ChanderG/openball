#include"menus.h"
#include"main.h"
#include"items.h"
#include"tools.h"

#include<GL/freeglut.h>
#include<iostream>
#include<cstdlib>

menuGroup mainMg;
extern int state;
extern map m;

void menuGroup :: setMenuGroup(int nos){
  no = nos;
  curr = 1;
}

int menuGroup :: getSelected(){
  return curr;
}

void menuGroup ::  moveUp(){
  if(curr == 1) curr = no; 
  else curr--;
}

void menuGroup :: moveDown(){
  if(curr == no) curr = 1; 
  else curr++;
} 

void quitGame(){
  cout << "Quiting game..." << endl; 
  exit(1);
}

void loadRandomMap(){
  resetGame();
  srand(time(NULL));

  int main_map[10][10];

  for(int i = 0;i < 10;i++)
    for(int j = 0;j < 10;j++){
      main_map[i][j] = rand()%2;   
      
    }  

  m.createMap(main_map,0.2, 0.1);
}

void handleMenuSelection(){
  if(state == GAME_PAUSED){
    switch(mainMg.getSelected()){
      case quitGameNo: //implying quit
              quitGame();  
	      break;
      case loadRandomMapNo: //implying quit
              loadRandomMap();  
	      break;
      default: //anything else
               break;
    }
  }
}



//helper function for drawing boxes
void menuItemBox(float lx, float ly, float l, float h){
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glColor4d(0.0, 0.0, 0.0, 0.5); 
  glVertex2f(lx,ly);
  glVertex2f(lx + l,ly);
  glVertex2f(lx + l,ly - h);
  glVertex2f(lx,ly - h);
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor4f(1, 1, 1, 0.5); 
  
  return;  
};

void mainMenu(){
  //draw rectangle for menu - centered
  float lx = -0.25;  
  float ly = 0.50;  
  float l = 0.5;
  float h = 0.75;

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBegin(GL_QUADS);
  glColor4f(1.0f, 1.0f, 1.0f, 0.2f);
  glVertex2f(lx,ly);
  glVertex2f(lx + l,ly);
  glVertex2f(lx + l,ly - h);
  glVertex2f(lx,ly - h);
  glEnd();
  glDisable(GL_BLEND);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glColor4d(0.0, 0.0, 0.0, 0.5); 
  glVertex2f(lx,ly);
  glVertex2f(lx + l,ly);
  glVertex2f(lx + l,ly - h);
  glVertex2f(lx,ly - h);
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor4f(1, 1, 1, 0.5); 

  //contents of main menu
  glRasterPos2f(lx, ly);

  lx += 0.05;
  ly -= 0.1;

  //there seems to be an issue with the font being rendered first 
  for(int i = 1;i <= mainmenusSize;i++){
    glRasterPos2f(lx, ly-(i-1)*(0.15));
    for(int j = 0;mainmenus[i-1][j] != '\0';j++){
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mainmenus[i-1][j]);
    }
    if(mainMg.getSelected() == i)
      menuItemBox(lx-0.025, ly-(i-1)*(0.15) + 0.075, 0.45, 0.1); //0.0875);   
  }

}
