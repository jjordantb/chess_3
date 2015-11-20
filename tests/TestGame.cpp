#include "TestGame.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TestGame);

void TestGame::setUp() {
  game = new Chess();
}

void TestGame::tearDown() {
  delete game;
}

void TestGame::testConstructor() {
  CPPUNIT_ASSERT(game != NULL);
}

void TestGame::testSetup() {

}

void TestGame::testIsOver() {
  // Setup the board
  game->setup();
  game->board->getSquare(0, 2)->removePiece();
  game->board->draw(std::cout);
  CPPUNIT_ASSERT(game->isOver());

}

void TestGame::testTurn() {

}

void TestGame::testPlay() {

}
