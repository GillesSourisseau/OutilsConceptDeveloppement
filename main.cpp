#include <iostream>
#include <string>
#include "PluginManager.hpp"

using namespace std;

int main(){
    
    int rows, columns, resineaux;
    string pluginName = "pbase";

    PluginManager* pm = new PluginManager();
    vector<string> pluginsDisponibles = pm->getPluginNames();
    for(int i=0; i < pluginsDisponibles.size(); i++){
        cout<<i<<" ) "<<pluginsDisponibles[i]<<endl;
    }
    

    return 0;
}