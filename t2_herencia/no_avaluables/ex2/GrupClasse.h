#pragma once
#include"Grup.h"
#include"Assignatura.h"
#include<list>

class GrupClasse : public Grup, public Assignatura
{
public:
	GrupClasse();
	GrupClasse(const string& nom, const int nCreditsEstudiant, const int nCreditsProfessor, int nGrup, const string& horari, const int nCreditsProfessorGrup);
	~GrupClasse() {}

	int getCreditsProfessor() const { return m_nCreditsProfessorGrup; }
private:
	int m_nCreditsProfessorGrup; //nomes pel grup de classe
};

GrupClasse::GrupClasse()
{
	m_nom = "";
	m_nGrup = 0;
	m_nCreditsEstudiant = 0;
	m_nCreditsProfessor = 0;
}

GrupClasse::GrupClasse(const string& nom, const int nCreditsEstudiant, const int nCreditsProfessor, int nGrup, const string& horari, const int nCreditsProfessorGrup)
{
	m_nom = nom;
	m_nCreditsEstudiant = nCreditsEstudiant;
	m_nCreditsProfessor = nCreditsProfessor;
	m_nGrup = nGrup;
	m_horari = horari;
	m_nCreditsProfessorGrup = nCreditsProfessorGrup;
}
