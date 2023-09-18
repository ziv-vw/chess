#ifndef KNIGHT_H
#define KNIGHT_H


#include"Piece.h"
class Knight : public Piece {
    public:
    Knight(int rank, int file, Player* owner, bool hasMoved): Piece{rank, file, owner, hasMoved}{}
    char get_type() override;
    bool canMove(Coordinate cd) override;
};

#endif



