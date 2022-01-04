#include "MessagingService.h"

MessagingService::MessagingService() {
	container = new string[__CONTAINER_SIZE__];
	container[ERR_ALLOC_MEM] = "Blad alokacji pamieci! \n";
	container[ERR_OPEN_FILE] = "Blad otwarcia pliku! \n";
	container[ERR_WRITE_FILE] = "Blad zapisu do pliku! \n";
	container[ERR_READ_FILE] = "Blad odczytu z pliku! \n";
	container[WARN_ARR_FULL] = "Przepelnienie tablicy! \n";
	container[WARN_ARR_EMPTY] = "Tablica jest pusta! \n";
	container[WARN_ARR_UNKNOP] = "Bledny kod dzialania! \n";
	container[WARN_OBJ_NFOUND] = "Nie znaleziono elementu! \n";
	container[WARN_INDEX_OUT_OF_RANGE] = "Podano index poza dozwolonym zakresem! \n";
	container[WARN_OBJ_OUT_OF_RANGE] = "Obiekt poza dozwolonym zakresem! \n";
	container[WARN_VEC_EMPTY] = "Wektor jest pusty! \n";
	container[NO_FUNCTION] = "Funkcja nie istnieje! \n";
}
MessagingService::~MessagingService() {
	if (container != NULL) {
		delete[] container;
		container = NULL;
	}
}

void MessagingService::message(enum Message message) {
	cout << container[message] << endl;
	system("Pause");
	if (message < 4) exit(1);
}
