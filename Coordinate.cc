#include <iostream>
#include <memory>
#include "Coordinate.h"
#include "Piece.h"

using namespace std;

int Coordinate::get_rank() {
    return rank;
}

int Coordinate::get_file() {
    return file;
}

shared_ptr<Piece>& Coordinate::get_pc(){
    return pc;
}

//extra function for solution 2
/*
void Coordinate::set_pc(std::shared_ptr<Piece> new_pc){
    pc = new_pc;
    cout << new_pc << endl;
    cout << pc << endl;
}
*/

int Coordinate::get_color() {
    return color;
}

bool Coordinate::has_piece(){
    if(pc == nullptr){
        return false;
    }
    else {
        return true;
    }
}





