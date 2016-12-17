#ifndef __PSERVICE__
#define __PSERVICE__

#include "PluginInterface.hpp"

class PluginService{
public:
  static Plugin* p;
  static void addPlugin(Plugin* pp);
  static Plugin* getPlugin();
};

#endif //__PSERVICE__
