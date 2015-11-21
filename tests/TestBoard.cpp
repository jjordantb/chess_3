/*
 * TestBoard.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */

#include "TestBoard.h"

CPPUNIT_TEST_SUITE_REGISTRATION( TestBoard );

void TestBoard::setUp() {
  board = new ChessBoard(3, 3);
  wPiece = new Piece(Piece::white, 'p', new PawnMovement());
}

void TestBoard::tearDown() {
  delete board;
}

void TestBoard::testPlacePiece() {
  //Place White
  board->placePiece(wPiece, board->getSquare(0, 1));
  CPPUNIT_ASSERT(board->getSquare(0, 1)->getPiece() != NULL);

}

void TestBoard::testMovePiece() {
  // A correct move
  board->placePiece(wPiece, board->getSquare(0, 1));
  board->movePiece(board->getSquare(0, 1), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == wPiece);
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(1, 1), board->getSquare(5, 5)), invalid_coordinates_error);
}

void TestBoard::testConstructor() {

  CPPUNIT_ASSERT(board->width == 3);
  CPPUNIT_ASSERT(board->height == 3);

}
