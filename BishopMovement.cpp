/*
 * BishopMovement.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#include "BishopMovement.h"
#include "Exceptions.h"

std::vector<const Coord*> BishopMovement::path(const Coord* s, const Coord* e) {
	if (s->x == e->x || s->y == e->y)
		throw invalid_move_error("Bishops can only move diagonally");

	int xDirection = (s->x < e->x) ? 1 : -1;
	int yDirection = (s->y < e->y) ? 1 : -1;

	std::vector<const Coord*> path;
	for (int x = s->x, y = s->y; x != e->x + 1;
			x += xDirection, y += yDirection) {
		path.push_back(new Coord(x, y));
	}

	// Delete s and e, as they were recreated
	delete s;
	delete e;

	return path;
}
