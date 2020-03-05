#ifndef Tatwan_hpp
#define Tatwan_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Tatwan : public Space
{
protected:
	int queen;
	int guard;
public:
	Tatwan();
	void getDescription();
	void playGame(Player*);
};


#endif