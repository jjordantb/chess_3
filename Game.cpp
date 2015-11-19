/*
 * Game.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: anvik
 */

#include "Game.h"
#include "Exceptions.h"
#include <stdlib.h>

int Game::turn;
int Game::numPlayers;

void Game::play() {
	setup();

	board->draw(std::cout);

	while (!isOver()) {
		turn = turn % numPlayers;
		try {
			std::cout << "[Player " << turn << "] Enter location of piece to move {row col}: ";
			Square* p = getSquare(std::cin);

			std::cout << "[Player " << turn << "] Enter location of destination {row col}: ";
			Square* s = getSquare(std::cin);

			board->movePiece(p, s);

			board->draw(std::cout);
			turn++;

		} catch (invalid_coordinates_error& e) {
			std::cerr << e.what() << std::endl;
		} catch (invalid_move_error& e) {
			std::cerr << e.what() << std::endl;
		} catch (invalid_format_error& e) {
			std::cerr << e.what() << std::endl;
		} catch (invalid_piece_error& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "Game over." << std::endl;
}
