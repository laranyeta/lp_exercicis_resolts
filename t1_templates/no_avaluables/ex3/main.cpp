#include "Vector.h"
#include "Persona.h"
#include <iostream>
using namespace std;

template <class T>
bool comparaVectors(Vector<T> &v, T* resultat, int longitud)
{
	bool iguals = (longitud == v.longitud());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			if (!(resultat[i] == v[i]))
				iguals = false;
			else
				i++;
		}
	}
	return iguals;
}

template <class T>
void escriuVector(Vector<T> &v, int nValors)
{
	cout << "[";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << v[i] << ",";
	}
	if (nValors > 0)
		cout << v[nValors - 1];
	cout << "]";
}

template <class T>
void escriuValors(T valors[], int nValors)
{
	cout << "[";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << valors[i] << ",";
	}
	if (nValors > 0)
		cout << valors[nValors - 1];
	cout << "]";
}


int main()
{
	bool valid = true;
	float reduccio = 0.0;
	float grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	const int MAX_PROVES = 6;

	int resultat[MAX_PROVES][20] = {
		{ 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5 },
		{ 9, 8, 7, 6, 5, 0, 1, 2, 3, 4, 14, 13, 12, 11, 10, 15, 16, 17, 18, 19 },
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 }
	};
	int longitudResultat[MAX_PROVES] = { 10, 5, 5, 5, 20, 20 };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la classe VECTOR per elements de tipus INT" << endl;
	cout << "Comment :=>> ===========================================================" << endl;
	cout << "Comment :=>>  " << endl << endl;

	cout << "Comment :=>> Redimensionant i inicialitzant vector ....................... " << endl;
	Vector<int> v;
	v.redimensiona(10);
	for (int i = 0; i < 10; i++)
		v[i] = 10 - (i + 1);
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[0], longitudResultat[0]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v, longitudResultat[0]); cout << endl;

	valid = comparaVectors(v, resultat[0], longitudResultat[0]);
	if (!valid)
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;

	grade += (0.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Redimensionant el vector a un tamany mes petit ....................... " << endl;
	v.redimensiona(5);
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[1], longitudResultat[1]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v, longitudResultat[1]); cout << endl;
	
	if (!comparaVectors(v, resultat[1], longitudResultat[1]))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> ----------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Comprovant operador d'assignacio entre vectors ....................... " << endl;
	Vector<int> v2 = v;
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[2], longitudResultat[2]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v2, longitudResultat[2]); cout << endl;	

	if (!comparaVectors(v2, resultat[2], longitudResultat[2]))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> -------------------------------------------------------" << endl;
	cout << "Comment :=>> Comprovant constructor de copia ....................... " << endl;
	Vector<int> v3(v);
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[3], longitudResultat[3]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v3, longitudResultat[3]); cout << endl;		
	if (!comparaVectors(v3, resultat[3], longitudResultat[3]))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	cout << endl;
	cout << "Comment :=>> --------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Redimensionant un vector a un tamany mes gran ....................... " << endl;
	v.redimensiona(20);
	for (int i = 5; i < 10; i++)
		v[i] = i - 5;
	for (int i = 10; i < 15; i++)
		v[i] = 15 - (i - 10) - 1;
	for (int i = 15; i < 20; i++)
		v[i] = i;
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[4], longitudResultat[4]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v, longitudResultat[4]); cout << endl;

	if (!comparaVectors(v, resultat[4], longitudResultat[4]))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (0.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	cout << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Ordenant el vector ....................... " << endl;	
	v.sort();
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(resultat[5], longitudResultat[5]); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(v, longitudResultat[5]); cout << endl; 
	if (!comparaVectors(v, resultat[5], longitudResultat[5]))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	const int MAX_PERSONES = 10;
	Persona persones[MAX_PERSONES] = { { "B", 20 },{ "A", 20 },{ "B", 30 },{ "D", 40 },{ "C", 50 },
	{ "C", 20 },{ "D", 25 },{ "E", 30 },{ "B", 40 },{ "D", 30 } };
	Persona personesResultat[MAX_PERSONES] = { { "A", 20 },{ "B", 20 },{ "C", 20 },{ "D", 25 },{ "B", 30 },
	{ "D", 30 },{ "E", 30 },{ "B", 40 },{ "D", 40 },{ "C", 50 } };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la classe VECTOR per elements de tipus PERSONA" << endl;
	cout << "Comment :=>> ===============================================================" << endl;
	cout << "Comment :=>>  " << endl << endl;

	Vector<Persona> vPersona;
	cout << endl;
	cout << "Comment :=>> --------------------------------------------------------------" << endl;
	cout << "Comment :=>> Redimensionant i incialitzant el vector ....................... " << endl;
	vPersona.redimensiona(MAX_PERSONES);
	for (int i = 0; i < MAX_PERSONES; i++)
		vPersona[i] = persones[i];
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(persones, MAX_PERSONES); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(vPersona, MAX_PERSONES); cout << endl;
	if (!comparaVectors(vPersona, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	cout << endl;
	cout << "Comment :=>> ---------------------------------------------------------------" << endl;
	cout << "Comment :=>> Realitzant assignacio entre dos vectors ....................... " << endl;
	Vector<Persona> vPersona2 = vPersona;
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(persones, MAX_PERSONES); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(vPersona2, MAX_PERSONES); cout << endl;
	if (!comparaVectors(vPersona2, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio += .0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> ---------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Inicialitzant vector amb constructor de copia ....................... " << endl;
	Vector<Persona> vPersona3(vPersona);
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(persones, MAX_PERSONES); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(vPersona3, MAX_PERSONES); cout << endl;
	if (!comparaVectors(vPersona3, persones, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	Persona p;
	cout << endl;
	cout << "Comment :=>> -------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Recuperant Persona fora dels l�mits del vector (index negatiu) ....................... " << endl;
	p = vPersona[-1];
	cout << "Comment :=>> Resultat esperat: " << Persona() << endl ;
	cout << "Comment :=>> Resultat obtingut: " << p << endl;
	if ((p.getNom() != "") && (p.getEdat() != 0))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (0.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> -----------------------------------------------------------------------------------------------" << endl;
	cout << "Comment :=>> Recuperant Persona fora dels l�mits del vector (index superior al limit) ....................... " << endl;
	p = vPersona[MAX_PERSONES];
	cout << "Comment :=>> Resultat esperat: " << Persona() << endl;
	cout << "Comment :=>> Resultat obtingut: " << p << endl;
	if ((p.getNom() != "") && (p.getEdat() != 0))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (0.5 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> -----------------------------------------" << endl;
	cout << "Comment :=>> Ordenant el vector ....................... " << endl;
	vPersona.sort();
	cout << "Comment :=>> Resultat esperat: " << endl;
	cout << "Comment :=>> "; escriuValors(personesResultat, MAX_PERSONES); cout << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	cout << "Comment :=>> "; escriuVector(vPersona, MAX_PERSONES); cout << endl;
	if (!comparaVectors(vPersona, personesResultat, MAX_PERSONES))
	{
		valid = false;
		cout << "Comment :=>> ERROR" << endl;
		reduccio = 2.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	grade += (1.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;
	if (grade < 0)
		grade = 0;
	cout << endl << "Grade :=>> " << grade << endl;

	return 0;
}
