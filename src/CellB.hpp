#ifndef __CELLB__
#define __CELLB__

#include "Cell.hpp"

class CellB : public Cell{
    public:
        CellB(int x, int y);
        virtual ~CellB();
  void findNeighbors(int n,int m);
};




#endif //__CELLB__
