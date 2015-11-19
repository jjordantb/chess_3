#include "TestPawn.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestPawn);

void TestPawn::setUp() {
  board = new ChessBoard(3, 3);
  piece = new Piece(Piece::white, 'p', new PawnMovement());
  board->placePiece(piece, board->getSquare(0, 1));
}

void TestPawn::tearDown() {
  delete board;
  delete piece;
}

void TestPawn::testMovement() {

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

void TestPawn::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(0, 1)->getPiece() == piece);

}
