//Cell Class. Contained in Board Class
class Cell
{
	private:
		int row;
		int col;
		bool occupied;
		bool attacked;
	public:
		Cell(){}				//cell default constructor

		Cell(int r,int c,bool o,bool a);	//cell parameterized constructor

		int getRow();				//returns row

		int getCol();				//returns column

		bool getCellOccupied();			//returns true if cell is occupied by a ship, false otherwise

		void setCellOccupied();			//sets the occupied flag of cell to true

		bool getCellAttacked();			//returns true if cell is attacked by the enemy, false otherwise

		void setCellAttacked();			//sets attacked flag of a cell to true

		void Show();				//displays row n col of a cell

};


