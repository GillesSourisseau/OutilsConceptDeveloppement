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
        std::vector< std::vector<Cell*> > tab; // ?
    public:

        /** 
          \fn Grid
          \brief Constructor
          \param[in] n : int, lines
          \param[in] m : int, columns
          \param[in] resineaux : int, initial cells on the grid
          \param[in] gc : GridController pointer, ?
        */
        Grid(int n, int m, int resineaux, GridController* gc);

        /** 
          \fn ~Grid
          \brief Destructor
        */
        ~Grid();

        /** 
          \fn ~randomInitialise
          \brief Initialise randomly a cell to the value "pion" as a state.
          \param[in] pion : int, state of the cell
          \pre the state has to be an alive state
        */
        void randomInitialise(int pion);// here pion is the state of the cell (has to be alive)

        /** 
          \fn getRows
          \brief Getter of the number of rows
          \return this.n : int, number of rows
        */
        int getRows();

        /** 
          \fn getColumns
          \brief Getter of the number of columns
          \return this.m : int, number of columns
        */
        int getColumns();

        /** 
          \fn getResineaux
          \brief Getter of the number of resineaux
          \return this.resineaux : int, number of resineaux
        */
        int getResineaux();

        /** 
          \fn getTab
          \brief Getter of the matrix 
          \return this.tab : vector of vector of Cells, matrix of Cell*
        */
        std::vector< std::vector< Cell* > > getTab();

        /** 
          \fn getGC
          \brief Getter of the GridController
          \return this.gc : GridController pointer
        */
        GridController* getGC();
};



#endif //__GRID__