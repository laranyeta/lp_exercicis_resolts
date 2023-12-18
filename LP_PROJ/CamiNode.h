#pragma once

#include <string>
#include "PuntDeInteresBase.h"

using namespace std;

class CamiNode : public PuntDeInteresBase
{
public:
	CamiNode() { m_id = ""; }
	CamiNode(std::string id) {m_id = id;}
	CamiNode(Coordinate coordenades, std::string name, std::string id) : PuntDeInteresBase(coordenades, name), m_id(id) {}

	std::string getId() { return m_id; }

private:
	std::string m_id;

};
