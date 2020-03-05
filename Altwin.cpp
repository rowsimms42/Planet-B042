#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "Altwin.hpp"

Altwin::Altwin() : Space()
{
	riddler = 1;
	setPlanetName("Altwin");
	setVisited(false);
}

void Altwin::getDescription()
{
	std::cout << "Altwin is known for its large amount of debris from the last solar war. " << std::endl;
}

void Altwin::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "You park your ship and look out the window. It looks pretty abandoned, except for a creature on the side of the road carrying a basket of balls." << std::endl;
		std::cout << "You get out of your ship, and as you shut your door, you feel a tap on your shoulder. It's the creature. You aren't sure how it got to you so fast." << std::endl;

		while (riddler == 1)
		{
			std::cout << "Enter 1 to tell a fun fact, enter 2 to perform a trick: " << std::endl;
			std::cin >> input;

			while (std::cin.fail() || std::cin.peek() != '\n' || input < 1 || input > 2)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid Input. " << std::endl;
				std::cin >> input;
			}

			if (input == 1)
			{
				std::cout << "You tell him that Giant Huntsman spiders have leg-spans of around 12 inches." << std::endl;
				std::cout << "The creature looks horrified." << std::endl;
			}
			else if (input == 2)
			{
				std::cout << "You take 3 balls out of the creature's basket and perform a juggling trick." << std::endl;
				std::cout << "The creature is very impressed. You bond over your enjoyment of juggling." << std::endl;
				std::cout << "You ask the creature about the Queen's stolen items. The creature takes a glass ball out of its basket and hands it to you." << std::endl;
				std::cout << "I..uh...just happened to find it...' says the creature." << std::endl;
				player->addItem("Queen's glass ball");
				riddler--;
			}
		}
	}
	else if (visitedBefore() == true)
	{
		std::cout << "The creature is still on the side of the road with the basket of balls. It waves to you and performs a juggling trick. You wave back." << std::endl;
	}

	setVisited(true);
	player->setHealthPoints(player->getHealthPoints() - 3);
	std::cout << "Health points: " << player->getHealthPoints() << "/20" << std::endl;
	player->printInventory();

	int inputC;

	std::cout << "Enter 1 to go south to planet Navoo, or enter 2 to go north to planet Zyfran: " << std::endl;
	std::cin >> inputC;

	while (std::cin.fail() || std::cin.peek() != '\n' || inputC < 1 || inputC > 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Input. " << std::endl;
		std::cin >> inputC;
	}

	if (inputC == 1)
	{
		player->setLocation(south);
	}
	else if (inputC == 2)
	{
		player->setLocation(north);
	}
}