#ifndef __PLUGIN_MANAGER__
#define __PLUGIN_MANAGER__

#include <map>
#include <string>
#include <vector>
#include "PluginInterface.hpp"


class PluginManager{
    private:
        std::map<std::string, Plugin*> pluginsMap;
        std::vector<std::string> pluginsNames;
        std::vector<std::string> findPlugins(std::string directory);
        void loadPlugin(std::string path,std::string name);
        void registerPlugin(Plugin* p, std::string name);
    public:
        PluginManager();
        ~PluginManager();
        std::vector<std::string> getPluginNames(); 
        Plugin* getPlugin(std::string name);//instantiate from the correct factory a gridcontroller
};

typedef Plugin* reg();



#endif // __PLUGIN_MANAGER__
