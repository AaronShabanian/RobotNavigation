#include "Readfile.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
Readfile::Readfile(){

}
Readfile::~Readfile(){

}
void Readfile::findFile(string filename){
  int counter=0;
  int pacer=0;
  string line;
  //opening file that was already pre checked to exist in the AlgoMovement class.
  // Also copies file over to a new array.
  ifstream readfile (filename);
  if(readfile.is_open()){
   while(getline(readfile, line)){
     if(counter==0){
       stringstream reader(line);
       reader >> size;
      arr = new char*[size];
      for(int i=0; i<size; i++){
        arr[i] = new char[size];
      }
     }
     else{
     for(int i=0; i<size; i++){
          arr[pacer][i]=line[i];
        }
      }
      counter++;
      pacer=counter-1;
    }
  }
}
//getting goal and inital coordinates
void Readfile::findInitialGoal(){
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(arr[j][i]=='g'){
        goalX=i;
        goalY=j;
      }
      else if (arr[j][i]=='i') {
        initialX=i;
        initialY=j;
      }
    }
  }
}
