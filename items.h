//class defining the user controlled paddle

const int WIDTH = 1200;
const int HEIGHT = 700;

class paddle{
  float left, top, right, bottom;
  float length;

  public:
  paddle(float left,float top,float right,float bottom);  

  void drawPaddle();
  void movePaddle(int, int);

  float getLeft();
  float getRight();
  float getTop();
};

class map{
  int slots[10][10];  //right now boolean to show presence/absence of brick
  float length, width;

  public:
  map(int slots[10][10], float length, float width);
  map();  

  void createMap(int slots[10][10], float length, float width);
  void drawMap();
};

class ball{
  float centerX, centerY, halfside;
  float velX, velY;

  public:
  ball(float centerX, float centerY, float halfside);

  void drawBall();
  void moveBall(paddle p,map m);
};
