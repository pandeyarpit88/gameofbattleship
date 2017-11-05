#include<iostream>
#include "cell.h"
using namespace std;

//cell parameterized constructor
Cell :: Cell(int r,int c,bool o,bool a)
{
	row=r;
	col=c;
	occupied=o;
	attacked=a;
}


//returns row
int Cell :: getRow()
{
	return row;
}


//returns column
int Cell :: getCol()
{
	return col;
}


//returns true if cell is occupied by a ship, false otherwise
bool Cell :: getCellOccupied()
{
	return occupied;
}


//sets the occupied flag of cell to true
void Cell :: setCellOccupied()
{
	occupied = true;	
}


//returns true if cell is attacked by the enemy, false otherwise
bool Cell :: getCellAttacked()
{
	return attacked;
}

//sets attacked flag of a cell to true
void Cell :: setCellAttacked()
{
	attacked = true;	
}


//displays row n col of a cell
void Cell :: Show()
{
	cout<<"\nrow="<<row<<"col="<<col<<endl;
}
