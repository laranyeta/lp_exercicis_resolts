#ifndef _CAMI_BASE_H
#define _CAMI_BASE_H

#include "Common.h"
#include "Util.h"
#include <vector>

class CamiBase {
public:
	virtual std::vector<Coordinate> getCamiCoords() = 0;
	virtual int getNCoords() = 0;
};

#endif

