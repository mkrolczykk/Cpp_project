#pragma once
#include <fstream>
#include <string>

#include "Vector.h"
#include "MessagingService.h"

template<typename type>
class VectorFile : public Vector<type>
{
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
inline void VectorFile<type>::operator>>(const string fileName)
{
	type buffer;
	ifstream input(fileName, ios::binary | ios::in);

	if (!input.is_open())
	{
		logger.message(Message::ERR_OPEN_FILE);
	} else {
		while (input >> buffer) this->pushBack(buffer);
	
		if(input.eof()) logger.message(Message::INFO_READ_FILE_SUCCESS);

		input.close();
	}
}

template<typename type>
inline void VectorFile<type>::operator<<(const string fileName)
{
	ofstream output(fileName, ios::binary | ios::out);

	if (!output.is_open())
	{
		logger.message(Message::ERR_OPEN_FILE);
		system("pause");
		exit(1);
	}

	for (size_t i = 0; i < this->usingDataSize; i++) output << this->data[i];

	output.close();
	logger.message(Message::INFO_WRITE_FILE_SUCCESS);
}
