#include <iostream>
#include <vector>
#include <utility>
#include "Grid.hpp"
#include "PluginManager.hpp"
#include "PluginService.hpp"

using namespace std;

void showGrid(Grid gr){
  cout<<"inside showgrid"<<endl;
  for(int i=0; i<gr.sizeRows(); i++){
    for(int j=0; j<gr.sizeColumns();j++){
      cout<<(gr.getTab())[j+gr.sizeRows()*i]->getPion()<<" | ";
    }
    cout<<endl;
  }
}

void showNeighbors(Grid gr, int size){
  cout<<"inside showNeighbors"<<endl;
  for(int i=0; i<size;i++){
    vector< pair<int,int> >* nb = (gr.getTab())[i]->getNeighbors();
    for(int j=0; j<nb->size();j++){
      vector<pair<int,int>> v = *nb;
      cout<<v[j].first<<" "<<v[j].second<<" ; ";
    }
    cout<<endl;
  }
}


int main(){
  int n,m,resineaux;
  PluginManager* p = new PluginManager();
  cout<<"before getPlugin()"<<endl;
  Plugin* plugin = p->getPlugin("libpluginBase.so");
  
  cout<<"enter the number of rows : ";
  cin>>n;
  cout<<"enter the number of columns : ";
  cin>>m;
  cout<<"enter the number of resineaux : ";
  cin>>resineaux;

  cout<<"before constructing the grid"<<endl;

  Grid platou(n,m,resineaux);

  cout<<"after constructing the grid"<<endl;

  showGrid(platou);

  cout<<"after show method"<<endl;

  showNeighbors(platou,10);


  return 0;
}
  
  
