#include "Biblioteca.h"
#include <fstream>

using namespace std;

void Biblioteca::llegirPublicacions(const string& nomFitxer) 
{
	ifstream fitxer;
	
	fitxer.open(nomFitxer);
	
	if (fitxer.is_open()) {
	    //GENERAL
		string titol, codi, tipus; 
		//LLIBRE
		string autorLlibre;
		int nCopies, nDies;
		//REVISTA
		string periodRevista;
		int nExemplars;
		vector<int> totalExemplars;
		
		while (!fitxer.eof()) 
		{
			fitxer >> tipus >> codi >> titol;
			if (tipus == "L") 
			{ 
				fitxer >> autorLlibre >> nCopies >> nDies;
				Publicacio* l;
				l = new Llibre(titol, codi, tipus, autorLlibre, nCopies, nDies);

				m_llistaPublicacions.push_back(l);
				l->printPublicacio();
			}
			if (tipus == "R") 
			{ 
				fitxer >> periodRevista >> nExemplars;
				totalExemplars.resize(nExemplars);
				for (int i = 0; i < nExemplars; i++) 
					fitxer >> totalExemplars[i];

				Publicacio* r;
				r = new Revista(titol, codi, tipus, periodRevista, nExemplars, totalExemplars);
				m_llistaPublicacions.push_back(r);
				r->printPublicacio();
			}
		}
	}
	fitxer.close();
}

bool Biblioteca::prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar) 
{
	bool esPotPrestar = false;
	bool existeixPrestec = false;
	list<Publicacio*>::iterator it = m_llistaPublicacions.begin();

	while (it != m_llistaPublicacions.end() && !existeixPrestec) 
	{
		if ((*it)->getCodi() == codi) 
		{
			if ((*it)->getTipus() == "L" && (*it)->getPrestat(0) < (*it)->getNCopies()) 
			{
				dataRetorn = dataPrestec + (*it)->getNDiesPrestat();
				Prestec p(idUsuari, codi, dataPrestec, dataRetorn);
				
				m_prestecs.push_back(p);
				(*it)->setPrestat(1, 0);
				esPotPrestar = true;
			}
			if ((*it)->getTipus() == "R" && !(*it)->getPrestat(nExemplar)) 
			{
				dataRetorn = dataPrestec + 30;
				Prestec p(idUsuari, codi, dataPrestec, dataRetorn, nExemplar);
				
				m_prestecs.push_back(p);
				(*it)->setPrestat(true, nExemplar);
				esPotPrestar = true;
			}
			existeixPrestec = true;
		}
		it++;
	}
	return esPotPrestar;
}

bool Biblioteca::retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExemplar) 
{
	list<Prestec>::iterator it = m_prestecs.begin();
	bool esPotRetornar = false;
	bool existeixPrestec = false;

	while (it != m_prestecs.end() && !existeixPrestec) 
	{
		if ((*it).getidUsuari() == idUsuari && (*it).getCodiPublicacio() == codi && (*it).getnExemplar() == nExemplar) 
		{
			//cout << "Data esperada de retorn: " << (*it).getDataRetorn().getDia() << "/" << (*it).getDataRetorn().getMes() << "/" << (*it).getDataRetorn().getAny() << endl << endl;
			if (data < (*it).getDataRetorn())
				dataCorrecta = true;
			else
				dataCorrecta = false;
			existeixPrestec= true;
			esPotRetornar = true;
		}
		else
			it++;
	}
	if (existeixPrestec)
		m_prestecs.erase(it);

	return esPotRetornar;
}
