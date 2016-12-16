#ifndef __CELLB__
#define __CELLB__

#include "../Cell.hpp"
#include "../Grid.hpp"
#include <vector>

class CellB : public Cell{
    private:
        std::vector<CellB*> neighbors;
    public:
    	/** 
		  \fn CellB
		  \brief Constructor
		  \param[in] x : int, coordinate x
		  \param[in] y : int, coordinate y
		  \param[in] sizeNeighbors : int, number of neighbors
		  \param[in] nrPions : int, ?
		*/
        CellB(int x, int y, int sizeNeighbors, int nrPions);

       	/** 
		  \fn ~CellB
		  \brief Destructor
		*/
        virtual ~CellB();

        /** 
		  \fn getNeighborsAlive
		  \brief Get the number of neighbors alive
		  \return res : int, number of neighbors alive
		*/
        int getNeighborsAlive();

        /** 
		  \fn findNeighbors
		  \brief Find the neighbors and push them in the neighbor vector
		  \param[in] n : int, number of rows of the grid
		  \param[in] m : int, number of columns of the grid
		  \param[in] gr : Grid pointer, pointer of the grid
		*/
        void findNeighbors(int n, int m,Grid* gr);

        /** 
		  \fn getNeighbors
		  \brief Get all the neighbors
		  \return this.neighbors : vector of the neighbors
		*/
        std::vector< CellB* > getNeighbors();
};




#endif //__CELLB__