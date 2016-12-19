#include "PluginLife.hpp"
#include "CellLife.hpp"
#include "SpriteLife.hpp"
#include <iostream>
#include <map>

using namespace std;

extern "C" {
  extern Plugin* registerFactory(){return new PluginLife();}
}

PluginLife::PluginLife(){
  cout<<"inside PluginLife method"<<endl;
}

PluginLife::~PluginLife(){

}

void PluginLife::nextGeneration(Grid& gr){
  cout<<"inside plugin method nextgeneration() that outputs the next gen of the grid"<<endl;
  vector<int> temp;
  //init the temp vector with 0 state
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++){
    temp.push_back(0);
  }
  
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++){
    map<pair<int,int>,int> neighborsState = gr.getCellNeighborsState((gr.getTab())[ind]);
    int cellsAlive = 0;
    for(map<pair<int,int>,int>::iterator it=neighborsState.begin(); it!=neighborsState.end();++it){
      if(it->second == 1){
	cellsAlive++;
      }
    }
    int cellState = (gr.getTab())[ind]->getPion();
    if(cellState == 0){
      if(cellsAlive > 2){
	temp[ind] = 1;
      }
    }else if(cellsAlive == 2 || cellsAlive == 3){
      temp[ind] = 1;;
    }else if(cellsAlive < 2 || cellsAlive > 3){
      temp[ind] = 0;
    }
  }
  for(int ind=0; ind< gr.sizeRows() * gr.sizeColumns();ind++){
    (gr.getTab())[ind]->setPion(temp[ind]);
  }
}


Cell* PluginLife::getControllerCellType(int x, int y, int n, int m){
  cout<<"inside plugin method returning a derived class Cell"<<endl;
  CellLife* cl = new CellLife(x,y);
  cl->findNeighbors(n,m);
  return cl;
}


void PluginLife::applyProba(Grid& oldGrid, Grid& newGrid){
  cout<<"inside applyProba in the plugin"<<endl;
}


Sprite* PluginLife::getControllerSprite(){
  map<int,string> m;
  m.insert(std::make_pair(0,"white"));
  m.insert(std::make_pair(1,"black"));
  return new SpriteLife(m);
}
