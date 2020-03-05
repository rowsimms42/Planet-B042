#ifndef Navoo_hpp
#define Navoo_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Navoo : public Space
{
protected:
	int mask;
	int dragon;
public:
	Navoo();
	void getDescription();
	void playGame(Player*);
};


#endif