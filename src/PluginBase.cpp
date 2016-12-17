#include "PluginBase.hpp"
#include <iostream>

using namespace std;

extern "C" {
  extern PB* registerFactory(){return new PB();}
}

template<>
void PB::nextGeneration(Grid& gr){
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

template<>
CellB* PB::getControllerCellType(int x, int y, int n, int m){
  return new CellB(x,y);
}

template<>
void PB::applyProba(Grid& oldGrid, Grid& newGrid){

}

template<>
SpriteB* PB::getControllerSprite(){
  return new SpriteB("hehehe");
}
