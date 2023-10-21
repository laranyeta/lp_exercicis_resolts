#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

template<class T>
class Vector
{
public:
	Vector() : m_vector(nullptr), m_nElements(0), m_valorDefecte() {}
	Vector(const Vector& v); 
	~Vector();
	
	void redimensiona(int tamany);
	int longitud() { return m_nElements; }
	void sort();

	T& operator[](int nIndex);
	Vector<T>& operator=(const Vector<T>& v);

private:
	int m_nElements;
	T *m_vector; //array dinamic
	T m_valorDefecte;
};

template<class T>
Vector<T>::~Vector()
{
	//destructor
	delete[] m_vector;
	m_vector = nullptr;
}

template<class T>
Vector<T>::Vector(const Vector& v)
{
	//constructor copia
	m_nElements = v.m_nElements;

	if (m_nElements > 0)
	{
		m_vector = new T[m_nElements];
		for (int i = 0; i < m_nElements; i++)
			m_vector[i] = v.m_vector[i];
	}
	else
		m_vector = nullptr;
}

template<class T>
void Vector<T>::redimensiona(int tamany)
{
	//redimensionar array dinamic (reservant memoria)
	if (tamany != m_nElements)
	{
		if (tamany > 0)
		{
			T* nouVector;
			nouVector = new T[tamany];
			if (m_nElements > 0)
			{
				for (int i = 0; i < tamany; i++)
					nouVector[i] = m_vector[i];
				delete[] m_vector;
			}
			m_nElements = tamany;
			m_vector = nouVector;
		}
	}
	else
	{
		if (m_nElements > 0)
		{
			delete[] m_vector;
			m_vector = nullptr;
			m_nElements = 0;
		}
	}
}

template<class T>
void Vector<T>::sort()
{
	//ordena array dinamic (bubble sort)
	T aux;
	for (int i = 0; i < m_nElements; i++)
	{
		for (int j = 0; j < m_nElements - i - 1; j++)
		{
			if (m_vector[j] > m_vector[j + 1])
			{
				aux = m_vector[j];
				m_vector[j] = m_vector[j + 1];
				m_vector[j + 1] = aux;
			}
		}
	}
}

template<class T>
T& Vector<T>::operator[](int nIndex)
{
	//per poder accedir a qualsevol element de l'array dinamic
    if (nIndex >= 0 && nIndex < m_nElements)
	    return m_vector[nIndex];
	else
	{
	    cout << "ERROR! Index fora de limit.";
	    return m_valorDefecte;
	}
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)
{
	//operador assignacio
	if (this != &v)
	{
		if (m_nElements > 0)
			delete[] m_vector;
		m_nElements = v.m_nElements;
		m_vector = new T[m_nElements];

		for (int i = 0; i < m_nElements; i++)
			m_vector[i] = v.m_vector[i];
	}
	return *this;
}
