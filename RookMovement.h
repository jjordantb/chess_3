/*
 * RookMovement.h
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#ifndef ROOKMOVEMENT_H_
#define ROOKMOVEMENT_H_

#include "Movement.h"

class RookMovement : public Movement {
public:
	RookMovement(){};
	virtual ~RookMovement(){};
	std::vector<const Coord*> path(const Coord* s, const Coord* e);
};

#endif /* ROOKMOVEMENT_H_ */
