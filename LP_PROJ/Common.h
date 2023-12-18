#ifndef _COMMON_H
#define _COMMON_H

#include <functional>
#include <string>
#include <vector>

typedef std::pair<std::string, std::string> PAIR_ATTR_VALUE;
typedef std::pair<std::string, std::vector<PAIR_ATTR_VALUE>> CHILD_NODE;

//typedef
struct Coordinate{

    double lat;
    double lon;

    bool operator==(const Coordinate c) { return c.lat == lat && c.lon == lon; }
};//coordinate

extern "C" typedef struct {
    int i;
    double lat;
    double lon;
    unsigned int color;
    const char* title;
} PoiBridge;

extern "C" typedef struct {
    double* lats;
    double* lons;
    int size;
} WayBridge;

typedef struct {
    std::string id_element;
    std::vector<PAIR_ATTR_VALUE> atributs;
    std::vector<CHILD_NODE> fills;
} XmlElement;


#endif
