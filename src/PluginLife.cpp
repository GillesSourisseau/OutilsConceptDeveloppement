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
   vector<int> temp2;
   srand(time(0));
  //init the temp vector with gr states
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
      }else{
	if((it->second == 1 && cellState == 1) || (it->second == 2 && cellState == 2) ) sg++;
	if((it->second == 1 && cellState == 2) || (it->second == 2 && cellState == 2) ) dg++;
      }
      io++;
    }
    if(sg==1 && dg==0){
      temp[ind] = 0;
      continue;
    }else if( sg==0 && dg==1 ){
      int qrand = rand() % temp.size();
      temp[qrand] = (rand() % 2) + 1;
      temp[ind] = cellState;
      continue;
    }else if(sg==0 && dg==0 && cellState!=0){
      int qrand = rand() % freeNeighbors.size();
      temp[freeNeighbors[qrand].second + gr.sizeColumns() * freeNeighbors[qrand].first] = cellState;
      temp[ind]=0;
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
  m.insert(std::make_pair(1,"red"));
  m.insert(std::make_pair(2,"green"));
  return new SpriteLife(m);
}
