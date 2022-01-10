#include <fstream>

#include "Node.h"

Node::Node(int nb, char* st, double xx, double yy) : MCoord(xx, yy) {
	numb = nb;
	strcpy_s(str, st);
}

Node::Node() : MCoord() {
	numb = 0;
	strcpy_s(str, "");
}

Node::Node(Node &toCopy) {
	pcoord[0] = toCopy.pcoord[0];
	pcoord[1] = toCopy.pcoord[1];
	numb = toCopy.numb;
	strcpy_s(str, sizeof(str), toCopy.str);
}

Node& Node::operator=(const Node &obj) {
	if (this == &obj) return *this;

	pcoord[0] = obj.pcoord[0];
	pcoord[1] = obj.pcoord[1];
	numb = obj.numb;
	strcpy_s(str, sizeof(str), obj.str);

	return *this;
}

bool Node::operator==(const Node &obj) {
	return ((numb == obj.numb) && (pcoord[0] == obj.pcoord[0]) && (pcoord[1] == obj.pcoord[1]));
}

bool Node::operator==(const int &obj) {
	return (numb == obj);
}

ostream& operator<<(ostream &out, const Node &obj) {
	out << "Nazwa wierzcholka: '" << obj.str << "', numer wierzcholka: " << obj.numb << ", pcoord: (" << obj.pcoord[0] << "," << obj.pcoord[1] << ")" << endl;

	return out;
}

istream& operator>>(istream &in, Node &obj) {
	cout << "nazwa: ";
	in >> obj.str;
	cout << "numer: ";
	in >> obj.numb;
	cout << "x: ";
	in >> obj.pcoord[0];
	cout << "y: ";
	in >> obj.pcoord[1];

	return in;
}

ofstream& operator<<(ofstream& out, const Node& obj) {
	out.write(reinterpret_cast<const char*>(&obj.str), sizeof(obj.str));
	out.write(reinterpret_cast<const char*>(&obj.numb), sizeof(obj.numb));
	out.write(reinterpret_cast<const char*>(&obj.pcoord[0]), sizeof(obj.pcoord[0]));
	out.write(reinterpret_cast<const char*>(&obj.pcoord[1]), sizeof(obj.pcoord[1]));

	return out;
}

ifstream& operator>>(ifstream& in, Node& obj) {
	in.read(reinterpret_cast<char*>(&obj.str), sizeof(Node::str));
	in.read(reinterpret_cast<char*>(&obj.numb), sizeof(Node::numb));
	in.read(reinterpret_cast<char*>(&obj.pcoord[0]), sizeof(obj.pcoord[0]));
	in.read(reinterpret_cast<char*>(&obj.pcoord[1]), sizeof(obj.pcoord[1]));

	return in;
}