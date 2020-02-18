#include "Readfile.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
Readfile::Readfile(){

}
Readfile::~Readfile(){

}
void Readfile::findFile(){
  string filename;
  int counter=0;
  int pacer=0;
  int size=0;
  cout<<"Enter the name of the file you would like to read from"<<endl;
  cin>>filename;
  string line;
  ifstream readfile (filename);
  if(readfile.is_open()){
   while(getline(readfile, line)){
     if(counter==0){
       stringstream reader(line);
       reader >> size;
      arr = new char*[size];
      for(int i=0; i<5; i++){
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
