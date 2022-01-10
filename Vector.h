#pragma once
#include <iostream>

#include "MessagingService.h"

using namespace std;

template<typename type> class Vector {
private:
    size_t defaultAllocationSize = 10;
    MessagingService logger;

    /**
     * Extend size of the vector - zmiana rozmiaru wektora
     * @param newSizeValue - new size for vector (nowy rozmiar wektora)
    */
    void changeVectorSize(size_t newSizeValue);
protected:
    type* data;
    size_t allocatedDataSize;
    size_t usingDataSize;
public:
    /**
     * Create empty vector - tworzenie pustego wektora
    */
    Vector();

    /**
     * Create vector with passed size - tworzenie wektora o podanym rozmiarze
     * @param usingDataSize - size of creating vector (rozmiar dla tworzonego wektora)
    */
    Vector(size_t usingDataSize);

    /**
     * Deallocating, do cleanings
     * Zwalnianie pamieci
    */
    ~Vector();

    /**
     * Copy assigment operator. Kopiujący operator przypisania.
     * @param v - adress of vector to be assigned (adres do wektora ktory ma zostac przypisany)
    */
    Vector& operator=(const Vector& v);

    /**
     * Get element from specified index - pobieranie elementów spod przekazanego indeksu
     * @param index - index of element (indeks elementu)
     * @return reference to element (referencja do elementu)
    */
    type *at(size_t index);

    /**
     * Get address of first element - pobieranie adresu pierwszego elementu
     * @return address of first element (adres pierwszego elementu)
    */
    type *front();

    /**
     * Get address of last element - pobieranie adresu ostatniego używanego elementu
     * @return address of last element (adres ostatniego elementu)
    */
    type *back();

    /**
     * Get size of using data - pobieranie rozmiaru tablicy (uzywanej czesci)
     * @return size of using vector (rozmiar uzywanego wektora)
    */
    size_t size();

    /**
     * Add new element on the end of vector - dodaj nowy element na koniec wektora
     * @param newRecord - new value (nowa wartosc)
    */
    void pushBack(type newRecord);

    /**
     * Delete last element
     * Usuwanie ostatniego elementu
     */
    void popBack();

    /**
     * Check vector is empty - sprawdzanie, czy wektor jest pusty
     * @return true if vector is empty, false if not empty (prawda jezeli pusty, falsz jezeli niepusty)
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
     * @param index - index of element to erase (indeks wskazanego elementu do usuniecia)
    */
    void erase(size_t index);

    /**
     * Insert element on given index - wstawianie elementu pod wskazanym indeksem
     * @param obj - object to insert (obiekt do wstawienia)
     * @param ind - index on which new element will be inserted (indeks pod ktorym ma zostac dodany nowy element)
    */
    void insert(const type& obj, size_t ind);

    /** Dodatkowe
     * Show Vector data
     * Wyswietl zawartosc wektora
    */
    void showVectorData();
};

/**
 * Searching for an item in an array - wyszukiwanie elementu w tablicy
 * @param p_begin - pointer to the first element of array (wskaznik na pierwszy element tablicy)
 * @param p_end - the first free element in the array (pierwszy wolny element tablicy)
 * @param k - search key (klucz przeszukiwania)
 * @return Pointer to the found item or NULL if no item found (wskaznik do odnalezionego elementu lub NULL jezeli nic nie znaleziono)
*/
template <class type, class Key>
type* find(const type *p_begin, const type *p_end, const Key& k);

// Implementation

template<typename type>
inline Vector<type>::Vector() {
    data = new type[defaultAllocationSize];
    allocatedDataSize = defaultAllocationSize;
    usingDataSize = 0;
}

template<typename type>
Vector<type>::Vector(size_t usingDataSize) {
    data = new type[usingDataSize];
    this->allocatedDataSize = usingDataSize;
    this->usingDataSize = 0;
}

template<typename type>
Vector<type>::~Vector() {
    delete[] data;
    data = nullptr;
}

template<typename type>
Vector<type>& Vector<type>::operator=(const Vector<type>& v) {
    if (this == &v) return *this;
    if (data != nullptr) {
        delete[] data;
        allocatedDataSize = 0;
        usingDataSize = 0;
    }

    data = new type[v.allocatedDataSize];
    for (size_t i = 0; i < v.usingDataSize; i++) data[i] = v.data[i];
    allocatedDataSize = v.allocatedDataSize;
    usingDataSize = v.usingDataSize;

    return *this;
}


template<typename type>
type* Vector<type>::at(size_t index) {
    if (index >= 0 && index < usingDataSize) return &data[index];
    
    logger.message(Message::WARN_INDEX_OUT_OF_RANGE);
    throw out_of_range("\nIndeks poza dozwolonym zasiegiem!\n");
}

template<typename type>
type* Vector<type>::front() {
    return size() >= 1 ? &data[0] : throw exception("\nWektor jest pusty!\n");
}

template<typename type>
type* Vector<type>::back() {
    return size() >= 1 ? &data[usingDataSize - 1] : throw exception("\nWektor jest pusty!\n");
}

template<typename type>
size_t Vector<type>::size() {
    return usingDataSize;
}

template<typename type>
void Vector<type>::pushBack(type newRecord) {
    if (usingDataSize >= allocatedDataSize) changeVectorSize(allocatedDataSize * 2);
    data[usingDataSize++] = newRecord;
}

template<typename type>
void Vector<type>::popBack() {
    if(usingDataSize > 0) --usingDataSize;
    else logger.message(Message::WARN_VEC_EMPTY);
}

template<typename type>
bool Vector<type>::isEmpty() {
    return usingDataSize == 0 ? true : false;
}

template<typename type>
void Vector<type>::clear() {
    delete[] data;

    data = new type[defaultAllocationSize];
    allocatedDataSize = defaultAllocationSize;
    usingDataSize = 0;
}

template<typename type>
void Vector<type>::shrinkToFit() {
    changeVectorSize(usingDataSize);
}

template<typename type>
void Vector<type>::erase(size_t index) {
    if (index >= 0 && index <= usingDataSize) {
        type* i = &data[index+1];
        type* j = &data[index];

        for (; i < (data + usingDataSize); ++i, ++j) *j = *i;

        usingDataSize--;
    } else logger.message(Message::WARN_INDEX_OUT_OF_RANGE);
}

template<typename type>
inline void Vector<type>::insert(const type& obj, size_t ind) {
    if (ind <= usingDataSize) {
        if (usingDataSize >= allocatedDataSize) changeVectorSize(allocatedDataSize * 2);
        usingDataSize++;
        for (size_t i = (usingDataSize - 1); i > ind; i--) data[i] = data[i - 1];
        data[ind] = obj;
    } else logger.message(Message::WARN_INDEX_OUT_OF_RANGE);
}

template<typename type>
inline void Vector<type>::showVectorData() {
    if (this->usingDataSize > 0) {
        cout << "\nVector data: " << endl;
        for (size_t i = 0; i < this->usingDataSize; ++i) cout << "Obiekt " << i << " -> " << this->data[i] << endl;
    } else logger.message(Message::WARN_VEC_EMPTY);
}

template<typename type>
void Vector<type>::changeVectorSize(size_t newSizeValue) {
    if (newSizeValue == allocatedDataSize) return;
    if (data == nullptr) {
        usingDataSize = 0;
        allocatedDataSize = 0;
    }

    const size_t newSize = newSizeValue < usingDataSize ? usingDataSize : newSizeValue;

    type* buffer = new type[newSize];
    allocatedDataSize = newSize;

    for (size_t i = 0; i < usingDataSize; i++) buffer[i] = data[i];

    delete[] data;
    data = buffer;
}

template<class type, class Key>
inline type* find(const type* p_begin, const type *p_end, const Key &k) {
    if ((p_begin == nullptr) || (p_end == nullptr) || (p_begin > p_end)) return nullptr;

    type* p_tmp = const_cast<type*>(p_begin);
    for (; p_tmp <= p_end; ++p_tmp) if (*p_tmp == k) return p_tmp;

    return nullptr;
}
