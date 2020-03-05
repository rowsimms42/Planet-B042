#include <iostream>
#include <string>
#include <limits>
#include "Menu.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "B042.hpp"
#include "Dracco.hpp"
#include "Navoo.hpp"
#include "Altwin.hpp"
#include "Zyfran.hpp"
#include "Tatwan.hpp"
#include <vector>


Menu::Menu()
{
	
}

void Menu::start()
{

	gameOver = false;

	//////////////////////////////////////
	//initialize spaces
	player = new Player();
	p_B042 = new B042();
	p_Dracco = new Dracco();
	p_Navoo = new Navoo();
	p_Altwin = new Altwin();
	p_Zyfran = new Zyfran();
	p_Tatwan = new Tatwan();

	p_B042->setNorth(p_Dracco);
	p_B042->setSouth(nullptr);
	p_B042->setEast(nullptr);
	p_B042->setWest(nullptr);

	p_Dracco->setNorth(p_Navoo);
	p_Dracco->setSouth(p_B042);
	p_Dracco->setEast(nullptr);
	p_Dracco->setWest(nullptr);

	p_Navoo->setNorth(p_Altwin);
	p_Navoo->setSouth(p_Dracco);
	p_Navoo->setEast(nullptr);
	p_Navoo->setWest(nullptr);

	p_Altwin->setNorth(p_Zyfran);
	p_Altwin->setSouth(p_Navoo);
	p_Altwin->setEast(nullptr);
	p_Altwin->setWest(nullptr);

	p_Zyfran->setNorth(p_Tatwan);
	p_Zyfran->setSouth(p_Altwin);
	p_Zyfran->setEast(nullptr);
	p_Zyfran->setWest(nullptr);

	p_Tatwan->setNorth(nullptr);
	p_Tatwan->setSouth(p_Zyfran);
	p_Tatwan->setEast(nullptr);
	p_Tatwan->setWest(nullptr);

	//initialize player
	player->setLocation(p_B042);
	/////////////////////////////////////

	while (player->checkFinish() == false)
	{
		if (player->getHealthPoints() <= 0)
		{
			std::cout << "You do not have enough health points to make it to another planet. Game over." << std::endl;
			break;
		}
		else
		{
			player->getLocation()->getDescription();
			player->getLocation()->playGame(player);

			if (player->getHealthPoints() <= 0)
			{
				std::cout << "You do not have enough health points to make it to another planet. Game over." << std::endl;
				break;
			}
		}
	}

	std::cout << "*************************************************" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::cout << "*************************************************" << std::endl;

}


void Menu::beginningPrompt()
{
	std::cout << "You are a pilot from a planet called B042." << std::endl;
	std::cout << "It is a small planet with a yellow sky, 3 volcanoes(1 active, 2 dormant), several small streams, and a variety of plants." << std::endl;
	std::cout << "Unfortuntely, B042 has become overrun with undesireable vegetation." << std::endl;
	std::cout << "A nearby planet, Tatwan, has the solution to kill the vegetation, but the Queen in charge, known as the Black Queen, hates visitors..." << std::endl;
	std::cout << "During the Black Queen's last tour through the galaxy, four items were stolen from her." << std::endl;
	std::cout << "You overheard where they are each located while having a drink at a pub on your home planet." << std::endl;
	std::cout << "If you go to the Black Queen empty handed she will surely turn you away, but she might be willing to give you the solution in exchange for her stolen items." << std::endl;
	std::cout << "Unfortunately, the items are scattered throughout different planets in the galaxy." << std::endl;
	std::cout << "There are 6 planets and 4 stolen items to find. You start each game with 20 health points, and each trip in your space ship costs 3 health points. " << std::endl;
	std::cout << "Do you want to go find the items and bring them to the Black Queen?" << std::endl;
}


void Menu::checkAnswer(int *a)
{
	while (std::cin.fail() || std::cin.peek() != '\n' || *a < 1 || *a > 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Input. " << std::endl;
		std::cin >> *a;
	}
}

void Menu::cleanup()
{
	if (player)
	{
		delete player;
		player = nullptr;
	}
	if (p_B042)
	{
		delete p_B042;
		p_B042 = nullptr;
	}
	if (p_Dracco)
	{
		delete p_Dracco;
		p_Dracco = nullptr;
	}
	if (p_Navoo)
	{
		delete p_Navoo;
		p_Navoo = nullptr;
	}
	if (p_Altwin)
	{
		delete p_Altwin;
		p_Altwin = nullptr;
	}
	if (p_Zyfran)
	{
		delete p_Zyfran;
		p_Zyfran = nullptr;
	}
	if (p_Tatwan)
	{
		delete p_Tatwan;
		p_Tatwan = nullptr;
	}
}

void Menu::menu()
{
	int answer;

	do
	{
		beginningPrompt();
		std::cout << "Enter 1 to play, 2 to exit: " << std::endl;
		std::cin >> answer;
		checkAnswer(&answer); //validate input

		switch (answer)
		{
		case 1:
			start(); //play game
			break;
		case 2:
			std::cout << "Goodbye." << std::endl; //exit game
			break;
		default:
			std::cout << "Invalid input. " << std::endl;
			//break;
		}
		cleanup();

	} while (answer != 2);
}

Menu::~Menu()
{
	
}