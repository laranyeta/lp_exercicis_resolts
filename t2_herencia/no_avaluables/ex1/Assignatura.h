#pragma once
#include <string>
using namespace std;

class Assignatura
{
public:
	Assignatura() : m_nom(""), m_nCreditsEstudiant(0), m_nCreditsProfessor(0) {};
	Assignatura(const string& nom, const int nCreditsEstudiant, const int nCreditsProfessor) : m_nom(nom),
		m_nCreditsEstudiant(nCreditsEstudiant), m_nCreditsProfessor(nCreditsProfessor) {}
	~Assignatura() {};

	string getNom() const { return m_nom; }
	int getCreditsEstudiant() const { return m_nCreditsEstudiant; }
	int getCreditsProfessor() const { return m_nCreditsProfessor; }
private:
	string m_nom;
	int m_nCreditsEstudiant;
	int m_nCreditsProfessor;
};
