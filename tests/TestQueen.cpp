#include "TestQueen.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestQueen);

void TestQueen::setUp() {
  board = new ChessBoard(5, 5);
  piece = new Piece(Piece::white, 'q', new QueenMovement());
  board->placePiece(piece, board->getSquare(2, 2));
}

void TestQueen::tearDown() {
  delete board;
  delete piece;
}

void TestQueen::testHorizontal() {
  //Min
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 3));
  CPPUNIT_ASSERT(board->getSquare(2, 3)->getPiece() == piece);
  board->movePiece(board->getSquare(2, 3), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Max
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 4));
  CPPUNIT_ASSERT(board->getSquare(2, 4)->getPiece() == piece);
  board->movePiece(board->getSquare(2, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestQueen::testVertical() {
  //Min
  board->movePiece(board->getSquare(2, 2), board->getSquare(3, 2));
  CPPUNIT_ASSERT(board->getSquare(3, 2)->getPiece() == piece);
  board->movePiece(board->getSquare(3, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Max
  board->movePiece(board->getSquare(2, 2), board->getSquare(4, 2));
  CPPUNIT_ASSERT(board->getSquare(4, 2)->getPiece() == piece);
  board->movePiece(board->getSquare(4, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestQueen::testDiagonal() {
  //Min
  board->movePiece(board->getSquare(2, 2), board->getSquare(3, 3));
  CPPUNIT_ASSERT(board->getSquare(3, 3)->getPiece() == piece);
  board->movePiece(board->getSquare(3, 3), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 2), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);
  board->movePiece(board->getSquare(1, 1), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Max
  board->movePiece(board->getSquare(2, 2), board->getSquare(0, 0));
  CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);
  board->movePiece(board->getSquare(0, 0), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 2), board->getSquare(4, 4));
  CPPUNIT_ASSERT(board->getSquare(4, 4)->getPiece() == piece);
  board->movePiece(board->getSquare(4, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestQueen::testOther() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(2, 2), board->getSquare(3, 4)), invalid_move_error);
}

void TestQueen::testConstructor() {
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}
