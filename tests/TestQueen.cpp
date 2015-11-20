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

void TestQueen::testMovement() {
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

  //Ends
  //diagonal
  board->movePiece(board->getSquare(2, 2), board->getSquare(0, 0));
  CPPUNIT_ASSERT(board->getSquare(0, 0)->getPiece() == piece);
  board->movePiece(board->getSquare(0, 0), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  board->movePiece(board->getSquare(2, 2), board->getSquare(4, 4));
  CPPUNIT_ASSERT(board->getSquare(4, 4)->getPiece() == piece);
  board->movePiece(board->getSquare(4, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Vertial
  board->movePiece(board->getSquare(2, 2), board->getSquare(4, 2));
  CPPUNIT_ASSERT(board->getSquare(4, 2)->getPiece() == piece);
  board->movePiece(board->getSquare(4, 2), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Horizontal
  board->movePiece(board->getSquare(2, 2), board->getSquare(2, 4));
  CPPUNIT_ASSERT(board->getSquare(2, 4)->getPiece() == piece);
  board->movePiece(board->getSquare(2, 4), board->getSquare(2, 2));
  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

  //Purpose failure
  // board->movePiece(board->getSquare(2, 2), board->getSquare(3, 4));
  // CPPUNIT_ASSERT(board->getSquare(3, 4)->getPiece() != piece);

}

void TestQueen::testConstructor() {

  CPPUNIT_ASSERT(board->getSquare(2, 2)->getPiece() == piece);

}
