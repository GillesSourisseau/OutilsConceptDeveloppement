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
  void* handle = dlopen(this->pathPlugin.c_str(),RTLD_NOW);
  if(!handle){
    cerr<<"handle error "<<dlerror()<<endl;
    exit(EXIT_FAILURE);
  }
  dlerror();
  reg* regFactory = (reg*) dlsym(handle,"registerFactory");
  const char* dlsym_error = dlerror();
  if(dlsym_error){
    cerr<<"Can not load symbol registerFactory: "<<dlsym_error<<endl;
    exit(EXIT_FAILURE);
  }
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
      if(res == nullptr){
	cout<<"cell could not be created"<<endl;;
	exit(1);
      }
    }else if (method==2){
      Grid* g = (Grid*) params[0];
      p->nextGeneration(*g);
    }else if(method == 3){
      res = p->getControllerSprite();
      if(res == nullptr){
	cout<<"sprite could not be created"<<endl;
	exit(1);
      }
    }else if(method == 4){
      Grid* og = (Grid*) params[0];
      Grid* ng = (Grid*) params[1];
      p->applyProba(*og,*ng);
    }
  }
  dlclose(handle);
  return res;
}

Cell* PluginManager::getCellFromPlugin(int i,int j,int n, int m){
  void* params[] = {&i, &j, &n, &m};
  Cell* res =(Cell*) loadPlugin(1,params);
  if(res != nullptr){
    cout<<"verifing "<<res->getPion()<<endl;
  }
  return res;
}

void PluginManager::getNextGen(Grid* gr){
  void* params[] = {gr};
  loadPlugin(2,params);
}

Sprite* PluginManager::getSpriteFromPlugin(){
  int i = 1;
  void* params[] = {&i};
  Sprite* res = (Sprite*) loadPlugin(3,params);
  return res;
}

void PluginManager::applyProbaOnCells(Grid* og,Grid* ng){
  void* params[] = {og,ng};
  loadPlugin(4,params);
}


void PluginManager::setPluginPath(string path){
  this->pathPlugin = path;
}

PluginManager::PluginManager(){
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



