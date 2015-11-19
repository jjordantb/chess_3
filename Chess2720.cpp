//============================================================================
// Name        : Chess2720.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include "Chess.h"

int main(void) {

	Game* g = new Chess();
	g->play();

	delete g;

	return EXIT_SUCCESS;
}
