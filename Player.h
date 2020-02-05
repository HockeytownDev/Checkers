#ifndef Player_H
#define Player_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
    private:
	    char color;
	 	int current_pieces;
	 	int unplayed_pieces;
		int live_pieces;
		bool placed;
	
	public:
		Player(char);
		char get_color();
		int get_current_pieces();
		int get_unplayed_pieces();
		int get_live_pieces();
		bool get_placed();
		void set_color(char c);
		void set_current_pieces(int cp);
		void set_unplayed_pieces(int up);
		void set_live_pieces(int lp);		
		void set_placed(bool pl);
		void update(string action);
};

#endif
