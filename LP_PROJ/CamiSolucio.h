#pragma once
#include "CamiBase.h"
#include "PuntDeInteresBase.h"
#include "CamiNode.h"

#include<vector>

using namespace std;

class CamiSolucio : public CamiBase
{
public:
	CamiSolucio();
	CamiSolucio(std::vector<Coordinate> coordenades);
	CamiSolucio(const XmlElement& element, vector<CamiNode*> nodes);
	~CamiSolucio() {}

	std::vector<Coordinate> getCamiCoords() { return m_camiCoords; }
	int getNCoords() { return m_nCoords; }
	

private:
	std::string m_name;
	std::vector<Coordinate> m_camiCoords;
	int m_nCoords;
};


