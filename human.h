#ifndef HUMAN_H
#define HUMAN_H
#define MAXSHIPS 4
#include "player.h"
#include "board.h"
#include "computer.h"
#include <string.h>
#include <iostream>
#include "ship.h"
class Computer;
class Human : public Player
{
	public:
	Human();							//constructor for human
	
	int getValidInput();						//keeping input values within the bounds of board
	
	int attack(Computer *); 					//Player human attacks on a particular co=ordinates on computer's fleet
	
	bool CheckSafe(int &row,int &col,int &align,int sze);		//checks safety of position for ships with respect to other ships and bounds of the board 
	
	void inputships(int &align,int &row,int &col,int ship_no);	//inputs ships for human manually
	
	void displayboard();						//Displays the human board. all ships are visible
	
	int gethits();							//Returns Hits
	
	int getmiss();							//Returns Miss
	
	friend class Computer;						//Computer Class Being friends to Human class and Vice Versa
};
#endif
