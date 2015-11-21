#ifndef TESTQUEEN_H
#define TESTQUEEN_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../QueenMovement.h"
#include "../Exceptions.h"

class TestQueen : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestQueen);
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

#endif //TESTQUEEN_H
