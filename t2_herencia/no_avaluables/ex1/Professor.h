#pragma once
#include"Persona.h"

class Professor: public Persona
{
public:
	Professor();
	Professor(const string& niu, const string& nom, const string& departament, const int maximCredits);
	~Professor() {}

	int getMaximCredits() const { return m_maxCredits; }
	string getDepartament() const { return m_departament; }
	int getCreditsImpartits() const;

private:
	string m_departament;
	int m_maxCredits;
};

Professor::Professor()
{
	m_nom = "";
	m_niu = "";
	m_departament = "";
	m_maxCredits = 0;
}

Professor::Professor(const string& niu, const string& nom, const string& departament, const int maximCredits)
{
	m_niu = niu;
	m_nom = nom;
	m_departament = departament;
	m_maxCredits = maximCredits;
}

int Professor::getCreditsImpartits() const
{
	int totalCredits = 0;

	std::list<Assignatura>::const_iterator it = m_assignatures.begin();
	while (it != m_assignatures.end())
	{
		totalCredits += it->getCreditsProfessor();
		it++;
	}

	return totalCredits;
}


