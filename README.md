# C++ OOP project

## Stage 1 (etap 1)

#### Create an implementation of the `vector` container based on the declaration below. 
#### Stwórz implementację kontenera `vector`, na podstawie podanej poniżej deklaracji.

```c++
template<typename type>
class Vector {
private:
    type data*;
    size_t allocatedDataSize;
    size_t usingDataSize;

public:
    /**
     * Create empty vector
     * Tworzenie pustego wektora
     */
    Vector();

    /**
     * Create vector with passed size
     * Tworzenie wektor o podanym rozmiarze
     * @param usingDataSize size of creating vector
     */
    Vector(size_t usingDataSize);

    /**
     * Deallocating, do cleanings
     * Zwalnianie pamięci, robienie porządków
     */
    ~Vector();

    /**
     * Get element from specified index
     * Pobieranie elementów spod przekazanego indeksu
     * @param index index of element
     * @return reference to element
     */
    type *at(size_t index);

    /**
     * Get address of first element
     * Pobieranie adresu pierwszego elementu
     * @return address of first element
     */
    type *front();

    /**
     * Get address of last element
     * Pobieranie adresu ostatniego używanego elementu
     * @return address of last element
     */
    type *back();

    /**
     * Get size of using data
     * Pobieranie rozmiaru tablicy (używanej części)
     * @return size of using vector
     */
    size_t size();

    /**
     * Add new element on the end of vector
     * Dodaj nowy element na koniec wektora
     * @param newRecord new value
     */
    void pushBack(type newRecord);

    /**
     * Delete last element
     * Usuwanie ostatniego elementu
     */
    void popBack();

    /**
     * Check vector is empty
     * Sprawdzanie, czy wektor jest pusty
     * @return true if vector is empty, false if not empty
     */
    bool isEmpty();

    /** Dodatkowe
     * Delete all elements
     * Usuwanie wszystkich elementów z wektora
     */
    void clear();
    
    /** Dodatkowe
     * Reallocate data to fit allocated data to using data
     * Realokowanie pamięci, aby dopasować rozmiar zaalokowanej tablicy do używanej
     */
    void shrinkToFit();
    
    /**
     * Delete element on passed index
     * Usuwanie elementu pod wskazanym indeksem
     * @param size_t index of element to erase
     */
    void erase(size_t index);
};
```

#### Fields (atrybuty klasy)

The class contains the following fields:
- data - an indicator used to store data
- allocatedDataSize - the size (number of elements) of the allocated memory
- usingDataSize - size (number) of used elements 

Klasa zawiera następujące pola:
- data - wskaźnik służący do przechowywania danych
- allocatedDataSize - rozmiar (ilość elementów) zaalokowanej pamięci
- usingDataSize - rozmiar (ilość) używanych elementów

#### Constructors (konstruktory)

When creating an object, memory should be allocated to hold items. More memory can be allocated than is used. For example, when calling an empty constructor, you can allocate memory for 10 items and set the used size (usingDataSize) to 0. <br />

Podczas tworzenia obiektu powinna być alokowana pamięć do przechowywania elementów. Można zaalokować więcej pamięci, niż jest używane. Przykładowo przy wywołaniu pustego konstruktora można zaalokować pamięć dla 10 elementów i ustawić używaną wielkość (usingDataSize) na 0.

## Additional information (dodatkowe informacje)

You can create additional methods or fields as needed. <br />

Można tworzyć dodatkowe metody bądź pola, jeżeli będzie to potrzebne.

&nbsp;

&nbsp;

&nbsp;

## Stage 2 (etap 2)

#### Create file support (stwórz obsługę plików)

The goal of this stage is to create a file handler for the `Vector` class that will be able to write to and read content from disk. <br />

Celem etapu jest stworzenie obsługi plików dla klasy `Vector`, która będzie umożliwiała zapisywanie i odczytywanie zawartości z dysku.

### Correction in the `Vector` class (korekta w klasie `Vector`)

In the `Vector` class, move private fields to the protected section.  <br />

W klasie `Vector` pola prywatne przenieś do sekcji chronionych.

### A class to handle files (klasa do obsługi plików)

Create a new class that will add new functionality to the `Vector` class, saving and reading its contents from a file. This is to be done with the operators `<<` and `>>`. <br />

1. The class should be named `VectorFile` and should inherit from `Vector`.
2. It should have public implementations for the following operators:
    1. `<<` - saving data to a binary file
    2. `>>` - reading data from a binary file
    3. Think for yourself what to return and accept as an argument this operator.
3. May have other private fields and methods. 

<br />

Stwórz nową klasę, która będzie dodawała do klasy `Vector` nowe funkcjonalności, zapisywani i odczytywnaie jej zawartości z pliku. Ma to być dokonywane za pomocą operatorów `<<` i `>>`.

1. Klasa ma się nazywać `VectorFile` i ma dziedziczyć `Vector`.
2. Ma posiadać w sobie publiczne implementacje dla następujących operatorów:
   1. `<<` - zapisywanie danych do pliku binarnego
   2. `>>` - odczytywanie danych z pliku binarnego
   3. Sam wymyśl, co ma zwracać i przyjmować jako argument ten operator.
3. Może posiadać inne prywatne pola i metody.

&nbsp;

### Sample usage

1. Create a `VectorFile`.
2. Adding various data using the `push_back` method.
3. Use the operator `<<` to write input to a binary file.
4. End of the application
5. Launching the application
6. Reading the data from the file by means of the operator `>>`.
7. Deleting the last record (`popBack`) and adding two new ones (` pushback`).
8. Writing data to a file using the `<<` operator.
9. End of application.
10. Launching the application.
11. View all saved data. 

### Przykładowe użycie

1. Stworzenie `VectorFile`.
2. Dodanie różnych danych za pomocą metody `push_back`.
3. Użycie operatora `<<` do zapisania wprowadzonych danych do pliku binarnego.
4. Zakończenie aplikacji
5. Uruchomienie aplikacji
6. Wczytanie danych za pomocą operatora `>>` z pliku.
7. Usunięcie ostatniego rekordu (`popBack`) i dodanie dwóch nowych (`pushback`).
8. Zapisanie danych do pliku za pomocą operatora `<<`.
9. Zakończenie aplikacji.
10. Uruchomienie aplikacji.
11. Wyświetlenie wszystkich zapisanych danych.

&nbsp;

&nbsp;

&nbsp;

# Stage 3 (etap 3)

#### Create classes to store data (stwórz klasy przechowujące dane)

Create a class (stwórz klasę):

```c++
class MCoord
{
protected:
	double *pcoord;
public:
	mcoord(double xx, double yy);
	mcoord() { pcoord = NULL; }
	~mcoord() { ……………… }
};
```
Create a class node that inherits publicly from mcoord (utwórz klasę node, która publicznie dziedziczy po klasie mcoord):

```c++
class Node
{
int numb;       // vertex number
char str[512];  // vertex name
public:
node(int nb, char *st, double xx, double yy);
node();
…………………
};
```

The node class should also contain:

- operator overloads
   - `=` - assigning
   - `==` - compare
   - `<<` and `>>` - arbitrary streams support
- copy constructor 

<br />
Klasa node ma dodatkowo zawierać: <br /> <br />

- przeciążenia operatorów
  - `=` - przypisywanie
  - `==` - porównywanie
  - `<<` i `>>` - obsługa dowolnych strumieni
- konstruktor kopiujący


### Error handling class (klasa obsługi błędów)

Create a handling of errors, warnings and messages. All of them should be saved in one file. <br /> 

Stwórz obsługę błędów, ostrzeżeń i komunikatów. Wszystkie mają być zapisane w jednym pliku.


&nbsp;

&nbsp;

&nbsp;

# Stage 4 (etap 4)

#### 'find' function (funkcja find)

Create a template find function to search for an element in an array. <br />

Stwórz szablonową funkcję find służącą do wyszukiwania elementu w tablicy.

```c++
template <class T, class Key>
T * find(const T *p_begin, const T *p_end, const Key &k);
```

Where (gdzie):

- `T *p_begin` - a pointer to the first element of the array (wskaźnik na pierwszy element tablicy)
- `T *p_end` - the first free element in the array (pierwszy wolny element tablicy)
- `Key &k` - search key (e.g. vertex number); klucz przeszukiwania (np. numer wierzchołka).

Return (zwracane):

- pointer to the found item (wskaźnik do odnalezionego elementu)
- `NULL` lub `nullptr` when the object is not found (w przypadku nieznalezienia obiektu)


&nbsp;

&nbsp;

&nbsp;

# Stage 5 (etap 5)

#### Create a user interface (stwórz interfejs użytkownika). <br /> <br />

Create a data management application. It will store objects of type `MCoord` in a container created in stage 1. <br />

Stwórz aplikację zarządzającą danymi. Będzie ona przechowywać obiekty typu `MCoord` w kontenerze stworzonym w etapie 1. <br /> <br />

Create a text-based user interface that will be in loop and have following options:
- object deletion
- clearing the object array
- object modification
- inserting an object in a specific place
- finding all objects compatible with the key (vertex number)
- saving data to disk
- reading data from the disk
- displaying data on the screen
- termination of the program 

<br />
Utwórz tekstowy interfejs użytkownika, który będzie działał w pętli i będzie posiadał opcje): <br /> <br />

- adding an object
- dodawania obiektu
- usuwania obiektu
- wyczyszczenie tablicy obiektów
- modyfikację obiektu
- wstawiania obiektu w określone miejsce
- znalezienia wszystkich obiektów zgodnych z kluczem (numerem wierzchołka)
- zapisanie danych na dysk
- odczytanie danych z dysku
- wyświetlenie danych na ekranie
- zakończenie działania programu

&nbsp;

&nbsp;

&nbsp;

# General info (uwagi ogólne)

All dynamic allocations and deallocations are to be done using the `new` and` delete` operators. <br />

Wszystkie dynamiczne alokacje i dealokacje mają być dokonywane za pomocą operatorów `new` i `delete`.

&nbsp;

**Search** 

Search by using the 'find' function you created in the early stages. Search by vertex numbers only, create in the class `Node` the appropriate overload of the `==` operator. 


**Wyszukiwanie**

Wyszukiwania dokonuj za pomocą stworzonej funkcji find. Szukaj tylko po numerach wierzchołków w tym celu stwórz w klasie 
`Node` odpowiednie przeciążenie operatora `==`.

&nbsp;

&nbsp;
