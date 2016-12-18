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
  Grid newGrid(gr.sizeRows(), gr.sizeColumns(),0);
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
	(newGrid.getTab())[ind]->setPion(1);
      }
    }else if(cellsAlive == 2 || cellsAlive == 3){
      (newGrid.getTab())[ind]->setPion(1);
    }else if(cellsAlive < 2 || cellsAlive > 3){
      (newGrid.getTab())[ind]->setPion(0);
    }
  }
}


Cell* PluginBase::getControllerCellType(int x, int y, int n, int m){
  cout<<"inside plugin method returning a derived class Cell"<<endl;
  return new CellB(x,y);
}


void PluginBase::applyProba(Grid& oldGrid, Grid& newGrid){
  cout<<"inside applyProba in the plugin"<<endl;
}


Sprite* PluginBase::getControllerSprite(){
  return new SpriteB("hehehe");
}
