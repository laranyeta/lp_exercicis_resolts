#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

template<class TClau, class TValor>
class Map
{
public:
	Map() {}
	Map(const Map& m) { m_elements = m.m_elements; }
	~Map() {}

	int longitud() const { return m_elements.size(); }
	bool esBuit() const { return m_elements.empty(); }

	TValor& operator[](const TClau& clau);
	const TValor& operator[](const TClau& clau) const;

	TClau& operator[](const int& posicio);
	const TClau& operator[](const int& posicio) const;

	void afegeix(const TClau& clau, const TValor& valor);
	Map<TClau, TValor>& operator=(const Map<TClau, TValor>& m);



private:
    void ordena();
    
	std::vector<pair<TClau, TValor>> m_elements;
	TClau m_clau;
	TValor m_valor;
};

//implementem funcions al header!

template<class TClau, class TValor>
void Map<TClau, TValor>::ordena()
{
    pair<TClau, TValor> aux;
    for (int i = 0; i < longitud(); i++)
    {
        for (int j = 0; j < longitud(); j++)
        {
            if (m_elements[i].first < m_elements[j].first)
            {
                aux = m_elements[i];
                m_elements[i] = m_elements[j];
                m_elements[j] = aux;
            }
        }
    }
}

template<class TClau, class TValor>
TValor& Map<TClau, TValor>::operator[](const TClau& clau)
{
	int inferior = 0;
	int superior = longitud() - 1; //mida del vector
	int mid;
	//first -> TClau
	//second -> TValor
	while (inferior <= superior)
	{
		mid = (inferior + superior) / 2; //mediana del vector

		if (m_elements[mid].first < clau)
			inferior = mid + 1;
		else if (m_elements[mid].first > clau)
			superior = mid - 1;
		else
			return m_elements[mid].second;
	}
	return m_valor;
}

template<class TClau, class TValor>
const TValor& Map<TClau, TValor>::operator[](const TClau& clau) const //mateixa implementacio que l'anterior!
{
	int inferior = 0;
	int superior = longitud() - 1; 
	int mid;

	while (inferior <= superior)
	{
		mid = (inferior + superior) / 2; 

		if (m_elements[mid].first < clau)
			inferior = mid + 1;
		else if (m_elements[mid].first > clau)
			superior = mid - 1;
		else
			return m_elements[mid].second;
	}
	return m_valor;
}

template<class TClau, class TValor>
TClau& Map<TClau, TValor>::operator[](const int& posicio)
{
	if (posicio < 0 || posicio > longitud())
		return m_clau;
	else
		return m_elements[posicio].first;
}

template<class TClau, class TValor>
const TClau& Map<TClau, TValor>::operator[](const int& posicio) const //mateixa implementacio que l'anterior!
{
	if (posicio < 0 || posicio > longitud())
		return m_clau;
	else
		return m_elements[posicio].first;
}

template<class TClau, class TValor>
void Map<TClau, TValor>::afegeix(const TClau& clau, const TValor& valor)
{
	//busquem si existeix la clau dins del vector
	int i = 0;
	bool existeix = false;

	while (!existeix && i < longitud())
	{
		if (m_elements[i].first == clau)
		{
			m_elements[i].second = valor;
			existeix = true;
		}
		else
			i++;
	}

	if (!existeix)
	{
		typename vector<pair<TClau, TValor>>::iterator it = m_elements.begin();
		m_elements.insert(it, make_pair(clau, valor));
		ordena();
	}
}

template<class TClau, class TValor>
Map<TClau, TValor>& Map<TClau, TValor>::operator=(const Map<TClau, TValor>& m)
{
	if (this != &m)
	{
		if (m_elements != NULL)
			m_elements = m.m_elements;
	}
	return *this;
}

