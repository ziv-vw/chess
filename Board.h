#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "Coordinate.h"

class Coordinate;

class Board {
private:
    std::vector<Coordinate> all_cr;

public:
    void setup();
    char display(int row, int file);
    Coordinate& get_coord(int row, int file); //accessor
};

#endif

