#pragma once
#include "Data.h"
#include <string>
#include <list>
#include <iostream>
#include <vector>
#include "Publicacio.h"
#include "Llibre.h"
#include "Revista.h"
#include "Prestec.h"

class Biblioteca
{
public:
	Biblioteca() {}
	~Biblioteca() {}
	void llegirPublicacions(const string& nomFitxer);
	bool prestar(const string& idUsuari, const string& codi, const Data& dataPrestec, Data& dataRetorn, int nExemplar = 0);
	bool retornar(const string& idUsuari, const string& codi, const Data& data, bool& dataCorrecta, int nExemplar = 0);
private:
	list<Publicacio*> m_llistaPublicacions;
	list<Prestec> m_prestecs;
};
