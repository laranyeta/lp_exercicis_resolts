#pragma once
#include "PuntDeInteresBase.h"
#include "Util.h"

class PuntDeInteresRestaurantSolucio : public PuntDeInteresBase
{
public:
	PuntDeInteresRestaurantSolucio();
	PuntDeInteresRestaurantSolucio(Coordinate coordenada, std::string nom, std::string wheelchair, std::string cuina);
	unsigned int getColor();

	std::string getName() { return this->m_name; }
	Coordinate getCoord() { return this->m_coord; }
private:
	Coordinate m_coord;
	std::string m_name;
	std::string m_wheelchair;
	std::string m_cuina;
};
