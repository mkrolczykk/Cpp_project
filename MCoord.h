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
	virtual string printValue() const;
	virtual bool isEqual(const int& key) const;
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
	 * Create object from other object of the same type - tworzenie obiektu na bazie innego obiektu tego samego typu
	 * @param cd - reference to object - adres do obiektu
	*/
	MCoord(const MCoord& cd);

	/**
	 * Deallocating, do cleanings
	 * Zwalnianie pamieci
	*/
	virtual ~MCoord();

	/**
	 * Output stream handling - obsluga strumienia wyjscia
	 * @param out - output stream (strumien wyjsciowy)
	 * @param obj - the object for being streamed out (obiekt do wypisania na strumieniu wyjscia)
	 * @return reference to output stream (referencja do strumienia wyjsciowego)
	*/
	friend ostream& operator<<(ostream& out, const MCoord& obj);

	/**
	 * Overload of operator '==' for searching by number of vertex - przeciazenie operatora porownania '==' dla szukania tylko po numerach wierzcholkow
	 * @param obj - number of vertex (numer wierzcholka)
	 * @return true if equal or false if not (prawda jezeli numery wierzcholkow sa takie same, falsz jezeli nie)
	*/
	bool operator==(const int& key);
};

