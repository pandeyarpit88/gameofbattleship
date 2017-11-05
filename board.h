#ifndef BOARD_H
#define BOARD_H
#ifndef MAXSIZE 
#define MAXSIZE 10
#endif
#include "ship.h"
#include "cell.h"

//Board Class. Contained in Each Player Class whether Human or Computer
class Board
{
	private:
	Cell cell[MAXSIZE+1][MAXSIZE+1]; //Contains a two-d array of cells making a square matrix
	public:
	Board();//initializes each cell
	bool getBoardOccupied(int posx,int posy);//check ship is there or not
	bool getBoardAttacked(int posX,int posY);//for checking attack attack condition
	void setBoardAttacked(int posX,int posY);//setting attacked flag to true
	void setBoardOccupied(int row,int col);//setting occupied flag to true
	void showcells(int row,int col);

};
#endif
