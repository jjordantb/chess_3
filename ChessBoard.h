/*
 * ChessBoard.h
 *
 *  Created on: Oct 7, 2015
 *      Author: anvik
 */

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "Board.h"
#include <iostream>

class ChessBoard: public Board {
public:
	ChessBoard(const int w, const int h);
	virtual ~ChessBoard(){};

	/**
	 * Provide checking for chess boards
	 */
	void movePiece(Square* s, Square* d) const;
};

#endif /* CHESSBOARD_H_ */
