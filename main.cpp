/********************************
 *
 *	town trams planing
 *	this code was tested on Ubuntu and Windows OS
 *  
 *	test task is made by Alex
 *	mobile +38(050) 341 98 91
 * 
********************************/
#include <iostream>
#include <string>
#include <fstream>

//#include "chess.ini"
//#include "chess.h"

using namespace std;
/////////////////////////START
/////////////////////////START
/////////////////////////START

enum {NOTHING = 0, PAWN = 1, BISHOP = 2, KNIGHT = 3, ROOK = 4, QUEEN = 5, KING = 6, CHECKER = 10};//figure_status 
enum {DEAD = 0, ALIVE};//figure_state 
enum {BLACK = 0, WHITE};//figure_membership
// two enums for classical fefinitions
enum {ONE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT}; // vertical
enum {A = 0, B, C, D, E, F, G, H}; // horizontal
const int board_side = 8; 

class coords
{
public:
	int x_coord;
	int y_coord;	
};


class Figure
{
public:
	int x_coord;
	int y_coord;
	int status;
	bool membership;
	bool state;
//public:
	Figure()
	{
		x_coord = A;
		y_coord = ONE;
		status = CHECKER;
		membership = BLACK;
		state = ALIVE;
	}
	Figure(int horizontal, int vertical, int _status, bool _membership, bool _state)
	{
		x_coord = horizontal;
		y_coord = vertical;
		status = _status;
		membership = _membership;
		state = _state;
	}
//	~Figure();
	//void move(int _x, int _y)
	//{
		//	checking its rights and capabilities
		//	1) which moves can the figure do according to:
		//		1.1) its status
		//		AND
		//		1.2) its current position (are there these coords in limits of the board)
		
		/*	- as a result should be known the finite range of possibile new position(s)
			2) is there other figure there
			2.1) is it a stranger or a own
			3) will the new position be able to injure 
		*/

	//}
	
};


class Player
{
	int move_counter;
	int self_id;
public:
	Player(int s_id) { self_id = s_id; move_counter = 0; }

	~Player();
	
};

void move(Figure *Current_figure)
//void move(int status, int _x, int _y) // class affiliation is undefined
{ 
	int x = Current_figure->x_coord;
	int y = Current_figure->y_coord;
	int status = Current_figure->status;

	coords* current_coords = nullptr;
	//	which figure is given ( deal done == switch(status))
	//	checking its rights and capabilities 	( deal done )
	//	1) which moves can the figure do according to:
	//		1.1) its status ( deal done == "y + 1" and so on)
	//		AND
	//		1.2) its current position (are there these coords in limits of the board or not)
	//		( deal done == ">= board_side" and so on)
	switch(status)
	{
		case CHECKER: 
			
			current_coords = new coords[4];
			// normal possible moves
			current_coords[0].y_coord = y + 1;
			current_coords[0].x_coord = x + 1;
			current_coords[1].y_coord = y - 1;
			current_coords[1].x_coord = x - 1;

			current_coords[2].y_coord = y - 1;
			current_coords[2].x_coord = x + 1;
			current_coords[3].y_coord = y + 1;
			current_coords[3].x_coord = x - 1;
			for (int i = 0; i < 4; ++i)
				cout << "x_coord = " << current_coords[i].x_coord << " and y_coord = " << current_coords[i].y_coord << endl;
				cout << endl;
			for (int i = 0; i < 4; ++i)
			{
				if(	// board overflow cases
					current_coords[i].y_coord < 0 ||
					current_coords[i].x_coord < 0 ||
					current_coords[i].y_coord >= board_side ||
					current_coords[i].x_coord >= board_side
				) { current_coords[i].y_coord = 100; current_coords[i].x_coord = 100; }
			}

			for (int i = 0; i < 4; ++i)
				cout << "x_coord = " << current_coords[i].x_coord << " and y_coord = " << current_coords[i].y_coord << endl;

			delete[] current_coords;
		break;

		default:
			cout << " incorrect argument (figure status)" << endl;
	}
	/*	- as a result should be known the finite range of possibile new position(s)
		2) is there other figure there
		2.1) is it a stranger or a own
		3) will the new position be able to injure 
	*/
	return ;	
}

/////////////////////////FINISH
/////////////////////////FINISH
/////////////////////////FINISH

Figure *Fig[board_side * board_side];

int main(void)
{
	for (int i = 0, _horizontal = 0, _vertical = 0, _status = 10, _membership = 0, _state = 0; i < (board_side * board_side); ++i)
	{
		



		Fig[i] = new Figure(_horizontal, _vertical, _status, _membership, _state);
	}
	
	

	move(Fig[0]);

	delete Fig[board_side * board_side];
	
	return 0;
}