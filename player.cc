#include <iostream>
#include <string>
#include "player.h"
#include "Game.h"
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"


int Player::get_id() {
return id;
}

Game* Player::get_game() {
return currentGame;
}

