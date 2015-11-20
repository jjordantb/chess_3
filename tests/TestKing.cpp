#include "TestKing.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestKing);

void TestKing::setUp() {
  board = new ChessBoard(5, 5);
  piece = new Piece(Piece::white, 'k', new KingMovement());
  board->placePiece(piece, board->getSquare(2, 2));
}

void TestKing::tearDown() {
  delete board;
  delete piece;
}

void TestKing::testMovement() {

  /*
   * One square moves, valid.
   */

  //Vertical
  board->movePiece(board->getSquare(2, 2), board->getSquare(3, 2));
  CPPUNIT_ASSERT(board->getSquare(3, 2)->getPiece() == piece);
  board->movePiece(board->getSquare(3, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Horizontal
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 3));
  CPPUNIT_ASSERT(board->getSquare(2, 3)->getPiece() == piece);
  board->movePiece(board->getSquare(2, 3), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Diagonal
  board->movePiece(board->getSquare(2, 2), board->getSquare(3, 3));
  CPPUNIT_ASSERT(board->getSquare(3, 3)->getPiece() == piece);
  board->movePiece(board->getSquare(3, 3), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 2), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);
  board->movePiece(board->getSquare(1, 1), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

}

void TestKing::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

}
