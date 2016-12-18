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

void* PluginManager::loadPlugin(int method, void* params[]){
  cout<<"inside loadPlugin method"<<endl;
  void* handle = dlopen(this->pathPlugin.c_str(),RTLD_NOW);
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
  Plugin* p = nullptr;
  p = (*regFactory)();
  void* res=nullptr;
  if(p!=nullptr){
    if(method==1){//returne Plugin cell
      int* x =(int*) params[0];
      int* y =(int*) params[1];
      int* n =(int*) params[2];
      int* m =(int*) params[3];
      res = p->getControllerCellType(*x,*y,*n,*m);
      cout<<"end test"<<endl;
    }else if (method==2){
      cout<<"now we are going to get the next state of the grid"<<endl;
      Grid& g = (Grid&) params[0];
      p->nextGeneration(g);
      cout<<"method nextGeneration ended"<<endl;
    }else if(method == 3){
      cout<<"getting the sprite class from the plugin"<<endl;
      res = p->getControllerSprite();
      cout<<"sprite has been retrieved"<<endl;
    }else if(method == 4){
      cout<<"applying probabilities on the grid"<<endl;
      Grid& og = (Grid&) params[0];
      Grid& ng = (Grid&) params[1];
      p->applyProba(og,ng);
      cout<<"end applyproba method"<<endl;
    }
  }
  dlclose(handle);
  return res;
}

Cell* PluginManager::getCellFromPlugin(int i,int j,int n, int m){
  void* params[] = {&i, &j, &n, &m};
  Cell* res =(Cell*) loadPlugin(1,params);
  return res;
}

void PluginManager::getNextGen(Grid& gr){
  void* params[] = {&gr};
  loadPlugin(2,params);
}

Sprite* PluginManager::getSpriteFromPlugin(){
  int i = 1;
  void* params[] = {&i};
  Sprite* res = (Sprite*) loadPlugin(3,params);
  return res;
}

void PluginManager::applyProbaOnCells(Grid& og,Grid& ng){
  void* params[] = {&og,&ng};
  loadPlugin(4,params);
}


void PluginManager::setPluginPath(string path){
  this->pathPlugin = path;
}

PluginManager::PluginManager(){
  cout<<"inside pluginManager constructor"<<endl;
  setPluginPath("./plugins/PluginBase.so");//init with default plugin

  cout<<"This is the plugins List"<<endl;
  vector<string> plarr = findPlugins("./plugins/");
  for(int i=0;i<plarr.size();i++){
    string base = plarr[i].substr(plarr[i].find_last_of("/")+1,plarr[i].size()-1);
    string name = base.substr(0,base.find_last_of("."));
    cout<<i<<" ) "<<plarr[i]<<endl;
  }
}

PluginManager::~PluginManager(){

}



