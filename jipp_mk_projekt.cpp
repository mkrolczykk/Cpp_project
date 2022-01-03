// jipp_mk_projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "Vector.h"
#include "VectorFile.h"

#include <iostream>

using namespace std;

int main() {

    Vector<int> v1;
    
    v1.pushBack(5);
    v1.pushBack(60);
    v1.pushBack(120);
    cout << "wektor 1 size: " << v1.size() << endl;
    cout << "czy wektor jest pusty?: " << v1.isEmpty() << endl;
    cout << "wart na 2 miejscu: " << *v1.at(1) << endl;
    cout << "front: " << *v1.front() << endl;
    cout << "back: " << *v1.back() << endl;
    v1.popBack();
    cout << "after popBack: " << *v1.back() << endl;
    v1.clear();
    cout << "after clear function: " << v1.size() << endl;

    Vector<size_t>* v2 = new Vector<size_t>(20);

    cout << "\n\n\nwektor 2 usingData start size: " << v2->size() << endl;
    v2->pushBack(7);
    v2->pushBack(8);
    v2->pushBack(9);
    v2->pushBack(10);
    v2->shrinkToFit();
    cout << "wektor 2 size after shrinkToFit function: " << v2->size() << endl;

    cout << "\nwart na 2 miejscu przed usunieciem elementu: " << *v2->at(1) << endl;
    v2->erase(1);
    cout << "wart na 2 miejscu: " << *v2->at(1) << endl;
    cout << "wart na 3 miejscu: " << *v2->at(2) << endl;
    //cout << "wart na 4 miejscu (nie powinno jej byc): " << *v2->at(3) << endl;
    v2->pushBack(15);
    cout << "wart na 4 miejscu po dodaniu nowego elementu: " << *v2->at(3) << endl;
    v2->pushBack(16);
    cout << "wart na 5 miejscu po dodaniu nowego elementu: " << *v2->at(4) << endl;

    Vector<int> v3;

    cout << "\n\nwektor 3" << endl;
    v3.pushBack(5555);
    cout << "head: " << *v3.front() << endl;
    cout << "tail: " << *v3.back() << endl;

    v3.clear();
    cout << v3.isEmpty() << endl;
    v3.pushBack(5345345);
    cout << *v3.back() << endl;

    // Etap 2
    cout << "\n\nEtap 2 ---------------------------------------------------------" << endl;
    string fileName = "binaryFile.dat"; // nazwa roboczego pliku binarnego

    VectorFile<int> vectorFile; // utworzenie VectorFile

    /*
    Przykladowe uzycie - schemat z Github
    */
    vectorFile.pushBack(10);
    vectorFile.pushBack(11);
    vectorFile.pushBack(12);
    vectorFile.pushBack(15);
    
    vectorFile << fileName;    // zapis binarny do pliku
    
    vectorFile.popBack();
    vectorFile.popBack();
    
    vectorFile >> fileName;    // odczyt z pliku binarnego

    vectorFile.popBack();
    vectorFile.pushBack(66);
    vectorFile.pushBack(67);

    vectorFile << fileName;    // zapis binarny nr 2 do pliku

    vectorFile >> fileName;    // odczyt wszystkich zapisanych danych
}
