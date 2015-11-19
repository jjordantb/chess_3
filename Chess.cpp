/*
 * Chess.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: anvik
 */

#include "Chess.h"
#include "ChessBoard.h"
#include "Exceptions.h"
#include "KingMovement.h"
#include "PawnMovement.h"
#include "RookMovement.h"
#include "BishopMovement.h"
#include "QueenMovement.h"
#include <iostream>
#include <assert.h>
#include <sstream>

#define SIZE 6

Chess::Chess() {
	board = new ChessBoard(SIZE, SIZE);

	// Create King pieces
	bKing = new Piece(Piece::black, 'K', new KingMovement);
	wKing = new Piece(Piece::white, 'k', new KingMovement);

	// Create Rook pieces
	for (int i = 0; i < 2; i++) {
		bRooks.push_back(new Piece(Piece::black, 'R', new RookMovement));
		wRooks.push_back(new Piece(Piece::white, 'r', new RookMovement));
	}

	// Create Bishop pieces
	for (int i = 0; i < 2; i++) {
		bBishops.push_back(new Piece(Piece::black, 'B', new BishopMovement));
		wBishops.push_back(new Piece(Piece::white, 'b', new BishopMovement));
	}

	// Create Queen pieces
	bQueen = new Piece(Piece::black, 'Q', new QueenMovement);
	wQueen = new Piece(Piece::white, 'q', new QueenMovement);

	// Create Pawn pieces
	for (int i = 0; i < 6; i++) {
		bPawns.push_back(new Piece(Piece::black, 'P', new PawnMovement));
		wPawns.push_back(new Piece(Piece::white, 'p', new PawnMovement));
	}

}

Chess::~Chess() {

	delete wKing;
	delete bKing;
	delete wQueen;
	delete bQueen;

	for (int i = 0; i < 2; i++) {
		delete bRooks.at(i);
		delete wRooks.at(i);
		delete bBishops.at(i);
		delete wBishops.at(i);
	}

	for (int i = 0; i < 6; i++) {
		delete bPawns.at(i);
		delete wPawns.at(i);
	}

	delete board;
}

void Chess::setup() const {
	// Black side
	board->placePiece(bKing, board->getSquare(5, 2));
	board->placePiece(bQueen, board->getSquare(5, 3));
	board->placePiece(bRooks.at(0), board->getSquare(5, 0));
	board->placePiece(bRooks.at(1), board->getSquare(5, 5));
	board->placePiece(bBishops.at(0), board->getSquare(5, 1));
	board->placePiece(bBishops.at(1), board->getSquare(5, 4));
	for (int i = 0; i < 6; i++)
		board->placePiece(bPawns.at(i), board->getSquare(4, i));

	// White side
	board->placePiece(wKing, board->getSquare(0, 2));
	board->placePiece(wQueen, board->getSquare(0, 3));
	board->placePiece(wRooks.at(0), board->getSquare(0, 0));
	board->placePiece(wRooks.at(1), board->getSquare(0, 5));
	board->placePiece(wBishops.at(0), board->getSquare(0, 1));
	board->placePiece(wBishops.at(1), board->getSquare(0, 4));
	for (int i = 0; i < 6; i++)
		board->placePiece(wPawns.at(i), board->getSquare(1, i));

	turn = 0;
	numPlayers = 2;
}

/**
 * Game is over if one of the kings is killed
 */
bool Chess::isOver() const {

	return (wKing->isAlive() == false || bKing->isAlive() == false);
}

Square* Chess::getSquare(std::istream &is) const {

	std::string input_line;
	getline(is, input_line);
	std::istringstream iss(input_line);

	int row, col;
	if (!(iss >> row >> col)) {
		throw invalid_format_error("Incorrect coordinate entry format");
	}

	if (0 > row || row >= SIZE) {
		std::ostringstream s;
		s << "Row off board: " << row;
		throw invalid_coordinates_error(s.str().c_str());
	}
	if (0 > col || col >= SIZE) {
		std::ostringstream s;
		s << "Column off board: " << col;
		throw invalid_coordinates_error(s.str().c_str());
	}

	return board->getSquare(row, col);
}

