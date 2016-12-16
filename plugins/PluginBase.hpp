#ifndef __PBASE__
#define __PBASE__

#include "../PluginInterface.hpp"
#include "CellB.hpp"


class PluginBaseFactory : public GridControllerFactory{
    public:
        GridController* create();
};

template<typename T,typename K>
class PluginBase : public GridController<T,K>{
    public:
        PluginBase();
        virtual ~PluginBase();
        void nextGeneration(Grid& gr);
        T* getControllerCellType(int x, int y, int n, int m);
        void applyProba(Grid& oldGrid, Grid& newGrid);
        K* getControllerSprite();
        void computeNeighbors(Grid* gr);
};

typedef PluginBase<CellB,SpriteB>  PB;




#endif // __PBASE__