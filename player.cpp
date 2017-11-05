#include<iostream>
#include"player.h"
using namespace std;


//Returns player name
char *Player :: getname()
{
	return name;
}


//Checks for a valid boolean input value for alignment of ships
int Player::getValidBool()
{
	int alignm;
	while(1)
	{
		cin>>alignm;
		if(alignm >= 1 && alignm <= 2)
			return alignm;
		else
			cout<<"\n\t\t\t\tWrong Input !!!!"<<"\n\t\t\t\tPlease Input Again : ";
	}
}

//Validates the alignment of ships with respect to the board boundaries
bool Player :: shipAlignmentValidation(int size,int posX,int posY,int alignment)
{
    if(alignment==2)//horizontal alignment
	{
         if((size+posY-1)<=MAXSIZE)
              return true;
         else
         	return false;	
	}
    else//vertical alignment
	{
         if((size+posX-1)<=MAXSIZE)
               return true;
         else
         	return false;
	}
}

//Ships occupy their position on the board one cell at a time
void Player :: updateBoardShip(int posX,int posY,int align,int size)
{
	int i;
		if(align==1) //vertical alignment
		{
			for(i=posX;i<=posX+size-1;i++)
			{
				B.setBoardOccupied(i,posY);
			}
		}
		else //horizontal
		{
			for(i=posY;i<=posY+size-1;i++)
			{
				B.setBoardOccupied(posX,i);
			}
		}

}


//Returns true if player has been hit
bool Player :: getAttacked(int row,int col)
{
	return(B.getBoardAttacked(row,col));
}

//Returns true if a position has been occupied
bool Player :: getOccupied(int row,int col)
{
	return(B.getBoardOccupied(row,col));
}


//Player has been hit
void Player :: setAttacked(int row,int col)
{
	B.setBoardAttacked(row,col);
}
