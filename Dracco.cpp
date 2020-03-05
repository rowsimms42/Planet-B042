#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "Dracco.hpp"

Dracco::Dracco() : Space()
{
	hat = 1;
	setPlanetName("Dracco");
	setVisited(false);
}

void Dracco::getDescription()
{
	std::cout << "Dracco is known for its swampy atmosphere and rather pecululiar habitants called Raxels." << std::endl;
}

void Dracco::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "You park your ship on the dock and make your way over to a little tavern called The Flying Saucer. You enter, and make your way into the bar." << std::endl;
		std::cout << "The bar is mostly empty, but there are a few Raxels playing cards at the corner table. Do you want to approach them? Enter 1 for yes, 2 for no." << std::endl;
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
			std::cout << "You gained 2 health points for courage." << std::endl;
			player->setHealthPoints(player->getHealthPoints() + 2);
			std::cout << "'Ugh...a human' says the Raxel on the far side of the table." << std::endl;
		}

		else if (input == 2)
		{
			std::cout << "The raxels approach you anyways." << std::endl;
		}

		while (hat == 1)
		{
			int inputB;

			std::cout << "Enter 1 to tell a joke, enter 2 to give a compliment." << std::endl;
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
				std::cout << "You tell them the joke: 'What is the astronauts favorite key on the keyboard? The space bar!'" << std::endl;
				std::cout << "They don't have computers on Dracco, and nobody understands your joke." << std::endl;
				//hat = false;
			}
			else if (inputB == 2)
			{
				std::cout << "You give one of the Raxels a compliment. You say you like his necktie." << std::endl;
				std::cout << "The Raxel smiles and tells you that he knit it himself. He asks you what he can do for you, and you say you are looking for one of the Black Queen's stolen items." << std::endl;
				std::cout << "He tells you that the Black Queen's stolen hat is behind the bar, and goes and gets it for you." << std::endl;
				player->addItem("Queen's hat");
				hat--;
			}
		}
	}
	else
	{
		std::cout << "You go back to the Flying Saucer. A note on the door says 'closed for holiday'" << std::endl;
	}

	setVisited(true);
	player->setHealthPoints(player->getHealthPoints() - 3);
	std::cout << "Health points: " << player->getHealthPoints() << "/20" << std::endl;
	player->printInventory();

	int inputC;

	std::cout << "Enter 1 to go south to planet B042, or enter 2 to go north to planet Navoo: " << std::endl;
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