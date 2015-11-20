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

  game->board->placePiece(game->bKing, game->board->getSquare(5, 2));
  game->board->placePiece(game->wPawns.at(0), game->board->getSquare(4, 2));
  game->board->movePiece(game->board->getSquare(4, 2), game->board->getSquare(5, 2));
  CPPUNIT_ASSERT(game->isOver());

}

void TestGame::testTurn() {

}

void TestGame::testPlay() {

}
