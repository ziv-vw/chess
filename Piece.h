#ifndef PIECE_H
#define PIECE_H
#include "player.h"

class Coordinate;
class Board;
class Player;

class Piece {
protected:
    int rank;
    int file;
    Player* owner;
    bool hasMoved;
public:
    Piece(int rank, int file, Player* owner, bool hasMoved): rank{rank}, file{file}, owner{owner}, hasMoved{hasMoved}{}
    void move(Coordinate &cd);
    virtual bool canMove(Coordinate cd) = 0;
    bool checking(Coordinate &cd);
    int get_rank();
    int get_file();
    bool get_hasMoved();
    Player* get_owner();
    virtual char get_type() = 0;
};

#endif



