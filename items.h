//class defining the user controlled paddle
class paddle{
  float left, top, right, bottom;
  float length;

  public:
  paddle(float left,float top,float right,float bottom);  

  void drawPaddle();
  void movePaddle(int, int);
};

class ball{
  float centerX, centerY, halfside;

  public:
  ball(float centerX, float centerY, float halfside);

  void drawBall();
};
