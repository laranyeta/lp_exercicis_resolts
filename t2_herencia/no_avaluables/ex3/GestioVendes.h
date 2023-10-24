#pragma once
#include"LlistaProductes.h"

class GestioVendes: public LlistaProductes
{
public:
	GestioVendes();
	~GestioVendes() {}

	void llegeixProductes(const string& nomFitxer);
	float afegeixVendaPresencial(const string& codiProducte, int nUnitats, const string& data, const string& botiga);
	float afegeixVendaOnLine(const string& codiProducte, int nUnitats, const string& data, const string& adreca);
	void escriuVendes(const string& nomFitxer);

	GestioVendes& operator=(const GestioVendes& gv);
private:
	int m_nUnitats;
	string m_data;
	float m_importTotal;
	//venda presencial
	string m_botiga;
	//venda online
	string m_adreca;
	float m_despeses;
};

GestioVendes::GestioVendes()
{
	m_nUnitats = 0;
	m_data = "";
	m_importTotal = 0.0;
	m_botiga = "";
	m_adreca = "";
	m_despeses = 0.0;
}

void GestioVendes::llegeixProductes(const string& nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
	//general
		int tipus;
		string codi;
		float preu;

		//llibre
		string titol;
		string autor;
		int nPagines;

		//electrodomestic
		string marca;
		string model;
		float volum;

		while (!fitxer.eof())
		{
			fitxer >> tipus >> codi >> preu;

			if (tipus == 0) //llibre
			{
			   fitxer >> titol >> autor >> nPagines;
			   Producte* l;
			   l = new Llibre(codi, preu, titol, autor, nPagines);
			   m_productes.push_back(l);
			}
			
			if (tipus == 1) //electrodomestic
			{
			    fitxer >> marca >> model >> volum; 
			    Producte* e;
			    e = new Electrodomestic(codi, preu, marca, model, volum);
			    m_productes.push_back(e);
			}
		}
	}
	fitxer.close();
}

float GestioVendes::afegeixVendaPresencial(const string& codiProducte, int nUnitats, const string& data, const string& botiga)
{
	list<Producte*>::iterator it = m_productes.begin();
	bool existeixProducte = false;

	while (!existeixProducte && it != m_productes.end())
	{
		if (codiProducte == (*it)->getCodi())
			existeixProducte = true;
		else
			it++;
	}

	if (existeixProducte)
	{
		m_botiga = botiga;
		m_data = data;
		m_importTotal = (*it)->calculaPreu(nUnitats, VENDA_PRESENCIAL);
		return m_importTotal;
	}
	return -1;
}

float GestioVendes::afegeixVendaOnLine(const string& codiProducte, int nUnitats, const string& data, const string& adreca)
{
	list<Producte*>::iterator it = m_productes.begin();
	bool existeixProducte = false;

	while (!existeixProducte && it != m_productes.end())
	{
		if (codiProducte == (*it)->getCodi())
			existeixProducte = true;
		else
			it++;
	}

	if (existeixProducte)
	{
		m_adreca = adreca;
		m_data = data;
		m_importTotal = (*it)->calculaPreu(nUnitats, VENDA_ONLINE);
		return m_importTotal;
	}
	return -1;
}

void GestioVendes::escriuVendes(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	
	if (fitxer.is_open())
	{
	    list<Producte*>::iterator it = m_productes.begin();
	    
	    
	       fitxer << (*it)->getCodi() << m_nUnitats << m_importTotal << m_botiga; //(*it)->getPreu();
	       it++; 
	
	}
	fitxer.close();
}

GestioVendes& GestioVendes::operator=(const GestioVendes& gv)
{
    if (this != &gv)
    {
        m_nUnitats = gv.m_nUnitats;
        m_data = gv.m_data;
        m_importTotal = gv.m_importTotal;
        m_botiga = gv.m_botiga;
        m_adreca = gv.m_adreca;
        m_despeses = gv.m_despeses;
    }
    return *this;
}
