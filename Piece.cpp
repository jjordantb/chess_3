/*
 * Piece.cpp
 *
 *  Created on: Sep 4, 2015
 *      Author: anvik
 */

#include "Piece.h"
#include <iostream>

Piece::Piece(colour c, char s, Movement* m) :
		symbol { s }, player { c }, movement { m } {
	alive = true;
}

bool Piece::isAlive() const {
	return alive;
}

void Piece::kill() {
	alive = false;
}

Piece::~Piece(){
	delete movement;
}
