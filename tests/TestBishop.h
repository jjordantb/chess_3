/*
 * TestBishop.h
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */

#ifndef TESTBISHOP_H
#define TESTBISHOP_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Piece.h"
#include "../ChessBoard.h"
#include "../BishopMovement.h"
#include "../Exceptions.h"

class TestBishop : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestBishop);
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

#endif //TESTBISHOP_H
