#pragma once

template <class T>
void ordena(T vector[], int nElements)
{
	//bubble sort
	T aux;
	for (int i = 0; i < nElements; i++)
	{
		for (int j = 0; j < nElements - i - 1; j++)
		{
			if (vector[j] > vector[j + 1])
			{
				aux = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = aux;
			}
		}
	}
}

template <class T>
bool cercaBinaria(T vector[], const T& valor, int nElements)
{
	//binary search
	int inici = 0;
	int final = nElements - 1;
	bool trobat = false;

	while (!trobat && inici <= final)
	{
		int mig = (inici + final) / 2;
		if (vector[mig] == valor)
			trobat = true;
		else
		{
			if (vector[mig] > valor)
				final = mig - 1;
			if (vector[mig] < valor)
				inici = mig + 1;
		}
	}
	return trobat;
}
