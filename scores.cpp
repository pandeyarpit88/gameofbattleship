#include "scores.h"

//Scores Constructor
scores :: scores()
{
}

//Read Scores from a file
int scores :: read(scor s[],char filename[])
{
	ifstream ifs;
	ifs.open(filename);
	int count = 0;
	for(int i=0 ; i<10 ; i++)
	{
		if(ifs.eof() != 0)
		{
			break;
		}
		else
		{
			ifs >> s[i].name;
			ifs >> s[i].score;
			count++;
		}
	}
	ifs.close();
	if(count==10)
		return count+1;
	else
		return count;
}


//Write a score into the file
int scores :: write_back_to_file(int count,char filename[])
{
	ofstream onf(filename,ios::trunc);	
	int i=0;
	for (itr=lst.begin();(itr!=lst.end() && i<10 );itr++,i++)
		{
			onf << (*itr).name;
			onf<<"\n";
			onf << (*itr).score;
			onf<<"\n";
		}
	onf.close();
}

//Move an array of scores to a list
int scores :: move_to_lst(scor s[],int count,scor s1)
{
	int flag = 0,i=0;
	for( i=0;i<count;i++)
		lst.push_back(s[i]);
	
	if(lst.empty())
	{
		lst.push_back(s1);
	}
	else
	{
		i=0;
		for (itr1=lst.begin();(itr1!=lst.end() && i<10 );itr1++ ,i++)
		{
			if(s1.score >= (*itr1).score )
			{
				lst.insert(itr1,s1);
				flag = 1;
				break;
			}
		}
		if(flag == 0 && count < 10 )
		{
			lst.push_back(s1);
		}
	}
}

//Add a new score
void scores :: add_new_score(char name[],int score,int difficulty)
{
	scor s[SIZE],s1;
	char filename[SIZE];
	strcpy(s1.name,name);
	s1.score=score;
	if(difficulty==1)
	{
		strcpy(filename,"easy.txt");
	}
	else
	{
		strcpy(filename,"hard.txt");
	}
	int count = read(s,filename);
	if(count <10)
		move_to_lst(s,count-1,s1);
	else
		move_to_lst(s,count,s1);
	write_back_to_file(count,filename);
}


//Show scores with respect to a particular difficulty level
void scores :: show_scores(int difficulty)
{
	scor s[SIZE];
	char filename[SIZE];
	ifstream ifs;
	scor sc;
	if(difficulty==1)
	{
		strcpy(filename,"easy.txt");
	}
	else
	{
		strcpy(filename,"hard.txt");
	}
	ifs.open(filename);
	int count=read(s,filename);
	cout<<"\n\n\n\n\n\t\t\t\tHigh Scores\n\n";
	if(difficulty==1)
		cout<<"\n\n\t\t\tDifficulty Level: Easy\n\n\n";
	else
		cout<<"\n\n\t\t\tDifficulty Level: Hard\n\n\n";
	
	cout<<"\t\t";							//Formatting of output
	cout.width(4);
	cout<<"Rank";
	cout.width(30);
	cout<<"Name";
	cout.width(10);
	cout<<"Score";
	cout<<"\n";
	if(count==10)
	{
		for(int i=0 ; i<count ; i++)
		{
			if(ifs.eof() != 0)
			{
				break;
			}
			else
			{	
				ifs >> sc.name;
				ifs >> sc.score;
				cout<<"\n\t\t";
				cout.width(4);
				cout<<i+1;
				cout.width(30);
				cout<<sc.name;
				cout.width(10);
				cout<<sc.score;
			}
		}
	}
	else
	{	 
		for(int i=0 ; i<count-1 ; i++)
		{
			if(ifs.eof() != 0)
			{
				break;
			}
			else
			{
				ifs >> sc.name;
				ifs >> sc.score;
				cout<<"\n\t\t";
				cout.width(4);
				cout<<i+1;
				cout.width(30);
				cout<<sc.name;
				cout.width(10);
				cout<<sc.score;
			}
		}
	}
	ifs.close();
	cout<<"\n\n\n";
}
