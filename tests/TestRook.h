#ifndef TESTROOK_H
#define TESTROOK_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../RookMovement.h"
#include "../Exceptions.h"

class TestRook : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestRook);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testHorizontal);
  CPPUNIT_TEST(testVertical);
  CPPUNIT_TEST(testDiagonal);
  CPPUNIT_TEST(testOther);
  CPPUNIT_TEST_SUITE_END();

private:
  Board *board;
  Piece *piece;

public:
  void setUp();
  void tearDown();
  void testHorizontal();
  void testVertical();
  void testDiagonal();
  void testOther();
  void testConstructor();

};

#endif //TESTROOK_H
