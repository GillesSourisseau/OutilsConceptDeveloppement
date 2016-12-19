#ifndef __CELLL__
#define __CELLL__

#include "Cell.hpp"

class CellLife : public Cell{
public:
  CellLife(int x, int y);
  virtual ~CellLife();
  void findNeighbors(int n,int m);
};




#endif //__CELLL__
