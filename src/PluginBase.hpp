#ifndef __PBASE__
#define __PBASE__

#include "PluginInterface.hpp"
#include "Cell.hpp"
#include "Sprite.hpp"

/*!
 *\class PluginBase
 *\brief class that extends the Plugin interface and defines the basic behaviour specified in the  
 */
class PluginBase : public Plugin{
public :
  /*!
   *\brief Constructor of PluginBase class
   *\see Plugin
   */
  PluginBase();

  /*!
   *\brief Destructor of PluginBase class
   */
  ~PluginBase();
  
  /*!
   *\name nextGeneration
   *\brief change grid's state and implements the Plugin nextGeneration method
   */
  void nextGeneration(Grid& gr);
  
  /*!
   *\name getControllerCellType
   *\brief implements the Plugin getControllerCellType method
   */
  Cell* getControllerCellType(int x,int y, int n, int m);

  /*!
   *\name applyProba
   *\brief implements the Plugin applyProba method
   */
  void applyProba(Grid& oldGrid, Grid& newGrid);

  /*!
   *\name getControllerSprite
   *\brief implements the Plugin getControllerSprite method
   *\todo to implement
   */
  Sprite* getControllerSprite();
};

//typedef PluginBase<CellB,SpriteB> PB;


#endif //__PBASE__
