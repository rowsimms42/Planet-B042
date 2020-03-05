#ifndef B042_hpp
#define B042_hpp
#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"

class B042 : public Space
{
protected: 
	int iceCream;
public:
	B042();
	void getDescription();
	void playGame(Player*);
	//bool iceCream;
};


#endif