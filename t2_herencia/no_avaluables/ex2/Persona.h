#pragma once
#include<list>
#include"GrupClasse.h"

class Persona
{
public:
	Persona() : m_niu(""), m_nom("") {}
	Persona(const string& niu, const string& nom) : m_niu(niu), m_nom(nom) {}
	~Persona() {}

	string getNiu() const { return m_niu; }
	string getNom() const { return m_nom; }

	bool cercaAssignatura(const string& nomAssignatura);
	bool afegeixAssignatura(const GrupClasse& assignatura);
protected: //es pot accedir des de les classes derivades!
	string m_nom;
	string m_niu;
	std::list<GrupClasse> m_grupsAssignatures;
};

bool Persona::cercaAssignatura(const string& nomAssignatura)
{
	std::list<GrupClasse>::iterator it = m_grupsAssignatures.begin();
	bool existeixGrup= false;

	while (!existeixGrup && it != m_grupsAssignatures.end())
	{
		if (nomAssignatura == it->getNom())
			existeixGrup = true;
		else
			it++;
	}
	return existeixGrup;
}

bool Persona::afegeixAssignatura(const GrupClasse& grupAssignatura)
{
	bool esPotAfegir = false;

	if (!cercaAssignatura(grupAssignatura.getNom()))
	{
		m_grupsAssignatures.push_back(grupAssignatura);
		esPotAfegir = true;
	}
	return esPotAfegir;
}
