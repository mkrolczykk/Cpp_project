#pragma once
#include <iostream>

#include "MCoord.h"

using namespace std;

class Node : public MCoord {
	int numb;       // Numer wierzcholka
	char str[512];  // Nazwa wierzcholka
public:
	/**
	 * Create Node with passed parameters - tworzenie Node'a z podanymi parametrami
	 * @param nb - number of node (numer wierzcholka)
	 * @param st - name of node (nazwa wierzcholka)
	 * @param xx - x cordinate (wspolrzedna x)
	 * @param yy - y cordinate (wspolrzedna y)
	*/
	Node(int nb, char* st, double xx, double yy);

	/**
	 * Create empty Node - tworzenie pustego Node'a
	*/
	Node();

	/**
	 * Copy constructor - konstruktor kopiujacy
	 * @param toCopy - object to be copied (obiekt do skopiowania)
	*/
	Node(Node &toCopy);

	/**
	 * Overload of operator '=' - przeciazenie operatora '='
	 * @param obj - the object being assigned (obiekt przypisywany)
	 * @return assigned object (obiekt przypisany)
	*/
	Node &operator=(const Node &obj);

	/**
	 * Overload of operator '==' - przeciazenie operatora porownania '=='
	 * @param obj - the object for comparison (obiekt do porownywania)
	 * @return true if equal or false if not (prawda jezeli obiekty sa takie same, falsz jezeli nie)
	*/
	bool operator==(const Node &obj);

	/** ????????????????????????????????
	 * Overload of operator '==' - przeciazenie operatora porownania '=='
	 * @param obj - the object for comparison (obiekt do porownywania)
	 * @return true if equal or false if not (prawda jezeli obiekty sa takie same, falsz jezeli nie)
	*/

	//bool operator==(const int &obj); ????????????????????????????

	/**
	 * Output stream handling - obsluga strumienia wyjscia
	 * @param out - output stream (strumien wyjsciowy)
	 * @param obj - the object for being streamed out (obiekt do wypisania na strumieniu wyjscia)
	 * @return reference to output stream (referencja do strumienia wyjsciowego)
	*/
	friend ostream &operator<<(ostream &out, const Node &obj);

	/**
	 * Input stream handling - obsluga strumienia wejscia
	 * @param out - input stream (strumien wejsciowy)
	 * @param obj - the object for being streamed in (obiekt dla strumienia wejscia)
	 * @return reference to input stream (referencja do strumienia wejsciowego)
	*/
	friend istream &operator>>(istream &in, Node &obj);
};

