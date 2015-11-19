#include "TestQueen.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestQueen);

void TestQueen::setUp() {
  board = new ChessBoard(3, 3);
  piece = new Piece(Piece::white, 'q', new QueenMovement());
  board->placePiece(piece, board->getSquare(1, 1));
}

void TestQueen::tearDown() {
  delete board;
  delete piece;
}

void TestQueen::testMovement() {
  // A correct move
  board->movePiece(board->getSquare(1, 1), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);

}

void TestQueen::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);

}
