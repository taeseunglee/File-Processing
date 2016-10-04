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

#include "./recordInsert.cpp"
#include "./recordDelete.cpp"

template <class T>
void recordUpdate(T oldT, T newT, string strfilename) {
	char *filename = new char [strfilename.length() + 1];
	std::strcpy (filename, strfilename.c_str());
	ifstream ifs (filename);
	
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <T> tFile (buffer);

	tFile.Open (filename, ios::out);
	
	if (tFile.Update(oldT, newT) == -1) {
		cout << "Update fail!" << endl;
	}
	else {
		cout << "Update Success!" << endl;
	}
	tFile.Close ();

	delete [] filename;

}


void recordModifyMember(vector<Member>& memberData) {
	cout << "Enter Member ID for modification" << endl << ">> ";
	string id;
	cin >> id;

	vector<Member>::iterator it = findFromEnv(memberData, id);
	if (it == memberData.end()) { return ; }

	Member findMemTemp(*it);

	// modification
	cout << "========= modification starting ============" << endl;
	
	string temp;
	cout << "Input Name." << endl;
	getline(cin, temp); getline(cin, temp);
	(*it).setName(temp);

	cout << "Input Phone Number." << endl;
	cin >> temp;
	(*it).setPhoneNumber(temp);

	cout << "Input address." << endl;
	cin >> temp;
	(*it).setAddress(temp);

	cout << "Input email" << endl;
	cin >> temp;
	(*it).setEmail(temp);

	cout << "Input birthday." << endl;
	cin >> temp;
	(*it).setBirthday(temp);

	cout << "=========== modification end ==============" << endl;

	cout << "Updating.." << endl;

	// Updating(Appending)
	recordUpdate(findMemTemp, *it, "../built/fileOfMember.dat");
}

void recordModifyStock(vector<Stock>& stockData) {
	cout << "Enter Stock ID for modification" << endl << ">> ";
	string id;
	cin >> id;

	vector<Stock>::iterator it = findFromEnv(stockData, id);
	if (it == stockData.end()) { return ; }

	Stock findStkTemp(*it); // current object copying
	// modification
	cout << "========= modification starting ============" << endl;
	
	string temp;
	cout << "Input the category.(8 characters)" << endl;
	cin >> temp;
	(*it).setCategory(temp);

	cout << "Input the material." << endl;
	cin >> temp;
	(*it).setMaterial(temp);

	cout << "Input the price.(6 characters(Numeric). ex.35,000)" << endl;
	cin >> temp;
	(*it).setPrice(temp);

	cout << "Input Stock.(4 characters(Numeric) ex. 96, 1400)" << endl;
	cin >> temp;
	(*it).setStock(temp);

	cout << "Input washingInfo." << endl;
	cin >> temp;
	(*it).setWashingInfo(temp);

	cout << "Input size (Type S, M, L or XL)" << endl;
	cin >> temp;
	(*it).setSize(temp);

	cout << "=========== modification end ==============" << endl;

	cout << "Updating.." << endl;

	// Updating(Appending)
	recordUpdate(findStkTemp, *it, "../built/fileOfStock.dat");
}

void recordModifyPurchase(vector<Purchase>& purchaseData) {
	cout << "Enter Purchase ID for modification" << endl << ">> ";
	string id;
	cin >> id;

	// fail to find same id.
	vector<Purchase>::iterator it = findFromEnv(purchaseData, id, 3);
	if (it == purchaseData.end()) { return ; }

	Purchase findPurTemp(*it); // current object copying

	// modification
	string temp;
	cout << "========= modification starting ============" << endl;
	
	cout << "Input the quantity." << endl;
	cin >> temp;
	(*it).setQuantity(temp);

	cout << "=========== modification end ==============" << endl;

	cout << "Updating.." << endl;

	// Updating(Appending)
	recordUpdate(findPurTemp, *it, "../built/fileOfPurchase.dat");
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

	switch (menuNum) {
		case 1: recordModifyMember(env.memberData); break;
		case 2: recordModifyStock(env.stockData); break;
		case 3: recordModifyPurchase(env.purchaseData); break;
		case 4: break;
	}
}


#ifdef test_recordModify
int main() {

	return 0;
}
#endif

#endif
