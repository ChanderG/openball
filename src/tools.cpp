//additional misc functions
#include"tools.h"

#include<GL/freeglut.h>
#include<string>

void displayScore(int lives){
  int x = -1;
  int y = -1;

  //glColor3f( r, g, b );
  glRasterPos2f(x, y);

  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, lives + '0');

  std::string msg = " live(s) left";
  for(int i = 0;msg[i] != '\0';i++){
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[i]);
  }
  return;
}
