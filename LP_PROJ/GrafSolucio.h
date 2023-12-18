#ifndef GRAF_H
#define GRAF_H

#include <vector>
#include <string>
#include <stack>
#include <list>
#include<limits>
#include<cstdio>
#include "CamiBase.h"

using namespace std;

const double DISTANCIA_MAXIMA{ numeric_limits<double>::max() };

class GrafSolucio
{
public:
	/////CONSTRUCTORS
	GrafSolucio();
	GrafSolucio(const vector<CamiBase*>& cami);
	~GrafSolucio() {}

	/////METODES
	void construirGraf(const vector<CamiBase*>& camins);

	void inserirAresta(int posNode1, int posNode2);
	int inserirNode(const Coordinate& node);

	int distanciaMinima(vector<double>& distancia, vector<bool>& visitat);
	void dijkstra(int node1, int node2, vector<double>& distancia, vector<int>& anterior);

	stack<Coordinate> camiMesCurt(const Coordinate& c1, const Coordinate& c2);
private:
	vector<Coordinate> m_nodes;
	vector<vector<double>> m_matriuAdj;
	int m_nNodes;
};
#endif
