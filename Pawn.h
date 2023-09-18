#ifndef PAWN_H
#define PAWN_H
#include <memory>

#include"Piece.h"
class Pawn : public Piece {
    public:
    bool ifWeak;
    Pawn(int rank, int file, Player* owner, bool hasMoved, bool ifWeak): Piece{rank, file, owner, hasMoved}, ifWeak{ifWeak}{}
    char get_type() override;
    std::shared_ptr<Piece> promote(char pieceT);
    bool canMove(Coordinate cd) override;
};

#endif



