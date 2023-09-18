#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <utility>

class Game;

class Coordinate;

// Player headers
class Player {
private:
    int id;
    Game* currentGame;

public:
    Player(int id, Game* currentGame): id{id}, currentGame{currentGame}{} // constructor

    // accessors
    int get_id();
    Game* get_game();

    virtual bool make_move(int rank1, int file1, int rank2, int file2) = 0;
};

// end of Player headers


// human header
class Human : public Player {
public:
    Human(int id, Game* currentGame) : Player(id, currentGame) {}
    bool make_move(int rank1, int file1, int rank2, int file2) override;
};


// computer header
class Computer : public Player{
public:
    Computer(int id, Game* currentGame) : Player(id, currentGame) {}

    // computer make_move will not need the position arguments to be filled, so they can just pass 0 to it
    bool make_move(int rank1, int file1, int rank2, int file2);

    std::vector<Coordinate> find_pieces(); // find starting pieces
    virtual std::vector<std::pair<Coordinate, Coordinate>> find_moves(std::vector<Coordinate> pieceList) = 0; // find all possible moves from pieces
};

// various Level headers
class Level1 : public Computer{
public:
    Level1(int id, Game* currentGame) : Computer(id, currentGame) {}
    std::vector<std::pair<Coordinate, Coordinate>> find_moves(std::vector<Coordinate> piecelist);
};

class Level2: public Computer{
public:
    Level2(int id, Game* currentGame) : Computer(id, currentGame) {}
    std::vector<std::pair<Coordinate, Coordinate>> find_moves(std::vector<Coordinate> piecelist);
};

class Level3 : public Computer{
public:
    Level3(int id, Game* currentGame) : Computer(id, currentGame) {}
    std::vector<std::pair<Coordinate, Coordinate>> find_moves(std::vector<Coordinate> piecelist);
};

class Level4 : public Computer{
public:
    Level4(int id, Game* currentGame) : Computer(id, currentGame) {}
    std::vector<std::pair<Coordinate, Coordinate>> find_moves(std::vector<Coordinate> piecelist);
};

// end of level headers

#endif

