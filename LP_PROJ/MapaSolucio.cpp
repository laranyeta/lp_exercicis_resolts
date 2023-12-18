#include "MapaSolucio.h" 
#include"Util.h"
#include"CamiSolucio.h"
#include<stack>

MapaSolucio::MapaSolucio()
{
	m_puntInteres.resize(0);
	m_camins.resize(0);
	m_camiNode.resize(0);
	m_ballTree = new BallTree;
}

MapaSolucio::~MapaSolucio()
{
	for (auto itPunt = m_puntInteres.begin(); itPunt != m_puntInteres.end(); itPunt++)
		delete* itPunt;
	m_puntInteres.clear();

	for (auto itCami = m_camins.begin(); itCami != m_camins.end(); itCami++)
		delete* itCami;
	m_camins.clear();
	
	for (auto itCamiNode = m_camiNode.begin(); itCamiNode != m_camiNode.end(); itCamiNode++)
		delete* itCamiNode;
	m_camiNode.clear();
}

void MapaSolucio::parsejaXmlElements(std::vector<XmlElement>& xmlElements)
{
	//ALLIBEREM CONTINGUT DELS ATRIBUTS DE PUNT INTERES I CAMINS
	for (auto itPunt = m_puntInteres.begin(); itPunt != m_puntInteres.end(); itPunt++)
		delete* itPunt;
	m_puntInteres.clear();

	for (auto itCami = m_camins.begin(); itCami != m_camins.end(); itCami++)
		delete* itCami;
	m_camins.clear();

	std::vector<XmlElement> nodesXml;
	std::vector<XmlElement> caminsXml;

	//RECORREM EL VECTOR xmlElements
	for (int i = 0; i < xmlElements.size(); i++)
	{
		//NODE
		if (xmlElements[i].id_element == "node") //si és un node
			nodesXml.push_back(xmlElements[i]); //afegim al vector de nodes
		//CAMI
		if (xmlElements[i].id_element == "way") //si és un camí
			caminsXml.push_back(xmlElements[i]); //afegim al vector de camins
	}

	//PARSEJEM PUNTS D'INTERES

	for (auto itNode = nodesXml.begin(); itNode < nodesXml.end(); itNode++)
	{
		for (auto itFills = itNode->fills.begin(); itFills < itNode->fills.end(); itFills++)
		{
			if (itFills->first == "tag")
			{
				//ES RESTAURANT
				std::pair<std::string, std::string> valorTag = Util::kvDeTag(itFills->second); //per al pair del make_pair(second)
				if (valorTag.first == "amenity")
				{
					Coordinate coord = { 0.0, 0.0 };
					std::string name = "undefinit";
					std::string cuisine = "undefinit";
					std::string wheelchair = "undefinit";

					for (auto itAtribut = itNode->atributs.begin(); itAtribut < itNode->atributs.end(); itAtribut++)
					{
						if (itAtribut->first == "lat")
							coord.lat = std::stod(itAtribut->second);
						if (itAtribut->first == "lon")
							coord.lon = std::stod(itAtribut->second);
					}

					for (auto itFillSegon = itNode->fills.begin(); itFillSegon < itNode->fills.end(); itFillSegon++)
					{
						if (itFillSegon->first == "tag")
						{
							std::pair<std::string, std::string> valorTagSegon = Util::kvDeTag(itFillSegon->second);
							if (valorTagSegon.first == "name")
								name = valorTagSegon.second;
							if (valorTagSegon.first == "cuisine")
								cuisine = valorTagSegon.second;
							if (valorTagSegon.first == "wheelchair")
								wheelchair = valorTagSegon.second;
						}
					}

					if (name != "undefinit")
						m_puntInteres.push_back(new PuntDeInteresRestaurantSolucio(coord, name, wheelchair, cuisine));
				}
			}
			//ES BOTIGA
			if (itFills->first == "tag")
			{
				std::pair<std::string, std::string> valorTag = Util::kvDeTag(itFills->second);
				if (valorTag.first == "shop")
				{
					Coordinate coord = { 0.0, 0.0 };
					std::string name = "undefinit";
					std::string shop = "undefinit";
					std::string wheelchair = "undefinit";
					std::string openingHours = "undefinit";

					for (auto itAtribut = itNode->atributs.begin(); itAtribut < itNode->atributs.end(); itAtribut++)
					{
						if (itAtribut->first == "lat")
							coord.lat = std::stod(itAtribut->second);
						if (itAtribut->first == "lon")
							coord.lon = std::stod(itAtribut->second);
					}

					for (auto itFillSegon = itNode->fills.begin(); itFillSegon < itNode->fills.end(); itFillSegon++)
					{
						if (itFillSegon->first == "tag")
						{
							std::pair<std::string, std::string> valorTagSegon = Util::kvDeTag(itFillSegon->second);
							if (valorTagSegon.first == "name")
								name = valorTagSegon.second;
							if (valorTagSegon.first == "shop")
								shop = valorTagSegon.second;
							if (valorTagSegon.first == "opening_hours")
								openingHours = valorTagSegon.second;
							if (valorTagSegon.first == "wheelchair")
								wheelchair = valorTagSegon.second;
						}
					}
					if (name != "undefinit")
						m_puntInteres.push_back(new PuntDeInteresBotigaSolucio(coord, name, wheelchair, shop, openingHours));
				}
			}
		}
	}

	//PARSEJEM CAMINS
	for (int index = 0; index < caminsXml.size(); index++)
	{
		XmlElement camiActual;
		double nodeCamiActual = 0.0;
		double nodeActual = 0.0;
		std::vector<double> nodesCami;
		std::vector<Coordinate> coordenadesCami;

		camiActual = caminsXml[index];

		for (int i = 0; i < camiActual.fills.size(); i++)
		{
			if (camiActual.fills[i].first == "nd")
				nodesCami.push_back(std::stod(camiActual.fills[i].second[0].second)); // = valorTag.fills[i].first

		}

		for (int i = 0; i < nodesCami.size(); i++)
		{
			nodeCamiActual = nodesCami[i];

			for (int j = 0; j < nodesXml.size(); j++)
			{
				for (int k = 0; k < camiActual.atributs.size(); k++)
					if (camiActual.atributs[k].first == "id")
						nodeActual = std::stod(nodesXml[j].atributs[k].second);

				if (nodeActual == nodeCamiActual)
				{
					double latitud = 0.0;
					double longitud = 0.0;

					for (int indexAtribut = 0; indexAtribut < nodesXml[j].atributs.size(); indexAtribut++)
					{
						if (nodesXml[j].atributs[indexAtribut].first == "lat")
							latitud = std::stod(nodesXml[j].atributs[indexAtribut].second);
						if (nodesXml[j].atributs[indexAtribut].first == "lon")
							longitud = std::stod(nodesXml[j].atributs[indexAtribut].second);
					}
					Coordinate coordNova{ latitud, longitud };
					coordenadesCami.push_back(coordNova);
				}
			}
		}

		//COMPROVEM QUE NO HI HAGI CAMINS REPETITS
		std::vector<Coordinate> clonCoordenades = coordenadesCami;
		int vegades;

		for (auto itOriginal = coordenadesCami.begin(); itOriginal < coordenadesCami.end(); itOriginal++)
		{
			vegades = 0;
			for (auto itClon = clonCoordenades.begin(); itClon < clonCoordenades.end(); itClon++)
			{
				if (itOriginal->lat == itClon->lat && itOriginal->lon == itClon->lon)
				{
					vegades++;

					if (vegades > 1)
					{
						clonCoordenades.erase(itClon);
						break;
					}
				}
			}
		}
		m_camins.push_back(new CamiSolucio(clonCoordenades));
	}
}

CamiBase* MapaSolucio::buscaCamiMesCurt(PuntDeInteresBase* desde, PuntDeInteresBase* a)
{
	Coordinate origen = m_ballTree->nodeMesProper(desde->getCoord(), origen, m_ballTree);
	Coordinate desti = m_ballTree->nodeMesProper(a->getCoord(), desti, m_ballTree);

	stack<Coordinate> camiStack;
	vector<Coordinate> camiVector;

	camiStack = m_graf.camiMesCurt(origen, desti);
	camiVector.resize(camiStack.size());
	int i = 0;

	while (!camiStack.empty())
	{
		camiVector[i] = camiStack.top();
		camiStack.pop();
		i++;
	}

	CamiBase* camiResultat = new CamiSolucio(camiVector);

	return camiResultat;
}
