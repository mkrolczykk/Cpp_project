#include "MCoord.h"


MCoord::MCoord(double xx, double yy) {
	allocateMemory();

	pcoord[0] = xx;
	pcoord[1] = yy;
}

MCoord::MCoord() : MCoord(0,0){}

MCoord::~MCoord() {
	if (pcoord != nullptr) {
		delete[] pcoord;
		pcoord = nullptr;
	}
}

void MCoord::allocateMemory() {
	pcoord = nullptr;

	try { pcoord = new double[2]; }
	catch (bad_alloc) { 
		logger.message(Message::ERR_ALLOC_MEM);
	}
}

MCoord::MCoord(const MCoord& cd) : MCoord(0,0) {
	this->pcoord[0] = cd.pcoord[0];
	this->pcoord[1] = cd.pcoord[1];
}

string MCoord::printValue() const
{
	string retVal = "pcoord: (" + std::to_string(this->pcoord[0]) + ", " + std::to_string(this->pcoord[1]) + ")";
	return retVal;
}

bool MCoord::isEqual(const int& key) const
{
	return false;
}

bool MCoord::operator==(const int& key)
{
	return this->isEqual(key);
}

ostream& operator<<(ostream& out, const MCoord& obj)
{
	out << obj.printValue() << endl;

	return out;
}
