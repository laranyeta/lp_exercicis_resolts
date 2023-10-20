#pragma once
#include <utility>
using namespace std;

template <class TClau, class TValor>
bool cercaBinaria(pair<TClau, TValor> vector[], const TClau& clau, int nElements, TValor& valor)
{
	//binary search
	int inici = 0;
	int final = nElements - 1;
	bool trobat = false;

	while (!trobat && inici <= final)
	{
		int mig = (inici + final) / 2;
		if (vector[mig].first == clau)
		{
			valor = vector[mig].second;
			trobat = true;
		}
		else
		{
			if (vector[mig].first > clau)
				final = mig - 1;
			if (vector[mig].first < clau)
				inici = mig + 1;
		}
	}
	return trobat;
}
