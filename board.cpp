
#include"board.h"
using namespace std;


//Board Constructor
Board :: Board()
{
	int i,j;	
	for(i=1;i<=MAXSIZE;i++)
	{
		for(j=1;j<=MAXSIZE;j++)
		{
			Cell c(i,j,0,0);
			cell[i][j]=c;
			
		}
	}
}

//To Check Whether a Particular Cell of the Board is Occupied by a Ship. Returns True or False
bool Board :: getBoardOccupied(int row,int col)
{
	if(cell[row][col].getCellOccupied())
		return true;
	else
		return false;
}

//Returns True if a Particular Cell of a board has been attacked by the Enemy, False Otherwise
bool Board :: getBoardAttacked(int row,int col)
{
		if(cell[row][col].getCellAttacked())
		return true;
	else
		return false;

}

//Sets the Attacked flag of a Cell of the Board to true if it has been attacked by the enemy
void Board :: setBoardAttacked(int row,int col)
{
	cell[row][col].setCellAttacked();
}


//Sets the Occupied flag of a Cell of the Board to true if it has been occupied by a ship
void Board :: setBoardOccupied(int row,int col)
{
	cell[row][col].setCellOccupied();
}


//Used to display the rows and columns of a particular cell
void Board :: showcells(int i,int j)
{
	cell[i][j].Show();
}
