#ifndef __PLUGIN_MANAGER__
#define __PLUGIN_MANAGER__

#include "PluginInterface.hpp"
#include <map>
#include <string>
#include <vector>

class PluginManager{
    private:
        std::map<std::string,GridControllerFactory* > gridControllerMap;
        std::vector<std::string> pluginNames;
        std::vector<std::string> findPlugins(std::string directory);
        GridControllerFactory* loadPlugin(std::string path);
        void registerGridController(GridControllerFactory* gf, std::string name);
    public:
        PluginManager();
        ~PluginManager();
        std::vector<std::string> getPluginNames(); 
        GridController* getGridController(std::string name);//instantiate from the correct factory a gridcontroller
};

typedef GridControllerFactory* reg();



#endif // __PLUGIN_MANAGER