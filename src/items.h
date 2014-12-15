//class defining the user controlled paddle

const int WIDTH = 1200;
const int HEIGHT = 700;

class paddle{
  float left, top, right, bottom;
  float length;

  //imparting x momentum to ball
  float delta;

  public:
  paddle(float left,float top,float right,float bottom);  

  void drawPaddle();
  void movePaddle(int, int);

  void resetPaddle();

  float getLeft();
  float getRight();
  float getTop();
  float getDelta();
};

class map{
  int slots[10][10];  //right now boolean to show presence/absence of brick
  float length, width;

  public:
  map(int slots[10][10], float length, float width);
  map();  

  void createMap(int slots[10][10], float length, float width);
  void drawMap();
  float getLength();
  float getWidth();
  //update condition of block
  int updateBlock(int i,int j, int status);
};

class ball{
  float centerX, centerY, halfside;
  float velX, velY;

  //initial values needed to revive ball
  float initCx, initCy, initVelX, initVelY;

  public:
  ball(float centerX, float centerY, float halfside);

  void drawBall();

  //the most important function
  //all physics occurs here
  void moveBall(paddle p,map* m, int& lives);

  void resetBall();
  void launchBall();
};
