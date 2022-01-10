#include "MessagingService.h"

MessagingService::MessagingService() {
	messageContainer = new string[__MESSAGE_CONTAINER_SIZE__];

	messageContainer[ERR_ALLOC_MEM] = "\nBlad alokacji pamieci! \n";
	messageContainer[ERR_OPEN_FILE] = "\nBlad otwarcia pliku! \n";
	messageContainer[ERR_WRITE_FILE] = "\nBlad zapisu do pliku! \n";
	messageContainer[ERR_READ_FILE] = "\nBlad odczytu z pliku! \n";
	messageContainer[WARN_MENU_WRONG_CHOICE] = "\nBlednie podana opcja! \n";
	messageContainer[WARN_OBJ_NFOUND] = "\nNie znaleziono elementu! \n";
	messageContainer[WARN_INDEX_OUT_OF_RANGE] = "\nPodano index poza dozwolonym zakresem! \n";
	messageContainer[WARN_OBJ_OUT_OF_RANGE] = "\nObiekt poza dozwolonym zakresem! \n";
	messageContainer[WARN_VEC_EMPTY] = "\nWektor jest pusty! \n";
	messageContainer[INFO_READ_FILE_SUCCESS] = "\nPomyslnie wczytano dane z pliku. \n";
	messageContainer[INFO_WRITE_FILE_SUCCESS] = "\nPomyslnie zapisano dane w podanym pliku. \n";
	messageContainer[INFO_SEARCH_COMPLETE] = "\nSzukanie obiektow zakonczone. \n";
	messageContainer[NO_FUNCTION] = "\nFunkcja nie istnieje! \n";
}

MessagingService::~MessagingService() {
	if (messageContainer != NULL) {
		delete[] messageContainer;
		messageContainer = NULL;
	}
}

void MessagingService::message(enum Message message) {
	cout << messageContainer[message] << endl;
	system("pause");
	// if (message < 4) exit(1);
}
