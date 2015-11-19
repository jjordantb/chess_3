/*
 * QueenMovement.h
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#ifndef QUEENMOVEMENT_H_
#define QUEENMOVEMENT_H_

#include "Movement.h"

class QueenMovement: public Movement {
public:
	QueenMovement(){};
	virtual ~QueenMovement(){};
	std::vector<const Coord*> path(const Coord* s, const Coord* e);
};

#endif /* QUEENMOVEMENT_H_ */
