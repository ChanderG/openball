//all menu related technology comes here
#include<string>
using namespace std;

void mainMenu();

//very inefficient
const int mainmenusSize = 3;
const string mainmenus[] = {"New Map", "Randomized Map", "Quit"};


const int maxGroupSize = 10;

//menu grouping - only to maintain selection
class menuGroup{
  int no; //number in group
  int curr;

  public:
  void setMenuGroup(int no);
  int getSelected();
  void moveUp();
  void moveDown();
};

