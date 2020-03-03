
#include <iostream>
using namespace std;
class Readfile{
public:
  Readfile();
  ~Readfile();
  /*
  findFile() is used to open the file and extract basic information from it
  */
  void findFile(string filename);
  char ** arr = NULL;
  int initialX;
  int initialY;
  int goalX;
  int goalY;
  int size=0;
  /*
  findInitialGoal() sets initalX, initialY, goalX, and goal y to the initial location and the goal location
  */
  void findInitialGoal();
};
