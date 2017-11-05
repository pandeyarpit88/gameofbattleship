#include<iostream>
#include"ship.h"

using namespace std;

//Default Constructor for Ship
Ship :: Ship()
{
	int size = 0;
	int alignment = 0;
	int posX = 0;
	int posY = 0;
	bool visible = 0;
}
 
 //Ship Parameterized Constructor
Ship :: Ship(int sze,int row,int col,bool alignmnt)
{
	size=sze;
	alignment=alignmnt;
	posX=row;
	posY=col;
	visible=false;
}

//Overloading Assignment Operator
void Ship :: operator=(const Ship *s1)
{
	size=s1->size;
	alignment=s1->alignment;
	posX=s1->posX;
	posY=s1->posY;
	visible=false;
}

//Set Visibility of a Ship to True
void Ship :: SetVisible()
{
	visible = true;
}

//Gets alignment of a ship
bool Ship :: getAlignment()
{
	return alignment;
}

//Get x co-ordinate value for the ship
int Ship :: getPosX()
{
	return posX;
}

//Get x co-ordinate value for the ship	
int Ship :: getPosY()
{
	return posY;
}

//Get visibility for the ship
bool Ship :: getVisibility()
{
	return visible;
}

