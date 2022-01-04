#pragma once
#include <iostream>

#include "MessagingService.h"

using namespace std;

class MCoord {
private:
	MessagingService logger;

	/*
	* Allocate memory for pcoord - alokowanie pamieci dla pcoord
	*/
	void allocateMemory();
protected:
	double *pcoord;
public:
	/**
	 * Create object with parameters - tworzenie obiektu z podaniem parametrow poczatkowych
	 * @param xx - x cordinate (wspolrzedna x)
	 * @param yy - y cordinate (wspolrzedna y)
	*/
	MCoord(double xx, double yy);

	/**
	 * Create empty object - tworzenie pustego obiektu
	*/
	MCoord();

	/**
	 * Deallocating, do cleanings
	 * Zwalnianie pamieci
	*/
	~MCoord();
};
