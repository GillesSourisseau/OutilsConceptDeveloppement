#include "PluginLife.hpp"
#include "CellLife.hpp"
#include "SpriteLife.hpp"
#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

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
   srand(time(0));
  //init the temp vector with 0 state
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++){
    temp.push_back(0);
  }
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++){
    int sg = 0;
    int dg = 0; 
    int io = 0;
    int cellState = (gr.getTab())[ind]->getPion();
    vector< pair<int,int> > freeNeighbors;
    map<pair<int,int>,int> neighborsState = gr.getCellNeighborsState((gr.getTab())[ind]);
    for(map<pair<int,int>,int>::iterator it=neighborsState.begin(); it!=neighborsState.end();++it){
      if(it->second == 0){
	freeNeighbors.push_back(it->first);
      }
      if(io == 1 || io == 3 || io == 4 || io == 6){
	if((it->second == 1 && cellState == 1) || (it->second == 2 && cellState == 2) ) sg++;
	if((it->second == 1 && cellState == 2) || (it->second == 2 && cellState == 2) ) dg++;
      }
      io++;
    }
    if( sg==1 && dg==0){
      temp[ind] = 0;
      continue;
    }else if( sg==0 && dg==1 ){
      bool found = false;
      while(!found){
	int qrand = rand() % freeNeighbors.size();
	if(temp[freeNeighbors[qrand].second + gr.sizeColumns() * freeNeighbors[qrand].first] == 0){
	  temp[freeNeighbors[qrand].second + gr.sizeColumns() * freeNeighbors[qrand].first] = (rand() % 2) + 1;
	  found = true;
	}
      }
    }else if(sg==0 && dg==0 && cellState!=0){
      bool found = false;
      while(!found){
	int qrand = rand() % freeNeighbors.size();
	if(temp[freeNeighbors[qrand].second + gr.sizeColumns() * freeNeighbors[qrand].first] == 0){
	  temp[freeNeighbors[qrand].second + gr.sizeColumns() * freeNeighbors[qrand].first] = cellState;
	  found = true;
	}
      }
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
  m.insert(std::make_pair(0,"black"));
  m.insert(std::make_pair(1,"red"));
  m.insert(std::make_pair(2,"green"));
  return new SpriteLife(m);
}
