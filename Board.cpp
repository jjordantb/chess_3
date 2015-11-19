/*
 * Board.cpp
 *
 *  Created on: Sep 2, 2015
 *      Author: anvik
 */

#include "Board.h"
#include <iostream>
#include <assert.h>
#include <sstream>
#include "Exceptions.h"

Board::Board(const int w, const int h) :
		height { h }, width { w } {
	board = new Square*[height];
	for (int row = 0; row < height; row++) {
		board[row] = new Square[width];
		for (int col = 0; col < width; col++) {
			board[row][col].row = row;
			board[row][col].col = col;
		}
	}
}

Board::~Board() {
	for (int row = 0; row < width; row++)
		delete[] board[row];
	delete[] board;
}

void Board::draw(std::ostream& o) const {

	/**
	 * Show the column coordinates
	 */
	o << " ";
	for (int j = 0; j < width; j++)
		o << j;

	o << std::endl;

	/**
	 * Iterate through the rows drawing the symbol for each column
	 */
	for (int i = 0; i < height; i++) {
		o << i; // Show the row coordinate
		for (int j = 0; j < width; j++) {
			Square s = board[i][j];
			o << s.symbol();
		}
		o << std::endl;
	}
}

void Board::placePiece(Piece* p, Square* s) const {
	s->setPiece(p);
}

void Board::movePiece(Square* s, Square* d) const {
	int startRow = s->row;
	int startCol = s->col;
	int endRow = d->row;
	int endCol = d->col;

	// Check that move is on board
	if (0 > startRow || startRow >= height) {
		std::ostringstream s;
		s << "Row " << startRow << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}
	if (0 > startCol || startCol >= width) {
		std::ostringstream s;
		s << "Column " << startCol << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}
	if (0 > endRow || endRow >= height) {
		std::ostringstream s;
		s << "Row " << endRow << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}
	if (0 > endCol || endCol >= width) {
		std::ostringstream s;
		s << "Column " << endCol << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}

	Piece* p = board[startRow][startCol].getPiece();
	if (p == NULL) {

		std::ostringstream s;
		s << "No piece at [" << startRow << "," << startCol << "]";
		throw invalid_piece_error(s.str().c_str());
	}

	board[endRow][endCol].setPiece(p);
	board[startRow][startCol].removePiece();
}

Square* Board::getSquare(int r, int c) const {
	if (0 > r || r >= height) {
		std::ostringstream s;
		s << "Row " << r << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}

	if (0 > c || c >= width) {
		std::ostringstream s;
		s << "Column " << c << " off board.";
		throw invalid_coordinates_error(s.str().c_str());
	}
	return &board[r][c];
}

