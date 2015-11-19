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

void TestBishop::testMovement() {

  // Correct moves
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

  // Incorrect moves, vertical/horizontal
  // board->movePiece(board->getSquare(2, 2), board->getSquare(3, 2));
  // CPPUNIT_ASSERT(board->getSquare(3, 2)->getPiece() != piece);
  //
  // board->movePiece(board->getSquare(2, 2), board->getSquare(2, 3));
  // CPPUNIT_ASSERT(board->getSquare(2, 3)->getPiece() != piece);

}

void TestBishop::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);

}
