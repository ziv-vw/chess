#include "Queen.h"
#include "Coordinate.h"
#include "Game.h"
#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include <memory>
#include <iostream>

using namespace std;
char Queen::get_type() {
	return 'q';
}


bool Queen::canMove(Coordinate cd) {
	int r1 = cd.get_rank();
	int f1 = cd.get_file();
	//If it sits on square(x,y), it can move to square (x,y±i) or (x±i,y) or (x±i,y±i) for some 0< i <= 4
	if ((r1 == rank || f1 == file || r1 - rank == f1 - file || r1 - rank == file - f1) && !(rank == r1 && file == f1) && 
    (cd.has_piece() == false || (cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner()))) {
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
		} else if (r1 > rank) {
            for (int i = 1; i < r1 - rank; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(rank + i, file);
				if (temp.has_piece() == true) return false;
			}
        } else if (r1 < rank) {
            for (int i = 1; i < rank - r1; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(r1 + i, file);
				if (temp.has_piece() == true) return false;
			}
        } else if (f1 > file) {
            for (int i = 1; i < f1 - file; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(rank, file + i);
				if (temp.has_piece() == true) return false;
			}
        } else if (f1 < file) {
            for (int i = 1; i < file - f1; i++) {
				Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(rank, f1 + i);
				if (temp.has_piece() == true) return false;
			}
        } else {
            return false;
        }
        return true;
	}
	return false;
}


