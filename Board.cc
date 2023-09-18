#include <iostream>
#include <memory>
#include <vector>
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"
//#include "King.h"

using namespace std;
//empty board without any piece
void Board::setup(){
    // board creation
    //shared_ptr<Piece> uni = make_shared<King>(King{-1, -1, nullptr, false});
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            // 0 is '_', 1 is ' '
            if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0)) {  // black squares?
                all_cr.push_back(Coordinate{i, j, nullptr, 0});
            }
            else { // white squres?
                all_cr.push_back(Coordinate{i, j, nullptr, 1});
            }
        }
    }
}

// Board display
char Board::display(int row, int file){
    // no piece case -> display underlying board
    if (all_cr[8*row+file].has_piece() == false){
        if (all_cr[8*row+file].get_color() == 0) {
            return '_';
        }
        else{
            return ' ';
        }
    }

    // piece retrieval
    else if (all_cr[8*row+file].get_pc()->get_owner()->get_id() == 0){
        return all_cr[8*row+file].get_pc()->get_type() - 'a' + 'A';
    }
    else {
        return all_cr[8*row+file].get_pc()->get_type();
    }
}

// reference accessor
Coordinate& Board::get_coord(int row, int file){
    return all_cr[8*row+file];
}


// delete?
/*
Board::~Board(){
    for (int i = 0; i < 64; i++){
        delete all_cr[i];
    }
}
*/



