#include "BallTree.h"

using namespace std;

void BallTree::construirArbre(std::vector<Coordinate> coordenades) {
    // TODO: Utilitza aquest metode per construir el teu BallTree
    // TODO: amb les coordenades que se us passen per parametre

    //MIREM QUINES SON LES COORDENADES QUE NO ES REPETEIXEN EN EL VECTOR
    std::vector<Coordinate>::iterator it;
    std::vector<Coordinate> coordSenseRepeticio;

    //ITEREM SOBRE EL VECTOR DE COORDENADES QUE ES PASSA PER PARAMETRE
    for (int i = 0; i < coordenades.size(); i++)
    {
        it = std::find(coordenades.begin(), coordenades.end(), coordenades[i]); //find() calcula la posicio on esta troba per primer cop un element dins un vector
        if (it - coordenades.begin() == i) //mirem si la distancia de l'inici a l'iterador it coincideix amb la posicio del vector on estem mirant (i)
            coordSenseRepeticio.push_back(coordenades[i]); //afegim la coordenada en qüestió
    }

    //IMPLEMENTACIÓ BALL TREE
    m_root = this;
    m_coordenades = coordSenseRepeticio; //només mirarem per les coordenades que no es repeteixen

    //////SEGUIM DIAGRAMA DE FLUX//////
    // 1. Calcula punt central dels nodes //
    Coordinate puntC = Util::calcularPuntCentral(coordSenseRepeticio);
    // 2. Calcula distancia dels nodes respecte punt C, s'agafa el punt mes llunya A //
    Coordinate puntA = calculaPuntLlunya(coordSenseRepeticio, puntC);
    // 3. Calcula distancia dels nodes respecte punt A, s'agafa el punt més llunya B //
    Coordinate puntB = calculaPuntLlunya(coordSenseRepeticio, puntA); //calculem quin es el punt mes llunya des del primer punt mes llunya

    ////// ESTABLIM RELACIONS //////
    std::vector<Coordinate> partDreta, partEsquerra; //guarda els recorreguts de la part dreta i part esquerra del ball tree

    dretaOEsquerra(partEsquerra, partDreta, coordSenseRepeticio, puntA, puntB);
    
    BallTree* fill = new BallTree; //creem un nou fill
    //l'arrel serà el node que estem mirant
    //aplicacio recursiva per cada bola de l'arbre que s'estigui computant
    m_pivot = puntC; //el pivot es el punt C
    m_left = construirArbreRecursiu(partEsquerra);
    m_right = construirArbreRecursiu(partDreta);
    m_radi = Util::DistanciaHaversine(puntC, puntA); //el radi es la distancia des del punt A

}

void BallTree::inOrdre(std::vector<std::list<Coordinate>>& out) 
{
    if (m_left != nullptr)
        m_left->inOrdre(out);

    std::list<Coordinate> coordenades;

    for (int i = 0; i < m_coordenades.size(); i++)
        coordenades.push_back(m_coordenades[i]);

    out.push_back(coordenades);

    if (m_right != nullptr)
        m_right->inOrdre(out);
}

void BallTree::preOrdre(std::vector<std::list<Coordinate>>& out)
{
    std::list<Coordinate> coordenades;

    for (int i = 0; i < m_coordenades.size(); i++)
        coordenades.push_back(m_coordenades[i]);

    out.push_back(coordenades);

    if (m_left != nullptr)
        m_left->preOrdre(out);

    if (m_right != nullptr)
        m_right->preOrdre(out);
}

void BallTree::postOrdre(std::vector<std::list<Coordinate>>& out)
{
    if (m_left != nullptr)
        m_left->postOrdre(out);

    if (m_right != nullptr)
        m_right->postOrdre(out);

    std::list<Coordinate> coordenades;

    for (int i = 0; i < m_coordenades.size(); i++)
        coordenades.push_back(m_coordenades[i]);

    out.push_back(coordenades);
}

Coordinate BallTree::nodeMesProper(Coordinate targetQuery, Coordinate& Q, BallTree* ball) {
    ////////// TODO: TASCA 3 //////////
           /// DEFINICIONS ///
    //pdi: coordenades punt interes (target query)
    //bola actual: ball (area del ball tree que estem mirant)
    //Q: coordenada node-cami


    if (ball == nullptr)
        return Q;
    else
    {
        if ((Util::DistanciaHaversine(targetQuery, ball->m_pivot) - ball->m_radi) >= Util::DistanciaHaversine(targetQuery, Q))
            return Q;
        else
        {
            if (ball->m_radi == 0)
            {
                if (Util::DistanciaHaversine(targetQuery, ball->m_coordenades[0]) < Util::DistanciaHaversine(targetQuery, Q))
                Q = ball->m_coordenades[0];
            }
            else
            {
                if (ball->m_left != nullptr && ball->m_right != nullptr)
                {
                    nodeMesProper(targetQuery, Q, ball->m_left);
                    nodeMesProper(targetQuery, Q, ball->m_right);
                }
            
            }
        }
        return Q; 
    }
    //si la bola es una fulla, actualitza Q si es el node camí més proper al punt d'interes (dels punts que formen la bola)//
    // que bola sigui fulla vol dir que no té radi, al ser l'ultim node per mirar --> fulla.radi = 0.0//


    //sino:
        //calcula distancia pdi respecte el punt central de la bola esquerre (Da) --> ball->m_left->m_pivot//
        //calcula distancia pdi respecte el punt central de la bola dreta (Db) --> ball->m_right->m_pivot//
        //Si Da < Db --> cerca primer l'esquerra, despres la dreta //
        //Si Da >= Db, cerca primer la dreta i despres l'esquerra //
}

Coordinate BallTree::calculaPuntLlunya(const vector<Coordinate>& coordenades, const Coordinate& ref)
{
    //METODE PER CALCULAR VALORS MAXIMS (TANT VALOR COM DISTANCIA)
    Coordinate valorMaxim = coordenades[0]; //coordenada mes llunyana
    double distanciaMaxima = Util::DistanciaHaversine(coordenades[0], ref); //distancia de la coordenada mes llunyana

    //ITEREM EL VECTOR DE COORDENADES PER TROBAT EL SEU VALOR MAXIM (PES MAXIM)
    for (int i = 0; i < coordenades.size(); i++)
    {
        if (distanciaMaxima < Util::DistanciaHaversine(coordenades[i], ref))
        {
            valorMaxim = coordenades[i];
            distanciaMaxima = Util::DistanciaHaversine(coordenades[i], ref);
        }
    }
    return valorMaxim;
}

BallTree* BallTree::construirArbreRecursiu(std::vector<Coordinate> recorregutCoordenades)
{
    ///// CAS BASIC /////
    //si només hi ha un element a l'arbre, la recursivitat ha acabat aquí//
    if (recorregutCoordenades.size() == 1)
    {
        BallTree* fill = new BallTree;
        fill->m_right = nullptr;
        fill->m_left = nullptr;
        fill->m_root = this;
        fill->m_coordenades = recorregutCoordenades;
        fill->m_radi = 0.0;
        fill->m_pivot = recorregutCoordenades[0];

        return fill;
    }
    ///// CAS GENERAL /////
    //si hi ha més d'un element a l'arbre//
    else
    {
        ///////DIAGRAMA DE FLUX. PER CADA NODE///////
        //1. Calcula distancia al punt A//
        //2. Calcula distancia al punt B//
        Coordinate puntC = Util::calcularPuntCentral(recorregutCoordenades);
        Coordinate puntA = calculaPuntLlunya(recorregutCoordenades, puntC);
        Coordinate puntB = calculaPuntLlunya(recorregutCoordenades, puntA);

        std::vector<Coordinate> partDreta, partEsquerra;
        dretaOEsquerra(partEsquerra, partDreta, recorregutCoordenades, puntA, puntB);

        BallTree* fill = new BallTree;
        
        fill->m_pivot = puntC;
        fill->m_coordenades = recorregutCoordenades;
        fill->m_root = this;
        fill->m_left = construirArbreRecursiu(partEsquerra);
        fill->m_right = construirArbreRecursiu(partDreta);
        fill->m_radi = Util::DistanciaHaversine(puntC, puntA);

        return fill;
    }
}

void BallTree::dretaOEsquerra(vector<Coordinate>& partEsquerra, vector<Coordinate>& partDreta, const vector<Coordinate>& coordenades, const Coordinate& puntA, const Coordinate& puntB)
{
    for (int i = 0; i < coordenades.size(); i++)
    {

        ////// DIAGRAMA DE FLUX. PER CADA NODE ///////
        // Si D1 < D2, nodeActual<-bolaEsquerra)
        if ((Util::DistanciaHaversine(coordenades[i], puntA)) < (Util::DistanciaHaversine(coordenades[i], puntB)))
            partEsquerra.push_back(coordenades[i]);
        // Si D1 >= D2, nodeActual<-bolaDreta)
        else
            partDreta.push_back(coordenades[i]);
    }
}




