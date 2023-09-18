#include <iostream>
#include <string>
#include <cstdlib> 
#include <vector>
#include "player.h"
#include "Game.h"
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"




// find starting pieces for a player
std::vector<Coordinate> Computer::find_pieces(){
    std::vector<Coordinate> startpieceList;

    Board* currentBoard = get_game()->get_boards(); // set board for easier access
    
    // loop through all possible pieces in the board
    for (int i = 0; i < 8; i++){ // rank
        for (int j = 0; j < 8; j++){ // file
            Coordinate currentCoord = currentBoard->get_coord(i, j); // set current coordinate

            if(currentCoord.has_piece()){ // has piece
                if(currentCoord.get_pc()->get_owner()->get_id() == get_id()){ // owned by player
                    startpieceList.push_back(currentCoord);
                }
            }
        }
    }

    return startpieceList;
}

// random legal moves
bool Computer::make_move(int rank1, int file1, int rank2, int file2){
    std::vector<std::pair<Coordinate, Coordinate>> moveList = find_moves(find_pieces()); // generate move list
    // checkmate / stalemate
    if (moveList.size() == 0){
        return false;
    }

    int randInd = std::rand() % moveList.size(); // generate random move index

    // assign from coordinates
    int fromRow = moveList[randInd].first.get_rank();
    int fromFile = moveList[randInd].first.get_file();

    // assign to coordinates
    int toRow = moveList[randInd].second.get_rank();
    int toFile = moveList[randInd].second.get_file();

    get_game()->get_boards()->get_coord(fromRow, fromFile).get_pc()->move(get_game()->get_boards()->get_coord(toRow, toFile)); // make move from piece in game
    get_game()->get_boards()->get_coord(fromRow, fromFile).get_pc().reset() ; // delete piece from original position
    return true;

}

