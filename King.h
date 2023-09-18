#ifndef KING_H
#define KING_H

#include "Piece.h"

class Coordinate;

class King : public Piece {
    public:
    King(int rank, int file, Player* owner, bool hasMoved): Piece{rank, file, owner, hasMoved}{}
    char get_type();
    bool canMove(Coordinate cd) override;
};

#endif



