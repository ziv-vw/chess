#include "Bishop.h"
#include "Coordinate.h"
#include "Game.h"
#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"
#include <memory>

using namespace std;

char Bishop::get_type() {
	return 'b';
}

bool Bishop::canMove(Coordinate cd) {
	int r1 = cd.get_rank();
	int f1 = cd.get_file();

	//If it sits on square(x,y), it can move to square (x±i,y±i) for some 0 < i <= 4
	if (!(rank == r1 && file == f1) && (cd.has_piece() == false || (cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner()))) {
		if (r1 - rank == f1 - file && r1 - rank > 0) {
			for (int i = 1; i < r1 - rank; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(rank + i, file + i);
				if (temp.has_piece() == true) return false;
			}
		} else if (r1 - rank == file - f1 && r1 - rank > 0) {
			for (int i = 1; i < r1 - rank; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(rank + i, f1 + i);
				if (temp.has_piece() == true) return false;
			}
		} else if (rank - r1 == f1 - file && rank - r1 > 0) {
			for (int i = 1; i < r1 - rank; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(r1 + i, file + i);
				if (temp.has_piece() == true) return false;
			}
		} else if (rank - r1 == file - f1 && rank - r1 > 0) {
			for (int i = 1; i < r1 - rank; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(r1 + i, f1 + i);
				if (temp.has_piece() == true) return false;
			}
		} else {
			return false;
		} 
		return true;
	}
	return false;
}


