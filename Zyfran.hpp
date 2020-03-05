#ifndef Zyfran_hpp
#define Zyfran_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Zyfran : public Space
{
protected:
	int crystal;
public:
	Zyfran();
	void getDescription();
	void playGame(Player*);
};


#endif