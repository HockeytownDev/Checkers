#ifndef BoardPosition_H
#define BoardPosition_H

#include <iostream>

using namespace std;

class BoardPosition
{
	public:
		BoardPosition();
		bool check_new_position(char * board, int p1, int p2);
		bool check_remove_position(char * board, int p1, int p2);
		bool blocked_at(char * board, int p);
		bool check_blocked(char * board, char color);
		char check_mill_color(char * board, char * mills, char turn_color);
};

#endif
