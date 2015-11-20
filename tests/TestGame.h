#ifndef TESTGAME_H
#define TESTGAME_H

#include <cppunit/extensions/HelperMacros.h>

#include "../Game.h"

class TestGame : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestGame);
  CPPUNIT_TEST(testConstructor);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();
  void testConstructor();

};

#endif //TESTGAME_H
