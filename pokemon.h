#ifndef POKEMON_H
#define POKEMON_H

#include <fstream>
#include <string>
#include <cmath>
#include <list>

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};

struct PokeEntry {
	int number;
	char name[20];
	char type[10];
	char description[200];
	PokeEntry(int n) {
		std::ifstream entryFile(std::to_string(n) + ".txt");
		entryFile >> number;
		entryFile >> name;
		entryFile >> type;
		entryFile.seekg(1, std::ios::cur);
		entryFile.getline(description, 199);
		entryFile.close();
	};
};

class Pokemon {
private:
	std::string name;
	int level = 1;
public: PokeEntry *entry;
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
	std::list<element> weaknesses;

public:
	Pokemon(int i) {
		entry = new PokeEntry(i);
	}

	~Pokemon() {}
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}
	std::string get_species() {
		return this->entry->name;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);

	friend Pokemon* make_pokemon(element type, std::string name);

};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);
};

class Grass: public Pokemon {
public:
	Grass(int index);
};

#endif // POKEMON_H
