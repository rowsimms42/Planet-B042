#ifndef Altwin_hpp
#define Altwin_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Altwin : public Space
{
protected:
	int riddler;
public:
	Altwin();
	void getDescription();
	void playGame(Player*);
};


#endif