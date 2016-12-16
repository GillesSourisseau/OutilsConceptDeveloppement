#ifndef __CELL__
#define __CELL__

#include "Grid.hpp"

class Cell{
	private:
		int coordx;
		int coordy;
		int pion;
		int nrPions;
		int sizeNeighbors;
		
	public:
		
		/** 
		  \fn Cell
		  \brief Constructor
		  \param[in] x : int, coordinate x
		  \param[in] y : int, coordinate y
		  \param[in] sizeNeighbors : int, number of neighbors
		  \param[in] nrPions : int, ?
		*/
		Cell(int x, int y, int sizeNeighbors, int nrPions);

		/** 
		  \fn ~Cell
		  \brief Destructor
		*/
		~Cell();

		/** 
		  \fn getPion
		  \brief Getter of Pion
		  \return this.pion : int, state of the "pion" on the cell
		*/
		int getPion();

		/** 
		  \fn setPion
		  \brief Setter of Pion
		*/
		void setPion(int pion);

		/** 
		  \fn getSizeNeighbors
		  \brief Getter of sizeNeighbors
		  \return this.sizeNeighbors : int, number of neighbors
		*/
		int getSizeNeighbors();

		/** 
		  \fn setSizeNeighbors
		  \brief Setter of sizeNeighbors
		*/
		void setSizeNeighbors(int sz); 
		
		/** 
		  \fn getCoordX
		  \brief Getter of coordX
		  \return this.coordX : int, coordinate x
		*/
		int getCoordX();

		/** 
		  \fn getCoordY
		  \brief Getter of coordY
		  \return this.coordY : int, coordinate y
		*/
		int getCoordY();

		/** 
		  \fn getNrPions
		  \brief Getter of nrPions
		  \return this.nrPions : int, ?
		*/
		int getNrPions();

		/** 
		  \fn setNrPions
		  \brief Setter of nrPions
		*/
		void setNrPions(int nrPions);

		/** 
		  \fn validateCoords
		  \brief Verify that the coords generated for neighbors are valid and if not modify them to be valid
		  \param[in] x : int pointer, ?
		  \param[in] y : int pointer, ?
		  \param[in] n : int, ?
		  \param[in] m : int, ?
		*/
		void validateCoords(int* x, int* y, int n, int m);

		/** 
		  \fn validateCoords
		  \brief Constructs the list of neighbors
		  \param[in] n : int, ?
		  \param[in] m : int, ?
		  \param[in] gr : Grid pointer, pointer on the Grid of the cell.
		*/
		virtual void findNeighbors(int n, int m,Grid* gr)=0;

};



#endif // __CELL__