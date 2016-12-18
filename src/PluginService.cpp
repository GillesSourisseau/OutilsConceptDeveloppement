#include "PluginService.hpp"
#include <string>
using namespace std;

string PluginService::pathPlugin = "./plugins/PluginBase.so";

void PluginService::setPath(string path){
  PluginService::pathPlugin = path;
}

string PluginService::getPath(){
  return PluginService::pathPlugin;
}
