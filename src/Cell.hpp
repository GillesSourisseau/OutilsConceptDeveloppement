#ifndef __CELL__
#define __CELL__

#include <vector>
#include <utility>

/*!
 *\class Cell
 *\name Cell
 *\brief this is an abstract class that describes the property and behaviour of a cell in the grid
 */
class Cell{
private:
  int coordx;
  int coordy;
  int pion;
  int nrPions;
  int sizeNeighbors;
  std::vector< std::pair<int,int> > neighbors;
  
public:
  /*!
   *\brief Constructor of class Cell
   *\param[in] x,y - coordinates of the cell in the grid
   *\param[in] sizeNeighbors - the number of neighbors cells 
   *\param[in] nrPions - the number of different possible states
   */
  Cell(int x, int y, int sizeNeighbors, int nrPions);
  /*!
   *\brief Destructor of Cell instances
   */
  virtual ~Cell();
  /*!
   *\name getPion
   *\brief return the current state of the cell
   *\return an integer representing the state of the cell
   */
  int getPion();

  /*!
   *\name setPion
   *\brief sets the state of a cell
   *\param[in] pion - state of the cell
   */
  void setPion(int pion);

  /*!
   *\name getSizeNeighbors
   *\brief returns the number of neighbors a type of cell can have
   *\return number of neighbors of the cell
   */
  int getSizeNeighbors();

  /*!
   *\name setSizeNeighbors
   *\brief sets the max number of neighbors one cell type can have
   *\param[in] sz - number of neighbors
   */
  void setSizeNeighbors(int sz); 

  /*!
   *\name getCoordX
   *\return the x coordinate of the cell
   */
  int getCoordX();

  /*!
   *\name getCoordY
   *\return the y coordinate of the cell
   */
  int getCoordY();

  /*!
   *\name getNrPions
   *\return the number of pions one cell type can have
   */
  int getNrPions();

  /*!
   *\name setNrPions
   *\brief sets the number of pions one cell type can have
   *\param[in] nrPions - number of pions
   */
  void setNrPions(int nrPions);

  /*!
   *\name getNeighbors
   *\brief returns the list of neighbour cells as coordinates, not actuall cells
   *\return a poiter to a vector of coordinates
   */
  std::vector< std::pair<int,int> >* getNeighbors();

  /*!
   *\name validateCoords
   *\brief verify that the coords generated for neighbors are valid and if not modify them to be valid
   *\param[in] x,y - pointers to the x and y coordinate
   *\param[in] n,m - size of the grid: rows and columns
   */
  void validateCoords(int* x, int* y, int n, int m);

  /*!
   *\name findNeighbors
   *\brief pure abstract method that constructs a list of coords representing the neighbor cells
   *each pair of coordinates is verified by validateCoords method
   *\param[in] n,m - size of the grid: rows and columns
   */
  virtual void findNeighbors(int n, int m)=0;
  
};



#endif // __CELL__
