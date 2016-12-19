#include "PluginWar.hpp"
#include "CellW.hpp"
#include "SpriteW.hpp"
#include <iostream>
#include <map>

using namespace std;

extern "C" {
  extern Plugin* registerFactory(){return new PluginWar();}
}

PluginWar::PluginWar(){
  cout<<"inside PluginWar method"<<endl;
}

PluginWar::~PluginWar(){

}

void PluginWar::nextGeneration(Grid& gr)
{

  cout<<"inside plugin method nextgeneration() OF PLUGINWAR that outputs the next gen of the grid"<<endl;
  vector<int> temp;
  bool fought = false;
  bool redMove = false;
  bool blueMove = false;
  int cpt = 0;
  
  //init the temp vector with 0 state
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++)
    {
      temp.push_back(0);
    }
  
  for(int ind=0;ind < gr.sizeRows() * gr.sizeColumns();ind++)
    {
      
      map<pair<int,int>,int> neighborsState = gr.getCellNeighborsState((gr.getTab())[ind]);
      int cellsRed = 0;
      int cellsBlue = 0;
      
      for(map<pair<int,int>,int>::iterator it=neighborsState.begin(); it!=neighborsState.end();++it)
	{
	  
	  if(it->second == 2)
	    {
	      cellsBlue++;
	    }
	  if(it->second == 3)
	    {
	      cellsRed++;
	    }
	  
	  if (cpt == 3)
	    {
	      if (it->second == 2)
		{
		  blueMove = true;
		}
	    }
	  
	  if (cpt == 4)
	    {
	      if (it->second == 3)
		{
		  redMove = true;
		}
	    }
	  
	  cpt++;
	}
      
      int cellState = (gr.getTab())[ind]->getPion();
      if(cellState == 2)
	{
	  if (cellsRed == 0)
	    {
	      fought = false;
	    }
	  else
	    {
	      fought = true;
	      
	      if(cellsRed >= cellsBlue+1)
		{
		  temp[ind] = 0;
		}
	      if(cellsRed < cellsBlue+1)
		{
		  temp[ind] = 2;
		}
	    }
	  
	}
      else if (cellState == 3)
	{
	  if (cellsBlue == 0)
	    {
	      fought = false;
	    }
	  else
	    {
	      fought = 1;
	      
	      if(cellsBlue >= cellsRed+1)
		{
		  temp[ind] = 0;
		}
	      if(cellsBlue < cellsRed+1)
		{
		  temp[ind] = 3;
		}
	    }
	  
	}
      else if (cellState == 0)
	{
	  if (blueMove && redMove)
	    {
	      temp[ind] = 0;
	    }
	  if (!fought && blueMove)
	    {
	      temp[ind] = 2;
	    }
	  
	  if (!fought && redMove)
	    {
	      temp[ind] = 3;
	    }
	  
	  
	}
      
    }
  
  for(int ind=0; ind< gr.sizeRows() * gr.sizeColumns();ind++)
    {
      (gr.getTab())[ind]->setPion(temp[ind]);
    }
}


Cell* PluginWar::getControllerCellType(int x, int y, int n, int m){
  cout<<"inside plugin method returning a derived class Cell"<<endl;
  CellW* cw = new CellW(x,y);
  cw->findNeighbors(n,m);
  return cw;
}


void PluginWar::applyProba(Grid& oldGrid, Grid& newGrid){
  cout<<"inside applyProba in the plugin"<<endl;
}


Sprite* PluginWar::getControllerSprite(){
  map<int,string> m;
  m.insert(std::make_pair(0,"white"));
  m.insert(std::make_pair(1,"red"));
  m.insert(std::make_pair(2,"blue"));
  return new SpriteW(m);
}
