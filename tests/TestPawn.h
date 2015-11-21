#ifndef TESTPAWN_H
#define TESTPAWN_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../PawnMovement.h"
#include "../Exceptions.h"

class TestPawn : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestPawn);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testForward);
  CPPUNIT_TEST(testReverse);
  CPPUNIT_TEST(testDiagonal);
  CPPUNIT_TEST_SUITE_END();

private:
  Board *board;
  Piece *piece;

public:
  void setUp();
  void tearDown();
  void testForward();
  void testReverse();
  void testDiagonal();
  void testConstructor();

};

#endif //TESTPAWN_H
