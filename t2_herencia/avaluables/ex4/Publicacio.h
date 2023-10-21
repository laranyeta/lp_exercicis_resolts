#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Publicacio {
public:
	Publicacio() { m_titol = "null"; m_codi = "null"; m_tipus = "null"; }
	Publicacio(string titol, string codi, string tipus) 
	{
		m_titol = titol; m_codi
			= codi; m_tipus = tipus;
	}
	virtual void printPublicacio() {
		cout << m_tipus << " " << m_codi << " " << m_titol << " ";
	}
	virtual int getPrestat(int exemplar) const { return -1; }
	virtual void setPrestat(int num, int exemplar) {}
	virtual int getNDiesPrestat() const { return -1; }
	virtual int getNCopies() const { return -1; }
	string getTipus() { return m_tipus; }
	string getCodi() { return m_codi; }
private:
	string m_titol;
	string m_codi;
	string m_tipus;
};
