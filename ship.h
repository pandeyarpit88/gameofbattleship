#ifndef SHIP_H
#define SHIP_H
class Ship
{
	private:
		int size;
		int alignment;
		int posX;
		int posY;
		bool visible;
	public:
		Ship();						//Default Constructor for Ship

		Ship(int sze,int row,int col,bool align);	 //Ship Parameterized Constructor

		void operator=(const Ship *S);			//Overloading Assignment Operator

		bool getAlignment();				//Gets alignment of a ship

		int getPosX();					//Get x co-ordinate value for the ship

		int getPosY();					//Get x co-ordinate value for the ship	

		bool getVisibility();				//Get visibility for the ship

		void SetVisible();				//Set Visibility of a Ship to True

};
#endif
