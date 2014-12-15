//all menu related technology comes here
#include<string>
using namespace std;

void mainMenu();
void handleMenuSelection();

//display about screen
void showAboutScreen();

//very inefficient
const int mainmenusSize = 5;
const int quitGameNo = 5;
const int loadRandomMapNo = 2;
const int showAboutNo = 4;
const string mainmenus[] = {"New Map", "Load Random Map", "Instructions", "About", "Quit"};

const string aboutString = "Openball by ChanderG \n chandergovind@gmail.com";


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

