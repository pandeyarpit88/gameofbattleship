
/*
 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
 =                                                                                 =
 =   Project          :  Battle Ship A turn taking strategy game                   =
 =   Author           :  Shreyas Pandey,Arpit Pandey,Ambrish Chandan Keshri        =
 =   Date Created     :  31/10/2010	                                           =
 =   Language         :  C++                                                       =
 =                                                                                 =
 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
*/

/*--------------------------------------------------------------------------------------------
				PREPROCESSOR DIRECTIVES
--------------------------------------------------------------------------------------------*/

#include"game.h"
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define LEN 20
using namespace std;

/*---------------------------------------------------------------------------------------------------
   INTEGER VALIDATION CODE
--------------------------------------------------------------------------------------------------*/
int getvalidint()
{
char numstring[LEN];
int len,i,numint,start=0;
short int flag=1;
	do
	{
		cin>>numstring;
	
		len=strlen(numstring);

		if(numstring[0]=='-')
			start=1;

		for(i=start;i<len;i++)
		{
			flag=0;
			if(numstring[i]<'0' || numstring[i]>'9')
			{
				flag=1;
				break;
			}
			else
				continue;
		}
	}while(flag==1);

	if(flag==0)
	{
		numint=atoi(numstring);
		return(numint);
	}
}
/*
int getvalint()
{
	char variablename[];
	char vn1[];
	char numstring[LEN];
	int len,i,numint,count=0;
	short int flag;
	do
	{
		flag=0;
		if(count>0)
  		{
  			cout<<"\n NOTE : PLEASE ENTER THE VALID "<<variablename<<" NUMBER ";
  			cout<<vn1<<endl;
		}
		cout<<"\n ENTER THE"<<variablename<<"NUMBER "<<vn1<<" = ";
		cin>>numstring;
		len=strlen(numstring);
		for(i=0;i<len;i++)
		{
			if((numstring[i]< '0') || (numstring[i]> '9'))
			{     
				flag=1;
				count=count+1;
				break;
			}        
		}          
	}
 
 	while(flag==1);
 	if(flag==0)
  	{  
  		numint=atoi(numstring);
  	}
	return (numint);
}   
*/

void header()
{
	system("clear");
	cout<<"\n------------------------------------------------------------------------------------------------------------";
	cout<<"\n				  		Game Of Battle Ship In C++";
	cout<<"\n------------------------------------------------------------------------------------------------------------";
	cout<<"\n\t\t --------------------------------------------------------------------------------\n";
	cout<<"\t\t | Usage									|\n";
	cout<<"\t\t | g++ *.cpp -o battleship.exe							|\n";
	cout<<"\t\t | ./battleship.exe <input							|\n";
	cout<<"\t\t --------------------------------------------------------------------------------\n";
	
	
	cout<<"\n\n";
}


void about_us()
{
	cout<<"\n\t\t --------------------------------------------------------------------------------\n";
	cout<<"\t\t | Shreyas Pandey		| -> Team Leader				|\n";
	cout<<"\t\t | Arpit Pandey			| -> Member					|\n";
	cout<<"\t\t | Ambrish Chandan Keshri	| -> Member					|\n";
	cout<<"\t\t --------------------------------------------------------------------------------\n";
	
	cout<<"\n\n\n\t\t\t\t\tPRESS ENTER TO CONTINUE ...";
	getchar();
}

void thank_user()
{
	system("clear");
	cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t * THANK YOU *\n\n\t\t\t\t\t\t* VISIT AGAIN *\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
}

/*---------------------------------------------------------------------------------------------------
   TERMINATION CODE
--------------------------------------------------------------------------------------------------*/

char termination()
{
    char t;
    do
    {
    getchar();
    cout<<"\n If you want to go back to main menu then press 'Y' |or| 'N' to exit = ";
    cin>>t;
	if(t!='y'  && t!='Y' && t!='n' && t!='N')
	{
		cout<<"\n NOTE :(Please enter the character Y or N)\n";
	}
	if(t=='n' || t=='N')
	{
        cout<<"\n Thank you & have a nice day\n";
        cout<<"\n";
        exit(0);
	}
    }
    while(t!='y' && t!='Y' && t!='n' && t!='N');
    return(t);
}

/*---------------------------------------------------------------------------------------------------
   DISPLAY FILE FUNCTION
--------------------------------------------------------------------------------------------------*/
void display(FILE *fp)
{
    char c;
    //system("clear");
    if (fp == NULL)
        {	 
        cout<<"File doesn't exist\n";
        }    
    else 
	{
    	   do 
	     {
              	c = getc(fp);  /* get one character from the file */
              	putchar(c);    /* display it on the monitor       */
	     } 
	   while (c != EOF);  /* repeat until EOF (end of file)  */
	 }
}

int optionfunc()
{
int choice;
   cout<<" SELECT THE OPTION :                             \n";
   cout<<" ========================================================================================================================================\n";
   cout<<" PRESS 1 => Back to Main Menu    \n";
   cout<<" PRESS 2 => Play the Game    \n";
   cout<<" PRESS 3 => Help File \n";
   cout<<" PRESS 4 => Show High Scores \n";
   cout<<" PRESS 5 => Exit                     \n";
   choice=getvalidint();
   cout<<"\n";
   cout<<" ========================================================================================================================================\n";
   return (choice);
}

/*--------------------------------------------------------------------------------------------
					MAIN FUNCTION
--------------------------------------------------------------------------------------------*/
main()
{
int choice,choic;
char c;
Game G;
FILE *fp;
	system("clear");
	header();

	/*------------------------------------------------------------------------------------
				   	INTRO MODULE
	------------------------------------------------------------------------------------*/
   
	about_us();
	
	srand(time(NULL));
	do // menu do while
	{
		header();
		choice = optionfunc();
		switch(choice)
		{
			case 1:
				header();
				about_us();
			break;
			case 2:
				cout<<"\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout<<"\t\t\t\tWelcome To BattleShip !\n\n\t\t\t\tA Turn Taking Strategy Game\n";
				cout<<"\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
				G.input();
				G.play();
				G.result();
			break;

			case 3:
				fp = fopen("help.txt", "r");
				display(fp);
			break;
			case 4:
				cout<<"\n\t\t\tEnter Difficulty Level: ";
				cout<<"\n\t\t\t\tPress 1 for Easy: ";
				cout<<"\n\t\t\t\tPress 2 for Hard: ";
				cin>>choic;				
				G.showhighscores(choic);
			break;
			case 5:
				thank_user();
				exit(0);
			break;
			default:
		/*----------------------------------------------------------------------------------------
				DEFAULT CASE
		----------------------------------------------------------------------------------------*/
				system("clear");
				cout<<"\n Please enter the valid option \n\n";
			break;

			
		}
		c=termination();
	}while(c!='y' || c !='Y');
	thank_user();
	return 0;
}
