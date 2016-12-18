#ifndef __PSERVICE__
#define __PSERVICE__
#include <string>

class PluginService{
public:
  static std::string pathPlugin;
  static void setPath(std::string path);
  static std::string getPath();
};

#endif //__PSERVICE__
