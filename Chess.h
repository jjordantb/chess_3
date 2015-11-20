/*
 * Chess.h
 *
 *  Created on: Sep 4, 2015
 *      Author: anvik
 */

#ifndef CHESS_H_
#define CHESS_H_

#include "Game.h"
#include <vector>

/**
 * A chess board game
 */
class Chess: public Game {
public:
	Chess();
	virtual ~Chess();
	/**
	 * Sets up the game board with pieces
	 */
	void setup() const;
	/**
	 *  The game ends when one of the King pieces is taken.
	 */
	bool isOver() const;
	/**
	 * Read the row and column for a location on the board.
	 * The row and column values are separated by a space on one line.
	 */
	Square* getSquare(std::istream &is) const;

private:
	Piece* wKing; /*!< the White King */
	Piece* bKing; /*!< the Black King */
	std::vector<Piece*> wRooks; /*!< the White Rooks */
	std::vector<Piece*> bRooks; /*!< the Black Rooks */
	std::vector<Piece*> wPawns; /*!< the White Pawns */
	std::vector<Piece*> bPawns; /*!< the Black Pawns */
	Piece* wQueen; /*!< the White Queen */
	Piece* bQueen; /*!< the Black Queen */
	std::vector<Piece*> wBishops; /*!< the White Bishops */
	std::vector<Piece*> bBishops; /*!< the Black Bishops */

	friend class TestGame;
};

#endif /* CHESS_H_ */
