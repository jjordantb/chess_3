/*
 * Piece.h
 *
 *  Created on: Sep 3, 2015
 *      Author: anvik
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <vector>
#include "Movement.h"

/**
 * A piece on the board of the game
 */
class Piece {
public:
	/**
	 * Enumeration for colour of piece
	 */
	enum colour {black, white};

	/**
	 * @param c the colour of the piece
	 * @param s the symbol for the piece
	 */
	Piece(const colour c, const char s, Movement* m);
	virtual ~Piece();
	/**
	 * @return true if the piece is still active on the board, false otherwise.
	 */
	bool isAlive() const;
	/**
	 * Sets the piece to be inactive on the board
	 */
	void kill();

	/**
	 * Symbol for the piece
	 */
	const char symbol;

	/**
	 * Colour of the piece
	 */
	const colour player;

	/**
	 * How the piece moves
	 */
	Movement* movement;

private:
	bool alive; /*!< Indicates if the piece is still active in the game */

};

#endif /* PIECE_H_ */
