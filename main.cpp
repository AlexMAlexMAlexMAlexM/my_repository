/********************************
 *
 *	
 *	this code was tested on Ubuntu and Windows OS
 *  
 *	test task is made by Alex
 *	mobile +38(050) 341 98 91
 * 
********************************/
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

//#include "chess.ini"
#include "chess.h"
#include "Figure.h"
#include "chessUtilities.h"

using namespace std;

enum {NOTHING = 0, PAWN = 1, BISHOP = 2, KNIGHT = 3, ROOK = 4, QUEEN = 5, KING = 6, CHECKER = 10};//figure_status 
enum {DEAD = 0, ALIVE};//figure_state 
enum {BLACK = 1, WHITE};//figure_membership
enum {ONE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, BOARD_SIDE}; // vertical
enum {A = 0, B, C, D, E, F, G, H}; // horizontal
 

class coordinates
{
public:
	int x_coord;
	int y_coord;	
};


class Figure
{
//public:
	int x_coord;
	int y_coord; 
	int status;
	int membership;
	bool state;
public:
	Figure()
	{
		x_coord = A;
		y_coord = ONE;
		status = CHECKER;
		membership = BLACK;
		state = ALIVE;
	}

	Figure(int horizontal, int vertical, int _status, int _membership, bool _state)
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
	int get_horizontal() {	return x_coord;	}
	int get_vertical() {	return y_coord;	}
	int get_status() {	return status;	}
	int get_membership() {	return membership;	}
	int get_state() {	return state;	}
	
};


class Player
{
	int move_counter;
	int self_id;
public:
	Player(int s_id) { self_id = s_id; move_counter = 0; }

	~Player();
	
};
/*
void move(Figure *Current_figure)// class affiliation is undefined
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
	//		( deal done == ">= BOARD_SIDE" and so on)
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
					current_coords[i].y_coord >= BOARD_SIDE ||
					current_coords[i].x_coord >= BOARD_SIDE
				) { current_coords[i].y_coord = 100; current_coords[i].x_coord = 100; }
			}

			for (int i = 0; i < 4; ++i)
				cout << "x_coord = " << current_coords[i].x_coord << " and y_coord = " << current_coords[i].y_coord << endl;

			delete[] current_coords;
		break;

		default:
			cout << " incorrect argument (figure status)" << endl;
	}
	//	- as a result should be known the finite range of possibile new position(s)
	//	2) is there other figure there
	//	2.1) is it a stranger or a own
	//	3) will the new position be able to injure 
	
	return ;	
}*/

Figure *Fig[BOARD_SIDE][BOARD_SIDE] = {nullptr};
void set_All_Figures(Figure* Fig[BOARD_SIDE][BOARD_SIDE], int BOARD_SIDE);

int main(void)
{
	set_All_Figures(Fig, BOARD_SIDE);
	/*int horizontal = A, vertical = ONE, _status = CHECKER, _membership = 0; 
	bool _state = 0;
	for (int h = 0; h < BOARD_SIDE; ++h)
	{
		for (int v = 0; v < BOARD_SIDE; ++v) 
		{
			if ( 
				( v == ONE && (!(h%2)) ) ||
				( v == TWO && ((h%2)) ) ||
				( v == THREE && (!(h%2)) ) ||
				( v == SIX && ((h%2)) ) ||
				( v == SEVEN && (!(h%2)) ) ||
				( v == EIGHT && ((h%2)) )
			)
			{
				_state = ALIVE;
				if ( v == ONE ||
					 v == TWO ||
					 v == THREE )
					 _membership = BLACK;
		
				if ( v == SIX ||
					 v == SEVEN ||
					 v == EIGHT )
					 _membership = WHITE;
			}
			else
			{
				_state = DEAD;
				_membership = NOTHING;
			}
			horizontal = h + 1;
			vertical = v + 1;
			//horizontal = h; it is a case without ZERO
			//vertical = v;	it is a case without ZERO
			
			Fig[v][h] = new Figure(horizontal, vertical, _status, _membership, _state);	
		}	
	}*/	

	cout << "\n" << endl;
	for (int v = (BOARD_SIDE - 1); v >= 0; --v)
	{
		for (int h = 0; h < BOARD_SIDE; ++h) 
		{
			cout << " [" << Fig[v][h]->get_state() << " " << Fig[v][h]->get_membership() <<"] ";
		}
		cout << "\n" << endl;
	}

	for (int h = 0; h < BOARD_SIDE; ++h)
		for (int v = 0; v < BOARD_SIDE; ++v) 
			delete Fig[v][h];
	
	// HOW TO CHECK MEMORY CLEANING ?
	// HOW WRITE CORRECT Pointer Figure[][] as an argument ? is resolved
	// HOW to replace/substitute part of code without aguments and a returned value ?
	// how to use struct/class "coords" within class Figure 
	// how to search with parameter(s)

	//move(Fig[0][0]);

	
	
	return 0;
}

inline bool isAlive(int v, int h)
{
	 return ( 
	 			( v == ONE && (!(h%2)) ) ||
				( v == TWO && ((h%2)) ) ||
				( v == THREE && (!(h%2)) ) ||
				( v == SIX && ((h%2)) ) ||
				( v == SEVEN && (!(h%2)) ) ||
				( v == EIGHT && ((h%2)) ) 
			);	

}
void set_All_Figures(Figure* Fig[BOARD_SIDE][BOARD_SIDE], int BOARD_SIDE)
{
	int horizontal = A, vertical = ONE, _status = CHECKER, _membership = 0; 
	bool _state = 0;
	for (int h = 0; h < BOARD_SIDE; ++h)
	{
		for (int v = 0; v < BOARD_SIDE; ++v) 
		{
			if (isAlive(v,h))
			{
				_state = ALIVE;
				if ( v == ONE ||
					 v == TWO ||
					 v == THREE )
					 _membership = BLACK;
		
				if ( v == SIX ||
					 v == SEVEN ||
					 v == EIGHT )
					 _membership = WHITE;
			}
			else
			{
				_state = DEAD;
				_membership = NOTHING;
			}
			horizontal = h + 1;
			vertical = v + 1;
			//horizontal = h; it is a case without ZERO
			//vertical = v;	it is a case without ZERO
			
			Fig[v][h] = new Figure(horizontal, vertical, _status, _membership, _state);	
		}
	}	
}
