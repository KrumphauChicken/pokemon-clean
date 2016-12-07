#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
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

	void set_name(std::string s) {	// Make a set_name as a quick-fix, or
		name = s;					// move name to protected.
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);

	//friend Pokemon* make_pokemon(int index, std::string);

	virtual int attack1(Pokemon *) = 0;
	virtual int attack2(Pokemon *) = 0;

};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);
protected:
	virtual int attack1(Pokemon*); /* NOTE: Making this protected means that
	 * I cannot use attack1 from a plain, non-pointerized instance of any
	 * of the subclasses of Water (even though one can still be defined),
	 * and must use a Pokemon pointer to a Squirtle or other water species. */
};

class Grass: public Pokemon {
public:
	Grass(int index);
};

class Squirtle: public Water {
public:
	Squirtle(std::string s = "Squirtle"): Water(7) {set_name(s);}
	int attack2(Pokemon*);
};

class Wartortle: public Water {
public:
	Wartortle(std::string s = "Wartortle"): Water(8) {set_name(s);}
	int attack2(Pokemon*);
};

class Blastoise: public Water {
public:
	Blastoise(std::string s = "Blastoise"): Water(9) {set_name(s);}
	int attack1(Pokemon*);
	int attack2(Pokemon*);
};

Pokemon* make_pokemon(int index);

#endif // POKEMON_H
