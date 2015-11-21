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

void TestPawn::testForward() {
  board->movePiece(board->getSquare(0, 1), board->getSquare(1, 1));
  CPPUNIT_ASSERT(board->getSquare(1, 1)->getPiece() == piece);
}

void TestPawn::testReverse() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(1, 1), board->getSquare(0, 1)), invalid_piece_error);
}

void TestPawn::testDiagonal() {
  CPPUNIT_ASSERT_THROW(board->movePiece(board->getSquare(1, 1), board->getSquare(2, 2)), invalid_piece_error);
}

void TestPawn::testConstructor() {
  CPPUNIT_ASSERT(board->getSquare(0, 1)->getPiece() == piece);

}
