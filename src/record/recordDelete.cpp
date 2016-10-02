#ifndef __RECORD_DELETE__
#define __RECORD_DELETE__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void recordDeleteMain() {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: Delete Member" << endl;
	cout << "2: Delete Ticket" << endl;
	cout << "3: Delete Purchase" << endl;
	cout << "4: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	switch (menuNum) {
		case 1: recordDeleteMember(); break;
		case 2: recordDeleteStock(); break;
		case 3: recordDeletePurchase(); break;
		case 4: break;
	}
}

void recordDeleteMember() {

}

void recordDeleteStock() {

}

void recordDeletePurchase () {

}

#ifdef test_recordDelete
int main() {

	return 0;
}
#endif

#endif
