// std
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
// game
#include "Board.h"
#include "Game.h"
#include "Piece.h"
#include "player.h"
// displays
#include "Display.h"
#include "displayType.h"


using namespace std;

int main() {
	double scores[2] = {0};
	bool endss = false;

	while(endss == false) { //mutiple games
		int turn = 0;
		string command;

		// game environment variables
		bool set_up = false;
		bool game_end = false;

		// temporary variables for set up 
		vector <int> ranks;
		vector <int> files;
		vector <char> pcs;

		// game state variables
		set_up = false;
		game_end = false;

		// game variables
		Player *p1 = nullptr;
		Player *p2 = nullptr;
		Game *game = nullptr;
		Display display;
		std::shared_ptr<displayType> text;
		bool has_game = false;

		while (true) {
			if (game_end) break;
			// taking input

			// variable setting
			cin >> command;
			if (cin.eof()) {
				game_end = true;
				endss = true; 
				break;
			}
			// creation of standard game
			if (command == "game") {
				string player; // cin variable
				cin >> player;
				string player1 = player;
				cin >> player;
				string player2 = player;
				bool inv = false;
				if(!((player1 == "human" || player1 == "computer[1]") && (player2 == "human" || player2 == "computer[1]"))){
					cout << "Invalid input for player, disgarded" << endl;
					inv = true;
				} else {
					Board *board = new Board;
					board->setup();
					game = new Game{board}; // game variable


					// display variables
					text = std::shared_ptr<displayType>(new textDisplay(game));
					display.addDisplay(text);

					// player1 selection
					if(player1 == "human") {
						Player *p = new Human{0, game};
						p1 = p;
					} else if (player1 == "computer[1]") {
						Player *p = new Level1{0, game};
						p1 = p;
						//} else if (player == "computer[2]") {
						//Level2 p{0, game};
						//p1 = &p;
						//} else if (player == "computer[3]") {
						//Level3 p{0, game};
						//p1 = &p;
						//} else if (player == "computer[4]") {
						//Level4 p{0, game};
						//p1 = &p;
				}

				// player2 selection
				if(player2 == "human") {
					Player* q = new Human{1, game};
					p2 = q;
				} 
				else if (player2 == "computer[1]") {
					Player *q = new Level1{1, game};
					p2 = q;
					// } else if (player == "computer[2]") {
					// Level2 p{1, game};
					// p2 = &p;
					// } else if (player == "computer[3]") {
					// Level3 p{1, game};
					// p2 = &p;
					// } else if (player == "computer[4]") {
					// Level4 p{1, game};
					// p2 = &p;
				} 
				// set up board for normal game
				if (set_up == false) {
					turn = 0;
					for (int i = 0; i < 8; i++) {
						game->add('P', 1, i, p1);
					}
					game->add('R', 0, 0, p1);
					game->add('R', 0, 7, p1);
					game->add('N', 0, 1, p1);
					game->add('N', 0, 6, p1);
					game->add('B', 0, 2, p1);
					game->add('B', 0, 5, p1);
					game->add('Q', 0, 3, p1);
					game->add('K', 0, 4, p1);
					for (int i = 0; i < 8; i++) {
						game->add('p', 6, i, p2);
					}
					game->add('r', 7, 0, p2);
					game->add('r', 7, 7, p2);
					game->add('n', 7, 1, p2);
					game->add('n', 7, 6, p2);
					game->add('b', 7, 2, p2);
					game->add('b', 7, 5, p2);
					game->add('q', 7, 3, p2);
					game->add('k', 7, 4, p2);
					turn = 0;
					display.notifyDisplays();

				} else {
					for (int i = 0; i < ranks.size(); i++) {
						if ('A' <= pcs[i] && pcs[i] <= 'Z') {
							game->add(pcs[i], ranks[i], files[i], p1);
						} else {
							game->add(pcs[i], ranks[i], files[i], p2);
						}
					}
					display.notifyDisplays();
				}
				}
				has_game = true;
			} 

			// setup mode
			else if (command  == "setup") {
				cin >> command;
				if (cin.eof()) {
					endss = true; 
					game_end = true;
					break;
				}
				while (true) {
					char op;
					char temp;
					int rank = -1;
					int file = -1;
					string s;
					if (command == "done") {
						bool hask = false;
						bool hasK = false;
						for (int i = 0; i < pcs.size(); i++) {
							if (pcs[i] == 'k') {
								hask = true;
							} else if (pcs[i] == 'K') {
								hasK = true;
							}
						}
						if (hask == false || hasK == false) {
							cout << "Not two king on board, please keep adding." << endl;
						} else {
							break;
						}
					}
					// adding piece
					if (command == "+") {
						cin >> s;
						istringstream is{s};
						is >> op;
						cin >> s;
						istringstream is2{s};
						is2 >> temp;
						file = temp - 'a';
						is2 >> rank;	
						rank = rank - 1;
						bool invalid = false;

						if (op == 'k') {
							for (int i = 0; i < pcs.size(); i++) {
								if (pcs[i] == 'k') {
									invalid = true;
									break;
								}
							} 
						} else if (op == 'K') {
							for (int i = 0; i < pcs.size(); i++) {
								if (pcs[i] == 'K') {
									invalid = true;
									break;
								}
							}
						} else if (op == 'p' || op == 'P') {
							if (rank == 0 || rank == 7) {
								invalid = true;
							}
						}
						for (int i = 0; i < pcs.size(); i++) {
							if (ranks[i] == rank && files[i] == file) {
								invalid = true;
								break;
							}
						}
						if (!((op =='k' || op =='K' || op =='p' || op =='P' || op =='Q' || op =='q' 
										|| op =='N' || op =='n' || op =='B' || op =='b' || op =='R' || op =='r') 
									&& 0 <= rank && rank <= 7 && 0 <= file && file <= 7 )) {
							invalid = true;
						}
						if (invalid == false) {

							ranks.emplace_back(rank);
							files.emplace_back(file);
							pcs.emplace_back(op);
						} else {
							cout << "Invalid action, disgarded." << endl;
						}

						// removal of piece
					} else if (command == "-") {
						cin >> s;
						istringstream is{s};
						is >> temp;
						file = temp - 'a';
						is >> rank;
						rank = rank - 1;
						for (int i = 0; i < ranks.size(); i++) {
							if (ranks[i] == rank && files[i] == file) {
								ranks.erase(ranks.begin() + i);
								files.erase(files.begin() + i);
								pcs.erase(pcs.begin() + i);
							}
						}

						// set color
					} else if (command == "=") {
						//use int to represent color, convenient for more players
						if (turn == 0 || turn == 1) {
							cin >> turn;
						} else {
							cout << "Invalid action, disgarded." << endl;
						}
					} else {
						cout << "Invalid input command" << endl;
					}
					cin >> command;
					if (cin.eof()) {
						endss = true; 
						game_end = true;
						break;
					}
				}
				set_up = true;
			} else if (command == "move") {	
				if (has_game == false) {
					cout << "Please initialize a game first." << endl; 
				} else {	
					//find whose turn
					Player *ptr;
					if (turn % 2 == 0) {
						ptr = p1;
					} else {
						ptr = p2;
					}
					//declare variables
					string coor;
					char temp;
					int rank;
					int file;
					int rank2;
					int file2;

					//distinguish type of player
					//computer don't need to read from input
					/*if (ptr->get_type() == 'C') {
					  rank = 0;
					  file = 0;
					  rank2 = 0;
					  file2 = 0;
					  }*/

					//human read from input and convert to corresponding variable
					cin >> coor;
					istringstream is{coor};
					is >> temp;
					file = temp - 'a';
					is >> rank;
					rank = rank - 1;
					cin >> coor;
					istringstream is2{coor};
					is2 >> temp;
					file2 = temp - 'a';
					is2 >> rank2;
					rank2 = rank2 - 1;

					//decide if the input is valid
					if(!( 0 <= rank && rank <= 7 && 0 <= file && file <= 7 &&  0 <= rank2 && rank2 <= 7 && 0 <= file2 && file2 <= 7)){
						cout << "Invalid action, disgarded." << endl;
					} else { //move
						//decide whose turn to move

						//move

						if(ptr->make_move(rank, file, rank2, file2) == true) {
							//if succeed, change turn and display
							turn++;
							display.notifyDisplays();

							//decide whether this move will lead to the end of game or checking
							Player *ptr;
							if (turn % 2 == 0) {
								ptr = p1;
							} else {
								ptr = p2;
							}
							int endgame = game->endGame(ptr);
							if (endgame != 0) { // game ends
								
								if (endgame == 1) {
									scores[turn  % 2] += 0.5;
									scores[(turn + 1) % 2] += 0.5;
									cout << "Stalemate." << endl;
									game_end = true;
								} else if(endgame == 2){
									scores[(turn + 1) % 2]++;
									if (turn % 2 == 1) {
										cout << "Checkmate! White wins!" << endl;
									} else {
										cout << "Checkmate! Black wins!" << endl;
										game_end = true;
									}
								} else {
									if (turn % 2 == 1) {
										cout << "Black is in check." << endl;
									} else {
										cout << "White is in check." << endl;
									}
								}
								// delete heap allocated objects
								delete game->get_boards();
								delete game;
								delete p1;
								delete p2; 
							}
						} else {
							cout << "invalid move, please try again." << endl;
						}
					}
				}
			} else if (command == "resign") { // resignation ends game
				game_end = true;
				scores[(turn + 1) % 2]++;
				if (turn % 2 == 1) {
					cout << "White wins!" << endl;
				} else {
					cout << "Black wins!" << endl;
				}
			
			// delete heap allocated objects
			delete game->get_boards();
			delete game;
			delete p1;
			delete p2;

			} else {
				cout << "Invalid input command. Please try again." << endl;
			}
		}

	}
	cout << "Final Score:" << endl;
	cout << "White: " << scores[0] << endl;
	cout << "Black: " << scores[1] << endl;
	return 0;
}

