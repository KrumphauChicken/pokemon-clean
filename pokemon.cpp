#include "pokemon.h"

Fire::Fire(int index) : Pokemon(index) {
	maxHP += 1; speed += 2;
	attack += 2; defense -= 2;
	specialAttack += 4; specialDefense += 1;
	weaknesses.push_back(element::water);
}

Water::Water(int index) : Pokemon(index) {
	maxHP += 2; speed -= 1;
	attack -= 2; defense += 2;
	specialAttack -= 4; specialDefense -= 1;
	weaknesses.push_back(element::grass);
}

Grass::Grass(int index) : Pokemon(index) {
	maxHP -= 3; speed -= 2;
	attack -= 2; defense += 0;
	specialAttack -= 3; specialDefense += 0;
	weaknesses.push_back(element::fire);
}

int Water::attack1(Pokemon* target) {
	const char * attackName = "Bubble";
	int damage = 2;
	damage = target->take_damage(damage, std::list<element> {element::water});

	std::cout << this->get_name() << " used " << attackName << ". " << \
	          target->entry->name << " took " << damage << " damage!";

	return damage;
}

int Blastoise::attack1(Pokemon* target) {
	const char * attackName = "Water Pledge";
	int damage = 8;
	damage = target->take_damage(damage, std::list<element> {element::water, element::dragon});

	std::cout << this->get_name() << " used " << attackName << ". " << \
	          target->entry->name << " took " << damage << " damage!";

	return damage;
}

int Squirtle::attack2(Pokemon* target) {
	const char * attackName = "Tackle";
	int damage = 2;
	damage = target->take_damage(damage, std::list<element> {element::normal});

	std::cout << this->get_name() << " used " << attackName << ". " << \
	          target->entry->name << " took " << damage << " damage!";

	return damage;
}

int Wartortle::attack2(Pokemon* target) {
	const char * attackName = "Surf";
	int damage = 4;
	damage = target->take_damage(damage, std::list<element> {element::water});

	std::cout << this->get_name() << " used " << attackName << ". " << \
	          target->entry->name << " took " << damage << " damage!";

	return damage;
}

int Blastoise::attack2(Pokemon* target) {
	const char * attackName = "Hydro Cannon";
	int damage = 6;
	damage = target->take_damage(damage, std::list<element> {element::water});

	std::cout << this->get_name() << " used " << attackName << ". " << \
	          target->entry->name << " took " << damage << " damage!";

	return damage;
}


int Pokemon::take_damage(int damageAmount, std::list<element> damageTypes) {
	int weaknessCount = 0;
	for(auto wIt = weaknesses.begin(); wIt != weaknesses.end(); wIt++)
		for(auto dIt = damageTypes.begin(); dIt != damageTypes.end(); dIt++)
			if(*dIt == *wIt) weaknessCount++;

	damageAmount = damageAmount * (log(5 * weaknessCount + 5) / log(5));
	currentHP -= damageAmount;
	return damageAmount;
};

// With the new make_pokemon version, some of the decisions in homework 6
// are obsolete and need to be fixed, but it gets the lesson across.
Pokemon *make_pokemon(int index) {
	switch(index) {
		case 7: return new Squirtle();
		case 8: return new Wartortle();
		case 9: return new Blastoise();
		default: return nullptr;
	}
}

/*Pokemon *make_pokemon(element e, std::string n) {

	Pokemon *newPokemon;
	if(e == element::fire) {
		newPokemon = new Fire(1);
		newPokemon->name = n;
	} else if(e == element::grass) {
		newPokemon = new Grass(1);
		newPokemon->name = n;
	} else if(e == element::water) {
		newPokemon = new Water(1);
		newPokemon->name = n;
	}
	return newPokemon;

}*/
