#ifndef ROOK_H
#define ROOK_H

#include"Piece.h"
class Rook : public Piece {
    public:
    Rook(int rank, int file, Player* owner, bool hasMoved): Piece{rank, file, owner, hasMoved}{}
    char get_type() override;
    bool canMove(Coordinate cd) override;
};

#endif



