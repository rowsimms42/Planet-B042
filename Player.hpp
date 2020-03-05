#ifndef Player_hpp
#define Player_hpp
#include <string>
#include <iostream>
#include "Space.hpp"
#include <vector>

class Space;

class Player
{
private:
	int healthPoints;
	std::vector<std::string> inventory;
	int inventoryCapacity;
	Space* location;
	bool alive;
	//bool finish;

public:
	bool finish;
	Player();
	void setLocation(Space*);
	Space* getLocation();

	//health
	void setHealthPoints(int);
	int getHealthPoints();

	//inventory functions
	void addItem(std::string);
	void removeItem(std::string);
	void printInventory();
	bool checkItem(std::string);

	//alive
	bool checkAlive();

	bool checkFinish();

	//deconstructor
	~Player();


};

#endif