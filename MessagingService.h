#pragma once
#include <string>
#include <iostream>

using namespace std;

/*
* Komunikaty dla bledow, ostrzezen i komunikatorow
*/
enum Message {
	ERR_ALLOC_MEM,				// blad alokacji pamieci
	ERR_OPEN_FILE,				// blad otwarcia pliku	
	ERR_WRITE_FILE,				// blad zapisu do pliku
	ERR_READ_FILE,				// blad odczytania z pliku
	WARN_MENU_WRONG_CHOICE,		// blednie podana opcja (komunikat dla interface'u)
	WARN_OBJ_NFOUND,			// nie znaleziono elementu
	WARN_INDEX_OUT_OF_RANGE,	// podano index poza dozwolonym zakresem
	WARN_OBJ_OUT_OF_RANGE,		// obiekt poza dozwolonym zakresem
	WARN_VEC_EMPTY,				// wektor jest pusty
	INFO_READ_FILE_SUCCESS,		// pomyslnie wczytano dane z pliku
	INFO_WRITE_FILE_SUCCESS,	// pomyslnie zapisano dane w podanym pliku
	INFO_SEARCH_COMPLETE,		// szukanie zakonczone
	NO_FUNCTION,				// brak funkcji
	COMMAND_FINISHED,			// koniec zadanej operacji

	__MESSAGE_CONTAINER_SIZE__			// rozmiar enum (liczba komunikatow)
};

class MessagingService {
private:
	string *messageContainer;
public:
	/**
	 * Create empty object - tworzenie obiektu
	*/
	MessagingService();

	/**
	 * Deallocating, do cleanings
	 * Zwalnianie pamieci
	*/
	~MessagingService();

	/**
	 * Log error message - wypisz komunikat dla bledu
	 * @param message - message to print (komunikat bledu do wyswietlenia)
	*/
	void message(enum Message message);
};

