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


float paddle ::  getLeft(){
  return left;
}  
float paddle :: getRight(){
  return right;
}
float paddle :: getTop(){
  return top;
}

ball :: ball(float cX, float cY, float hs){
  centerX = cX;
  centerY = cY;
  halfside = hs;
  
  velX = 0.001;
  velY = 0.001;
}

void ball :: drawBall(){
  glBegin(GL_POLYGON);

  glVertex2f(centerX-halfside, centerY-halfside);
  glVertex2f(centerX+halfside, centerY-halfside);
  glVertex2f(centerX+halfside, centerY+halfside);
  glVertex2f(centerX-halfside, centerY+halfside);

  glEnd();
  return;
}

void ball :: moveBall(paddle p, map m){
  if((centerX <= -1.0) || (centerX >= 1.0)) velX *= -1; 
  if((centerY <= -1.0) || (centerY >= 1.0)) velY *= -1; 

  if((centerX >= p.getLeft()) && (centerX <= p.getRight()) && ((centerY - halfside) <= p.getTop())){
    velY *= -1;
  }

  centerX += velX;
  centerY += velY;
}

//right now just copies the matrix
//need to add the ability to read from a file or have an inbuilt level editor
map :: map(int s[10][10], float l, float w){
  for(int i = 0;i<10;i++)
    for(int j = 0;j<10;j++)
      slots[i][j] = s[i][j];
  length = l;
  width = w;
}
  
map :: map(){

}

void map :: createMap(int s[10][10], float l, float w){
  for(int i = 0;i<10;i++)
    for(int j = 0;j<10;j++)
      slots[i][j] = s[i][j];
  length = l;
  width = w;
}

void map :: drawMap(){
  float cornerX = -1.0;
  float cornerY = 1.0;

  for(int i = 0;i<10;i++)
    for(int j = 0;j<10;j++){
      if(slots[i][j] == 0) continue;
     
      //basically drawing a brick
      //more information may be added later on in this grid
      glBegin(GL_POLYGON);
      glVertex2f(cornerX + j*length, cornerY - i*width);
      glVertex2f(cornerX + (j+1)*length, cornerY - i*width);
      glVertex2f(cornerX + (j+1)*length, cornerY - (i+1)*width);
      glVertex2f(cornerX + j*length, cornerY - (i+1)*width);
      glEnd();

    }
  return;
}
