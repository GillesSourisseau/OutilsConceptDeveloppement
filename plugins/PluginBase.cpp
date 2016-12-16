#include "PluginBase.hpp"
#include "CellB.hpp"
#include <iostream> 

using namespace std;


GridController* PluginBaseFactory::create()
{
        return ( new PB());
};

declare_plugin(PluginBaseFactory);


PB::PB(){

}

PB::~PB(){

}

void PB::nextGeneration(Grid& gr){
    Grid newGrid(gr->getRows(),gr->getColumns(),0,this);
    for(int i=0; i< gr->getRows(); i++){
        for(int j=0;j< gr->getColumns();j++){
            CellB* c = (gr->getTab())[i][j];
            if(c->getPion() == 0){
                if(c->getNeighborsAlive() > 2){
                    (newGrid.getTab())[i][j]->setPion(1);
                }
            }else{
                if(c->getNeighborsAlive() == 2 || c->getNeighborsAlive() == 3){
                    (newGrid.getTab())[i][j]->setPion(1);
                }else if(c->getNeighborsAlive < 2){
                    (newGrid.getTab())[i][j]->setPion(0);
                }
            }
        }
    }
}

CellB* PB::getControllerCellType(int x, int y, int n, int m){
    return new CellB(x,y,8,2);
}

void PB::applyProba(Grid& oldGrid, Grid& newGrid){

}

SpriteB* PB::getControllerSprite(){
    return new Sprite("hehe");
} 

void PB::computeNeighbors(Grid* gr){
    for(int i=0;i<gr->getRows();i++){
        for(int j=0;j<gr->getColumns();j++){
            CellB* c = (CellB*) (gr->getTab())[i][j];
            c->findNeighbors(gr->getRows(), gr->getColumns(), gr);
        }
    }
}

