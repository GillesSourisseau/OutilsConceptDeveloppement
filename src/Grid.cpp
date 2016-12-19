#include "Grid.hpp"
#include "PluginService.hpp"
#include "PluginManager.hpp"
#include <iostream>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid(int n, int m, int resineaux) : n(n), m(m), resineaux(resineaux){
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
  randomInitialise(1);
}

Grid::~Grid(){

}

typedef pair<int,int> pairs;

void Grid::randomInitialise(int pion){
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
    std::cout << "COUCOU4" << std::endl;
    Cell* c = getCellAtIndex(f.first,f.second);
    std::cout << f.first << std::endl;
    std::cout << f.second << std::endl;
    if(c != nullptr){
    std::cout << "pion" << c->getPion() << std::endl;
    std::cout << "sizeNeighbors" << c->getSizeNeighbors() << std::endl;
    std::cout << "CoordX" << c->getCoordX() << std::endl;
    std::cout << "CoordY" << c->getCoordY() << std::endl;
    std::cout << "NrPions" << c->getNrPions() << std::endl;
       c->setPion(pion);
    }
    std::cout << "COUCOU6" << std::endl;
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
  return tab[j + (this->n)*i];
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
