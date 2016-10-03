#ifndef __RECORD_SEARCH__
#define __RECORD_SEARCH__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../environment.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <cstring>
#include <vector>

void recordSearchMain(Environment& env) {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: Search Member" << endl;
	cout << "2: Search Ticket" << endl;
	cout << "3: Search Purchase" << endl;
	cout << "4: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;
	string id;

	switch (menuNum) {
		case 1: cout << "Input a Id what you search" << endl << ">>";
				cin >> id;
				findFromEnv(env.memberData, id);
				break;

		case 2: cout << "Input a Id what you search" << endl << ">>";
				cin >> id;
				findFromEnv(env.stockData, id);
				break;

		case 3: cout << "Select the type" << endl;
				cout << "1: MemberId" << endl << "2: StockId" << endl << "3: PurchaseId" << endl;

				int flag;
				cin >> flag;
				if (!(flag == 1 || flag == 2 || flag == 3)) { 
					cout << "You must enter the number 1, 2 or 3" << endl; 
					break;
				}

				cout << "Enter a Id what you search" << endl << ">>";
				cin >> id;
				findFromEnv(env.purchaseData, id, flag);
				break;
		case 4: break;
	}
}

#ifdef test_recordSearch
int main() {

	return 0;
}
#endif

#endif
