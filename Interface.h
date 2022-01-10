#pragma once
#include <iostream>

#include "Vector.h"
#include "VectorFile.h"
#include "MCoord.h"
#include "Node.h"
#include "MessagingService.h"

using namespace std;

/*
* Commands available from interface - komendy dostepne z poziomu interface'u
*/
enum Command {
	COMMAND_PUSH,
	COMMAND_POP,
	COMMAND_ERASE,
	COMMAND_CLEAR_ALL,
	COMMAND_MODIFY,
	COMMAND_INSERT,
	COMMAND_FIND,
	COMMAND_SAVE,
	COMMAND_LOAD,
	COMMAND_DISPLAY,
	COMMAND_FINISH,

	__COMMAND_CONTAINER_SIZE__	// enum size
};

/*
* Interface commands messages - komunikaty dla komend z menu
*/
enum CommandMessage {

	PUSH_INFO,
	ERASE_INFO,
	INSERT_INFO,
	OBJ_ADDED,
	FIND_INFO,
	DEL_FIND,
	OBJ_ARE_DEL,
	WHICH_MOD_OB,
	MOD_OB,
	SAVE_INFO,
	LOAD_INFO,
	FILE_LOAD,

	__COMMAND_MESSAGE_CONTAINER_SIZE__	// enum size
};

class Interface {
private:
	bool run;	// true = program on, false = program off
	Vector<Node> vector;
	Node obj;
	MessagingService logger;
	string* menu;                 // tablica tekstowa dostepnych polecen w menu
	string* description;		  // tablica tekstowa komunikatow dla polecen z menu
public:
	/**
	 * Create interface - tworzenie interfejsu uzytkownika
	*/
	Interface();

	/**
	 * Deallocating, do cleanings
	 * Zwalnianie pamieci
	*/
	~Interface();

	/**
	 * Check if program is running - sprawdzenie czy program nie zostal przerwany
	 * @return true = program on, false = program off
	 */
	bool isRunning();

	/**
	 * Display main menu
	 * Wyswietl menu glowne (interfejs)
	*/
	void showMenu();

	/**
	 * Add element at the end
	 * Dodaj nowy element na koncu
	*/
	void push();

	/**
	 * Pop element from the end
	 * Usun element z konca
	*/
	void pop();

	/**
	 * Remove element from given index
	 * Usun element pod wskazanym indeksem
	*/
	void erase();

	/**
	 * Clear structure
	 * Wyczysc tablice obiektow
	*/
	void clear();

	/**
	 * Modify an object
	 * Modyfikuj obiekt
	*/
	void modify();

	/**
	 * Insert element on given index
	 * Wstaw element w okreslone miejsce
	*/
	void insert();

	/**
	 * Find all objects with given key (vertex number)
	 * Znajdz wszystkie obiekty zgodne z kluczem (numerem wierzcholka)
	*/
	void findObjects();

	/**
	 * Write data to disk as a binary file
	 * Zapisz dane na dysku w postaci pliku binarnego
	*/
	void save();

	/**
	 * Read data from binary file
	 * Wczytaj dane z pliku binarnego
	*/
	void load();

	/**
	 * Show the data on the screen
	 * Wyswietl dane na ekranie
	*/
	void display();

	/**
	 * Exit the program
	 * Zakoncz dzialanie programu
	*/
	void finish();

	/**
	 * Handle indefinite activities
	 * Obsluz nieokreslone dzialania uzytkownika (bledny wybor opcji w menu)
	*/
	void wrongChoice();
};

