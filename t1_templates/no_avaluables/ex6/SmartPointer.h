#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:
	SmartPointer() { m_pointer = nullptr; m_comptador = nullptr; }
	SmartPointer(SmartPointer<T>& p);

	SmartPointer<T>& operator=(T* p); 
	SmartPointer<T>& operator=(SmartPointer& p); 
	T& operator*(); 
	T* operator->(); 

	bool isNull();
private:
	T* m_pointer;
	int* m_comptador;
};

template<class T>
SmartPointer<T>::SmartPointer(SmartPointer<T>& p)
{
	m_pointer = p.m_pointer;
	m_comptador = p.m_comptador;

	if (m_comptador)
		m_comptador++;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(T* p)
{
	if (m_pointer != nullptr)
	{
		if (m_comptador)
		{
			m_comptador--;
			if (m_comptador == 0)
			{
				delete m_pointer;
				delete m_comptador;
			}	
		}
		
	}
	m_pointer = p;
	if (m_pointer)
		m_comptador = new int(1);
	else
		m_comptador = nullptr;

	return *this;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer& p)
{
	if (this != &p)
	{
		if (m_pointer != nullptr)
		{
			if (m_comptador)
			{
				if (m_comptador == 0)
				{
					delete m_pointer;
					delete m_comptador;
				}
			}
		}
		m_pointer = p.m_pointer;
		m_comptador = p.m_comptador;

		if (m_comptador)
			m_comptador++;
	}
	return *this;
}

template <class T>
T& SmartPointer<T>::operator*()
{
	if (isNull())
		cout << "ERROR: Pointer apunta a NULL." << endl;

	return *m_pointer; //retorna contingut apuntador
}

template<class T>
T* SmartPointer<T>::operator->()
{
	if (isNull())
		cout << "ERROR: Pointer apunta a NULL." << endl;

	return m_pointer; //retorna adreça apuntador
}

template<class T>
bool SmartPointer<T>::isNull()
{
	if (m_pointer == nullptr)
		return true;
	return false;
}
