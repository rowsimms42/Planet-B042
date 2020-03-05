#ifndef Space_hpp
#define Space_hpp
#include <iostream>
#include <string>
#include "Player.hpp"

class Player;

class Space
{

protected:
	Space* north;
	Space* south;
	Space* east;
	Space* west;
	std::string planetName;
	bool pastVisit;

public:
	//constructor
	Space();
	//setters/getters
	void setNorth(Space*);
	void setSouth(Space*);
	void setEast(Space*);
	void setWest(Space*);
	Space* getNorth();
	Space* getSouth();
	Space* getEast();
	Space* getWest();
	
	//get planet player is in
	void setPlanetName(std::string);
	std::string getPlanetName();

	//checks is player previously visited room
	virtual bool visitedBefore();
	virtual void setVisited(bool);

	//displays description in each room //pure virutal function
	virtual void getDescription() = 0;

	//play game //pure virtual function
	virtual void playGame(Player* player) = 0;


	//deconstructor 
	virtual ~Space();

};
#endif