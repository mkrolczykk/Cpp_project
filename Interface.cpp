#include "Interface.h"

Interface::Interface() : run(true)
{
	menu = new string[__COMMAND_CONTAINER_SIZE__];
	menu[COMMAND_PUSH] = "Dodaj obiekt \n";
	menu[COMMAND_POP] = "Usun obiekt z konca \n";
	menu[COMMAND_ERASE] = "Usun obiekt pod wskazanym indeksem \n";
	menu[COMMAND_CLEAR_ALL] = "Wyczysc tablice z obiektow \n";
	menu[COMMAND_MODIFY] = "Modyfikuj obiekt \n";
	menu[COMMAND_INSERT] = "Wstaw obiekt w okreslone miejsce \n";
	menu[COMMAND_FIND] = "Znajdz obiekty zgodne z podanym kluczem \n";
	menu[COMMAND_SAVE] = "Zapisz dane na dysk \n";
	menu[COMMAND_LOAD] = "Wczytaj dane z dysku \n";
	menu[COMMAND_DISPLAY] = "Wyswietl dane na ekranie \n";
	menu[COMMAND_FINISH] = "Zakoncz dzialanie programu \n";

	description = new string[__COMMAND_MESSAGE_CONTAINER_SIZE__]; 
	description[PUSH_INFO] = "\nPodaj: nazwe, nr wierzcholka oraz wspolrzedne x oraz y: \n";
	description[ERASE_INFO] = "\nPodaj indeks elementu (liczac od 0), ktory chcesz usunac: \n";
	description[INSERT_INFO] = "\nPodaj indeks(liczac od 0), pod ktorym ma zostac dodany nowy obiekt: \n";
	description[OBJ_ADDED] = "\nObiekt zostal dodany.\n";
	description[FIND_INFO] = "\nPodaj nr wierzcholka:";
	description[DEL_FIND] = "\nPodaj indeks obiektu do usuniecia:";
	description[OBJ_ARE_DEL] = "\nUsunieto wszystkie elementy.\n";
	description[WHICH_MOD_OB] = "\nPodaj nr wierzcholka ktory chcesz zmodyfikowac:\n";
	description[MOD_OB] = "\nPodaj indeks obiektu do modyfikacji:";
	description[SAVE_INFO] = "\nPodaj nazwe dla pliku w ktorym chcesz zapisac dane: \n";
	description[LOAD_INFO] = "\nPodaj pelna nazwe pliku z ktorego chcesz wczytac dane: \n";
	description[FILE_LOAD] = "\nOdczytano dane z pliku.\n";
}

Interface::~Interface()
{
	if (menu != nullptr) {
		delete[] menu;
		menu = nullptr;
	}
	if (description != nullptr) {
		delete[] description;
		description = nullptr;
	}
}

bool Interface::isRunning()
{
	return run;
}

void Interface::showMenu()
{
	cout << "\t\t***************MENU***************" << endl;
	cout << "\tWybierz opcje od 0 do " << __COMMAND_CONTAINER_SIZE__ - 1 << " wpisujac odpowiedni numer \n" << endl;
	for (int i = 0; i < __COMMAND_CONTAINER_SIZE__; i++) cout << i << ") " << menu[i] << endl;
	cout << "Wybierz operacje: ";
}

void Interface::push()
{
	Node* newObj = new Node();
	cout << description[PUSH_INFO];
	cin >> *newObj;
	vector.pushBack(newObj);

	cout << description[OBJ_ADDED] << endl;
}

void Interface::pop()
{
	vector.popBack();
}

void Interface::erase()
{
	vector.showVectorData();
	if (!vector.isEmpty()) {
		cout << description[ERASE_INFO];
		size_t index;
		cin >> index;
		vector.erase(index);
	}
}

void Interface::clear()
{
	if(!vector.isEmpty()) {
		vector.clear();
		cout << description[OBJ_ARE_DEL] << endl;
	} else logger.message(Message::WARN_VEC_EMPTY);
}

void Interface::modify()
{
	if (!vector.isEmpty()) {
		int index;
		vector.showVectorData();
		cout << description[MOD_OB] << endl;
		cin >> index;
		
		try {
			Node* nodeToModPtr = dynamic_cast<Node*>(*vector.at(index));
			if (nodeToModPtr != nullptr) cin >> *nodeToModPtr;
		} catch(out_of_range) {};
	} else logger.message(Message::WARN_VEC_EMPTY);
	
}

void Interface::insert()
{
	size_t position;
	Node* newObj = new Node();

	cout << description[INSERT_INFO] << endl;
	cin >> position;

	if (position < 0 || position > vector.size()) logger.message(Message::WARN_INDEX_OUT_OF_RANGE);
	else {
		cout << description[PUSH_INFO];
		cin >> *newObj;
		vector.insert(newObj, position);
		cout << description[OBJ_ADDED] << endl;
	}
}

void Interface::findObjects()
{
	int key;
	cout << description[FIND_INFO] << endl;
	cin >> key;

	MCoord** ptr = vector.front();

	do
	{
		ptr = find<MCoord*, int>(ptr, vector.back(), key);
		if (ptr != nullptr)
		{
			const size_t dst = ptr - vector.front();
			cout << "Znaleziono obiekt na miejscu (indeksie) nr " << dst << ": " << **ptr << endl;
			ptr += 1;
		}
	} while (ptr != nullptr);

	logger.message(Message::INFO_SEARCH_COMPLETE);
}

void Interface::save()
{
	// const string fileName = "binaryFile.dat";	// for testing
	string fileName;
	VectorFile<Node> vectorFile;

	cout << description[SAVE_INFO] << endl; 
	cin >> fileName;

	for (size_t i = 0; i < vector.size(); i++)
	{
		try
		{
			Node& tmpNode = dynamic_cast<Node&>(**vector.at(i));
			vectorFile.pushBack(tmpNode);
		}
		catch (const std::bad_cast&)
		{

		}
	}

	vectorFile << fileName;
}
 
void Interface::load()
{
	// const string fileName = "binaryFile.dat";	// for testing
	string fileName;
	VectorFile<Node> vectorFile;
	
	cout << description[LOAD_INFO] << endl;
	cin >> fileName;

	vectorFile >> fileName;
	for (size_t i = 0; i < vectorFile.size(); i++)
	{
		Node* newObj = new Node();
		*newObj = *vectorFile.at(i);
		vector.pushBack(newObj);
	}
}

void Interface::display()
{
	vector.showVectorData(); 
}

void Interface::finish() { run = false; }

void Interface::wrongChoice() { logger.message(WARN_MENU_WRONG_CHOICE); }

istream& operator>>(istream& is, Interface& ifc)
{
	int choice = -1;

	is >> choice;

	if (is.fail())
	{
		ifc.logger.message(WARN_MENU_WRONG_CHOICE);
		is.clear(istream::failbit);
	}

	switch (choice) {
	case 0:
		ifc.push();
		break;
	case 1:
		ifc.pop();
		break;
	case 2:
		ifc.erase();
		break;
	case 3:
		ifc.clear();
		break;
	case 4:
		ifc.modify();
		break;
	case 5:
		ifc.insert();
		break;
	case 6:
		ifc.findObjects();
		break;
	case 7:
		ifc.save();
		break;
	case 8:
		ifc.load();
		break;
	case 9:
		ifc.display();
		break;
	case 10:
		ifc.finish();
		break;
	default:
		ifc.wrongChoice();
		break;
	}

	if (choice != 10)
	{
		system("pause");
	}

	return is;
}
