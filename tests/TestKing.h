/*
 * TestKing.h
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */

#ifndef TESTKING_H
#define TESTKING_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../KingMovement.h"
#include "../Exceptions.h"

class TestKing : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestKing);
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

#endif //TESTKING_H
