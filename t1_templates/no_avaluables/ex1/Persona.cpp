#include "Persona.h"

ostream& operator<<(ostream& out, const Persona& p)
{
	out << "(" << p.m_nom << ", " << p.m_edat << ")";
	return out;
}

bool Persona::operator>(const Persona& p)
{
	//mirem si una persona es mes gran que l'altra
	bool esMajor = false;

	if (m_edat > p.m_edat)
		esMajor = true;
	else if (m_edat == p.m_edat)
	{
		if (m_nom > p.m_nom)
			esMajor = true;
	}
	return esMajor;
}

bool Persona::operator<(const Persona& p)
{
	//mirem si una persona es mes petita que l'altra
	bool esMenor = false;

	if (m_edat < p.m_edat)
		esMenor = true;
	else if (m_edat == p.m_edat)
	{
		if (m_nom < p.m_nom)
			esMenor = true;
	}
	return esMenor;
}
