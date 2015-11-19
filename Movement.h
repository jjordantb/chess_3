/*
 * Movement.h
 *
 *  Created on: Sep 4, 2015
 *      Author: anvik
 */

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include <vector>
#include <iostream>

class Coord {
public:
	Coord(int x, int y) :
			x { x }, y { y } {
	}
	const int x;
	const int y;

	virtual ~Coord() {
	}
	;
};

class Movement {
public:

	Movement() {
	}
	;
	virtual ~Movement() {
	}
	;
	virtual std::vector<const Coord*> path(const Coord* s, const Coord* e) =0;
};

#endif /* MOVEMENT_H_ */
