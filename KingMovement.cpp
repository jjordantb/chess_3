/*
 * KingMovement.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#include "KingMovement.h"
#include "Exceptions.h"
#include <math.h>

std::vector<const Coord*> KingMovement::path(const Coord* s, const Coord* e) {

	int xDistance = abs(s->x - e->x);
	int yDistance = abs(s->y - e->y);

	if (xDistance > 1 || yDistance > 1)
		throw invalid_move_error ("Kings can only move 1 space.");

	std::vector<const Coord*> path;
	path.push_back(s);
	path.push_back(e);
	return path;
}
