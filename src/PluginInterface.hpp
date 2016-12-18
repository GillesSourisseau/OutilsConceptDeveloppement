#ifndef __PLUGIN_INTERFACE__
#define __PLUGIN_INTERFACE__

#include "Sprite.hpp"
#include "Cell.hpp"
#include "Grid.hpp"

/*!
 *\class Plugin 
 *\brief abstract base class that represents the interface every plugin should implement by extending it
 *\todo add virtual destructor to this base class
 */
class Plugin{
public:
  /*!
   *\name nextGeneration
   *\brief method that changes the grid to the following state
   *all cells are looked upon and we decide if one cell change it's state based on some rules created by the derived class
   *\param[in] Grid& gr - a reference to our grid
   *\post the cells are all in their next state
   *\return nothing
   */
  virtual void nextGeneration(Grid& gr)=0;

  /*!
   *\name getControllerCellType
   *\brief this method returns a pointer to a instance of the derived class of Cell implemented by the plugin
   *becouse the app doesn't know the derived Cell class, it returns this instance as a Cell
   *\param[in] x,y - the two coordonates of the cell
   *\param[in] n - the number of rows of the grid
   *\param[in] m - the number of columns of the grid
   *\return a pointer to a Cell instance that is in reality a derived Cell instance
   */
  virtual Cell* getControllerCellType(int x, int y, int n, int m)=0;

  /*!
   *\name applyProba
   *\brief this method calls the plugin to define a probability in each cell, thus allowing or blocking some state changes
   *\param[in] oldGrid - this is the grid before we change it's cell states with nextGeneration(Grid& gr) 
   *\param[in] newGrid - this is the grid after we apply nextGeneration(Grid& gr)
   *\post the cells' state have the chance to change or not, based on the probability defined by the plugin
   *\return nothing
   */
  virtual void applyProba(Grid& oldGrid, Grid& newGrid)=0;

  /*!
   *\name getControllerSprite
   *\brief this method returns a pointer to a Sprite class defined in the plugin by derivation
   *\return the derived sprite from the plugin as a Sprite instance
   */
  virtual Sprite* getControllerSprite()=0;
};

#endif // __PLUGIN_INTERFACE__
