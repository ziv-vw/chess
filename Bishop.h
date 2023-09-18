#ifndef BISHOP_H
#define BISHOP_H

#include"Piece.h"

class Bishop : public Piece {
    public:
    Bishop(int rank, int file, Player* owner, bool hasMoved): Piece{rank, file, owner, hasMoved}{} // constructor
    char get_type() override; //accessors
    bool canMove(Coordinate cd) override;
};

#endif



