#pragma once
#include"Persona.h"
#include"GrupClasse.h"

class Estudiant : public Persona
{
public:
	Estudiant();
	Estudiant(const string& niu, const string& nom, const string& titulacio);
	~Estudiant() {}

	string getTitulacio() const { return m_titulacio; }
	int getCreditsMatriculats() const;
private:
	string m_titulacio;
	int m_nCredits;
};

Estudiant::Estudiant()
{
	m_nom = "";
	m_niu = "";
	m_titulacio = "";
	m_nCredits = 0;
}

Estudiant::Estudiant(const string& niu, const string& nom, const string& titulacio)
{
	m_nom = nom;
	m_niu = niu;
	m_titulacio = titulacio;
}

int Estudiant::getCreditsMatriculats() const
{
	int totalCredits = 0;

	std::list<GrupClasse>::const_iterator it = m_grupsAssignatures.begin();
	while (it != m_grupsAssignatures.end())
	{
		totalCredits += it->getCreditsEstudiant();
		it++;
	}

	return totalCredits;
}
