#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "Zyfran.hpp"

Zyfran::Zyfran() : Space()
{
	crystal = 1;
	setPlanetName("Zyfran");
	setVisited(false);
}

void Zyfran::getDescription()
{
	std::cout << "Zyran is a remote ice planet, known for its clear blue skies and furry habitants called Zwickies." << std::endl;
}

void Zyfran::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "You park your ship on the dock and get out. You make your way to the diner down the road called The Frozen Pie." << std::endl;
		std::cout << "You enter The Frozen Pie. A Zwickie approaches you." << std::endl;
		
		while (crystal == 1)
		{
			std::cout << "Enter 1 to tell a story, enter 2 to give a compliment." << std::endl;

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
				std::cout << "You tell the Zwickie about your travels through the galaxy to save your planet and retrieve the stolen items. The Zwickie particuarly enjoys the part with the juggling." << std::endl;
				std::cout << "The Zwickie admires your courage. It goes to the back room, and returns with the Black Queen's stolen crystal." << std::endl;
				player->addItem("Queen's crystal");
				crystal--;
			}
			else if (input == 2)
			{
				std::cout << "You tell the Zwickie that it has nice fur. It says thank you." << std::endl;
			}
		}

		int inputB;

		std::cout << "The Zwickie asks if you'd like to stay for a slice of pie before you head out." << std::endl;
		std::cout << "Enter 1 to stay, enter 2 to leave: " << std::endl;
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
			std::cout << "The pie fills you with energy. You gain 4 health points." << std::endl;
			player->setHealthPoints(player->getHealthPoints() + 4);
		}

	}
	else
	{
		std::cout << "There is a sign on the ship dock that says 'closed for ice'" << std::endl;
	}

	setVisited(true);
	player->setHealthPoints(player->getHealthPoints() - 3);
	std::cout << "Health points: " << player->getHealthPoints() << "/20" << std::endl;
	player->printInventory();

	int inputC;

	std::cout << "Enter 1 to go south to planet Altwin, or enter 2 to go north to planet Tatwan: " << std::endl;
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