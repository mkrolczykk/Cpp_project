#pragma once
#include <fstream>
#include <string>

#include "Vector.h"
#include "MessagingService.h"

template<typename type>
class VectorFile : public Vector<type> {
private:
	MessagingService logger;
public:
	/**
	 * Create empty object of VectorFile - tworzenie pustego obiektu
	*/
	VectorFile() : Vector<type>() {};

	/**
	 * Create VectorFile for vector with passed size - tworzenie VectorFile dla wektora o podanym rozmiarze
	 * @param usingDataSize - size of created vector (rozmiar dla tworzonego wektora)
	*/
	VectorFile(size_t usingDataSize) : Vector(usingDataSize) {};

	/**
	 * Reading data from a binary file - odczytywanie danych z pliku binrnego
	 * @param fileName - file name to read from (nazwa pliku do odczytu)
	*/
	void operator>>(const string fileName);

	/**
	 * Writing data to a binary file - zapisywanie danych do pliku binarnego
	 * @param fileName - file name to write to
	*/
	void operator<<(const string fileName);
};

// Implementation

template<typename type>
inline void VectorFile<type>::operator>>(const string fileName) {
	type buffer;
	ifstream input(fileName, ios::binary | ios::in);

	if (!input.is_open()) {
		cout << "\nError on opening file!\n" << endl;
		exit(1);
	}

	this->clear();
	
	while (input.read(reinterpret_cast<char*>(&buffer), sizeof(buffer))) this->pushBack(buffer);
	
	input.close();
	cout << "Succesfully loaded data from file '" << fileName << "'" << endl;
};

template<typename type>
inline void VectorFile<type>::operator<<(const string fileName) {
	ofstream output(fileName, ios::binary | ios::out);

	if (!output.is_open()) {
		cout << "\nError on opening file!\n" << endl;
		exit(1);
	}

	cout << "\nStart saving vector data to file '" << fileName << "'\n" << endl;

	char* ptr = reinterpret_cast<char *>(this->data);

	for (int i = 0; i < this->usingDataSize * sizeof(type); ++i) output.put(ptr[i]);

	output.close();
	cout << "Saving complete\n" << endl;
}
