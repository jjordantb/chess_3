#ifndef TESTKING_H
#define TESTKING_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../KingMovement.h"

class TestKing : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestKing);
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

#endif //TESTKING_H
