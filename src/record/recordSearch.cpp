#ifndef __RECORD_SEARCH__
#define __RECORD_SEARCH__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void recordSearchMain() {
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

	switch (menuNum) {
		case 1: recordSearchMember(); break;
		case 2: recordSearchStock(); break;
		case 3: recordSearchPurchase(); break;
		case 4: break;
	}
}

void recordSearchMember() {

}

void recordSearchStock() {

}

void recordSearchPurchase() {


}

#ifdef test_recordSearch
int main() {

	return 0;
}
#endif

#endif
