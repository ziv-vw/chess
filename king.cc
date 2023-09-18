#include "King.h"
#include "Coordinate.h"
#include "Game.h"
#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include <memory>
#include <iostream>


using namespace std;

char King::get_type() {
	return 'k';
}


bool King::canMove(Coordinate cd) {
	int r1 = cd.get_rank();
	int f1 = cd.get_file();
	if (r1 >= rank - 1 && r1 <= rank + 1 && f1 >= file - 1 && f1 <= file + 1 && !(rank == r1 && file == f1) && 
	(cd.has_piece() == false || (cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner()))) {
		return true;
	}
	return false;
}

