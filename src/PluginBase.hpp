#ifndef __PBASE__
#define __PBASE__

#include "PluginInterface.hpp"
#include "CellB.hpp"
#include "SpriteB.hpp"

template<typename T, typename K>
class PluginBase : public GridController<T,K>{
public :
  void nextGeneration(Grid& gr);
  T* getControllerCellType(int x,int y, int n, int m);
  void applyProba(Grid& oldGrid, Grid& newGrid);
  K* getControllerSprite();
};

typedef PluginBase<CellB,SpriteB> PB;


#endif //__PBASE__
