#ifndef __PLUGIN_MANAGER__
#define __PLUGIN_MANAGER__

#include <map>
#include <string>
#include <vector>
#include "PluginInterface.hpp"


class PluginManager{
private:
  std::string pathPlugin;
  void* loadPlugin(int method,void* params[]);
public:
  PluginManager();
  ~PluginManager();
  void setPluginPath(std::string path);
  std::vector<std::string> findPlugins(std::string directory);
  Cell* getCellFromPlugin(int x,int y,int n,int m);
  void getNextGen(Grid* gr);
  Sprite* getSpriteFromPlugin();
  void applyProbaOnCells(Grid& og,Grid& ng);
};


typedef Plugin* reg();



#endif // __PLUGIN_MANAGER__
