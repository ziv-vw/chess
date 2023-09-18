#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include "player.h"
#include "Game.h"
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"

// list of random legal moves from giving pieces
std::vector<std::pair<Coordinate, Coordinate>> Level1::find_moves(std::vector<Coordinate> pieceList){

    std::vector<std::pair<Coordinate, Coordinate>> moveList; // list of all moves

    for (auto piece = pieceList.begin(); piece != pieceList.end(); ++piece){ // loop through pieces 

        // retrieve starting piece coordinates
        int fromRank = piece->get_rank();
        int fromFile = piece->get_file();

        // loop through board and find possible moves
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){

                // adding possible move
                Coordinate& targetCoord = get_game()->get_boards()->get_coord(i, j); // set possible space to move to

                if (get_game()->get_boards()->get_coord(fromRank, fromFile).get_pc()->canMove(targetCoord)){ // can move to
                    moveList.push_back(std::make_pair(*piece, targetCoord)); // add target space
                }
            }
        }
        
        // check for empty target move pieces and return pair of moves
    }
    return moveList; 
}



