#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "Tatwan.hpp"

Tatwan::Tatwan() : Space()
{
	queen = 1;
	guard = 1;
	setPlanetName("Tatwan");
	setVisited(false);
}

void Tatwan::getDescription()
{
	std::cout << "Tatwan is a planet-wide cosmolitan city, known for its floating architecture and outlandish fashion." << std::endl;
}

void Tatwan::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "As you enter Tatwan's atmosphere, you can see the Black Queen's palace in the distance. You land your space ship at the dock and get out." << std::endl;
		std::cout << "You make your way to the Black Queen's palace. Once you get to the gate, a guard stops you." << std::endl;

		while (guard == 1)
		{
			std::cout << "Enter 1 to compliment, enter 2 to sing a song." << std::endl;
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
				std::cout << "You tell the guard that you like his top hat." << std::endl;
				std::cout << "The guard looks displeased and says 'well, that makes one of us...'" << std::endl;
			}
			else if (input == 2)
			{
				std::cout << "You sing Ziggy Stardust. The guard looks pleased and hums along with you." << std::endl;
				std::cout << "The guard lets you through the gate." << std::endl;
				guard--;
			}
		}
		
		std::cout << "You head down the spiral staircase and find the Black Queen sitting by her window." << std::endl;

		while (queen == 1)
		{
			int inputB;

			std::cout << "Enter 1 to tell the Black Queen about your journey, enter 2 to tell a fun fact." << std::endl;

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
				std::cout << "You tell the Black Queen about your travels through the galaxy to save your planet and retrieve her stolen items." << std::endl;
				std::cout << "You leave the part out about her guard letting you in." << std::endl;
				std::cout << "The Black Queen seems bored by your story, but is delighted to see her stolen items." << std::endl;
				std::cout << "She agrees to exchange the items for the solution." << std::endl;
				queen--;
				player->removeItem("Queen's glass ball");
				player->removeItem("Queen's hat");
				player->removeItem("Queen's scarf");
				player->removeItem("Queen's crystal");
				player->addItem("Solution");

			}
			else if (inputB == 2)
			{
				std::cout << "You tell the Black Queen that kangaroos can not walk backwards." << std::endl;
				std::cout << "She doesn't believe you." << std::endl;
			}
		}

		player->printInventory();
		std::cout << "Game over. You won! You go back home to B042 and use the solution. It works, and the undesirable vegetation begins to die." << std::endl;
		player->removeItem("Solution");
		player->finish = true;

	}
	else
	{
		std::cout << "The ship dock seems to have disappeared. Must have floated away somewhere..." << std::endl;
	}

	setVisited(true);
}