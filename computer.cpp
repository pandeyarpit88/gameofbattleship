#include"computer.h"

using namespace std;

//Constructor of Computer Class
Computer :: Computer()
{
	int row,col;
	int align;
	bool safe;
	
	cout<<"\n\t\t\t\t"<<"Please Enter Difficulty Level.";		//input of difficulty level
	cout<<"\n\t\t\t\t1. Easy \n\t\t\t\t2. Hard";
	cout<<"\n\t\t\t\tEnter Your Choice : ";
	difficulty = getValidBool();
	strcpy(name,"Computer");
	ship = new Ship[4];
	count = 1;
	attack_dimention= 0;
	flag = false;
	for(int i=1;i<=4;i++)						//checking for valid ship positions
	{
		inputships(align,row,col);
		safe=CheckSafe(row,col,align,i);
		if(!safe)
		{
			i--;
			continue;
		}
		Ship *S = new Ship(i,row,col,align);			//placing ships to valid positions
		ship[i] = S;
		updateBoardShip(row,col,align,i);
	}
}


//taking input for ship placements
void Computer :: inputships(int &align,int &row,int &col)		//taking random values for ship positions
{
	align=1 + rand()%2;
	row=rand()%(MAXSIZE)+1;
	col=rand()%(MAXSIZE)+1;
}


//Attacking human board
int Computer :: attack(Human *H,int nocells)	
{
	if(movetype==0)							//move type based on difficulty level
	{
		attackeasy(H,nocells);
	}
	else
	{
		attackhard(H,nocells);//add prev and next positions as properties
	}
}


//Selecting positions for intelligent attack
int Computer :: Select_Position_For_Hard_Attack(int &row,int &col)
{
  switch(count)
  {
  	
	case 1:					//below the recently attacked cell
		row = currentX +1;
		col = currentY;
		if(row > 10)
		{
			movetype = 0;
			count = 2;
		}
		break;
	case 2:					//right
		row = currentX;
		col = currentY+1;
		if(col > 10)
		{
			movetype = 0;
			count  = 3;
		}
		break;
	case 3:					//top
		row = currentX-1;
		col = currentY;
		if(row<1)
		{
			movetype = 0;
			count = 4;
		}
		break;
	case 4:					//left
		row = currentX;
		col = currentY-1;
		if(col <1)
		{
			movetype = 0;
			count = 1;
		}
		break;
	}	
	
}


//Going along attack in horizontal direction
int Computer :: Horizontal_Attack_Position(Human *H)
{
	if( (H->getAttacked(last_attacked_row,last_attacked_col)) && (flag == false) )
	{
		last_attacked_row = last_attacked_row + 1;
		if(last_attacked_row > 10 )
		{
			flag = true;
			last_attacked_row = currentX-1;
		} 
	}
	else if(H -> getAttacked(last_attacked_row,last_attacked_col))
	{
		last_attacked_row = last_attacked_row - 1;
		if(last_attacked_row < 1)
		{
			flag = false;
			last_attacked_row = rand() % 10 + 1;
			last_attacked_col = rand() % 10 + 1;

			movetype=0;
		}
	}
	else
	{
		last_attacked_row = rand() % 10 + 1;
		last_attacked_col = rand() % 10 + 1;
		attack_dimention = 0;
		movetype = 0;
		count = 1;
		flag = false;
	}
}


//Going along attack in vertical direction
int Computer :: Vertical_Attack_Position(Human *H)
{
	if( (H->getAttacked(last_attacked_row,last_attacked_col)) && (flag == false) )
	{
		last_attacked_col = last_attacked_col + 1;
		if(last_attacked_col >10 )
		{
			flag = true;
			last_attacked_col = currentY-1;
		} 
	}
	else if(H -> getAttacked(last_attacked_row,last_attacked_col))
	{
		last_attacked_col = last_attacked_col - 1;
		if(last_attacked_row < 1)
		{
			flag = false;
		last_attacked_row = rand() % 10 + 1;
		last_attacked_col = rand() % 10 + 1;			
			movetype=0;
		}
	}
	else
	{
		last_attacked_row = rand() % 10 + 1;
		last_attacked_col = rand() % 10 + 1;
		attack_dimention = 0;
		movetype = 0;
		count = 1;
		flag = false;
	}
}

//Attacking at specified position in hard level
bool Computer :: attack_function(Human *H,bool validattack)
{
	H->setAttacked(last_attacked_row,last_attacked_col);
	if(H->getOccupied(last_attacked_row,last_attacked_col))
	{
		hit++;
		attack_dimention = count % 2 +1;
		return true;
	}
	else
	{
		miss++;
		if(flag == false)
		{
			flag = true;
		}
		last_attacked_row = currentX;
		last_attacked_col = currentY;
		return false;
	}
}

//Learning position to attack based on previous attack status
int Computer :: attackhard(Human *H,int nocells)
{
	int attackcell,row,col;
	bool validattack=false;
	bool last_attack_status = true;
	while(!validattack)
	{
	    if(attack_dimention==0)
	    {
	    	Select_Position_For_Hard_Attack(last_attacked_row,last_attacked_col);
		count++;
		
		if(count>4)
		{
			movetype = 0;
			attack_dimention = 0;
			count = 1;
			flag=false;
			last_attacked_row = rand() % 10 + 1;
		last_attacked_col = rand() % 10 + 1;
		}
	    }
	    else
	    {
	    	if(attack_dimention == 1)
	   	{
	   		Horizontal_Attack_Position(H);
	   	}
	   	else
	   	{
	   		Vertical_Attack_Position(H);
	   	}
	    }
	    if(H->getAttacked(last_attacked_row,last_attacked_col))
	    {
		continue;
	    }
	    else
	    {
	    	validattack = true;
	    	last_attack_status = attack_function(H,validattack);
	    }
	    if(last_attack_status == false && attack_dimention!=0 && flag==true)
	    {
	    	attack_dimention = 0;
		movetype = 0;
		count = 0;
		flag = false;
		validattack=true;
	   }
	   else if (flag == true && count>4)
	    {
	    	movetype=1;
	    	count=1;
	    	validattack=true;
	   }
	   }
}


//Attack function for easy level
int Computer :: attackeasy(Human *H,int nocells)
{
	int attackcell,row,col;
	bool validattack=false;	
	while(!validattack)
	{
		attackcell=1+(rand()%nocells);
		attackcell=fabs(attackcell);
		row=attackcell/MAXSIZE;
		col=attackcell%MAXSIZE;
		if(col==0)
			col=10;
		if(row==0)
			row=10;
		if(H->getAttacked(row,col))
			continue;
		else
		{
			validattack=true;
			H->setAttacked(row,col);
			if(H->getOccupied(row,col))
			{
				hit++;
				if(difficulty == 2)
				{
					movetype = 1;
					count = 1;
				}
				last_attacked_row = currentX = row;
				last_attacked_col = currentY = col;
			}
			else
				miss++;
		}		
	}	
}

//checking if a ship placement is safe with respect to other ships and the boundaries of the board
bool Computer :: CheckSafe(int &row,int &col,int &align,int sze)
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

//returns hits made by computer
int Computer :: gethits()
{
	return hit;
}

//returns miss made by computer
int Computer :: getMiss()
{
	return miss;
}


//displays computer's board where ship positions are not visible to the player
void Computer :: displayboard()
{
	cout<<endl;
	cout<<"\n\t\t\t\t";
	cout.width(3);
	cout<<"    ";
	for(int k=1;k<=MAXSIZE;k++)
	{
		cout.width(3);
		cout<<k;
	}
	cout<<endl;
	for(int i=1;i<=MAXSIZE;i++)
	{
		cout<<"\n\t\t\t\t";
		cout.width(3);
		cout<<i<<" ";
		for(int j=1;j<=MAXSIZE;j++)
		{
			if(B.getBoardAttacked(i,j))
			{
				if(B.getBoardOccupied(i,j))
				{
					cout.width(3);
					cout<<"*";
				}
				else
				{
					cout.width(3);
					cout<<"@";
				}
			}
			else
			{
				cout.width(3);
				cout<<"-";
			}
		}
	}
	cout<<"\n\t\t\t\t";
	cout<<name<<" hits: "<<hit<<" miss: "<<miss<<endl;
}

//returns the difficulty level
int Computer :: getdifficulty()
{
	return difficulty;
}
