#ifndef SCORES_H
#define SCORES_H
#include<iostream>
#include<fstream>
#include<list>
#include<string.h>
#include<algorithm>

#define SIZE 40
using namespace std;

typedef struct scor							//Structure of a score
{
	char name[SIZE];
	int score;
}scor;

class scores
{
	list<scor> lst;							//Standard template List used to keep records in sorted order
	list<scor> :: iterator itr;
	list<scor> :: iterator itr1;					//Iterators for List Template Class
	public:
	scores();							//Scores Constructor
	
	int read(scor s[],char filename[]);				//Read Scores from a file
			
	int write_back_to_file(int count,char filename[]);		//Write a score into the file

	int move_to_lst(scor s[] , int count,scor s1);			//Move an array of scores to list

	void add_new_score(char name[],int score,int difficulty);	//Add a new score

	void show_scores(int difficulty);				//Show scores with respect to a particular difficulty level

};
#endif
