#include"items.h"
#include<GL/freeglut.h>

paddle :: paddle(float l,float t,float r,float b){
  left = l;
  top = t;
  right = r;
  bottom = b;
}

void paddle::drawPaddle(){
  glBegin(GL_POLYGON);

  glVertex2f(left, bottom);
  glVertex2f(right, bottom);
  glVertex2f(right, top);
  glVertex2f(left, top);

  glEnd();
  return;
}
