#include "MCoord.h"

MCoord::MCoord(double xx, double yy) {
	allocateMemory();

	pcoord[0] = xx;
	pcoord[1] = yy;
}

MCoord::MCoord() { 
	allocateMemory();
}

MCoord::~MCoord() {
	if (pcoord != NULL) {
		delete[] pcoord;
		pcoord = NULL;
	}
}

void MCoord::allocateMemory() {
	pcoord = NULL;

	try { pcoord = new double[2]; }
	catch (bad_alloc) { logger.message(Message::ERR_ALLOC_MEM); }
}
