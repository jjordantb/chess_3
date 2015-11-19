/*
 * PawnMovement.h
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#ifndef PAWNMOVEMENT_H_
#define PAWNMOVEMENT_H_

#include "Movement.h"

class PawnMovement: public Movement {
public:
	PawnMovement(){};
	virtual ~PawnMovement(){};
	std::vector<const Coord*> path(const Coord* s, const Coord* e);
};

#endif /* PAWNMOVEMENT_H_ */
