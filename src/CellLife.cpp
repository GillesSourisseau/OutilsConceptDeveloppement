#include "CellLife.hpp"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

CellLife::CellLife(int x, int y): Cell(x,y,8,2){
  cout<<"inside cellLife constructor"<<endl;
}

CellLife::~CellLife(){
  cout<<"inside cellLife destructor"<<endl;
}

void CellLife::findNeighbors(int n,int m){
  cout<<"inside findNeighbors method"<<endl;
  int dx=-1;
  int dy=-1;
  for(int i=0;i<this->getSizeNeighbors();i++){
    int x = this->getCoordX()+dx;
    int y = this->getCoordY()+dy;
    this->validateCoords(&x,&y,n,m);
    vector< pair<int,int> >* neighbors = this->getNeighbors();
    neighbors->push_back(pair<int,int>(x,y));
    if(i<2){
      dy++;
    }else if(i==2){
      dy=-1;
      dx++;
    }else if(i==3){
      dy=1;
    }else if(i==4){
      dx++;
      dy=-1;
    }else{
      dy++;
    }
  }
}
