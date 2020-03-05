#include <string>
#include <iostream>
#include "Player.hpp"
#include "Space.hpp"
#include <vector>
#include <algorithm>

Player::Player()
{
	//steps = 0;
	healthPoints = 20;
	inventoryCapacity = 6;
	finish = false;
}

Player::~Player()
{

}

void Player::setLocation(Space* current_location)
{
	location = current_location;
}

Space* Player::getLocation()
{
	return location;
}

void Player::setHealthPoints(int health)
{
	healthPoints = health;
}

int Player::getHealthPoints()
{
	return healthPoints;
}

bool Player::checkAlive()
{
	if (getHealthPoints() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::removeItem(std::string item)
{
	//https://stackoverflow.com/questions/9121532/delete-strings-in-a-vector
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i) == item)
		{
			inventory.erase(inventory.begin() + i);
		}
	}
}

//inventory functions
void Player::addItem(std::string item)
{
	if (inventory.size() > inventoryCapacity)
	{
		std::cout << "You can not carry any more items." << std::endl;
	}

	else
	{
		std::cout << "You have added the " << item << " to your inventory." << std::endl;
		inventory.push_back(item);
	}
}

void Player::printInventory()
{
	if (inventory.size() == 0)
	{
		std::cout << "You do not have any items in your inventory." << std::endl;
	}
	else
	{
		std::cout << "Inventory: " << std::endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			std::cout << "item #" << i + 1 << ": " << inventory.at(i) << " " << std::endl;
		}
	}
}

bool Player::checkFinish()
{
	return finish;
}


bool Player::checkItem(std::string item)
{
//https://stackoverflow.com/questions/6277646/in-c-check-if-stdvectorstring-contains-a-certain-value
	if (std::find(inventory.begin(), inventory.end(), item) != inventory.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}