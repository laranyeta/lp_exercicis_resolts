#include "LlistaProductes.h"
#include <iostream>
using namespace std;

LlistaProductes::~LlistaProductes()
{
	list<Producte*>::const_iterator it;
	for (it = m_productes.begin(); it != m_productes.end(); it++)
		delete* it;
}

LlistaProductes::LlistaProductes(const LlistaProductes& lp)
{
	list<Producte*>::const_iterator it;
	for (it = lp.m_productes.begin(); it != lp.m_productes.end(); it++)
	{
		m_productes.push_back((*it)->clone());
	}
}


LlistaProductes& LlistaProductes::operator=(const LlistaProductes& lp)
{
	if (this != &lp)
	{
		list<Producte*>::const_iterator it = m_productes.begin();
		while (it != m_productes.end())
		{
			delete* it;
			it = m_productes.erase(it);
		}
		for (it = lp.m_productes.begin(); it != lp.m_productes.end(); it++)
		{
			m_productes.push_back((*it)->clone());
		}
	}
	return *this;
}

void LlistaProductes::afegeixLlibre(const Llibre& l)
{
	m_productes.push_back(new Llibre(l));
}

void LlistaProductes::afegeixElectrodomestic(const Electrodomestic& e)
{
	m_productes.push_back(new Electrodomestic(e));
}

bool LlistaProductes::eliminaProducte(const string& codi)
{
	list<Producte*>::iterator it = m_productes.begin();
	bool trobat = false;
	while (!trobat && (it != m_productes.end()))
	{
		if ((*it)->getCodi() == codi)
			trobat = true;
		else
			it++;
	}
	if (trobat)
	{
		delete* it;
		m_productes.erase(it);
	}
	return trobat;
}

Producte* LlistaProductes::getProducte(const string& codi) const
{
	Producte* p = nullptr;
	list<Producte*>::const_iterator it = m_productes.begin();
	bool trobat = false;
	while (!trobat && (it != m_productes.end()))
	{
		if ((*it)->getCodi() == codi)
			trobat = true;
		else
			it++;
	}
	if (trobat)
		p = (*it);
	return p;
}

void LlistaProductes::mostra() const
{
	list<Producte*>::const_iterator it;
	for (it = m_productes.begin(); it != m_productes.end(); it++)
		(*it)->mostra();
	cout << endl;
}
