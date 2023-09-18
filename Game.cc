#include<iostream>
#include <memory>
#include "Game.h"
#include "Board.h"
#include "Coordinate.h"
#include "Rook.h"
#include "Queen.h"
#include "Piece.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Bishop.h"
using namespace std;

int Game::endGame(Player * player) {
	bool canmove = false;
	bool check;
	bool find = false;
	bool temp_find = false;
	//find king
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Coordinate &temp_king = get_boards()->get_coord(i, j);
			if (temp_king.has_piece() == true && temp_king.get_pc()->get_type() == 'k' && temp_king.get_pc()->get_owner() == player) {
				//check if it is a checking situation
				for (int i = 0; i < 8; i++) {
					for (int j = 0; j < 8; j++) {
						Coordinate temp = get_boards()->get_coord(i, j);
						if (temp.has_piece() == true && temp.get_pc()->canMove(temp_king) == true) {
							temp_find = true;
							check = true;
							break;
						}
					}
					if (temp_find == true) break;
				}
				find = true;
				break;
			}
		}
		if (find == true) break;
	}


	find = false;




	//check if there is any legal move available
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//find the pieces that belong to player
			if (board->get_coord(i, j).has_piece() == true && board->get_coord(i, j).get_pc()->get_owner() == player) {
				for (int m = 0; m < 8; m++) {
					for (int n = 0; n < 8; n++) {
						//for a random coord (m,n), decide whether pc can move to that coord
						if (board->get_coord(i, j).has_piece() == true && board->get_coord(i, j).get_pc()->canMove(board->get_coord(m, n)) == true &&
								board->get_coord(i, j).get_pc()->checking(board->get_coord(m, n)) == false) {
							canmove = true;
							break;
						}
					}
					if (canmove == true) break;
				}       
				if (canmove == true) break;
			}
		}
		if (canmove == true) break;
	}
	if(check == true && canmove == false) { //checkmate
		return 2;
	} else if (canmove == false) {
		return 1; // stalemate
	} else if (check == true && canmove == true){
		return 3;  //check
	}
	return 0;
}


//add specific pieces to a specific coordinate
void Game::add(char op, int rank, int file, Player * player){

	if (op == 'K' || op == 'k'){    
		//shared_ptr <Piece> temp = make_shared<King>(rank, file, player, false); 
		//get_boards()->get_coord(rank, file).get_pc().swap(temp);    

		//solition 2
		//get_boards()->get_coord(rank, file).set_pc(temp);

		//solution 3
		get_boards()->get_coord(rank, file).get_pc().reset(new King{rank, file, player, false});
	}
	else if (op == 'Q' || op == 'q'){
		get_boards()->get_coord(rank, file).get_pc().reset(new Queen{rank, file, player, false});
	}
	else if (op == 'B' || op == 'b'){
		get_boards()->get_coord(rank, file).get_pc().reset(new Bishop{rank, file, player, false});
	}
	else if (op == 'R' || op == 'r'){
		get_boards()->get_coord(rank, file).get_pc().reset(new Rook{rank, file, player, false});
	}
	else if (op == 'N' || op == 'n'){
		get_boards()->get_coord(rank, file).get_pc().reset(new Knight{rank, file, player, false});
	}
	else if (op == 'P' || op == 'p'){
		get_boards()->get_coord(rank, file).get_pc().reset(new Pawn{rank, file, player, false, false});
	}

}


Board* Game::get_boards(){
	return board;
}




