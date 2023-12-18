#pragma once
#include "MapaBase.h"
#include "Common.h"
#include <vector>
#include "Util.h"
#include "PuntDeInteresRestaurantSolucio.h"
#include "PuntDeInteresBotigaSolucio.h"
#include "CamiNode.h"
#include "CamiSolucio.h"
#include "GrafSolucio.h"
#include "BallTree.h"

class MapaSolucio : public MapaBase
{
public:
	MapaSolucio();
	~MapaSolucio();
	void getPdis(vector<PuntDeInteresBase*>& pdis) { pdis = m_puntInteres; }
	void getCamins(vector<CamiBase*>& camins) { camins = m_camins; }
	void parsejaXmlElements(vector<XmlElement>& xmlElements);

	CamiBase* buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a);
private:
	GrafSolucio m_graf;
	BallTree* m_ballTree;

	std::vector<CamiBase*> m_camins;
	std::vector<PuntDeInteresBase*> m_puntInteres;
	std::vector<CamiNode*> m_camiNode;

};

