#include"items.h"
#include<GL/freeglut.h>

#include<iostream>
using namespace std;

paddle :: paddle(float l,float t,float r,float b){
  left = l;
  top = t;
  right = r;
  bottom = b;
  length = r - l;
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

void paddle :: movePaddle(int x, int y){
  left = x/600.0 - length/2.0;
  right = x/600.0 + length/2.0;
  return;
}

