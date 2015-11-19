#ifndef TESTROOK_H
#define TESTROOK_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../RookMovement.h"

class TestRook : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestRook);
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

#endif //TESTROOK_H
