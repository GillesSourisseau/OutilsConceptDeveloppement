#include "CellB.hpp"
#include <iostream>
#include <vector>

using namespace std;

CellB::CellB(int x, int y, int sizeNeighbors, int nrPions) : Cell(x,y,sizeNeighbors,nrPions){

}

CellB::~CellB(){

}

int CellB::getNeighborsAlive(){
    int res = 0;
	vector<CellB*> ngb = this->getNeighbors();
	for(int i=0; i<ngb.size();i++){
		if(ngb[i]->getPion()==1){
			res++;
		}
	}
	return res;
}

vector<CellB*> CellB::getNeighbors(){
    return this->neighbors;
}

void CellB::findNeighbors(int n, int m,Grid* gr){
	int dx=-1;
	int dy=-1;
	for(int i=0;i<this->getSizeNeighbors();i++){
		int x = this->getCoordX()+dx;
		int y = this->getCoordY()+dy;
		this->validateCoords(&x,&y,n,m);
		(this->neighbors).push_back((gr->getTab())[x][y]);
		if(i<2){
			dy++;
		}else if(i==2){
			dy=-1;
			dx++;
		}else if(i==3){
			dy=1;
		}else if(i==4){
			dx++;
			dy=-1;
		}else{
			dy++;
		}
	}
}