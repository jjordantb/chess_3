/*
 * TestGame.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: Jordan Florchinger
 */

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
  game->setup();

  for (size_t r = 0; r < 2; r++) {
    for (size_t c = 0; c < 6; c++) {
      CPPUNIT_ASSERT(game->board->getSquare(r, c)->getPiece() != NULL);
    }
  }

  for (size_t r = 4; r < 6; r++) {
    for (size_t c = 0; c < 6; c++) {
      CPPUNIT_ASSERT(game->board->getSquare(r, c)->getPiece() != NULL);
    }
  }

}

void TestGame::testIsOver() {
  game->board->placePiece(game->bKing, game->board->getSquare(5, 2));
  game->board->placePiece(game->wPawns.at(0), game->board->getSquare(4, 2));
  game->board->movePiece(game->board->getSquare(4, 2), game->board->getSquare(5, 2));
  CPPUNIT_ASSERT(game->isOver());
}

void TestGame::testTurn() {
  game->setup();
  CPPUNIT_ASSERT(game->numPlayers == 2);
  CPPUNIT_ASSERT(game->turn == 0);
}
