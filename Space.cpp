#include <iostream>
#include <string>
#include "Space.hpp"

Space::Space()
{
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;
	pastVisit = false;
}

void Space::setPlanetName(std::string planet_name)
{
	planetName = planet_name;
}
std::string Space::getPlanetName()
{
	return planetName;
}

void Space::setNorth(Space* n)
{
	north = n;
}

void Space::setSouth(Space* s)
{
	south = s;
}

void Space::setEast(Space* e)
{
	east = e;
}

void Space::setWest(Space* w)
{
	west = w;
}

Space* Space::getNorth()
{
	return north;
}

Space* Space::getSouth()
{
	return south;
}

Space* Space::getEast()
{
	return east;
}

Space* Space::getWest()
{
	return west;
}

void Space::setVisited(bool previousVisit)
{
	pastVisit = previousVisit;
}

bool Space::visitedBefore()
{
	return pastVisit;
}

//deconstructor
Space::~Space()
{
	//delete north;
	//delete south;
	//delete east;
	//delete west;
}