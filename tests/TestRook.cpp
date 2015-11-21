#include "TestRook.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestRook);

void TestRook::setUp() {
  board = new ChessBoard(5, 5);
  piece = new Piece(Piece::white, 'r', new RookMovement());
  board->placePiece(piece, board->getSquare(2, 2));
}

void TestRook::tearDown() {
  delete board;
  delete piece;
}

void TestRook::testHorizontal() {
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 0));
  CPPUNIT_ASSERT(board->getSquare(2, 0)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 0), board->getSquare(2, 4));
  CPPUNIT_ASSERT(board->getSquare(2, 4)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestRook::testVertical() {
  board->movePiece(board->getSquare(2, 2), board->getSquare(0, 2));
  CPPUNIT_ASSERT(board->getSquare(0, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(0, 2), board->getSquare(4, 2));
  CPPUNIT_ASSERT(board->getSquare(4, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(4, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}

void TestRook::testDiagonal() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(2, 2), board->getSquare(3, 3)), invalid_move_error);
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(2, 2), board->getSquare(0, 0)), invalid_move_error);
}

void TestRook::testOther() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(2, 2), board->getSquare(3, 4)), invalid_move_error);
}

void TestRook::testConstructor() {
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);
}
