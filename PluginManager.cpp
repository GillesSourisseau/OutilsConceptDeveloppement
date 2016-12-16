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

GridControllerFactory* PluginManager::loadPlugin(string path){
    void* handle = dlopen(path.c_str(),RTLD_LAZY);
    if(!handle){
        cerr<<dlerror()<<endl;
        exit(EXIT_FAILURE);
    }
    dlerror();

    reg* regFactory = (reg*) dlsym(handle,"registerFactory");
    const char* dlsym_error = dlerror();
    if(dlsym_error){
        cerr<<"Can not load symbol registerFactory: "<<dlsym_error<<endl;
        exit(EXIT_FAILURE);
    }
    GridControllerFactory* gcf = (*regFactory)();
    dlclose(handle);
    return gcf;
}

void PluginManager::registerGridController(GridControllerFactory* gf,string name){
    this->gridControllerMap.insert(pair<string,GridControllerFactory* >(name,gf));
}

PluginManager::PluginManager(){
    vector<string> plarr = findPlugins("./plugins/");
    for(int i=0;i<plarr.size();i++){
        string base = plarr[i].substr(plarr[i].find_last_of("/"),plarr[i].size()-1);
        string name = base.substr(0,base.find_last_of("."));
        GridControllerFactory* gcf  = loadPlugin(plarr[i]);
        registerGridController(gcf,name);
        this->pluginNames.push_back(name);
    }
}

PluginManager::~PluginManager(){

}

vector<string> PluginManager::getPluginNames(){
    return this->pluginNames;
}

GridController* PluginManager::getGridController(string name){
    GridControllerFactory* gf = this->gridControllerMap.find(name)->second;
    GridController* gCtrl =  gf->create();
    return gCtrl;
}



