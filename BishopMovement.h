/*
 * BishopMovement.h
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#ifndef BISHOPMOVEMENT_H_
#define BISHOPMOVEMENT_H_

#include "Movement.h"

class BishopMovement: public Movement {
public:
	BishopMovement(){};
	virtual ~BishopMovement(){};
	std::vector<const Coord*> path(const Coord* s, const Coord* e);
};

#endif /* BISHOPMOVEMENT_H_ */
