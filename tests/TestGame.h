#ifndef TESTGAME_H
#define TESTGAME_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Game.h"
#include "../Chess.h"

class TestGame : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestGame);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST(testSetup);
  CPPUNIT_TEST(testIsOver);
  CPPUNIT_TEST(testTurn);
  CPPUNIT_TEST(testPlay);
  CPPUNIT_TEST_SUITE_END();

private:
  Game* game;

public:
  void setUp();
  void tearDown();

  void testConstructor();

  void testSetup();
  void testIsOver();
  void testTurn();
  void testPlay();

};

#endif //TESTGAME_H
