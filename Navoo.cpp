#include <iostream>
#include <string>
#include <limits>
#include "Space.hpp"
#include "Player.hpp"
#include "Navoo.hpp"

Navoo::Navoo() : Space()
{
	mask= 1;
	dragon = 1;
	setPlanetName("Navoo");
	setVisited(false);
}

void Navoo::getDescription()
{
	std::cout << "Navoo was a jungle planet known for its vast forests and intelligent coexisting ruling class of dragons and humans. Now, it is largely unhabitable due to its growing toxic atmosphere." << std::endl;
}

void Navoo::playGame(Player* player)
{
	if (visitedBefore() == false)
	{
		int input;
		std::cout << "You park your space ship on the dock. On the other side of the dock, you see a man sitting in a chair with a cassette player." << std::endl;
		std::cout << "Do you want to talk to him ? Enter 1 for yes, 2 for no : " << std::endl;
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
			int inputB;
			std::cout << "He looks up at you and smiles. He has a David Bowie album on his cassette player. He plays you a few songs, and you bond over your shared taste in music. " << std::endl;
			std::cout << "The sound of David Bowie gives you energy. You gain 4 health points." << std::endl;
			player->setHealthPoints(player->getHealthPoints() + 4);
			std::cout << "He offers you a gas mask for your stay on Navoo. Take it?: Enter 1 for yes, 2 for no: " << std::endl;

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
				player->addItem("Gas Mask");
				mask--;
			}
		}

		int inputC;

		std::cout << "You walk out of the ship dock and head towards the village towards a diner called 'Dragos'." << std::endl;
		std::cout << "Once you get to the diner, you approach the creature behind the register." << std::endl;

		while (dragon == 1)
		{
			std::cout << "Enter 1 to ask about the Black Queen's stolen items, enter 2 to ask the creature about its day." << std::endl;
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
				std::cout << "You ask the creature about the stolen items. The creature huffs, 'How dare you accuse me of being a thief!'" << std::endl;
			}
			if (inputC == 2)
			{
				std::cout << "You ask the creature about its day. The creature tells you that it slayed 3 dragons on its walk to work this morning." << std::endl;
				std::cout << "You don't believe the creature, but you nod and look impressed. The creature smiles." << std::endl;
				std::cout << "You ask the creature about the Black Queen's stolen item. The creature disappears to the back of the diner and returns with a scarf." << std::endl;
				std::cout << "'A dragon stole it...' says the creature." << std::endl;
				dragon--;
				player->addItem("Queen's scarf");
			}
		}
		if (mask == 0)
		{
			std::cout << "You thank the man at the dock for the gas mask and give it back to him. He says thank you." << std::endl;
			player->removeItem("Gas Mask");
		}
		else if (mask == 1)
		{
			std::cout << "Your time spent in Navoo's toxic atmosphere has taken a toll on your health. You lose 2 health points." << std::endl;
			player->setHealthPoints(player->getHealthPoints() - 2);
		}
	}
	else if (visitedBefore() == true)
	{
		std::cout << "You park your ship on the dock. Dragons sworm your ship, forcing you to leave." << std::endl;
	}

	setVisited(true);
	player->setHealthPoints(player->getHealthPoints() - 3);
	std::cout << "Health points: " << player->getHealthPoints() << "/20" << std::endl;
	player->printInventory();

	int inputD;

	std::cout << "Enter 1 to go south to planet Dracco, or enter 2 to go north to planet Altwin: " << std::endl;
	std::cin >> inputD;

	while (std::cin.fail() || std::cin.peek() != '\n' || inputD < 1 || inputD > 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid Input. " << std::endl;
		std::cin >> inputD;
	}

	if (inputD == 1)
	{
		player->setLocation(south);
	}
	else if (inputD == 2)
	{
		player->setLocation(north);
	}

}