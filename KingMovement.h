/*
 * KingMovement.h
 *
 *  Created on: Sep 17, 2015
 *      Author: anvik
 */

#ifndef KINGMOVEMENT_H_
#define KINGMOVEMENT_H_

#include "Movement.h"
#include <vector>

class KingMovement: public Movement {
public:
	KingMovement(){};
	virtual ~KingMovement(){};
	std::vector<const Coord*> path(const Coord* s, const Coord* e);
};

#endif /* KINGMOVEMENT_H_ */
