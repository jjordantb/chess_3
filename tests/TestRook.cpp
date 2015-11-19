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

void TestRook::testMovement() {

  // A correct move
  // Horizontal
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 0));
  CPPUNIT_ASSERT(board->getSquare(2, 0)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 0), board->getSquare(2, 4));
  CPPUNIT_ASSERT(board->getSquare(2, 4)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Vertical
  board->movePiece(board->getSquare(2, 2), board->getSquare(0, 2));
  CPPUNIT_ASSERT(board->getSquare(0, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(0, 2), board->getSquare(4, 2));
  CPPUNIT_ASSERT(board->getSquare(4, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(4, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  // Diagonal / Other move for error
  // board->movePiece(board->getSquare(2, 2), board->getSquare(3, 3));
  // CPPUNIT_ASSERT(board->getSquare(3, 3)->getPiece() == piece);

  // board->movePiece(board->getSquare(2, 2), board->getSquare(0, 0));
  // CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);

  // board->movePiece(board->getSquare(2, 2), board->getSquare(3, 4));
  // CPPUNIT_ASSERT(board->getSquare(3, 4)->getPiece() == piece);

}

void TestRook::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

}
