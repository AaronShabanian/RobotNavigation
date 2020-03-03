#include "AlgoMovement.h"
#include <math.h>
#include <bits/stdc++.h>
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
  //checks to see if the file exits and stores it into a string
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
  //finds file and copies it

  readfile.findFile(realfile);
  readfile.findInitialGoal();
  //Eshow is an array that has everywhere the algorithm goes even if it retraces
  char Eshow[readfile.size][readfile.size];
  for(int i=0; i<readfile.size;i++){
    for(int j=0; j<readfile.size;j++){
      Eshow[i][j]=readfile.arr[i][j];
    }
  }
  Eshow[readfile.initialY][readfile.initialX]='O';
  double initaldistance=0;
  //finds the inital distance from the inital location to the goal.
  if(method==1){
    initaldistance=getEuclideanDistance((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  else if(method==2){
    initaldistance=getManhattanDistance((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  else if(method==3){
    initaldistance=AStarEuclidean((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  else if(method==4){
    initaldistance=AStarManhattan((double)readfile.initialX, (double) readfile.goalX, (double)readfile.initialY, (double)readfile.goalY);
  }
  int x=readfile.initialX;
  int y= readfile.initialY;
  double distance=0;
  //coster is a vector of all possible places you could go, including moves from before
  vector<double> coster;
  //xpos and ypos are coordinates of where you are at that point so the cost is attached to the location
  vector<int> Xpos;
  vector<int> Ypos;
  //stepcounts is a vector of stepcount from each move
  vector<int> stepcounts;
  //printer is the array that is finally printed for the user to see
  char printer[readfile.size][readfile.size];
  //cost is used when going back from everywhere the algorithm explored to only printing the final path the algorithm decided
  double cost [4];
  int counter=1;
  int smallest=10000;
  double cheapest=100;
  while (true){
    //storing x and y positions so it knows where to go if algorithm decides to go on another path.
    //stroring x and y vars in vector 4 times since there are 4 directions per location
    cheapest=100;
    Xpos.push_back(x);
    Xpos.push_back(x);
    Xpos.push_back(x);
    Xpos.push_back(x);
    Ypos.push_back(y);
    Ypos.push_back(y);
    Ypos.push_back(y);
    Ypos.push_back(y);
    //storing stepcounts at that location incase the algorithm retraces in the A* Algorithms
    stepcounts.push_back(stepcount);
    stepcounts.push_back(stepcount);
    stepcounts.push_back(stepcount);
    stepcounts.push_back(stepcount);
    //getting distances that woud be for each way you can go
  if((x-1)>-1&&readfile.arr[y][x-1]!='+'&&Eshow[y][x-1]!='O'){

    if(method==1){
      distance=getEuclideanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method==2){
      distance=getManhattanDistance((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if(method==3){
      distance=AStarEuclidean((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if(method==4){
      distance=AStarManhattan((double)x-1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
  }
  //sets distance to a arbitrarily high number if it impossible to go that way
  else{
    distance =10000;
  }


  //cost[0]=distance;
  coster.push_back(distance);
  if((x+1)<readfile.size&&readfile.arr[y][x+1]!='+'&&Eshow[y][x+1]!='O'){
    if (method ==1){
      distance=getEuclideanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method ==2){
      distance=getManhattanDistance((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method ==3){
      distance=AStarEuclidean((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
    else if (method ==4){
      distance=AStarManhattan((double)x+1, (double)readfile.goalX, (double)y, (double)readfile.goalY);
    }
  }
  else{
    distance =10000;
  }

  //cost[1]=distance;
  coster.push_back(distance);
  if((y-1)>-1&&readfile.arr[y-1][x]!='+'&&Eshow[y-1][x]!='O'){
    if (method == 1 ){
      distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
    else if(method ==2){
      distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
    else if(method==3){
      distance=AStarEuclidean((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
    else if(method==4){
      distance=AStarManhattan((double)x, (double)readfile.goalX, (double)y-1, (double)readfile.goalY);
    }
  }
  else{
    distance =10000;
  }

//  cost[2]=distance;
  coster.push_back(distance);
  if((y+1)<readfile.size&&readfile.arr[y+1][x]!='+'&&Eshow[y+1][x]!='O'){

    if(method==1){
      distance=getEuclideanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
    else if(method==2){
      distance=getManhattanDistance((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
    else if(method==3){
      distance=AStarEuclidean((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
    else if(method==4){
      distance=AStarManhattan((double)x, (double)readfile.goalX, (double)y+1, (double)readfile.goalY);
    }
  }
  else{
    distance =10000;
  }
  //cost[3]=distance;
  coster.push_back(distance);
  smallest=0;
  cheapest=1000;
  //finds which path has the smallest distance based on algorithm and goes to that box on the grid, it is repeated until the goal is reached
  for(int i=0; i<(4*counter); i++){
     if(coster[i]<cheapest){
       smallest=i;
       cheapest=coster[i];
     }
  }
  x=Xpos[smallest];
  y=Ypos[smallest];
  stepcount=stepcounts[smallest];
 //use modulus to determine which direction to go in since the vectors are in groups of 4
  if(smallest%4==0){
    x--;
    Eshow[y][x]='O';
    stepcount++;
    coster[smallest]=10000;

  }
  else if(smallest%4==1){
    x++;
    Eshow[y][x]='O';
    stepcount++;
    coster[smallest]=10000;
  }
  else if(smallest%4==2){
    y--;
    Eshow[y][x]='O';
    stepcount++;
    coster[smallest]=10000;
  }
  else if(smallest%4==3){
    y++;
    Eshow[y][x]='O';
    stepcount++;
    coster[smallest]=10000;
  }
  // if(method==3){
  //   cout<<getEuclideanDistance((double)x,(double)readfile.goalX,(double)y,(double)readfile.goalY)<<endl;
  // }
  if(getEuclideanDistance((double)x,(double)readfile.goalX,(double)y,(double)readfile.goalY)==0){
    //used to delete paths that were checked but were not end up taken
    x=readfile.goalX;
    y=readfile.goalY;
    //copies over dots and walls to new array so the user can see it.
    for(int i=0; i< readfile.size; i++){
      for(int j=0; j< readfile.size; j++){
        printer[i][j]='.';
        if(Eshow[i][j]=='+'){
          printer[i][j]='+';
        }
      }
    }
    int less=0;

    // This loop goes backwards through the maze and follows the final path that was decided and removes anything places
    //that were originally explored but were not in the final path
    while (true){
      if(Eshow[y][x-1]=='O'&&(x-1)>-1&&readfile.arr[y][x-1]!='+'){
        if(method==1||method==3){
          distance=getEuclideanDistance((double)x-1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
        }
        else{
          distance=getManhattanDistance((double)x-1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
        }
      }
      else{
        distance=10000;
      }

      cost[0]=distance;
      if(Eshow[y][x+1]=='O'&&(x+1)<readfile.size&&readfile.arr[y][x+1]!='+'){
        if(method==1||method==3){
          distance=getEuclideanDistance((double)x+1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
        }
        else{
          distance=getManhattanDistance((double)x+1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
        }
      }
      else{
        distance=10000;
      }

      cost[1]=distance;
      if(Eshow[y+1][x]=='O'&&(y+1)<readfile.size&&readfile.arr[y+1][x]!='+'){
        if(method==1||method==3){
          distance=getEuclideanDistance((double)x,(double)readfile.initialX,(double)y+1,(double)readfile.initialY);
        }
        else{
          distance=getManhattanDistance((double)x,(double)readfile.initialX,(double)y+1,(double)readfile.initialY);
        }
      }
      else{
        distance=10000;
      }
      cost[2]=distance;
      if(Eshow[y-1][x]=='O'&&(y-1)>-1&&readfile.arr[y-1][x]!='+'){
        if(method==1||method==3){
          distance=getEuclideanDistance((double)x,(double)readfile.initialX,(double)y-1,(double)readfile.initialY);
        }
        else{
          distance=getManhattanDistance((double)x,(double)readfile.initialX,(double)y-1,(double)readfile.initialY);
        }
      }
      else{
        distance=10000;
      }
      cost[3]=distance;
      less=0;
      if(cost[1]==10000&&cost[2]==10000&&cost[3]==10000&&cost[0]==10000){
        if((x-1)>-1&&readfile.arr[y][x-1]!='+'){
          if(method==1||method==3){
            distance=getEuclideanDistance((double)x-1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
          }
          else{
            distance=getManhattanDistance((double)x-1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
          }
        }
        else{
          distance=10000;
        }
        cost[0]=distance;
        if((x+1)<readfile.size&&readfile.arr[y][x+1]!='+'){
          if(method==1||method==3){
            distance=getEuclideanDistance((double)x+1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
          }
          else{
            distance=getManhattanDistance((double)x+1,(double)readfile.initialX,(double)y,(double)readfile.initialY);
          }
        }
        else{
          distance=10000;
        }
        cost[1]=distance;
        if((y+1)<readfile.size&&readfile.arr[y+1][x]!='+'){
          if(method==1||method==3){
            distance=getEuclideanDistance((double)x,(double)readfile.initialX,(double)y+1,(double)readfile.initialY);
          }
          else{
            distance=getManhattanDistance((double)x,(double)readfile.initialX,(double)y+1,(double)readfile.initialY);
          }
        }
        else{
          distance=10000;
        }
        cost[2]=distance;
        if((y-1)>-1&&readfile.arr[y-1][x]!='+'){
          if(method==1||method==3){
            distance=getEuclideanDistance((double)x,(double)readfile.initialX,(double)y-1,(double)readfile.initialY);
          }
          else{
            distance=getManhattanDistance((double)x,(double)readfile.initialX,(double)y-1,(double)readfile.initialY);
          }
        }
        else{
          distance=10000;
        }
        cost[3]=distance;
      }
      if(cost[1]<cost[less]){
        less=1;
      }
      if(cost[2]<cost[less]){
        less=2;
      }
      if(cost[3]<cost[less]){
        less=3;
      }
      if(less==0){
        Eshow[y][x]='.';
        x--;
      }
      else if(less==1){
        Eshow[y][x]='.';
        x++;
      }
      else if(less==2){
        Eshow[y][x]='.';
        y++;
      }
      else if(less==3){
        Eshow[y][x]='.';
        y--;
      }

      printer[y][x]='O';
      //ends when it is back to inital location.

      if(getEuclideanDistance(x,readfile.initialX,y, readfile.initialY)==0){
        break;
      }
    }
   break;
  }
  counter++;
}
//printing out the array with the final path
if(method==1){
  cout<<"Euclidean Path"<<endl;
}
else if(method==2){
  cout<<"Manhattan Path"<<endl;
}
else if(method==3){
  cout<<"A Star Euclidean"<<endl;
}
else if(method==4){
  cout<<"A Star Manhattan"<<endl;
}
printer[readfile.goalY][readfile.goalX]='g';
printer[readfile.initialY][readfile.initialX]='i';
for(int i=0; i<readfile.size;i++){
  for(int j=0; j<readfile.size; j++){
    if(readfile.arr[i][j]=='a'){
      readfile.arr[i][j]='.';
      Eshow[i][j]='.';
      printer[i][j]='.';
    }
      cout<<printer[i][j]<<' ';
  }
  cout<<endl;
}
cout<<"Stepcount: "<<stepcount<<endl;
}


//Algorithms
double AlgoMovement::getEuclideanDistance(double initialX, double goalX, double initialY, double goalY){
  //cout<<"E1"<<endl;
  return (sqrt(((initialX-goalX)*(initialX-goalX))+((initialY-goalY)*(initialY-goalY))));
}
double AlgoMovement::AStarEuclidean(double initialX, double goalX, double initialY, double goalY){

  return (sqrt(((initialX-goalX)*(initialX-goalX))+((initialY-goalY)*(initialY-goalY)))+stepcount);
}
double AlgoMovement::getManhattanDistance(double initialX, double goalX, double initialY, double goalY){
  return (abs(goalX-initialX)+abs(goalY-initialY));
}
double AlgoMovement::AStarManhattan(double initialX, double goalX, double initialY, double goalY){
  return (abs(goalX-initialX)+abs(goalY-initialY)+stepcount);
}
