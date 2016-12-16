#ifndef __CELLB__
#define __CELLB__

#include "../Cell.hpp"
#include "../Grid.hpp"
#include <vector>

class CellB : public Cell{
    private:
        std::vector<CellB*> neighbors;
    public:
        CellB(int x, int y, int sizeNeighbors, int nrPions);
        virtual ~CellB();
        int getNeighborsAlive();
        void findNeighbors(int n, int m,Grid* gr);
        std::vector< CellB* > getNeighbors();
};




#endif //__CELLB__