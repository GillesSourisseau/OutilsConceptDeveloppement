#ifndef __GRID__
#define __GRID__

#include "Cell.hpp"
#include "PluginManager.hpp"
#include <vector>

class GridController;
class Grid{
    private:
        GridController* gc;
        int n;//lines
        int m;//columns
        int resineaux;// how many initial cells are on the grid ?
        std::vector< std::vector<Cell*> > tab;
    public:
        Grid(int n, int m, int resineaux, GridController* gc);
        ~Grid();
        void randomInitialise(int pion);// here pion is the state of the cell (has to be alive)
        int getRows();
        int getColumns();
        int getResineaux();
        std::vector< std::vector< Cell* > > getTab();
        GridController* getGC();
};



#endif //__GRID__