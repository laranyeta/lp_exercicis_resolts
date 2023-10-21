#pragma once
#include <iostream>
#include <string>
#include "Data.h"
using namespace std;
class Prestec 
{
public:
	Prestec() { m_numExemplar = 0; }
	Prestec(string idUsuari, string codiPublicacio, Data dataPrestec, Data dataRetorn, int numExemplar = 0) 
	{
		m_idUsuari = idUsuari;
		m_codiPublicacio = codiPublicacio;
		m_dataPrestec = dataPrestec;
		m_numExemplar = numExemplar;
		m_dataRetorn = dataRetorn;
	}
	string getidUsuari() const { return m_idUsuari; }
	string getCodiPublicacio() const { return m_codiPublicacio; }
	Data getDataPrestec() const { return m_dataPrestec; }
	int getnExemplar() const { return m_numExemplar; }
	Data getDataRetorn() const { return m_dataRetorn; }
private:
	string m_idUsuari;
	string m_codiPublicacio;
	Data m_dataPrestec;
	Data m_dataRetorn;
	int m_numExemplar;
};
