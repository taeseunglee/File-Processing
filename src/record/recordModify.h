#ifndef __RECORD_MODIFY__
#define __RECORD_MODIFY__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../environment.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

#include "./recordInsert.h"
#include "./recordDelete.h"

template <class T>
bool recordUpdate(int oldRecAddr, T newT, string strfilename) {
	char *filename = new char [strfilename.length() + 1];
	std::strcpy (filename, strfilename.c_str());
	ifstream ifs (filename);
	bool isSuccess = true;
	
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <T> tFile (buffer);

	tFile.Open (filename, ios::out);
	
	if (tFile.Update(oldRecAddr, newT) == -1) {
		cout << "Update fail!" << endl;
		isSuccess = false;
	}
	else {
		cout << "Update Success!" << endl;
	}
	tFile.Close ();

	delete [] filename;

	return isSuccess;
}


// If you modify information of specific member
bool recordModifyMember(Environment& env, string id = "") {
	if (id.empty()) {
		cout << "Enter Member ID for modification" << endl << ">> ";
		cin >> id;

		if (env.memberData.find(id) == env.memberData.end()) { // not found
			return false;
		}
	}

	Member memberTemp;
	memberTemp.setId(id);

	// modification
	cout << "========= Insert new information ============" << endl;
	bool isSuccess = getNewClass(env, memberTemp, true); // always true
	cout << "========= end ===============================" << endl;

	cout << "Updating.." << endl;

	// Updating(Appending)
	isSuccess = recordUpdate(env.memberData[id], memberTemp, "../built/fileOfMember.dat");

	return isSuccess;
}

bool recordModifyStock(Environment& env) {
	cout << "Enter Stock ID for modification" << endl << ">> ";
	string id;
	cin >> id;

	if (env.stockData.find(id) == env.stockData.end())
		return false;

	Stock stockTemp;
	stockTemp.setId(id);

	// modification
	cout << "========= modification starting ============" << endl;
	bool isSuccess = getNewClass(env, stockTemp, true); // always true
	cout << "=========== modification end ==============" << endl;

	cout << "Updating.." << endl;

	// Updating(Appending)
	isSuccess = recordUpdate(env.stockData[id], stockTemp, "../built/fileOfStock.dat");

	return isSuccess;
}

bool recordModifyPurchase(Environment& env, string id = "") {
	if (id.empty()) {
		cout << "Enter Purchase ID for modification" << endl << ">> ";
		cin >> id;

		if (env.purchaseData.find(id) == env.purchaseData.end())
			return false;
	}

	Purchase purchaseTemp;
	purchaseTemp.setPurchaseId(id);

	// modification
	cout << "========= modification starting ============" << endl;
	bool isSuccess = getNewClass(env, purchaseTemp, true);
	cout << "=========== modification end ==============" << endl;
	if (!isSuccess)
		return false;

	cout << "Updating.." << endl;

	// Updating(Appending)
	isSuccess = recordUpdate(env.purchaseData[id], purchaseTemp, "../built/fileOfPurchase.dat");

	return isSuccess;
}
void recordModifyMain(Environment& env) {
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
	bool isSuccess;

	switch (menuNum) {
		case 1: isSuccess = recordModifyMember(env); break;
		case 2: isSuccess = recordModifyStock(env); break;
		case 3: isSuccess = recordModifyPurchase(env); break;
		case 4: break;
	}
	if (isSuccess) {
		cout << "Modifing data completes" << endl;
	}
	else {
		cout << "Modifing data fails" << endl;
	}
}


#ifdef test_recordModify
int main() {

	return 0;
}
#endif

#endif
