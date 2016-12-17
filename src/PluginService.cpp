#include "PluginService.hpp"
#include <iostream>

Plugin* PluginService::p = nullptr;

void PluginService::addPlugin(Plugin* pp){
  PluginService::p = pp;
}

Plugin* PluginService::getPlugin(){
  return p;
}
