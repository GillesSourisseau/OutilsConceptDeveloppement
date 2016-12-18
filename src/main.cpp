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
  cout<<PluginService::getPath()<<endl;
  PluginManager* pm = new PluginManager();

  vector<string> names = pm->findPlugins("./plugins/");
  for(int i=0;i<names.size();i++){
    cout<<i<<" ) "<<names[i]<<endl;
  }

  //here you should ask the user if he wants to change the default plugin to another one
  
  Cell* cl = pm->getCellFromPlugin(1,2,3,4);
  cout<<cl->getPion();
  
  cout<<"enter the number of rows : ";
  cin>>n;
  cout<<"enter the number of columns : ";
  cin>>m;
  cout<<"enter the number of resineaux : ";
  cin>>resineaux;

  cout<<"before constructing the grid"<<endl;

  Grid platou(n,m,resineaux);
  /*
  for(int i=0;i<platou.sizeRows()*platou.sizeColumns();i++){
    cout<<"before findNeighbors"<<endl;
    cout<<(platou.getTab())[i]->getCoordX()<<" "<<(platou.getTab())[i]->getCoordY()<<" : "<<(platou.getTab())[i]->getPion();// this works
    (platou.getTab())[i]->findNeighbors(platou.sizeRows(),platou.sizeColumns());
    cout<<"after findNeighbors"<<endl;
  }
  */


  cout<<"after constructing the grid"<<endl;

  showGrid(platou);

  cout<<"after show method"<<endl;
  cout<<"number of possible states: "<<(platou.getTab())[1]->getNrPions()<<endl;

  showNeighbors(platou,10);


  return 0;
}
  
  
