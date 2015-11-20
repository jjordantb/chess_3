/*
 * Square.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: anvik
 */

#include "Square.h"
#include "Exceptions.h"
#include <stdlib.h>

Square::Square(): row{-1}, col{-1}, piece{NULL} {}

Square::Square(const int r=-1, const int c=-1): row{r}, col{c}
{
	piece = NULL;
}

void Square::setPiece(Piece* p) {
	/**
	 * If a piece exists on this square, kill it
	 */
	if (piece != NULL) {
		if (p->player == piece->player)
			throw invalid_move_error("Taking own piece");
		piece->kill();
	}
	piece = p;
}

Piece* Square::removePiece() {
	Piece* p = piece;
	piece = NULL;
	return p;
}

const char Square::symbol() const {
	if (piece != NULL)
		return piece->symbol;
	else
		return EMPTY;
}

Piece* Square::getPiece() const {
	return piece;
}

/*
const Square& Square::operator=(const Square& s){
	this->row = s.row;
	this->col = s.col;
	return *this;
}
*/
