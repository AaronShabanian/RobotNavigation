#include "Readfile.h"
#include <iostream>
using namespace std;
class AlgoMovement{
public:
  AlgoMovement();
  ~AlgoMovement();
  //checks to see if a file exists before transforming it
  string holdname();
  //name of the file
  string realfile;
  //this is to keep track of stepcount for the A* algorithms.
  int stepcount=0;
  /* This is the Successor function that scans all paths and gets distances based on each algorithm
  All distances are stored in a vector with the coordinates of that distane moved stored in another vector
  The stepcounts for each move are also stored in vectors so it knows what move to do next*/
  void movement(int method);
  //These are all the algorithms for Euclidean, Manhattan, A*Euclidean and A*Manhattan
  double getEuclideanDistance(double initialX, double goalX, double initialY, double goalY);
  double AStarManhattan(double initialX, double goalX, double initialY, double goalY);
  double AStarEuclidean(double initialX, double goalX, double initialY, double goalY);
  double getManhattanDistance(double initialX, double goalX, double initialY, double goalY);
};
