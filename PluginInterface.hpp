#ifndef __PLUGIN_INTERFACE__
#define __PLUGIN_INTERFACE__

#include "Grid.hpp"

#define declare_plugin(x) extern "C" GridControllerFactory* registerFactory(){ return new x;}

template<typename Interface>
class Factory{
    public:
        virtual Interface* create()=0;
};

template <typename T, typename K>
class GridController{
    public:
        //GridController();
        //virtual ~GridController();
        virtual void nextGeneration(Grid& gr)=0;
        virtual T* getControllerCellType(int x, int y, int n, int m)=0;
        virtual void applyProba(Grid& oldGrid, Grid& newGrid)=0;
        virtual K* getControllerSprite()=0;
        virtual void computeNeighbors(Grid* gr)=0;
};

//typedef Factory< GridController > GridControllerFactory;


#endif // __PLUGIN_INTERFACE__