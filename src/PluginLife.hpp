#ifndef __PLIFE__
#define __PLIFE__

#include "PluginInterface.hpp"
#include "Cell.hpp"
#include "Sprite.hpp"

/*!
 *\class PluginLife
 *\brief class that extends the Plugin interface and defines the basic behaviour specified in the  
 */
class PluginLife : public Plugin{
public :
  /*!
   *\brief Constructor of PluginLife class
   *\see Plugin
   */
  PluginLife();

  /*!
   *\brief Destructor of PluginLife class
   */
  ~PluginLife();
  
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


#endif //__PLIFE__
