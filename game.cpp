#define MAXX 30
#include "game.h"
#include<string.h>
using namespace std;


void Game :: Menu()
{
	
}


//Taking inputs for game regarding human and computer players
void Game :: input()
{
	char nme[MAX],nme1[MAX];
	int difficult;
	H= new Human;	
	C= new Computer;
}


//players take turns to attack on each others' fleet
int Game :: play()
{
	flag_game_end=0;
	turn=CoinToss();
	while(!flag_game_end)
	{
		if(turn==1) //1 for computer and 0 for human
		{
			C->attack(H,100);
		}
		else
		{
			H->attack(C);
		}
		turn=getTurn();
		system("clear");
		cout<<"\n";
		H->displayboard();
		C->displayboard();
		cout<<"\n\n\n";
		if(H->gethits()==10 || C->gethits()==10)
		{
			flag_game_end=true;
		}
	}
	return 0;
}


//shows the winner of the game and stores the high scores
int Game :: result()
{
	int points=0;
	cout<<"\n\t\t\t\t";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	if(turn==1)
	{
		cout<<"\n\t\t\t\t";
		cout<<H->getname()<<" Wins!"<<endl;
		points=500-((H->gethits() + H->getmiss())*5);
		S.add_new_score(H->getname(),points,C->getdifficulty());
		S.show_scores(C->getdifficulty());
	}
	else
	{
		cout<<"\n\t\t\t\t";
		cout<<C->getname()<<" Wins!"<<endl;
		
	}
	cout<<"\n\t\t\t\t";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	return 0;
}

//to decide who takes the first move
int Game :: CoinToss()
{
	int toss;
	toss=rand()%2;
	return toss;
}

//to return the turn
int Game :: getTurn()
{
	turn = (turn+1)%2;
	return turn;
}

//showing high scores
void Game :: showhighscores(int diff)
{
	S.show_scores(diff);
}
