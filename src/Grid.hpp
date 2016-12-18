#ifndef __GRID__
#define __GRID__

#include <vector>
#include <map>
#include "Cell.hpp"

/*!
 *\class Grid
 *\name Grid
 *\brief this is a class that define the structure and behaviour of a grid of cells
 */
class Grid{
private:
  int n;//lines
  int m;//columns
  int resineaux;//percentage of initial alive cells 
  std::vector<Cell*> tab;
public:
  /*!
   *\brief Constructor of class Grid
   *\param[in] n,m - size of the grid: number of rows and columns
   *\param[in] resineaux - percentage of initial alive cells
   *\warning resineaux should be a number between 1 and 100 
   */
  Grid(int n, int m, int resineaux);

  /*!
   *\brief Destructor of Grid instances
   */
  ~Grid();

  /*!
   *\name randomInitialise
   *\brief initialise the grid using the percentage of resineaux as percentage of alive cells in the grid placed at random valid locations
   *\param[in] pion - what state do we want to initialize the grid with
   */
  void randomInitialise(int pion);

  /*!
   *\name sizeRows
   *\return number of rows
   */
  int sizeRows();

  /*!
   *\name sizeColumns
   *\return number of columns
   */
  int sizeColumns();

  /*!
   *\name getResineaux
   *\return percentage of resineaux
   */
  int getResineaux();

  /*!
   *\name getCellAtIndex
   *\param[in] n,m - coordinates
   *\return a pointer to a cell find in the grid at n,m coordinates
   */
  Cell* getCellAtIndex(int n,int m);

  /*!
   *\name getTab
   *\return the data structure that holds the cells
   */
  std::vector<Cell*> getTab();

  /*!
   *\name getCellNeighborsState
   *\return a map containing the coordinates associated to a state value of the neighbors of the cell
   */
  std::map<std::pair<int,int>,int> getCellNeighborsState(Cell* c);
};



#endif //__GRID__
