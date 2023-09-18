#ifndef QUEEN_H
#define QUEEN_H

#include"Piece.h"
class Queen : public Piece {
    public:
    Queen(int rank, int file, Player* owner, bool hasMoved): Piece{rank, file, owner, hasMoved}{}
    char get_type() override;
    bool canMove(Coordinate cd) override;
};

#endif



