#include "player.h"
#include <string>

Player::Player(char c)
{
	color = c;
	current_pieces = 0;
	unplayed_pieces = 6;
	live_pieces = 6;	
	placed = false;
}

char Player::get_color() {
	return color;
}

int Player::get_current_pieces() {
	return current_pieces;
}

int Player::get_unplayed_pieces() {
	return unplayed_pieces;
}

int Player::get_live_pieces() {
	return live_pieces;
}

bool Player::get_placed() {
	return placed;
}


void Player::set_color(char c){
	color = c;
}

void Player::set_unplayed_pieces(int up) {
	unplayed_pieces = up;
}

void Player::set_current_pieces(int cp) {
	current_pieces = cp;
}

void Player::set_live_pieces(int lp){
	live_pieces = lp;
}	

void Player::set_placed(bool pl){
	placed = pl;
}	

void Player::update(string action){
	if(action == "add"){
	 	current_pieces++;
	 	unplayed_pieces--;
		if(!unplayed_pieces){
			placed = true;
		}
	} else if(action == "remove"){
		current_pieces--;
		live_pieces--;
	}
}
