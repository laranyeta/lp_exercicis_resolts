#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
public:
	SmartPointer() { m_pointer = nullptr; }
	SmartPointer(SmartPointer<T>& p);

	SmartPointer<T>&operator=(T* p); //a partir d'apuntador normal (tipus T)
	SmartPointer<T>&operator=(SmartPointer& p); //a partir d'apuntador intel·ligent (tipus SmartPointer)
	T& operator*(); //per accedir al contigut de l'apuntador
	T* operator->(); //sobrecarrega operador apuntador

	bool isNull();
private:
	T *m_pointer;
};

template<class T>
SmartPointer<T>::SmartPointer(SmartPointer<T>& p)
{
	m_pointer = p.m_pointer;
	p.m_pointer = nullptr;
}

template <class T>
SmartPointer<T>& SmartPointer<T>::operator=(T*p)
{
	if (m_pointer != nullptr)
		delete m_pointer;

	m_pointer = p;

	return *this;
}

template<class T>
SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer& p)
{
	if (m_pointer != nullptr)
		delete m_pointer;

	m_pointer = p.m_pointer;
	p.m_pointer = nullptr;

	return *this;
}

template <class T>
T &SmartPointer<T>::operator*()
{
	if (isNull())
		cout << "ERROR: Pointer apunta a NULL." << endl;

	return *m_pointer; //retorna contingut apuntador
}

template<class T>
T *SmartPointer<T>::operator->()
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


