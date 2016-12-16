#include "Grid.hpp"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid(int n, int m, int resineaux, GridController* gc) : n(n), m(m), resineaux(resineaux), gc(gc){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Cell* c = gc->getControllerCellType(i,j,n,m);//instantiate the cells from the plugin
            (this->tab[i]).push_back(c);
        }
    }
    gc->computeNeighbors(this);
}

Grid::~Grid(){

}

typedef pair<int,int> pairs;

void Grid::randomInitialise(int pion){
    int initsize = (this->resineaux / 100) * (this->n * this->m);
    int i=0;
    srand(time(0));
    
    set<pairs> initSet;
    pairs p; 
    while(i<initsize){
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
        (this->tab[f.first][f.second])->setPion(pion);
    }
}

int Grid::getRows(){
    return n;
}

int Grid::getColumns(){
    return m;
}

int Grid::getResineaux(){
    return this->resineaux;
}

vector< vector<Cell*> > Grid::getTab(){
    return this->tab;
}

GridController* Grid::getGC(){
    return this->gc;
}