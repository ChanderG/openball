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
  initCx = centerX = cX;
  initCy = centerY = cY;
  halfside = hs;
  
  initVelX = velX = 0.001;
  initVelY = velY = 0.001;
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

void ball :: moveBall(paddle p, map* m, int& lives){
  //collide with walls
  if((centerX <= -1.0) || (centerX >= 1.0)){
    velX *= -1; 
  }  
  if((centerY >= 1.0)){ 
    velY *= -1; 
  }
  
  //collide with floor => reset ball and decrement life
  if(centerY <= -1.0){
    //totally reset position and velocity
    resetBall();
    //decrement life count
    lives -= 1;
    return;
  }

  //collide with paddle
  if((centerX >= p.getLeft()) && (centerX <= p.getRight()) && ((centerY - halfside) <= p.getTop())){
    velY *= -1;
  }
  
  //collide with bricks
  //hardcoded number of bricks
  int J = (1.0 + centerX)/m->getLength();
  int I = -1*(-1.0 + centerY)/m->getWidth();

  //if there is a block there
  if(m->updateBlock(I, J, 0) == 1){
    velY *= -1;   
  }

  //move ball
  centerX += velX;
  centerY += velY;
}

void ball :: resetBall(){
  //reset from init values
  centerX = initCx;
  centerY = initCy;

  velX = initVelX;
  velY = initVelY;
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
      if(slots[i][j] == 0);
      else{ 
	//basically drawing a brick
	//more information may be added later on in this grid
	glBegin(GL_POLYGON);
	glVertex2f(cornerX + j*length, cornerY - i*width);
	glVertex2f(cornerX + (j+1)*length, cornerY - i*width);
	glVertex2f(cornerX + (j+1)*length, cornerY - (i+1)*width);
	glVertex2f(cornerX + j*length, cornerY - (i+1)*width);
	glEnd();
      }

    }
  return;
}

float map :: getLength(){
  return length;
}

float map :: getWidth(){
  return width;
}

//returns 0 if there never was any block there in the first place
//returns 1 iff a block has been collided with
int map :: updateBlock(int i,int j, int status){
  if((i >= 0) && (j >= 0) && (i < 10) && (j < 10)){
    if(slots[i][j] == 0) return 0;
    slots[i][j] = status;  
  }
  else{
    return 0;
  }
  return 1;
}
