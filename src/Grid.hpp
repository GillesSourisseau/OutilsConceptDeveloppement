#ifndef __GRID__
#define __GRID__

#include <vector>
#include <map>
#include "Cell.hpp"

class Grid{
    private:
        int n;//lines
        int m;//columns
        int resineaux;// how many initial cells are on the grid ?
        std::vector<Cell*> tab;
    public:
        Grid(int n, int m, int resineaux);//still uses PM to instanciate cells but it is hidden in the implementation
        ~Grid();
        void randomInitialise(int pion);// here pion is the state of the cell (has to be alive)
        int sizeRows();
        int sizeColumns();
        int getResineaux();
        Cell* getCellAtIndex(int n,int m);
        std::vector<Cell*> getTab();
        std::map<std::pair<int,int>,int> getCellNeighborsState(Cell* c);
};



#endif //__GRID__
