/*
 * ChessBoard.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: anvik
 */

#include "ChessBoard.h"
#include "Game.h"
#include "Exceptions.h"

ChessBoard::ChessBoard(const int w, const int h) :
		Board(w, h) {
}

void ChessBoard::movePiece(Square* s, Square* d) const {
	// Call base class version for generic validation
	Board::movePiece(s, d);

	// Move piece back in case there is an issue
	Piece* p = board[d->row][d->col].getPiece();
	board[s->row][s->col].setPiece(p);
	board[d->row][d->col].removePiece();

	// Check it is player's piece to move
	if (p->player == Piece::white && Game::turn % 2 != 0)
		throw invalid_move_error("Black moving white");
	if (p->player == Piece::black && Game::turn % 2 != 1)
		throw invalid_move_error("White moving black");

	// Check nothing in way
	const Coord* sCoord = new Coord(s->col, s->row);
	const Coord* eCoord = new Coord(d->col, d->row);
	Movement* m = p->movement;
	std::vector<const Coord*> piecePath = m->path(sCoord, eCoord);
	for (unsigned i = 1; i < piecePath.size(); i++) {
		const Coord* c = piecePath.at(i);
		Piece* p = getSquare(c->y, c->x)->getPiece();
		if (p != NULL)
			throw invalid_move_error("Cannot jump over pieces.");
	}

	for (unsigned int i = 0; i < piecePath.size(); i++)
		delete piecePath.at(i);

	if ((p->symbol == 'p' && sCoord->y > eCoord->y)
		|| (p->symbol == 'P' && sCoord->y < eCoord->y)) {
				throw invalid_move_error("Pawn cannot move backwards.");
	}

	board[d->row][d->col].setPiece(p);
	board[s->row][s->col].removePiece();
}
