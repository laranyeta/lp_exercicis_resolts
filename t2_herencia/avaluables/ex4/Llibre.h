#pragma once
#include "Publicacio.h"
using namespace std;
class Llibre : public Publicacio 
{
public:
	Llibre() { m_autor = ""; m_nCopies = 0; m_nDies = 0; m_copiesPrestades = 0; }
	Llibre(string titol, string codi, string tipus, const string& autor, int nCopies, int nDies) :
		Publicacio(titol, codi, tipus), m_autor(autor), m_nCopies(nCopies), m_nDies(nDies), m_copiesPrestades(0) {}
	void printPublicacio() 
	{
		Publicacio::printPublicacio();
		cout << m_autor << " " << m_nCopies << " " << m_nDies << endl << endl;
	}
	int getPrestat(int exemplar) const { return m_copiesPrestades; }
	void setPrestat(int num, int exemplar) { m_copiesPrestades += num; }
	int getNDiesPrestat() const { return m_nDies; }
	int getNCopies() const { return m_nCopies; }
private:
	string m_autor;
	int m_nCopies;
	int m_nDies;
	int m_copiesPrestades;
};
