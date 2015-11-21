/*
 * TestBoard.h
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */

#ifndef TESTBOARD_H
#define TESTBOARD_H

#include <cppunit/extensions/HelperMacros.h>

#include "../ChessBoard.h"
#include "../Piece.h"
#include "../PawnMovement.h"
#include "../Exceptions.h"

class TestBoard : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestBoard);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testPlacePiece);
  CPPUNIT_TEST(testMovePiece);
  CPPUNIT_TEST_SUITE_END();

private:
  Board *board;
  Piece* wPiece;

public:
  void setUp();
  void tearDown();

  void testPlacePiece();
  void testMovePiece();

  void testConstructor();

};

#endif //TESTBOARD_H
