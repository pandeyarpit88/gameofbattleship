#ifndef PLAYER_H
#define PLAYER_H
#ifndef MAX 
#define MAX 20
#endif
#include "board.h"
class Player
{
	protected:									//Human and Computer Classes Inherit these properties
		Board B;
		char name[MAX];
		int hit;
		int miss;
		Ship *ship;								//Pointer to a Ship
		
	public:
		Player(){}								//Player Constructor
		
		char *getname();							//Returns Player name				
		
		int getValidBool();							//Checks for a valid boolean input value for alignment of ships

		void updateBoardShip(int posX,int posY,int align,int size);		//Ships occupy their position on the board one cell at a time

		bool shipAlignmentValidation(int size,int posX,int posY,int alignment);	//Validates the alignment of ships with respect to the board boundaries

		bool getAttacked(int row,int col);					//Returns true if player has been hit

		bool getOccupied(int row,int col);					//Returns true if a position has been occupied

		void setAttacked(int row,int col);					//Player has been hit

};
#endif
