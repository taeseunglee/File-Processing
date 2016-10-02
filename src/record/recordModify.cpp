#ifndef __RECORD_MODIFY__
#define __RECORD_MODIFY__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void recordModifyMain() {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: Modify Member" << endl;
	cout << "2: Modify Ticket" << endl;
	cout << "3: Modify Purchase" << endl;
	cout << "4: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	switch (menuNum) {
		case 1: recordModifyMember(); break;
		case 2: recordModifyStock(); break;
		case 3: recordModifyPurchase(); break;
		case 4: break;
	}
}

void recordModifyMember() {

}

void recordModifyStock() {

}

void recordModifyPurchase() {

}

#ifdef test_recordModify
int main() {

	return 0;
}
#endif

#endif
