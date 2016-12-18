#ifndef __PBASE__
#define __PBASE__

#include "PluginInterface.hpp"
#include "Cell.hpp"
#include "Sprite.hpp"


class PluginBase : public Plugin{
public :
  PluginBase();
  ~PluginBase();
  void nextGeneration(Grid& gr);
  Cell* getControllerCellType(int x,int y, int n, int m);
  void applyProba(Grid& oldGrid, Grid& newGrid);
  Sprite* getControllerSprite();
};

//typedef PluginBase<CellB,SpriteB> PB;


#endif //__PBASE__
