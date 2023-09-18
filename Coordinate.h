#ifndef COORDINATE_H
#define COORDINATE_H
#include <memory>


class Piece;

class Coordinate {
private:
    std::shared_ptr<Piece> pc;
    int rank;
    int file;
    int color;

public:
    // constructors
    Coordinate() : pc{nullptr}, rank{0}, file{0}, color{0} {}
    Coordinate(int rank, int file, std::shared_ptr<Piece> pc, int color) : pc{pc}, rank{rank}, file{file}, color{color}{}
    // Coordinate(Coordinate &other): pc{std::make_unique<Piece>(*other.pc)}, rank{other.get_rank()}, file{other.get_file()}, color{other.get_color()}{}

    std::shared_ptr<Piece>& get_pc(); // mutable accessor
    int get_rank() ; //accessor
    int get_file() ; //accessor
    int get_color() ; //accessor
    bool has_piece() ; //To check whther if the coordinate has piece on it
    //extra function for solution 2
    //void set_pc(std::shared_ptr<Piece> new_pc); //mutator
};

#endif




