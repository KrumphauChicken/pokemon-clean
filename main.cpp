#include <iostream>
#include "pokemon.h"

int main(int argc, char **argv) {

	Pokemon* bubbles = new Squirtle("Bubbles");
	Pokemon* enemy = new Blastoise;

	bubbles->attack1(enemy);

	Squirtle squirt;

	return 0;
}
