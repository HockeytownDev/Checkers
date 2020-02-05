#include "Board.h"

Board::Board(){
	for(int i = 0; i < 16; i++){
		board[i] = ' ';
	}
	
	for(int i = 0; i < 8; i++){
		mills[i] = ' ';
	}	
}

void Board::print_board(){
    cout << endl<<endl;
    cout<< "13(" << board[13] << ")---------14(" << board[14] << ")--------15(" << board[15] << ")" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << "   |   10(" << board[10] << ")--11(" << board[11] << ")--12(" << board[12] << ")    |" << endl
        << "   |      |             |     |" << endl
        << " 6(" << board[6] << ")---7(" << board[7] << ")          8(" << board[8] << ")--9(" << board[9] << ")" << endl
        << "   |      |             |     |" << endl
        << "   |    3(" << board[3] << ")---4(" << board[4] << ")---5(" << board[5] << ")    |" << endl
        << "   |             |            |" << endl
        << "   |             |            |" << endl
        << " 0(" << board[0] << ")----------1(" << board[1] << ")---------2(" << board[2] << ")" <<  endl;
}

char * Board::get_board(){
	return board;
}
char * Board::get_mills(){
	return mills;
}

bool Board::place_piece(int p, char color){
	if (p >= 0 && p <= 15 && board[p] == ' ') {
		board[p] = color;
		return true;
	}
	return false;
}
bool Board::remove_piece(int p, char color){
	if(p>=0 && p<=15 and board[p] == color){
		board[p] = ' ';
		return true;
	}
	return false;
}

bool Board::move_piece(int p1, int p2, char color){
	if(remove_piece(p1, color)){
		if(place_piece(p2, color)){
			return true;
		}
	}
	return false;
}
