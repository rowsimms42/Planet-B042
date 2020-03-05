
#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <string>
#include "Space.hpp"
#include "Player.hpp"
#include "B042.hpp"
#include "Dracco.hpp"

class Menu
{
private:
	bool gameOver;
	Player* player;
	Space* p_B042;
	Space* p_Dracco;
	Space* p_Navoo;
	Space* p_Altwin;
	Space* p_Zyfran;
	Space* p_Tatwan;
public:
	Menu();
	void menu();
	void checkAnswer(int*);
	void start();
	void beginningPrompt();
	//void stats();
	void cleanup();
	~Menu();
};

#endif 