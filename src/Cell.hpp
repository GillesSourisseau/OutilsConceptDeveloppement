#ifndef __CELL__
#define __CELL__

#include <vector>
#include <utility>

class Cell{
    private:
        int coordx;
        int coordy;
        int pion;
        int nrPions;
        int sizeNeighbors;
        std::vector< std::pair<int,int> > neighbors;
        
    public:
        
        Cell(int x, int y, int sizeNeighbors, int nrPions);
        virtual ~Cell();
        int getPion();
        void setPion(int pion);
        int getSizeNeighbors();
        void setSizeNeighbors(int sz); 
        
        int getCoordX();
        int getCoordY();
        int getNrPions();
        void setNrPions(int nrPions);
        std::vector< std::pair<int,int> >* getNeighbors();
        void validateCoords(int* x, int* y, int n, int m);//verify that the coords generated for neighbors are valid and if not modify them to be valid
        virtual void findNeighbors(int n, int m)=0;//constructs the list of neighbors that is a list of coords

};



#endif // __CELL__
