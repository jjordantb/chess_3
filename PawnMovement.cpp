/*
 * PawnMovement.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#include "PawnMovement.h"
#include "Exceptions.h"
#include <math.h>
#include "Game.h"

std::vector<const Coord*> PawnMovement::path(const Coord* s, const Coord* e) {
	if (s->x != e->x)
			throw invalid_move_error("Pawns move vertically");
	double distance = sqrt((abs(s->x - e->x) + abs(s->y - e->y)));
	if (distance > 1)
		throw invalid_move_error("Pawns move only 1 space");
	std::vector<const Coord*> p;
	p.push_back(s);
	p.push_back(e);
	return p;
}

