#include "Estudiant.h"
#include "Professor.h"
#include <iostream>
using namespace std;


void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

float testGrupClasse()
{
	float reduccio = 0;

	GrupClasse grup("ASSIG_1", 6, 6, 1, "dl 9 - 11", 3);
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> =======================================" << endl;
	cout << "Comment :=>> Iniciant test de la classe GrupClasse ..." << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ------------" << endl;
	cout << "Comment :=>> Inicialitzant dades del grup... " << endl;
	cout << "Comment :=>> Nom: " << "ASSIG_1" << " Cr. estudiant: " << 6 << " Cr. professor-assig: " << 6 << " N. grup: " << 1 <<
		" Horari: " << "dl 9 - 11 " << " Cr. professor - grup: " << 3 << " ..." << endl;
	cout << "Comment :=>> Comprovant inicialitzacio de les dades ..." << endl;
	cout << "Comment :=>> Nom Assignatura: " << grup.getNom() << endl;
	cout << "Comment :=>> Credits Estudiant: " << grup.getCreditsEstudiant() << endl;
	cout << "Comment :=>> Credits Assignatura Professor: " << grup.Assignatura::getCreditsProfessor() << endl;
	cout << "Comment :=>> N. grup: " << grup.getGrup() << endl;
	cout << "Comment :=>> Horari grup: " << grup.getHorari() << endl;
	cout << "Comment :=>> Credits Grup Professor: " << grup.getCreditsProfessor() << endl;
	if ((grup.getNom() != "ASSIG_1") || (grup.getCreditsEstudiant() != 6) || (grup.Assignatura::getCreditsProfessor() != 6) ||
		(grup.getGrup() != 1) || (grup.getHorari() != "dl 9 - 11") || (grup.getCreditsProfessor() != 3))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	return reduccio;
}



float testPersona()
{
	float reduccio = 0;
	const int MAX_PROVES = 3;
	GrupClasse grupsAssignatures[MAX_PROVES][4] = {
		{},
		{{"ASSIG_1", 6, 12, 1, "dl, 9-11", 6}},
		{{ "ASSIG_1", 6, 6 , 1, "dl 9-11", 6}, {"ASSIG_2", 3, 6, 2, "dm 11-13", 3}, {"ASSIG_3", 6, 4, 3, "dc 15-17", 4}, {"ASSIG_4", 9, 10, 4, "dj 17-19", 6}}
	};
	int nAssignatures[MAX_PROVES] = { 0, 1, 4 };
	string nomsCerca[MAX_PROVES][4] = {
		{"ASSIG_1"},
		{"ASSIG_1", "ASSIG_2"},
		{ "ASSIG_1", "ASSIG_2", "ASSIG_4", "ASSIG_5"}
	};
	int nNomsCerca[MAX_PROVES] = { 1, 2, 4 };
	bool resultatCerca[MAX_PROVES][4] = {
		{false},
		{true, false},
		{true, true, true, false}
	};

	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> =======================================" << endl;
	cout << "Comment :=>> Iniciant test de la classe Persona ..." << endl;
	cout << "Comment :=>> Inicialitzant dades de la persona " << "NIU_1 " << "NOM_1 ..." << endl;
	for (int i = 0; i < MAX_PROVES; i++)
	{
		Persona p("NIU_1", "NOM_1");
		bool valid = true;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> TEST CLASSE PERSONA: PROVA " << i + 1 << endl;
		cout << "Comment :=>> Afegint assignatures ..." << endl;
		for (int j = 0; j < nAssignatures[i]; j++)
		{
			cout << "Comment :=>> Assignatura: " << grupsAssignatures[i][j].getNom() << " "
				<< grupsAssignatures[i][j].getCreditsEstudiant() << " " << grupsAssignatures[i][j].getCreditsProfessor() << endl;
			p.afegeixAssignatura(grupsAssignatures[i][j]);
		}
		cout << "Comment :=>> " << endl;
		for (int j = 0; j < nNomsCerca[i]; j++)
		{
			bool resultat;
			cout << "Comment :=>> Buscant si existeix assignatura: " << nomsCerca[i][j] << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatCerca[i][j]); cout << endl;
			cout << "Comment :=>> -------" << endl;
			resultat = p.cercaAssignatura(nomsCerca[i][j]);
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			if (resultat == resultatCerca[i][j])
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
	}
	return reduccio;
}


float testEstudiant()
{
	float reduccio = 0;
	const int MAX_PROVES = 3;
	GrupClasse grupsAssignatures[MAX_PROVES][4] = {
		{},
		{ { "ASSIG_1", 6, 12, 1, "dl, 9-11", 6 } },
		{ { "ASSIG_1", 6, 6 , 1, "dl 9-11", 6 },{ "ASSIG_2", 3, 6, 2, "dm 11-13", 3 },{ "ASSIG_3", 6, 4, 3, "dc 15-17", 4 },{ "ASSIG_4", 9, 10, 4, "dj 17-19", 6 } }
	};
	int nAssignatures[MAX_PROVES] = { 0, 1, 4 };
	string nomsCerca[MAX_PROVES][4] = {
		{ "ASSIG_1" },
		{ "ASSIG_1", "ASSIG_2" },
		{ "ASSIG_1", "ASSIG_2", "ASSIG_4", "ASSIG_5" }
	};
	int nNomsCerca[MAX_PROVES] = { 1, 2, 4 };
	bool resultatCerca[MAX_PROVES][4] = {
		{ false },
		{ true, false },
		{ true, true, true, false }
	};
	int resultatCredits[MAX_PROVES] = { 0, 6, 24 };

	Estudiant eInicial("NIU_1", "NOM_1", "TITULACIO_1");
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> =======================================" << endl;
	cout << "Comment :=>> Iniciant test de la classe Estudiant ..." << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ------------" << endl;
	cout << "Comment :=>> Inicialitzant dades de l'estudiant " << "NIU_1 " << "NOM_1 " << "TITULACIO_1 ..." << endl;
	cout << "Comment :=>> -------" << endl;
	cout << "Comment :=>> Comprovant inicialitzacio de les dades ..." << endl;
	cout << "Comment :=>> Nom: " << eInicial.getNom() << endl;
	cout << "Comment :=>> NIU: " << eInicial.getNiu() << endl;
	cout << "Comment :=>> Titulacio: " << eInicial.getTitulacio() << endl;
	if ((eInicial.getNom() != "NOM_1") || (eInicial.getNiu() != "NIU_1") || (eInicial.getTitulacio() != "TITULACIO_1"))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	for (int i = 0; i < MAX_PROVES; i++)
	{
		Estudiant e("NIU_1", "NOM_1", "TITULACIO_1");
		bool valid = true;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> TEST CLASSE ESTUDIANT: PROVA " << i + 1 << endl;
		cout << "Comment :=>> Afegint assignatures ..." << endl;
		for (int j = 0; j < nAssignatures[i]; j++)
		{
			cout << "Comment :=>> Assignatura: " << grupsAssignatures[i][j].getNom() << " "
				<< grupsAssignatures[i][j].getCreditsEstudiant() << " " << grupsAssignatures[i][j].getCreditsProfessor() << endl;
			e.afegeixAssignatura(grupsAssignatures[i][j]);
		}
		cout << "Comment :=>> " << endl;
		for (int j = 0; j < nNomsCerca[i]; j++)
		{
			bool resultat;
			cout << "Comment :=>> Buscant si existeix assignatura: " << nomsCerca[i][j] << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatCerca[i][j]); cout << endl;
			cout << "Comment :=>> -------" << endl;
			resultat = e.cercaAssignatura(nomsCerca[i][j]);
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			if (resultat == resultatCerca[i][j])
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}

		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> Comprovant numero de credits matriculats..." << endl;
		cout << "Comment :=>> Valor esperat: " << resultatCredits[i] << endl;
		cout << "Comment :=>> -------" << endl;
		int nCredits = e.getCreditsMatriculats();
		cout << "Comment :=>> Valor obtingut: " << nCredits << endl;
		if (nCredits != resultatCredits[i])
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;
	}
	return reduccio;
}


float testProfessor()
{
	float reduccio = 0;
	const int MAX_PROVES = 3;
	GrupClasse grupsAssignatures[MAX_PROVES][4] = {
		{},
		{ { "ASSIG_1", 6, 12, 1, "dl, 9-11", 6 } },
		{ { "ASSIG_1", 6, 6 , 1, "dl 9-11", 6 },{ "ASSIG_2", 3, 6, 2, "dm 11-13", 3 },{ "ASSIG_3", 6, 4, 3, "dc 15-17", 4 },{ "ASSIG_4", 9, 10, 4, "dj 17-19", 6 } }
	};
	int nAssignatures[MAX_PROVES] = { 0, 1, 4 };
	string nomsCerca[MAX_PROVES][4] = {
		{ "ASSIG_1" },
		{ "ASSIG_1", "ASSIG_2" },
		{ "ASSIG_1", "ASSIG_2", "ASSIG_4", "ASSIG_5" }
	};
	int nNomsCerca[MAX_PROVES] = { 1, 2, 4 };
	bool resultatCerca[MAX_PROVES][4] = {
		{ false },
		{ true, false },
		{ true, true, true, false }
	};
	int resultatCreditsGrup[MAX_PROVES] = { 0, 6, 19 };

	Professor pInicial("NIU_1", "NOM_1", "DEPARTAMENT_1", 24);
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> =======================================" << endl;
	cout << "Comment :=>> Iniciant test de la classe Professor ..." << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ------------" << endl;

	cout << "Comment :=>> Inicialitzant dades del professor " << "NIU_1 " << "NOM_1 " << "DEPARTAMENT_1 " << 24 << " ..." << endl;
	cout << "Comment :=>> -------" << endl;
	cout << "Comment :=>> Comprovant inicialitzacio de les dades ..." << endl;
	cout << "Comment :=>> Nom: " << pInicial.getNom() << endl;
	cout << "Comment :=>> NIU: " << pInicial.getNiu() << endl;
	cout << "Comment :=>> Titulacio: " << pInicial.getDepartament() << endl;
	if ((pInicial.getNom() != "NOM_1") || (pInicial.getNiu() != "NIU_1") || (pInicial.getDepartament() != "DEPARTAMENT_1") || (pInicial.getMaximCredits() != 24))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	for (int i = 0; i < MAX_PROVES; i++)
	{
		Professor p("NIU_1", "NOM_1", "DEPARTAMENT_1", 24);
		bool valid = true;
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> ------------" << endl;
		cout << "Comment :=>> TEST CLASSE PROFESSOR: PROVA " << i + 1 << endl;
		cout << "Comment :=>> Afegint assignatures ..." << endl;
		for (int j = 0; j < nAssignatures[i]; j++)
		{
			cout << "Comment :=>> Assignatura: " << grupsAssignatures[i][j].getNom() << " "
				<< grupsAssignatures[i][j].getCreditsEstudiant() << " " << grupsAssignatures[i][j].getCreditsProfessor() << endl;
			p.afegeixAssignatura(grupsAssignatures[i][j]);
		}
		cout << "Comment :=>> " << endl;
		for (int j = 0; j < nNomsCerca[i]; j++)
		{
			bool resultat;
			cout << "Comment :=>> Buscant si existeix assignatura: " << nomsCerca[i][j] << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatCerca[i][j]); cout << endl;
			cout << "Comment :=>> -------" << endl;
			resultat = p.cercaAssignatura(nomsCerca[i][j]);
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			if (resultat == resultatCerca[i][j])
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> Comprovant numero de credits impartits..." << endl;
		cout << "Comment :=>> Valor esperat: " << resultatCreditsGrup[i] << endl;
		cout << "Comment :=>> -------" << endl;
		int nCredits = p.getCreditsImpartits();
		cout << "Comment :=>> Valor obtingut: " << nCredits << endl;
		if (nCredits != resultatCreditsGrup[i])
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;
	}
	return reduccio;
}


int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl;
	cout << "Comment :=>> Iniciant test " << endl;
	cout << "Comment :=>> ==============" << endl;

	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testGrupClasse();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testPersona();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (2.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testEstudiant();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (3.0 - reduccio);

	cout << "Grade :=>> " << grade << endl;

	reduccio = testProfessor();
	if (reduccio > 5.0)
		reduccio = 5.0;
	grade += (3.0 - reduccio);


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
