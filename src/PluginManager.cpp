#include "PluginManager.hpp"
#include <iostream>
#include <utility>
#include <map>
#include <glob.h>
#include <dlfcn.h>

using namespace std;

vector<string> PluginManager::findPlugins(string directory){
  vector<string> pluginArray;
  glob_t glob_result;
  string str = directory + "*.so";
  glob(str.c_str(),0,NULL,&glob_result);
  for(int i=0; i<glob_result.gl_pathc;++i){
    pluginArray.push_back(string(glob_result.gl_pathv[i]));
  }
  globfree(&glob_result);
  return pluginArray;
}

void PluginManager::loadPlugin(string path, string name){
  cout<<"inside loadPlugin method"<<endl;
  void* handle = dlopen(path.c_str(),RTLD_NOW);
  if(!handle){
    cerr<<"handle error "<<dlerror()<<endl;
    exit(EXIT_FAILURE);
  }
  dlerror();
  cout<<"before calling dlsym"<<endl;
  reg* regFactory = (reg*) dlsym(handle,"registerFactory");
  const char* dlsym_error = dlerror();
  if(dlsym_error){
    cerr<<"Can not load symbol registerFactory: "<<dlsym_error<<endl;
    exit(EXIT_FAILURE);
  }
  cout<<"before retrieving the plugin impementation"<<endl;
  Plugin* p = (*regFactory)();
  cout<<"plugin is retrieved; proceed with registering"<<endl;
  registerPlugin(p,name);
  dlclose(handle);
}

void PluginManager::registerPlugin(Plugin* p,string name){
  cout<<"inside registerPlugin method"<<endl;
  this->pluginsMap.insert(pair<string,Plugin*>(name,p));
}

PluginManager::PluginManager(){
  cout<<"inside pluginManager constructor"<<endl;
  vector<string> plarr = findPlugins("./plugins/");
  for(int i=0;i<plarr.size();i++){
    string base = plarr[i].substr(plarr[i].find_last_of("/"),plarr[i].size()-1);
    string name = base.substr(0,base.find_last_of("."));
    cout<<"plugin : "<<plarr[i]<<endl;
    loadPlugin(plarr[i],name);
    this->pluginsNames.push_back(name);
  }
}

PluginManager::~PluginManager(){

}

vector<string> PluginManager::getPluginNames(){
    return this->pluginsNames;
}

Plugin* PluginManager::getPlugin(string name){
    Plugin* p = this->pluginsMap.find(name)->second;
    return p;
}



