#pragma once
#include<string>

using namespace std;

class Grup
{
public:
	Grup() : m_nGrup(0), m_horari("") {}
	Grup(int nGrup, const string& horari) : m_nGrup(nGrup), m_horari(horari) {}
	~Grup() {}

	int getGrup() const { return m_nGrup; }
	string getHorari() const { return m_horari; }

protected:
	int m_nGrup;
	string m_horari;
};
