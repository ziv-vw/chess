#include "displayType.h"
#include <iostream>
#include "Game.h"
#include "Board.h"


void textDisplay::update(){
    Board* board = game->get_boards(); // set board variable

    // loop through dimensions of board, print each space
    for (int i = 7; i >= 0; --i){
        std::cout << i + 1 << " ";
        for (int j = 0; j <= 7; ++j){
            std::cout << board->display(i, j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "  abcdefgh" << std::endl;
}

int textDisplay::get_id(){
    return 0;
}

