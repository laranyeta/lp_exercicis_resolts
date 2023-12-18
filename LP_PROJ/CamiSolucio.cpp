#include "Common.h"
#include<vector>
#include "CamiSolucio.h"

CamiSolucio::CamiSolucio()
{
	m_camiCoords.resize(0);
	m_nCoords = 0;
}

CamiSolucio::CamiSolucio(std::vector<Coordinate> coordenades)
{
	m_nCoords = 0;

	for (int i = 0; i < coordenades.size(); i++)
	{
		m_camiCoords.push_back(coordenades[i]);
		m_nCoords++;
	}
}

CamiSolucio::CamiSolucio(const XmlElement& element, std::vector<CamiNode*> nodes)
{

	for (int i = 0; i < element.fills.size(); i++)
	{
		if (element.fills[i].first == "nd")
		{
			std::string id = element.fills[i].second[0].second;
			bool trobat = false;
			int j = 0;
			while (!trobat && j < nodes.size())
			{
				if (nodes[j]->getId() == id)
				{
					trobat = true;
					Coordinate c{ nodes[j]->getCoord().lat, nodes[j]->getCoord().lon };
					m_camiCoords.push_back(c);
				}
				j++;
			}
		}
		if (element.fills[i].second[0].second == "name")
			m_name = element.fills[i].second[1].second;
	}

	m_nCoords = m_camiCoords.size();

}
