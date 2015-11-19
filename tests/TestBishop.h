#ifndef TESTBISHOP_H
#define TESTBISHOP_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../BishopMovement.h"

class TestBishop : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestBishop);
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

#endif //TESTBISHOP_H
