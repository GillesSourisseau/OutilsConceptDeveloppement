#ifndef __CELLW__
#define __CELLW__

#include "Cell.hpp"

class CellW : public Cell{
    public:
        CellW(int x, int y);
        virtual ~CellW();
  void findNeighbors(int n,int m);
};

#endif //__CELLW__
