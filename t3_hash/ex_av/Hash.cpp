#include "Hash.h"
#include <math.h>
using namespace std;

Hash::Hash(int numIni, const string& descripcioDefecte)
{
	m_maxElements = numIni;
	m_descripcioDefecte = descripcioDefecte;
	m_diccionari.resize(m_maxElements, pair<string, string>("", ""));
	
	//IMPLEMENTAR 
    m_estat.resize(m_maxElements, 0); //LLIURE = 0
        
	m_numOcupats = 0;
}
Hash::~Hash()
{
}

int Hash::codi(string s) const
{
	unsigned long valor = 0;
	for (int i = 0; i < s.size(); i++)
	{
		valor+= (s[i]*pow(2,i));
		valor = valor%m_maxElements;
	}	
	return valor;
}

int Hash::codi2(int index, int vegades) const
{
	return (int)(index + pow(vegades,2)) % m_maxElements;
}

int Hash::cerca(const string& clau) const
{//Cerquem posicio amb collisions
	int indexInicial = codi(clau);
	int index = indexInicial;
	int vegades = 1;
	while (m_estat[index] != LLIURE)
	{
		if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
			return index;

     	index = codi2(indexInicial, vegades);
		vegades++;
	}
	return index;
}

void Hash::insert(const string& clau, const string& descripcio)
{
	//Cerquem posicio amb collisions
	int indexInicial = codi(clau);
	int index = indexInicial;
	int vegades = 1;
	bool trobat = false;
	
	// IMPLEMENTAR CODI inserció
	// Si la clau ja hi és a la taula la modifica amb el nou valor.
	// Sino l'afegeix a la posició correcta.
	while (m_estat[index] != LLIURE && !trobat)
	{
	    if (m_estat[index] == OCUPAT && m_diccionari[index].first == clau)
	        trobat = true;
	    else
	    {
	        index = codi2(indexInicial, vegades);
	        vegades++;
	    }
	}
	
	if (trobat)
	    m_diccionari[index].second = descripcio;
	else
	{
	    if (m_diccionari[index].first == "")
	    {
	        m_diccionari[index].first = clau;
	        m_diccionari[index].second = descripcio;
	        m_numOcupats++;
	        m_estat[index] = OCUPAT;
	    }
	    else
	        throw "COL·LISIO";
	}
}

string& Hash::operator[](const string& clau)
{
	int index = cerca(clau);

	if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
	{
		//Element trobat
		return m_diccionari[index].second;
	}
    
    //Element no trobat, l'inserim
	insert(clau, m_descripcioDefecte);
	return m_descripcioDefecte;

}

bool Hash::find(const string& clau, string& definicio)
{
	int index = cerca(clau);
	
	if ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
	{
		definicio = m_diccionari[index].second;
		return true;
	}
	definicio = "";
	return false;
}

bool Hash::esborra(const string& clau)
{
	int index = cerca(clau);
	while ((m_estat[index] == OCUPAT) && (m_diccionari[index].first == clau))
	{//Trobat l'esborrem
		//m_diccionari[index].second="";
		//m_diccionari[index].first= "";
		m_estat[index] = ESBORRAT;
		m_numOcupats--;
		return true;		
	}
	return false;
}


void Hash::mostra()
{
	for (int i = 0; i < m_diccionari.size(); i++)
	{
		if (m_diccionari[i].first!="")
		{
			cout << "POS: " <<i <<"  CLAU: " << m_diccionari[i].first <<"  VALOR: " << m_diccionari[i].second <<endl;
		}		
	}
}
