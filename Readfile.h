
#include <iostream>
using namespace std;
class Readfile{
public:
  Readfile();
  ~Readfile();
  void findFile(string filename);
  char ** arr = NULL;
  int initialX;
  int initialY;
  int goalX;
  int goalY;
  int size=0;
  void findInitialGoal();
};
