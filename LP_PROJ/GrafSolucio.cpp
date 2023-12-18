#include"GrafSolucio.h"
#include"Util.h"

/////CONSTRUCTORS
GrafSolucio::GrafSolucio()
{
	m_nNodes = 0;
	m_nodes.resize(0);
}


GrafSolucio::GrafSolucio(const vector<CamiBase*>& cami)
{
	//inicialitzem el nombre de nodes a 0
	m_nNodes = 0;
	m_matriuAdj.resize(0);

	int posNode1, posNode2, nCoordenades;

	for (int i = 0; i < cami.size(); i++)
	{
		nCoordenades = cami[i]->getNCoords();
		posNode1 = inserirNode(cami[i]->getCamiCoords()[0]);

		for (int j = 0; j < nCoordenades - 1; j++)
		{
			posNode2 = inserirNode(cami[i]->getCamiCoords()[j+1]);
			inserirAresta(posNode1, posNode2);
			posNode1 = posNode2;
		}
	}
}

void GrafSolucio::construirGraf(const vector<CamiBase*>& camins)
{
	m_nNodes = 0;
	m_matriuAdj.resize(0);

	int posNode1, posNode2, nCoordenades;

	for (int i = 0; i < camins.size(); i++)
	{
		nCoordenades = camins[i]->getNCoords();
		posNode1 = inserirNode(camins[i]->getCamiCoords()[0]);

		for (int j = 0; j < nCoordenades - 1; j++)
		{
			posNode2 = inserirNode(camins[i]->getCamiCoords()[j+1]);
			inserirAresta(posNode1, posNode2);
			posNode1 = posNode2;
		}
	}
}

/////METODES D'INSERCIO
void GrafSolucio::inserirAresta(int posNode1, int posNode2)
{
	//INSERIM ARESTA A LA MATRIU D'ADJACENCIA
	
	//calculem pes
	double pes = Util::DistanciaHaversine(m_nodes[posNode1], m_nodes[posNode2]);

	//fiquem pesos a la matriu d'adjacencia
	m_matriuAdj[posNode1][posNode2] = pes;
	m_matriuAdj[posNode2][posNode1] = pes;
}

int GrafSolucio::inserirNode(const Coordinate& node)
{
	//FEM CERCA DE NODES
	std::vector<Coordinate>::iterator it = m_nodes.begin();
	bool trobat = false;

	while (!trobat && it != m_nodes.end())
	{
		if (*it == node)
			trobat = true;
		else
			it++;
	}
	//MIREM SI HEM ARRIBAT AL FINAL
	if (it == m_nodes.end())
	{
		//afegim al vector de coordenades
		m_nodes.resize(m_nNodes);
		m_nodes.push_back(node);

		//afegim a la matriu d'adjacencia
		m_matriuAdj.push_back(std::vector<double>(m_nNodes, 0));
        m_nNodes++;

		for (int i = 0; i < m_nNodes; i++)
			m_matriuAdj[i].resize(m_nNodes, 0);

		return (m_nodes.size() - 1);
	}
	else
		return (it - m_nodes.begin());
}

int GrafSolucio::distanciaMinima(vector<double>& distancia, vector<bool>& visitat)
{
	double min = DISTANCIA_MAXIMA; //la constant DISTANCIA_MAXIMA vindrà definida a la funció de l'algorisme de Dijkstra
	int minIndex = -1;

	//on i és la posició del vei que estem mirant
	for (int i = 0; i < m_nNodes; i++)
		if (!visitat[i] && distancia[i] <= min)
		{
			min = distancia[i];
			minIndex = i;
		}
	return minIndex;
	//si es retorna -1, significa que no existeix una camí
}

void GrafSolucio::dijkstra(int node1, int node2, vector<double>& distancia, vector<int>& anterior)
{
	//inicialitzem les distancies per cada node amb els seu respectius veins
	distancia.resize(m_nNodes, DISTANCIA_MAXIMA);
	
	vector<bool> visitat;
	visitat.resize(m_nNodes, false);
	//inicialitzem els nodes visitats a false
	anterior.resize(m_nNodes, -1);

	distancia[node1] = 0;
	anterior[node1] = node1;

	//on i es un comptador
	for (int i = 0; i < m_nNodes - 1; i++)
	{
		int posVeiActual = distanciaMinima(distancia, visitat);
		//marquem el vei actual del node com a visitat
		if (posVeiActual != -1)
		{
			visitat[posVeiActual] = true;
			if (posVeiActual == node2)
				return;
			//on j es l'iterador per recorrer les columnes de la fila posVeiActual
			for (int j = 0; j < m_nNodes; j++)
			{
			    if (m_matriuAdj[posVeiActual][j] != 0)
			    {
			        //si hi ha una aresta
					if (!visitat[j]) //si no hem visitat el vei j del vei actual posVeiActual
						if (distancia[posVeiActual] + m_matriuAdj[posVeiActual][j] < distancia[j])
						{
							distancia[j] = distancia[posVeiActual] + m_matriuAdj[posVeiActual][j];
							anterior[j] = posVeiActual;
						}
			    }
					 
			}
			
							
		}
	}
}

stack<Coordinate> GrafSolucio::camiMesCurt(const Coordinate& coordenada1, const Coordinate& coordenada2)
{
	vector<Coordinate>::iterator itCoordenada1 = m_nodes.begin();
	vector<Coordinate>::iterator itCoordenada2 = m_nodes.begin();
	bool trobat = false;

	while (!trobat && itCoordenada1 != m_nodes.end())
	{
		if (*itCoordenada1 == coordenada1)
			trobat = true;
		else
			itCoordenada1++;
	}
	trobat = false;

	while (!trobat && itCoordenada2 != m_nodes.end())
	{
		if (*itCoordenada2 == coordenada2)
			trobat = true;
		else
			itCoordenada2++;
	}

	stack<Coordinate> camiFinal;

	if ((itCoordenada1 != m_nodes.end()) && (itCoordenada2 != m_nodes.end()))
	{
		int posNode1 = itCoordenada1 - m_nodes.begin();
		int posNode2 = itCoordenada2 - m_nodes.begin();

		vector<double> vectorDistancia;
		vector<int> anterior;

		dijkstra(posNode1, posNode2, vectorDistancia, anterior);

		int it = posNode2;
		camiFinal.push(m_nodes[posNode2]);

		while (it != posNode1)
		{
			camiFinal.push(m_nodes[anterior[it]]);
			it = anterior[it];
		}
	}
	return camiFinal;
}


