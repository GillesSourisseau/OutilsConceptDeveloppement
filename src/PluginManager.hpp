#ifndef __PLUGIN_MANAGER__
#define __PLUGIN_MANAGER__

#include <map>
#include <string>
#include <vector>
#include "PluginInterface.hpp"

/*!
 *\class PluginManager
 *\brief this class defines methods to load, access and manage the plugins
 */
class PluginManager{
private:
  std::string pathPlugin;
  /*!
   *\name loadPlugin
   *\brief method that open the shared library, and use the handler to instantiate the plugin class, then execute one of the methods of the Plugin interface
   *\param[in] method - integer that defines which Plugin's interface method to execute: 1-getControllerCellType; 2-nextgeneration; 3-getControllerSprite; 4-applyProba
   *\param[in] params - an array of void* elements to be passed as parameters to the wrapped methods
   *\pre 0 < method < 5
   *\return some element of any type returned by one of the wrapped methods or nullptr
   */
  void* loadPlugin(int method,void* params[]);
public:
  
  /*!
   *\brief Constructor of PluginManager class
   *\post sets the instance with the path to the PluginBase.so plugin (default)
   */
  PluginManager();
  
  /*!
   *\brief Destructor of PluginManager class
   */
  ~PluginManager();

  /*!
   *\name setPluginpath
   *\brief this method changes the path of the plugin that should be loaded 
   *\param[in] path - the path to the new plugin
   *\pre path should be a valid path
   *\return nothing
   */
  void setPluginPath(std::string path);

  /*!
   *\name findPlugins
   *\brief this method gets all the plugins' names (complete path) that are found in the specified directory
   *\param[in] directory - directory where the method searches for the plugins
   *\pre directory must be a valid name
   *\return a vector of plugin paths 
   */
  std::vector<std::string> findPlugins(std::string directory);

  /*!
   *\name getCellFromPlugin
   *\brief wrapping method of Plugin's getControllerCellType method, invoke loadPlugin method
   *\param[in] x,y coordonates of the cell we want to get from the plugin
   *\param[in] n,m size of rows and columns of the grid
   *\return a pointer to a Cell 
   */
  Cell* getCellFromPlugin(int x,int y,int n,int m);

  /*!
   *\name getNextGen
   *\brief wrapping method of Plugin's nextGeneration method, invoke loadPlugin method
   *\param[in] gr - pointer to the grid to modify 
   *\post the grid change it's state
   *\return nothing
   */
  void getNextGen(Grid* gr);

  /*!
   *\name getSpriteFromPlugin
   *\brief wrapping method of Plugin's getControllerSprite method, invoke loadPlugin method
   *\return pointer to a Sprite 
   */
  Sprite* getSpriteFromPlugin();

  /*!
   *\name applyProbaOnCells
   *\brief wrapping method of Plugin's applyProba method, invoke loadPlugin method
   *\param[in] og, ng - old and new grid / before and after the use of getNextGen method
   *\post some of the cells change their state, others not
   *\return nothing
   */
  void applyProbaOnCells(Grid* og,Grid* ng);
};


typedef Plugin* reg();



#endif // __PLUGIN_MANAGER__
