#include"menus.h"
#include"main.h"

#include<GL/freeglut.h>

void mainMenu(){
  //draw rectangle for menu - centered
  glBegin(GL_POLYGON);

  glVertex2f(-0.25, -0.25);
  glVertex2f(-0.25, 0.25);
  glVertex2f(0.25, 0.25);
  glVertex2f(0.25, -0.25);

  glEnd();
}
