#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "B042.hpp"

B042::B042() : Space()
{
	iceCream = 1;
	setPlanetName("B042");
	setVisited(false);
}

void B042::getDescription()
{
	std::cout << "B042 is your home planet. It is known for its yellow sky, 3 volcanoes(1 active, 2 dormant), several small streams, and a variety of plants." << std::endl;
}

void B042::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "It's time to get started. Would you like to eat some ice cream before you go? Enter 1 for yes, 2 for no: " << std::endl;
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
			player->setHealthPoints(player->getHealthPoints() + 8);
			std::cout << "You ate the ice cream. You gained 8 health points." << std::endl;
			iceCream--;
		}
		else
		{
			std::cout << "You didn't eat the ice cream." << std::endl;
		}

	}
	else if (visitedBefore() == true)
	{
		int inputB;

		if (iceCream == 0)
		{
			std::cout << "Looks like everything is the same around here." << std::endl;
		}
		else if (iceCream == 1)
		{
			std::cout << "The ice cream is still here. Would you like to eat it? Enter 1 for yes, 2 for no: " << std::endl;

			std::cin >> inputB;

			while (std::cin.fail() || std::cin.peek() != '\n' || inputB < 1 || inputB > 2)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid Input. " << std::endl;
				std::cin >> inputB;
			}
			if (inputB == 1)
			{
				player->setHealthPoints(player->getHealthPoints() + 8);

				std::cout << "You ate the ice cream. You gained 8 health points." << std::endl;
				iceCream--;
			}
			else
			{
				std::cout << "You didn't eat the ice cream." << std::endl;
			}
		}
		std::cout << "The site of home fills you with energy. You didn't lose any health points for this trip." << std::endl;
	}
	setVisited(true);

	std::cout << "Health points: " << player->getHealthPoints() << "/20" << std::endl;
	player->printInventory();

	std::cout << "Next stop: planet Dracco." << std::endl;

	player->setLocation(north);

}

