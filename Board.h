#ifndef Board_H	
#define Board_H

#include <iostream>

using namespace std;

class Board
{
    private:
		char board[16];
		char mills[8];
	
	public:
		Board();
		void print_board();
		char * get_board();
		char * get_mills();
		bool place_piece(int p, char color);
		bool remove_piece(int p, char color);
		bool move_piece(int p1, int p2, char color);
};

#endif
