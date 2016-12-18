#include "PluginBase.hpp"
#include "CellB.hpp"
#include "SpriteB.hpp"
#include <iostream>

using namespace std;

extern "C" {
  extern Plugin* registerFactory(){return new PluginBase();}
}

PluginBase::PluginBase(){
  cout<<"inside PluginBase method"<<endl;
}

PluginBase::~PluginBase(){

}

void PluginBase::nextGeneration(Grid& gr){
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


Cell* PluginBase::getControllerCellType(int x, int y, int n, int m){
  cout<<"inside plugin method returning a derived class Cell"<<endl;
  CellB* cb = new CellB(x,y);
  cb->findNeighbors(n,m);
  return cb;
}


void PluginBase::applyProba(Grid& oldGrid, Grid& newGrid){
  cout<<"inside applyProba in the plugin"<<endl;
}


Sprite* PluginBase::getControllerSprite(){
  return new SpriteB("hehehe");
}
