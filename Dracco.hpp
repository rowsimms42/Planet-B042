#ifndef Dracco_hpp
#define Dracco_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Dracco : public Space
{
protected:
	int hat;
public:
	Dracco();
	void getDescription();
	void playGame(Player*);
};


#endif