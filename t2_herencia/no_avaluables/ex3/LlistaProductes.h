#pragma once
#include "Producte.h"
#include "Llibre.h"
#include "Electrodomestic.h"
#include <list>
using namespace std;

class LlistaProductes
{
public:
	LlistaProductes() {}
	~LlistaProductes();
	LlistaProductes(const LlistaProductes& lp);
	LlistaProductes& operator=(const LlistaProductes& lp);

	void afegeixLlibre(const Llibre& l);
	void afegeixElectrodomestic(const Electrodomestic& e);
	bool eliminaProducte(const string& codi);
	Producte* getProducte(const string& codi) const;
	void mostra() const;
protected:
	list<Producte*> m_productes;
};
