#include "Readfile.h"
#include <iostream>
using namespace std;
class AlgoMovement{
public:
  AlgoMovement();
  ~AlgoMovement();
  void manhattan();
  string holdname();
  string realfile;
  void movement(int method);
  double getEuclideanDistance(double initialX, double goalX, double initialY, double goalY);
  double getManhattanDistance(double initialX, double goalX, double initialY, double goalY);
};
