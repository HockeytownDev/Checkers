#include "BoardPosition.h"

BoardPosition::BoardPosition(){
	return;
}

bool BoardPosition::check_new_position(char * board, int p1, int p2) {
    if (board[p2] == ' ') {
        switch (p1) {
            case 0:
                if (p2 == 1 || p2 == 6)
                    return true;
                break;
            case 1:
                if (p2 == 0 || p2 == 2 || p2 == 4)
                    return true;
                break;
            case 2:
                if (p2 == 1 || p2 == 9)
                    return true;
                break;
            case 3:
                if (p2 == 4 || p2 == 7)
                    return true;
                break;
            case 4:
                if (p2 == 1 || p2 == 3 || p2 == 5)
                    return true;
                break;
            case 5:
                if (p2 == 4 || p2 == 8)
                    return true;
                break;
            case 6:
                if (p2 == 0 || p2 == 7 || p2 == 13)
                    return true;
                break;
            case 7:
                if (p2 == 3 || p2 == 6 || p2 == 10)
                    return true;
                break;
            case 8:
                if (p2 == 5 || p2 == 9 || p2 == 12)
                    return true;
                break;
            case 9:
                if (p2 == 2 || p2 == 8 || p2 == 15)
                    return true;
                break;
            case 10:
                if (p2 == 7 || p2 == 11)
                    return true;
                break;
            case 11:
                if (p2 == 10 || p2 == 12 || p2 == 14)
                    return true;
                break;
            case 12:
                if (p2 == 8 || p2 == 11)
                    return true;
                break;
            case 13:
                if (p2 == 6 || p2 == 14)
                    return true;
                break;
            case 14:
                if (p2 == 11 || p2 == 13 || p2 == 15)
                    return true;
                break;
            case 15:
                if (p2 == 9 || p2 == 14)
                    return true;
                break;
        }
        return false;
    } else
        return false;
}

bool BoardPosition::check_remove_position(char * board, int p1, int p2) {
    if (board[p2] != ' ') {
        switch (p1) {
            case 0:
                if (p2 == 1 || p2 == 6 || p2 == 2 || p2 == 4 || p2 == 7 || p2 == 13)
                    return true;
                break;
            case 1:
                if (p2 == 0 || p2 == 2 || p2 == 4 || p2 == 6 || p2 == 9 || p2 == 3 || p2 == 5)
                    return true;
                break;
            case 2:
                if (p2 == 1 || p2 == 9 || p2 == 0 || p2 == 4 || p2 == 8 || p2 == 15)
                    return true;
                break;
            case 3:
                if (p2 == 4 || p2 == 7 || p2 == 1 || p2 == 5 || p2 == 6 || p2 == 10)
                    return true;
                break;
            case 4:
                if (p2 == 1 || p2 == 3 || p2 == 5 || p2 == 0 || p2 == 2 || p2 == 7 || p2 ==8)
                    return true;
                break;
            case 5:
                if (p2 == 4 || p2 == 8 || p2 == 1 || p2 == 3 || p2 == 9 || p2 == 12)
                    return true;
                break;
            case 6:
                if (p2 == 0 || p2 == 7 || p2 == 13 || p2 == 1 || p2 == 3 || p2 == 10 || p2 == 14)
                    return true;
                break;
            case 7:
                if (p2 == 3 || p2 == 6 || p2 == 10 || p2 == 4 || p2 == 0 || p2 == 13 || p2 == 11)
                    return true;
                break;
            case 8:
                if (p2 == 5 || p2 == 9 || p2 == 12 || p2 == 4 || p2 == 2 || p2 == 15 || p2 == 3 || p2 == 11)
                    return true;
                break;
            case 9:
                if (p2 == 2 || p2 == 8 || p2 == 15 || p2 == 1 || p2 == 3 || p2 == 5 || p2 == 12 || p2 == 14)
                    return true;
                break;
            case 10:
                if (p2 == 7 || p2 == 11 || p2 == 3 || p2 == 6 || p2 == 12 || p2 == 14)
                    return true;
                break;
            case 11:
                if (p2 == 10 || p2 == 12 || p2 == 14 || p2 == 7 || p2 == 3 || p2 == 8 || p2 == 13 || p2 == 15)
                    return true;
                break;
            case 12:
                if (p2 == 8 || p2 == 11 || p2 == 5 || p2 == 9 || p2 == 10 || p2 == 14)
                    return true;
                break;
            case 13:
                if (p2 == 6 || p2 == 14 || p2 == 0 || p2 == 7 || p2 == 3 || p2 == 11 || p2 == 15)
                    return true;
                break;
            case 14:
                if (p2 == 11 || p2 == 13 || p2 == 15 || p2 == 10 || p2 == 12 || p2 == 6 || p2 == 9)
                    return true;
                break;
            case 15:
                if (p2 == 9 || p2 == 14 || p2 == 2 || p2 == 8 || p2 == 11 || p2 == 13)
                    return true;
                break;
        }
        return false;
    } else
        return false;
}

bool BoardPosition::blocked_at(char * board, int p) {
    switch (p) {
        case 0:
            if (board[1] != ' ' && board[6] != ' ')
                return true;
            break;
        case 1:
            if (board[0] != ' ' && board[2] != ' ' && board[4] != ' ')
                return true;
            break;
        case 2:
            if (board[1] != ' ' && board[9] != ' ')
                return true;
            break;
        case 3:
            if (board[4] != ' ' && board[7] != ' ')
                return true;
            break;
        case 4:
            if (board[1] != ' ' && board[3] != ' ' && board[5] != ' ')
                return true;
            break;
        case 5:
            if (board[4] != ' ' && board[8] != ' ')
                return true;
            break;
        case 6:
            if (board[0] != ' ' && board[7] != ' ' && board[13] != ' ')
                return true;
            break;
        case 7:
            if (board[3] != ' ' && board[6] != ' ' && board[10] != ' ')
                return true;
            break;
        case 8:
            if (board[5] != ' ' && board[9] != ' ' && board[12] != ' ')
                return true;
            break;
        case 9:
            if (board[2] != ' ' && board[8] != ' ' && board[15] != ' ')
                return true;
            break;
        case 10:
            if (board[7] != ' ' && board[11] != ' ')
                return true;
            break;
        case 11:
            if (board[10] != ' ' && board[12] != ' ' && board[14] != ' ')
                return true;
            break;
        case 12:
            if (board[8] != ' ' && board[11] != ' ')
                return true;
            break;
        case 13:
            if (board[6] != ' ' && board[14] != ' ')
                return true;
            break;
        case 14:
            if (board[11] != ' ' && board[13] != ' ' && board[15] != ' ')
                return true;
            break;
        case 15:
            if (board[9] != ' ' && board[14] != ' ')
                return true;
            break;
    }
    return false;
}

bool BoardPosition::check_blocked(char * board, char color){
	for(int i = 0; i < 16; i++){
		if(board[i] == color && (!blocked_at(board, i))){
			return false;
		}
	}
	return true;
}

char BoardPosition::check_mill_color(char * board, char * mills, char turn_color) {
    int j = 0;
    char g[8];
    char mill_color = ' ';
    
    for (int i = 0; i < 8; i++) {
    	g[i] = ' ';
    }    

    for (int i = 0; i < 4; i++) {
        if (board[i + j] == board[i + j + 1] && board[i + j] == board[i + j + 2]
                && board[i + j] != ' ') {
            if (board[i + j] == 'R')
                g[i] = 'R';
            else if (board[i + j] == 'B')
                g[i] = 'B';
        }
        if (i < 1 || i > 1)
            j += 2;
        else
            j += 6;
    }
    if (board[0] != ' ' && board[6] != ' '
            && board[13] != ' ') {
        if (board[0] == board[6] && board[0] == board[13]) {
            if (board[0] == 'R')
                g[4] = 'R';
            else if (board[0] == 'B')
                g[4] = 'B';
        }
    }
    if (board[3] != ' '
            && board[7] != ' ' && board[10] != ' ') {
        if (board[3] == board[7] && board[3] == board[10]) {
            if (board[3] == 'R')
                g[5] = 'R';
            else if (board[3] == 'B')
                g[5] = 'B';
        }
    }
    if (board[5] != ' ' && board[8] != ' '
            && board[12] != ' ') {
        if (board[5] == board[8] && board[5] == board[12]) {
            if (board[5] == 'R')
                g[6] = 'R';
            else if (board[5] == 'B')
                g[6] = 'B';
        }
    }
    if (board[2] != ' '
            && board[9] != ' ' && board[15] != ' ') {
        if (board[2] == board[9] && board[2] == board[15]) {
            if (board[2] == 'R')
                g[7] = 'R';
            else if (board[2] == 'B')
                g[7] = 'B';
        }
    }

    for (int i = 0; i < 8; i++) {
        if (mills[i] != g[i] && g[i] != ' ') {        	
            if (turn_color == 'R') {
				mill_color = 'R';
            } else {
            	mill_color = 'B';
            }
	    
            break;
        }
    }
        
    for(int i = 0; i < 8; i++){
    	mills[i] = g[i];
	}
	
	return mill_color;
}
