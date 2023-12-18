#include "PuntDeInteresRestaurantSolucio.h"

//IMPLEMENTACIONS DELS MÈTODES

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio() : PuntDeInteresBase()
{
	this->m_coord = { 0.0, 0.0 };
	this->m_name = "undefinit";
	this->m_wheelchair = "undefinit";
	this->m_cuina = "undefinit";
}

PuntDeInteresRestaurantSolucio::PuntDeInteresRestaurantSolucio(Coordinate coord, std::string name, std::string wheelchair, std::string cuina) : PuntDeInteresBase(coord, name)
{
	this->m_coord = coord;
	this->m_name = name;
	this->m_wheelchair = wheelchair;
	this->m_cuina = cuina;
}

unsigned int PuntDeInteresRestaurantSolucio::getColor()
{
	if (m_wheelchair == "yes")
	{
		if (m_cuina == "pizza")
			return 0x03FCBA;
		else
			return 0x251351;
	}
	else
	{
		if (m_cuina == "chinese")
			return 0xA6D9F7;
		else
			return (PuntDeInteresBase::getColor());
	}
}
