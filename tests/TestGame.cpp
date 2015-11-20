#include "TestGame.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestGame);

void TestGame::setUp() {
  game = new Chess();
}

void TestGame::tearDown() {
  delete game;
}

void TestGame::testConstructor() {

}

void TestGame::testSetup() {

}

void TestGame::testIsOver() {

}

void TestGame::testTurn() {

}

void TestGame::testPlay() {

}
