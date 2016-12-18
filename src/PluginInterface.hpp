#ifndef __PLUGIN_INTERFACE__
#define __PLUGIN_INTERFACE__

#include "Sprite.hpp"
#include "Cell.hpp"
#include "Grid.hpp"



class Plugin{
    public:
        virtual void nextGeneration(Grid& gr)=0;
        virtual Cell* getControllerCellType(int x, int y, int n, int m)=0;
        virtual void applyProba(Grid& oldGrid, Grid& newGrid)=0;
        virtual Sprite* getControllerSprite()=0;
//virtual void computeNeighbors(Grid* gr)=0;
};

//typedef GridController<Cell,Sprite> Plugin;

//#define declare_plugin(x) extern "C" Plugin* factoryPlugin(){ return new x; }

#endif // __PLUGIN_INTERFACE__
