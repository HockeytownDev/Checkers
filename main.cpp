#include <iostream>
#include "Player.h"
#include "Board.h"
#include "BoardPosition.h"

struct Move
{
    int from;
    int to;
};

void handle_mills(BoardPosition * positions, Board * board, Player * player, char color, char remove_color, int move)
{
    if (positions->check_mill_color(board->get_board(), board->get_mills(), color) == color)
    {
        int remove;

        while(true)
        {
            cout << "You have made a string of 3. You may remove an opponent's piece up to 2 positions away." << endl
                 << "What piece will you remove(-1 to skip): ";
            cin >> remove;

            if(remove == -1)
            {
                break;
            }
            else if(!positions->check_remove_position(board->get_board(), move, remove))
            {
                continue;
            }
            else if(board->remove_piece(remove, remove_color))
            {
                player->update("remove");
                board->print_board();
                break;
            }
        }
    }
}

int handle_add_input(Player * player, Board * board, char player_char)
{
    string player_str(1, player_char);
    int move;
    while(true)
    {
        cout << player_str + " Player: What position will you place your piece? ";
        cin >> move;
        if(board->place_piece(move, player_char))
        {
            player->update("add");
            board->print_board();
            break;
        }
    }
    return move;
}

struct Move handle_move_input(Board * board, char player_char)
{
    string player_str(1, player_char);
    struct Move m;

    while(true)
    {
        cout << player_str + " Player: What piece are you moving? ";
        cin >> m.from;
        cout << "Where are you moving it to? ";
        cin >> m.to;

        if(board->move_piece(m.from, m.to, player_char))
        {
            board->print_board();
            break;
        }
    }
    return m;
}

bool handle_wins(Player * p1, Player * p2, Board * board, BoardPosition * bp, char p1_char, char p2_char)
{
    if(p1->get_live_pieces() <= 2 || bp->check_blocked(board->get_board(), p1_char))
    {
        cout << p2_char << " won";
        return true;
    }

    if(p2->get_live_pieces() <= 2 || bp->check_blocked(board->get_board(), p2_char))
    {
        cout << p1_char << " won";
        return true;
    }

    return false;
}

int main()
{
    Board board;
    Player player_red = Player('R');
    Player player_black = Player('B');
    BoardPosition positions;

    board.print_board();

    // Phase 1
    while(true)
    {
        int black_move = -1;
        int red_move = -1;

        if (!player_black.get_placed())
        {
            black_move = handle_add_input(&player_black, &board, 'B');
            handle_mills(&positions, &board, &player_red, 'B', 'R', black_move);
        }

        if (!player_red.get_placed())
        {
            red_move = handle_add_input(&player_red, &board, 'R');
            handle_mills(&positions, &board, &player_black, 'R', 'B', red_move);
        }

        if(handle_wins(&player_red, &player_black, &board, &positions, 'R', 'B'))
        {
            return 0;
        }

        if(player_red.get_placed() && player_black.get_placed())
        {
            break;
        }
    }

    // Phase2
    while(true)
    {
        struct Move black_p = handle_move_input(&board, 'B');
        handle_mills(&positions, &board, &player_red, 'B', 'R', black_p.to);
        if(handle_wins(&player_red, &player_black, &board, &positions, 'R', 'B'))
        {
            break;
        }

        struct Move red_p = handle_move_input(&board, 'R');
        handle_mills(&positions, &board, &player_black, 'R', 'B', red_p.to);
        if(handle_wins(&player_red, &player_black, &board, &positions, 'R', 'B'))
        {
            break;
        }
    }

    return 0;
}
