#include "Grid.hpp"
#include "PluginService.hpp"
#include "PluginManager.hpp"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid(int n, int m, int resineaux,vector<int> pions) : n(n), m(m), resineaux(resineaux){
  cout<<"inside grid constructor"<<endl;
  PluginManager* p = new PluginManager();
  p->setPluginPath(PluginService::getPath());
  if(p==nullptr){
    cout<<"ERRORR: null pointer to pluginManager"<<endl;
    exit(1);
  }
  int ind = 0;
  for(int i=0;i<n;i++){
    cout<<"one step"<<endl;
    for(int j=0;j<m;j++){
      tab.push_back(p->getCellFromPlugin(i,j,n,m));
      cout<<"case "<<i<<" "<<j<<" created in tab["<<ind<<"]"<<endl;
      ind++;
    }
  }
  cout<<"before randomInitialise; resineaux = "<<this->resineaux<<endl;
  randomInitialise(pions);
}

Grid::~Grid(){

}

typedef pair<int,int> pairs;

void Grid::randomInitialise(vector<int> pions){
  cout<<"inside random initialise"<<endl;
  double initsize = ((double)this->resineaux / 100)*(this->n * this->m);
  cout<<"number of cells to init : "<<initsize<<endl;
  int i=0;
  srand(time(0));

  int castedint = (int) initsize;
  cout<<"CASTEDINT : "<<castedint<<endl;
    
  set<pairs> initSet;
  pairs p; 

  while(i<castedint){
    int x = rand() % n;
    int y = rand() % m;

    p.first = x;
    p.second = y; 
    pair<set<pairs>::iterator,bool> ret = initSet.insert(p);
    if(ret.second == true){
      i++;
    }
  } 

  set<pairs> :: iterator it;

  for(it = initSet.begin(); it != initSet.end(); it++){
    pairs f = *it;
    Cell* c = getCellAtIndex(f.first,f.second);
    int randint = rand() % pions.size();
    cout<<"pion = "<<"randint"<<endl;
    c->setPion(pions[randint]);
  }
}

int Grid::sizeRows(){
    return n;
}

int Grid::sizeColumns(){
    return m;
}

int Grid::getResineaux(){
    return this->resineaux;
}

vector<Cell*> Grid::getTab(){
    return this->tab;
}

Cell* Grid::getCellAtIndex(int i,int j){
  if((i<0 && i>=n) && (j<0 && j>=m)){
    cout<<"INDICES I,J MAL DEFINIES"<<endl;
    exit(1);
  }else if((j+(this->m)*i) >= (this->n * this->m)){
    cout<<"INDICE DANS TAB NON EXISTANT"<<endl;
    exit(1);
  }
  return tab[j + (this->m)*i];
}

map<pair<int,int>,int> Grid::getCellNeighborsState(Cell* c){
  map<pair<int,int>,int> cellStateMap;
  vector< pair<int,int> >* neighborsList = c->getNeighbors();
  for(int i=0;i<neighborsList->size();i++){
    pair<int,int> coords = (*neighborsList)[i];
    Cell* cc = getCellAtIndex(coords.first, coords.second);
    int state = cc->getPion();
    cellStateMap.insert(std::make_pair(coords, state));
  }
  return cellStateMap;
}
