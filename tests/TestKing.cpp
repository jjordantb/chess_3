#include "TestKing.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestKing);

void TestKing::setUp() {
  board = new ChessBoard(3, 3);
  piece = new Piece(Piece::white, 'k', new KingMovement());
  board->placePiece(piece, board->getSquare(0, 1));
}

void TestKing::tearDown() {
  delete board;
  delete piece;
}

void TestKing::testMovement() {

  // A correct move
  board->movePiece(board->getSquare(0, 1), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);

  //Throws can't move backwards exception
  // board->movePiece(board->getSquare(1, 1), board->getSquare(0, 1));
  // CPPUNIT_ASSERT(board->getSquare(0, 1)->getPiece() == NULL);

  //Throws can't move diagonal exception
  // board->movePiece(board->getSquare(1, 1), board->getSquare(2, 2));
  // CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == NULL);

}

void TestKing::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(0, 1)->getPiece() == piece);

}
