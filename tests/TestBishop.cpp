/*
 * TestBishop.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */


#include "TestBishop.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestBishop);

void TestBishop::setUp() {
  board = new ChessBoard(4, 4);
  piece = new Piece(Piece::white, 'b', new BishopMovement());
  board->placePiece(piece, board->getSquare(0, 0));
}

void TestBishop::tearDown() {
  delete board;
  delete piece;
}

void TestBishop::testHorizontal() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(0, 0), board->getSquare(0, 1)), invalid_move_error);
}

void TestBishop::testVertical() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(0, 0), board->getSquare(1, 0)), invalid_move_error);
}

void TestBishop::testDiagonal() {
  board->movePiece(board->getSquare(0, 0), board->getSquare(3, 3));
  CPPUNIT_ASSERT(board->getSquare(3, 3)->getPiece() == piece);

  board->movePiece(board->getSquare(3, 3), board->getSquare(0, 0));
  CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);

  board->movePiece(board->getSquare(0, 0), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 2), board->getSquare(3, 1));
  CPPUNIT_ASSERT(board->getSquare(3, 1)->getPiece() == piece);

  board->movePiece(board->getSquare(3, 1), board->getSquare(1, 3));
  CPPUNIT_ASSERT(board->getSquare(1, 3)->getPiece() == piece);

  board->movePiece(board->getSquare(1, 3), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestBishop::testOther() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(0, 0), board->getSquare(2, 3)), invalid_move_error);
}

void TestBishop::testConstructor() {
  CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);
}
