#include "player.h"
#include "Board.h"
#include "Coordinate.h"
#include "Game.h"
#include "Piece.h"
#include <memory>
#include <iostream>
using namespace std;

bool Human::make_move(int rank1, int file1, int rank2, int file2) {      
        // set 2 coordinates
                        

        Coordinate& from = get_game()->get_boards()->get_coord(rank1, file1);
        Coordinate& to = get_game()->get_boards()->get_coord(rank2, file2);

        shared_ptr<Piece> pc = from.get_pc();


        if (pc->get_owner() != this) return false;

        // successful move
        if (pc != nullptr && pc->canMove(to) == true && pc->checking(to) == false) {
                pc->move(to);
                from.get_pc().reset();
                return true;
        }
        return false;
}

