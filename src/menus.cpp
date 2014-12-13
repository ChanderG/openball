#include"menus.h"
#include"main.h"

#include<GL/freeglut.h>
#include<string>

void mainMenu(){
  //draw rectangle for menu - centered
  
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glBegin(GL_QUADS);
  glColor4f(1.0f, 1.0f, 1.0f, 0.2f);
  glVertex2f(-0.25, -0.25);
  glVertex2f(-0.25, 0.25);
  glVertex2f(0.25, 0.25);
  glVertex2f(0.25, -0.25);
  glEnd();
  glDisable(GL_BLEND);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glBegin(GL_POLYGON);
  glColor4d(0.0, 0.0, 0.0, 0.5); 
  glVertex2f(-0.25, -0.25);
  glVertex2f(-0.25, 0.25);
  glVertex2f(0.25, 0.25);
  glVertex2f(0.25, -0.25);
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor4f(1, 1, 1, 0.5); 

  //contents of main menu
  float x = -0.25;
  float y = 0.25;
  glRasterPos2f(x, y);

  std::string msg = "New Map";
  for(int i = 0;msg[i] != '\0';i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[i]);
  }
  
}
