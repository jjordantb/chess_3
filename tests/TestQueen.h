#ifndef TESTQUEEN_H
#define TESTQUEEN_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../QueenMovement.h"

class TestQueen : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestQueen);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testMovement);
  CPPUNIT_TEST_SUITE_END();

private:
  Board *board;
  Piece *piece;

public:
  void setUp();
  void tearDown();
  void testMovement();
  void testConstructor();

};

#endif //TESTQUEEN_H
