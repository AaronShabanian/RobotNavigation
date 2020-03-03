#include "AlgoMovement.h"
#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
  AlgoMovement algoMovement;
  algoMovement.stepcount=0;
  //1 is euclidean, 2 is Manhattan,3 is A*Euclidean, 4 is A*Manhattan
  algoMovement.movement(1);
  algoMovement.stepcount=0;
  algoMovement.movement(2);
  algoMovement.stepcount=0;
  algoMovement.movement(3);
  algoMovement.stepcount=0;
  algoMovement.movement(4);
}
