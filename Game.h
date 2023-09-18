#ifndef GAME_H
#define GAME_H

class Player;

class Coordinate;

class Board;

class Game{
private:
    Board* board;

public:
    Game(Board* board): board{board}{} //constuctor
    int endGame(Player * player); //To check whther if the game is end
    void add(char op, int rank, int file, Player* player); //add specific pieces to a specific coordinate
    Board* get_boards(); //accessors
};

#endif

