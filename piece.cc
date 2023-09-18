#include "Piece.h"
#include "Coordinate.h"
#include <memory>
#include "Game.h"
#include "Board.h"
#include "Rook.h"
#include "Queen.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include <iostream>

using namespace std;



int Piece::get_rank() {
    return rank;
}

int Piece::get_file() {
    return file;
}

Player* Piece::get_owner(){
    return owner;
}

bool Piece::get_hasMoved(){
	return hasMoved;
}
void Piece::move(Coordinate &cd) {
    shared_ptr <Piece>& original = get_owner()->get_game()->get_boards()->get_coord(rank, file).get_pc();
	rank = cd.get_rank();
	file = cd.get_file();
	cd.get_pc() = original;
	hasMoved = true;
}


bool Piece::checking(Coordinate &cd) {
	//all pcs in target coordinate whose owner aren't current player, canMove(cd) == true

    //store necessary information for the original two coordinates;
    // original coordinates
    int temp_rank_from = rank;
    int temp_file_from = file;
    std::shared_ptr<Piece> temp_pc_from = nullptr; 
    
    // target coordinates
    std::shared_ptr<Piece> temp_pc_to = cd.get_pc();

    bool find = false;
    bool check = false;
    //mimic the behavior of makeMove()

    //move the piece
    if (canMove(cd) == true) {
        move(cd);
    }
    //find the original coord that *this belongs to and change it pc field to nullptr
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(i, j);
            if (temp.has_piece() == true && temp.get_rank() == temp_rank_from && temp.get_file() == temp_file_from) {
                temp_pc_from = temp.get_pc();
                temp.get_pc() = nullptr;
                find = true;
                break;
            }
        }
        if (find == true) break;
    }

bool temp_find = false;


	//find the king piece for current player
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Coordinate &temp_king = get_owner()->get_game()->get_boards()->get_coord(i, j);
            if (temp_king.has_piece() == true &&  temp_king.get_pc()->get_type() == 'k' && temp_king.get_pc()->get_owner() == get_owner()) {
//use the moved coordinates to check if the movement will cause a checking situation
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(i, j);
            if (temp.has_piece() == true && temp.get_pc()->canMove(temp_king) == true) {
                temp_find = true;
                check = true;
                break;
            }
        }
        if (temp_find == true) break;
    }
				find = true;
                break;
            }
        }
        if (find == true) break;
    }

    find = false;

    
    //restore the original state
    rank = temp_rank_from;
    file = temp_file_from;
    cd.get_pc() = temp_pc_to;

    find = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Coordinate temp = get_owner()->get_game()->get_boards()->get_coord(i, j);
            if (temp.has_piece() == true && temp.get_rank() == temp_rank_from && temp.get_file() == temp_file_from) {
                temp.get_pc() = temp_pc_from;
                find = true;
                break;
            }
        }
        if (find == true) break;
    }
    

    return check;
}

