#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"

#include "./showClass/showMember.cpp"
#include "./showClass/showPurchase.cpp"
#include "./showClass/showStock.cpp"

#include "./packingTest/memberTest.cpp"
#include "./packingTest/purchaseTest.cpp"
#include "./packingTest/stockTest.cpp"
#include "environment.h"

#include "./record/recordInsert.cpp"
#include "./record/recordSearch.cpp"

bool selectMenu (Environment &env);
bool ticketPurchaseSystem (Environment &env);


int main() {
	Environment env;
	setEnvironment(env);

	// make .dat from .txt
	memberTest(-1);
	stockTest(-1);
	purchaseTest(-1);

	while(selectMenu(env));

	return 0;
}

bool selectMenu (Environment &env) {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: showMember" << endl;
	cout << "2: showStock" << endl;
	cout << "3: showPurchase" << endl;
	cout << "4: MemberTest" << endl;
	cout << "5: StockTest" << endl;
	cout << "6: PurchaseTest" << endl;
	cout << "7: TicketPurchaseSystem" << endl;
	cout << "8: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	bool result = true;
	switch (menuNum) {
		case 1: showMember(); break;
		case 2: showStock(); break;
		case 3: showPurchase(); break;

		case 4: memberTest(); break;
		case 5: stockTest(); break;
		case 6: purchaseTest(); break;

		case 7: while(ticketPurchaseSystem(env)); break;
		case 8: default: return result = false;
	}


	return result;
}

bool ticketPurchaseSystem (Environment &env) {
	cout << "=================================================" << endl << ">> ";
	cout << "\t\tTicketPurchaseSystem" << endl;
	cout << "1: Search record" << endl;
	cout << "2: Insert record" << endl;
	cout << "3: Delete record" << endl;
	cout << "4: Modify record" << endl;
	cout << "5: Close TicketPurchaseSystem" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	bool result = true;
	switch (menuNum) {
		case 1: recordSearchMain(env); break;
		case 2: recordInsertMain(env); break;
		case 3: break;
		case 4: break;
		case 5: default: return result = false;
	}

	return result;
}

