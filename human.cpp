#include "human.h"
#include<stdlib.h>
#include<ctype.h>
using namespace std;

void Intro()
{
	cout<<"\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\t\t\t\t\tB * A * T * T * L * E * S * H * I * P";
	cout<<"\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


//constructor for human player
Human :: Human()
{
	int align;
	bool safe;
	int row,col,placement;
	cout<<"\n\t\t\t\tPlease Enter Your Name: ";
	cin>>name;
	ship = new Ship[4];

	Intro();
	displayboard();
	cout<<"\n\t\t\t\tHow Do You Want To Place Your Ships?\n\t\t\t\t1. Automatic\n\t\t\t\t2. Manual\n\t\t\t\tPlease Enter Your Choice: ";
	cin>>placement;						//placement of ships, can be auto aur manual
	Computer *comp;
	for(int i=1;i<=4;i++)
	{
		system("clear");
		Intro();
		if(placement==2)				//if player wants to input ships manually
		{
			inputships(align,row,col,i);
			safe=CheckSafe(row,col,align,i);
			if(!safe)
			{
				cout<<"\n\t\t\t\t Invalid Input ! \n Please Enter Again! \n";
				i--;
				cout<<"Press Enter to Continue ....";
				getchar();
				getchar();
				continue;
			}
			Ship *S = new Ship(i,row,col,align);
			ship[i] = S;
			updateBoardShip(row,col,align,i);
			displayboard();
			cout<<"\n\t\t\t\tPress Any Key to Continue ....";
			getchar();	
			getchar();
		}
		else						//for automatic placement
		{
			comp->inputships(align,row,col);
			safe=CheckSafe(row,col,align,i);
			if(!safe)
			{
				i--;
				continue;
			}
			Ship *S = new Ship(i,row,col,align);
			ship[i] = S;
			updateBoardShip(row,col,align,i);
			displayboard();	
		}
	}
	cout<<"\n\t\t\t\tPress Any Key to Start The Game ....";
	getchar();	
	getchar();
		
}


//Player human attacks on a particular co=ordinates on computer's fleet
int Human :: attack(Computer *C)
{
	int xpos,ypos;
	bool validAttack=false;
	//system("clear");
	Intro();
	cout<<"\t\t\t\tPlease enter the position where you want to attack : ";

	while(!validAttack)						//checks for valid attack positions
	{
		cout<<"\n\n\t\t\t\tPlease give row number : ";
		xpos = getValidInput();
		cout<<"\t\t\t\tPlease give column position : ";
		ypos = getValidInput();
		if(C->getAttacked(xpos,ypos))
		{
			cout<<"\n\t\t\tPlace already attacked...\n\t\t\tPlease Enter another Position "; 
			continue;
		}
		else
		{
			validAttack = true;
			C->setAttacked(xpos,ypos);
			if(C->getOccupied(xpos,ypos))
				hit++;		
			else
				miss++;
		}
	}	
}


//inputs ships for human manually
void Human :: inputships(int &align,int &row,int &col,int ship_no)
{
	
	cout<<endl<<"\n\t\t\t\tEnter Alignment of Ship "<<ship_no;
	cout<<"\n\t\t\t\t1 for Vertical, 2 for Horizontal : ";
	align = getValidBool();
	cout<<"\n\t\t\t\tEnter X position : ";
	row = getValidInput();
	cout<<"\n\t\t\t\tEnter Y position : ";
	col = getValidInput();
}


//keeping input values within the bounds of board
int Human :: getValidInput()
{
	int pos;
	while(1)
	{
		cin>>pos;
		if(pos>=1 && pos <=10)
			return pos;
		else
			cout<<"\n\t\t\t\tWrong Input !!!!"<<"\n\t\t\t\tPlease Input Again : ";
	}
}


//Displays the human board. all ships are visible
void Human :: displayboard()
{
	cout<<endl;
	cout<<"\n\t\t\t\t  ";
	
	for(int k=1;k<=MAXSIZE;k++)
	{	cout.width(3);
		cout<<k;
	}
	cout<<endl;
	for(int i=1;i<=MAXSIZE;i++)
	{	cout.width(3);
		cout<<" ";
		cout<<"\n\t\t\t\t";
		cout.width(3);
		cout<<i;
		for(int j=1;j<=MAXSIZE;j++)
		{
			if(B.getBoardOccupied(i,j))
			{
				if(B.getBoardAttacked(i,j))
				{
					cout.width(3);
					cout<<"*";
				}
				else
				{
					cout.width(3);
					cout<<"<>";
				}
			}
			else
			{
				if(B.getBoardAttacked(i,j))
				{
					cout.width(3);	
					cout<<"@";
				}
				else
				{
					cout.width(3);
					cout<<"-";
				}
			}
		}
	}
	
	cout<<"\n\n\t\t\t\t"<<name<<" hits: "<<hit<<" miss: "<<miss<<endl;
}


//checks safety of position for ships with respect to other ships and bounds of the board 
bool Human :: CheckSafe(int &row,int &col,int &align,int sze)
{
	if(shipAlignmentValidation(sze,row,col,align)==0)
	{
		return false;
	}
			
	if(align==1) //vertical alignment
	{
		for(int i=row;i<=row+sze-1;i++)					
		{
			if(B.getBoardOccupied(i,col))
				return false;			
		}
	}
	else//check for horizontal alignment
	{
		for(int i=col;i<=col+sze-1;i++)
		{
			if(B.getBoardOccupied(row,i))//check board occupied or not
				return false;
		}
	}	
	return true;
}

//Returns hits
int Human :: gethits()
{
	return hit;
}

//Returns miss
int Human :: getmiss()
{
	return miss;
}



