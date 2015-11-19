/*
 * RookMovement.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#include "RookMovement.h"
#include "Exceptions.h"

std::vector<const Coord*> RookMovement::path(const Coord* s, const Coord* e) {
	if (s->x != e->x && s->y != e->y)
		throw invalid_move_error(
				"Rooks can only move vertically or horizontally");

	std::vector<const Coord*> path;
	if (s->x != e->x) {
		int xDirection = (s->x < e->x) ? 1 : -1;
		for (int x = s->x; x != e->x + 1; x += xDirection)
			path.push_back(new Coord(x, s->y));
	} else {
		int yDirection = (s->y < e->y) ? 1 : -1;
		for (int y = s->y; y != e->y + 1; y += yDirection)
			path.push_back(new Coord(s->x, y));
	}

	// Delete s and e, as they were recreated
	delete s;
	delete e;

	return path;
}

