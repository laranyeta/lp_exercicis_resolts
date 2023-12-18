#include "PuntDeInteresBotigaSolucio.h"

//IMPLEMENTACIONS DELS MÈTODES

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio() : PuntDeInteresBase()
{
	this->m_coord = { 0.0, 0.0 };
	this->m_name = "undefinit";
	this->m_wheelchair = "undefinit";
	this->m_shop = "undefinit";
	this->m_openingHours = "undefinit";
}

PuntDeInteresBotigaSolucio::PuntDeInteresBotigaSolucio(Coordinate coord, std::string name, std::string wheelchair, std::string shop, std::string openingHours) : PuntDeInteresBase(coord, name)
{
	this->m_coord = coord;
	this->m_name = name;
	this->m_wheelchair = wheelchair;
	this->m_shop = shop;
	this->m_openingHours = openingHours;
}

unsigned int PuntDeInteresBotigaSolucio::getColor()
{
	size_t trobat = false;
	std::string cadena = "06:00-22:00";
	trobat = m_openingHours.find(cadena);
	if (m_shop == "supermarket")
		return 0xA5BE00;

	if (m_shop == "tobacco")
		return 0xFFAD69;
	if (m_shop == "bakery")
	{
		if (trobat != std::string::npos && m_wheelchair == "yes") //npos indica l'ausencia de la cadena que volem buscar
			return 0x4CB944;
		else
			return 0xE85D75;
	}
	else
		return 0xEFD6AC;
}
