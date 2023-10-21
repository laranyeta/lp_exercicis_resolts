#pragma once
#include "Publicacio.h"
using namespace std;
class Revista : public Publicacio 
{
public:
	Revista() 
    {
		m_periodRevista = ""; m_nExemplars = 0;
		m_estaPrestat.resize(m_nExemplars); 
		for (int i = 0; i < m_nExemplars; i++) 
		    m_estaPrestat[i] = false;
	}
	Revista(string titol, string codi, string tipus, string periodRevista, int nExemplars, vector<int> exemplars) :
		Publicacio(titol, codi, tipus), m_periodRevista(periodRevista), m_nExemplars(nExemplars) 
		{
			m_exemplars.resize(m_nExemplars);
			m_estaPrestat.resize(m_nExemplars);
			for (int i = 0; i < m_nExemplars; i++) 
			{
				m_estaPrestat[i] = false;
				m_exemplars[i] = exemplars[i];
			}
	    }
	void printPublicacio() 
	{
		Publicacio::printPublicacio();
		cout << m_periodRevista<< " " << m_nExemplars << " - ";
		
		for (int i = 0; i < m_nExemplars; i++)
			cout << m_exemplars[i] << " ";
		cout << endl << endl;
	}
	int getPrestat(int exemplar) const 
	{
		bool existeixPrestec = false;
		int i = 0;
		while (!existeixPrestec && i < m_nExemplars) 
		{
			if (exemplar == m_exemplars[i]) 
			{
				existeixPrestec = true;
				return m_estaPrestat[i];
			}
			else
				i++;
		}
		return exemplar;
	}
	void setPrestat(int resultat, int exemplar) 
	{
		bool existeixPrestec = false;
		int i = 0;
		while (!existeixPrestec && i < m_nExemplars) 
		{
			if (exemplar == m_exemplars[i]) 
			{
				m_estaPrestat[i] = resultat;
				existeixPrestec = true;
			}
			else
				i++;
		}
	}
private:
	string m_periodRevista;
	int m_nExemplars;
	vector<int> m_exemplars;
	vector<bool> m_estaPrestat;
};
