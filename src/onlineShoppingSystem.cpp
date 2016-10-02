#include "./showClass/showMember.cpp"
#include "./showClass/showPurchase.cpp"
#include "./showClass/showStock.cpp"

#include "./packingTest/memberTest.cpp"
#include "./packingTest/purchaseTest.cpp"
#include "./packingTest/stockTest.cpp"

bool selectMenu ();

int main() {
	while(selectMenu()) {}

	return 0;
}

bool selectMenu () {
	int menuNum;

	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: showMember" << endl;
	cout << "2: showStock" << endl;
	cout << "3: showPurchase" << endl;
	cout << "4: MemberTest" << endl;
	cout << "5: StockTest" << endl;
	cout << "6: Purchasetest" << endl;
	cout << "7: TicketPurchaseSystem" << endl;
	cout << "8: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	cin >> menuNum;

	


	return false;
}
