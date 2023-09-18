#include "Knight.h"
#include "Coordinate.h"
#include "Game.h"
#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include <memory>

char Knight::get_type() {
	return 'n';
}


bool Knight::canMove(Coordinate cd) {
	int r1 = cd.get_rank();
	int f1 = cd.get_file();
	//If it sits on square(x,y), it can move to square (x±2,y±1) or (x±1,y±2)
	if ((((r1 == rank - 1 || r1 == rank + 1) && (f1 == file - 2 || f1 == file + 2)) || ((r1 == rank - 2 || r1 == rank + 2) 
	&& (f1 == file - 1 || f1 == file + 1))) && !(rank == r1 && file == f1) && (cd.has_piece() == false || (cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner()))) {
		return true;
	}
	return false;
}

