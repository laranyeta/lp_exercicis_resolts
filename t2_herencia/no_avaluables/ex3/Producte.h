#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const int VENDA_PRESENCIAL = 0;
const int VENDA_ONLINE = 1;

class Producte
{
public:
	Producte() : m_codi(""), m_preu(0) {}
	Producte(const string& codi, float preu) : m_codi(codi), m_preu(preu) {}
	Producte(const Producte& p) { m_codi = p.m_codi; m_preu = p.m_preu; }
	virtual ~Producte() {  }

	virtual Producte* clone() = 0;

	void setCodi(const string& codi) { m_codi = codi; }
	void setPreu(float preu) { m_preu = preu; }
	string getCodi() { return m_codi; }
	float getPreu() { return m_preu; }

	virtual float calculaPreu(int nUnitats, int tipusVenda) = 0;
	virtual float calculaDespesesEnviament() = 0;
	virtual void mostra() = 0;
private:
	string m_codi;
protected:
	float m_preu;
};
