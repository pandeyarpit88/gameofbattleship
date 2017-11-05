#ifndef COMPUTER_H
#define COMPUTER_H
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 10
#define MAX 20
#include"player.h"
#include"ship.h"
#include"human.h"
#include"board.h"
#include <math.h>

class Human;
class Computer : public Player
{
	private:
		int difficulty;
		int currentX,currentY,last_attacked_row,last_attacked_col;
		bool attack_hard,flag;
		int count;
		int attack_dimention;
		bool movetype; 						//0 for normal move,1 for intelligent move
	public:
		Computer();						//Constructor of Computer Class

		bool CheckSafe(int &row,int &col,int &align,int sze);	//checking if a ship placement is safe with respect to other ships and the boundaries of the board


		int attack(Human *,int);				//Attacking human board

		int attackeasy(Human *,int);				//Attack function for easy level
	
		int attackhard(Human *,int);				//Learning position to attack based on previous attack status

		void displayboard();					//displays computer's board where ship positions are not visible to the player

		void inputships(int &align,int &row,int &col);
		int gethits();
		int getMiss();
		int getValidInput();
		int Select_Position_For_Hard_Attack(int &row,int &col);	//Selecting positions for intelligent attack

		int Horizontal_Attack_Position(Human *H);		//Going along attack in horizontal direction

		int Vertical_Attack_Position(Human *H);			//Going along attack in vertical direction

		bool attack_function(Human *H,bool validattack);	//Attacking at specified position in hard level

		int getdifficulty();
		friend class Human;					//Human Class is friends to Computer class and vice versa
};
#endif
