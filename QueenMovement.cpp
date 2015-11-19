/*
 * QueenMovement.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#include "QueenMovement.h"
#include <stdlib.h>
#include "Exceptions.h"

std::vector<const Coord*> QueenMovement::path(const Coord* s, const Coord* e) {

	std::vector<const Coord*> path;

	if (s->x == e->x) { // vertical move
		int yDirection = (s->y < e->y) ? 1 : -1;
		for (int y = s->y; y != e->y + 1; y += yDirection) {
			path.push_back(new Coord(s->x, y));
		}
	} else if (s->y == e->y) { // horizontal move
		if (s->x != e->x) {
			int xDirection = (s->x < e->x) ? 1 : -1;
			for (int x = s->x; x != e->x + 1; x += xDirection)
				path.push_back(new Coord(x, s->y));
		}
	} else if (abs(s->x - e->x) == abs(s->y - e->y)) { // diagonal move
		int xDirection = (s->x < e->x) ? 1 : -1;
		int yDirection = (s->y < e->y) ? 1 : -1;

		for (int x = s->x, y = s->y; x != e->x + 1; x +=
				xDirection, y += yDirection)
			path.push_back(new Coord(x, y));
	} else {
		throw invalid_move_error("Not a horizontal, vertical or diagonal move");
	}

	// Delete s and e, as they were recreated
	delete s;
	delete e;

	return path;
}

