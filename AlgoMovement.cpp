#include "AlgoMovement.h"
#include <math.h>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
AlgoMovement::AlgoMovement(){
}
AlgoMovement::~AlgoMovement(){

}
string AlgoMovement::holdname(){
  string filename;
  while(true){
    cout<<"What is the name of the file you would like to read from? ";
    cin>>filename;
    ifstream readfile (filename);
    if(readfile.is_open()){
      return filename;
    }
    else{
      cout<<"Invalid file, try again"<<endl;
    }
  }
}
void AlgoMovement::movement(int method){
  //method will act as a flag to see which algorithm to use for navigation
  Readfile readfile;
  if(method==1){
    realfile=holdname();
  }
  readfile.findFile(realfile);
  readfile.findInitialGoal();
  char Eshow[readfile.size][readfile.size];
  for(int i=0; i<readfile.size;i++){
    for(int j=0; j<readfile.size;j++){
      Eshow[i][j]=readfile.arr[i][j];
    }
  }
  Eshow[readfile.initialY][readfile.initialX]='O';
  double initaldistance=0;
  if(method==1){
    initaldistance=getEuclideanDistance((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  else if(method==2){
    initaldistance=getManhattanDistance((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  int x=readfile.initialX;
  int y= readfile.initialY;
  double distance=0;
  double cost [4];
  int counter=0;
  int smallest=100000000;
  while (true){
  if((x-1)>-1&&readfile.arr[y][x-1]!='+'&&Eshow[y][x-1]!='O'){
    if(method==1){
      distance=getEuclideanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method==2){
      distance=getManhattanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
  }
  else{
    if(Eshow[y][x-1]=='O'&&readfile.arr[y][x+1]=='+'&&readfile.arr[y+1][x]=='+'&&readfile.arr[y-1][x]=='+'){
      if(method == 1){
        distance=getEuclideanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
      }
      else if (method == 2){
        distance=getManhattanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
      }
      readfile.arr[y][x]='a';
    }
    else{
      distance=10000;
    }
  }
  cost[0]=distance;
  if((x+1)<readfile.size&&readfile.arr[y][x+1]!='+'&&Eshow[y][x+1]!='O'){
    if (method ==1){
      distance=getEuclideanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method ==2){
      distance=getManhattanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
  }
  else{
    if(Eshow[y][x+1]=='O'&&readfile.arr[y][x-1]=='+'&&readfile.arr[y+1][x]=='+'&&readfile.arr[y-1][x]=='+'){
      if (method ==1){
        distance=getEuclideanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
      }
      else if (method ==2){
        distance=getManhattanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
      }
      readfile.arr[y][x]='a';
    }
    else{
      distance=10000;
    }
  }
  cost[1]=distance;
  if((y-1)>-1&&readfile.arr[y-1][x]!='+'&&Eshow[y-1][x]!='O'){
    if (method == 1 ){
      distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
    else if(method ==2){
      distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
  }
  else{
    if(Eshow[y-1][x]=='O'&&readfile.arr[y][x+1]=='+'&&readfile.arr[y+1][x]=='+'&&readfile.arr[y][x-1]=='+'){
      if (method == 1 ){
        distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
      }
      else if(method ==2){
        distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
      }
      readfile.arr[y][x]='a';
    }
    else{
      distance=10000;
    }
  }
  cost[2]=distance;
  if((y+1)<readfile.size&&readfile.arr[y+1][x]!='+'&&Eshow[y+1][x]!='O'){
    if(method==1){
      distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
    else if(method==2){
      distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
  }
  else{
    if(Eshow[y+1][x]=='O'&&readfile.arr[y][x+1]=='+'&&readfile.arr[y-1][x]=='+'&&readfile.arr[y][x-1]=='+'){
      if(method==1){
        distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
      }
      else if(method==2){
        distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
      }
      readfile.arr[y][x]='a';
    }
    else{
      distance=10000;
    }
  }
  cost[3]=distance;
  smallest=0;
  //finds which path has the smallest euclidean distance and goes to that box on the grid, it is repeated until the goal is reached
  if(cost[1]<cost[smallest]){
    smallest=1;
  }
  if(cost[2]<cost[smallest]){
    smallest=2;
  }
  if(cost[3]<cost[smallest]){
    smallest=3;
  }
  if(smallest==0){
    x--;
    Eshow[y][x]='O';
    cout<<"left"<<endl;
  }
  else if(smallest==1){
    x++;
    Eshow[y][x]='O';
    cout<<"right"<<endl;
  }
  else if(smallest==2){
    y--;
    Eshow[y][x]='O';
    cout<<"up"<<endl;
  }
  else if(smallest==3){
    y++;
    Eshow[y][x]='O';
    cout<<"down"<<endl;
  }
  if(getEuclideanDistance((double)x,(double)readfile.goalX,(double)y,(double)readfile.goalY)==0){
    cout<<"reached"<<endl;
    break;
  }
  counter++;
}
if(method==1){
  cout<<"Euclidean Path"<<endl;
}
else if(method==2){
  cout<<"Manhattan Path"<<endl;
}
Eshow[readfile.goalY][readfile.goalX]='g';
Eshow[readfile.initialY][readfile.initialX]='i';
for(int i=0; i<readfile.size;i++){
  for(int j=0; j<readfile.size; j++){
    if(readfile.arr[i][j]=='a'){
      readfile.arr[i][j]='.';
      Eshow[i][j]='.';
    }
    cout<<Eshow[i][j]<<' ';
  }
  cout<<endl;
}
}


//Algorithms
double AlgoMovement::getEuclideanDistance(double initialX, double goalX, double initialY, double goalY){
  return (sqrt(((initialX-goalX)*(initialX-goalX))+((initialY-goalY)*(initialY-goalY))));
}
double AlgoMovement::getManhattanDistance(double initialX, double goalX, double initialY, double goalY){
  return (abs(goalX-initialX)+abs(goalY-initialY));
}
