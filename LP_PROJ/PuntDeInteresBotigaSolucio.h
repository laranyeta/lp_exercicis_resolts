#pragma once
#include "PuntDeInteresBase.h"
#include "Util.h"

class PuntDeInteresBotigaSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresBotigaSolucio();
	PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string wheelchair, std::string shop, std::string openingHours);
	unsigned int getColor();

	std::string getName() { return this->m_name; }
	Coordinate getCoord() { return this->m_coord; }

private:
	Coordinate m_coord;
	std::string m_name;
	std::string m_wheelchair;
	std::string m_shop;
	std::string m_openingHours;
};
