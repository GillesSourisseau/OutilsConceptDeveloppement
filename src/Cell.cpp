#include "Cell.hpp"
#include <vector>
#include <utility>
#include <iostream>
using namespace std;


Cell::Cell(int x, int y, int sizeNeighbors, int nrPions) : coordx(x), coordy(y), sizeNeighbors(sizeNeighbors), nrPions(nrPions), pion(0){
  cout<<"inside cell constructor"<<endl;
}

Cell::~Cell(){

}

int Cell::getPion(){
    return this->pion;
}

void Cell::setPion(int pion){
    this->pion = pion;
}

int Cell::getSizeNeighbors(){
    return this->sizeNeighbors;
}

void Cell::setSizeNeighbors(int sz){
    this->sizeNeighbors = sz;
}
/*
Cell** Cell::getNeighbors(){
    return this->neighbors;
}
*/

int Cell::getCoordX(){
    return this->coordx;
}

int Cell::getCoordY(){
    return this->coordy;
}

int Cell::getNrPions(){
    return this->nrPions;
}

void Cell::setNrPions(int nrPions){
    this->nrPions = nrPions;
}

void Cell::validateCoords(int* x, int* y,int n, int m){
    if(*x<0 && *y<0){
        *x = n-1;
        *y = m-1;
    }else if(*x<0 && (*y>=0 && *y<m)){
        *x = n-1;
    }else if(*x<0 && *y>=m){
        *x = n-1;
        *y = 0;
    }else if((*x>=0 && *x<n) && *y<0){
        *y = m-1;
    }else if((*x>=0 && *x<n) && *y>=m){
        *y = 0;
    }else if(*x>=n && *y<0){
        *x = 0;
        *y = m-1;
    }else if(*x>=n && (*y>=0 && *y<m)){
        *x = 0;
    }else if(*x>=n && *y>=m){
        *x = 0;
        *y = 0;
    }
}

vector<pair<int,int>>* Cell::getNeighbors(){
    return &(this->neighbors);
}


