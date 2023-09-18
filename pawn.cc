// pieces
#include "Pawn.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

// Game
#include "Coordinate.h"
#include "Game.h"
#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include <memory>
#include <iostream>


using namespace std;

char Pawn::get_type() {
	return 'p';
}


bool Pawn::canMove(Coordinate cd) {
	int r1 = cd.get_rank();
	int f1 = cd.get_file();
    if(get_owner()->get_id()== 0) {
	if (((r1 == rank + 1  || (r1 == rank + 2 && hasMoved == false)) && file == f1 && cd.has_piece() == false) || 
	(cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner() && (r1 == rank + 1 && (f1 == file + 1 || f1 == file - 1)))){
		return true;
	}
	return false;
    } else {
        if (((r1 == rank - 1 || (r1 == rank - 2 && hasMoved == false)) && file == f1 && cd.has_piece() == false) || 
	(cd.has_piece() == true && cd.get_pc()->get_owner() != get_owner() && (r1 == rank + 1 && (f1 == file + 1 || f1 == file - 1)))){
		return true;
	}
	return false;
    }
}

shared_ptr<Piece> Pawn::promote(char pieceT) {
    if (pieceT == 'n') {
       shared_ptr<Knight> pc = make_unique<Knight>(rank, file, owner, true);
       return pc;
    } else if (pieceT == 'q') {
        shared_ptr<Queen> pc = make_unique<Queen>(rank, file, owner, true);
        return pc;
    } else if (pieceT == 'r') {
        shared_ptr<Rook> pc = make_unique<Rook>(rank, file, owner, true);
        return pc;
    } else if (pieceT == 'b') {
        shared_ptr<Bishop> pc = make_unique<Bishop>(rank, file, owner, true);
        return pc;
    } else if (pieceT == 'p') {
        shared_ptr<Pawn> pc = make_unique<Pawn>(rank, file, owner, true, true);
        return pc;
    }
    return nullptr;
    
 }

