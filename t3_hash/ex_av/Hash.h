#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

//Amb col�lisions sondeig quadratic:

class Hash
{
public:
	Hash(int sizeIni=15, const string& descripcioDefecte="Definicio no existent");
	~Hash();
	string& operator[](const string& clau);
	//pair<string, string>& operator[](const int& index);
	void insert(const string& clau, const string& descripcio);	
	bool find(const string&clau, string& definicio);
	bool esborra(const string& clau);
	void mostra();
	
private:
	int codi(string s) const;	
	int codi2(int index, int vegades) const;
	int cerca(const string& clau) const;
	
	std::vector<std::pair<string, string> > m_diccionari;
	std::vector<int> m_estat;
	int m_numOcupats;
	int m_maxElements;
	string m_descripcioDefecte;

	static const int LLIURE = 0;
	static const int OCUPAT = 1;
	static const int ESBORRAT = 2;
};
