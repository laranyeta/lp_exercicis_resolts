#pragma once
#include<list>
#include"Assignatura.h"

class Persona
{
public:
	Persona() : m_niu(""), m_nom("") {}
	Persona(const string& niu, const string& nom) : m_niu(niu), m_nom(nom) {}
	~Persona() {}

	string getNiu() const { return m_niu; }
	string getNom() const { return m_nom; }

	bool cercaAssignatura(const string& nomAssignatura);
	bool afegeixAssignatura(const Assignatura& assignatura);
protected: //es pot accedir des de les classes derivades!
	string m_nom;
	string m_niu;
	std::list<Assignatura> m_assignatures;
};

bool Persona::cercaAssignatura(const string& nomAssignatura)
{
	std::list<Assignatura>::iterator it = m_assignatures.begin();
	bool existeixAssignatura = false;

	while (!existeixAssignatura && it != m_assignatures.end())
	{
		if (nomAssignatura == it->getNom())
			existeixAssignatura = true;
		else
			it++;
	}
	return existeixAssignatura;
}

bool Persona::afegeixAssignatura(const Assignatura& assignatura)
{
	bool esPotAfegir = false;

	if (!cercaAssignatura(assignatura.getNom()))
	{
		m_assignatures.push_back(assignatura);
		esPotAfegir = true;
	}
	return esPotAfegir;
}



