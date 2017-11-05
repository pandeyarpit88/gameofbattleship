#ifndef GAME_H
#define GAME_H
#include "computer.h"
#include "human.h"
#include "player.h"
#include<iostream>
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "scores.h"

//Game Class
class Game
{
	private:
		Human *H;					//Player 1
		Computer *C;					//Player 2
		int flag_game_end;				//Set to true When the game ends
		int turn; 					//0 means player's turn and 1 means computer's turn
		scores S;					//To show and store high scores
	public:
		void Menu();					//Main Menu
		void input();					//Taking inputs for game regarding human and computer players
		int play();					//players take turns to attack on each others' fleet
		int result();					//shows the winner of the game and stores the high scores
		int CoinToss();					//to decide who attacks first
		int getTurn();					//to return the turn
		void showhighscores(int diff);			//to show high scores according to a difficulty level
};
#endif
