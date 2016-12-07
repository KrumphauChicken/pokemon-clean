#include <iostream>
#include "pokemon.h"

int main(int argc, char **argv) {

	Pokemon* bubbles = new Squirtle("Bubbles");
	Pokemon* enemy = new Blastoise;

	bubbles->attack1(enemy);

	Pokemon* factoryTest = make_pokemon(8);
	std::cout << "\nName of factoryTest: " << factoryTest->get_name() \
	          << std::endl;

	return 0;
}
