//class defining the user controlled paddle
class paddle{
  public:
  float left, top, right, bottom;
  float length;

  paddle(float left,float top,float right,float bottom);  

  void drawPaddle();
  void movePaddle(int, int);
};
  
