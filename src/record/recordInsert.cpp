#ifndef __RECORD_INSERT__
#define __RECORD_INSERT__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../environment.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>
#include <cstring>

#ifdef test_recordInsert
int main() {

	return 0;
}
#endif

template<class T>
void recordInsert(vector<T> &tData, string strfilename) {
	char *filename = new char [strfilename.length() + 1];
	std::strcpy (filename, strfilename.c_str());
	ifstream ifs (filename);
	
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <T> tFile (buffer);

	T newTemp;
	getNewClass(newTemp);



	// Write test
	tFile.Open (filename, ios::out);
	bool overlapFlag = false;

	if (overlapCheck(tData, newTemp)) {
		overlapFlag = true;
		cout << "It is overlapped!" << endl;
	}
	else {
		if (tFile.Append(newTemp) == -1) {
			cout << "Append fail!" << endl;
		}
		else {
			insertToEnv(tData, newTemp);
			cout << "Insert Success!" << endl;
		}
	}
	tFile.Close ();

	delete [] filename;
}

void getNewClass(Member &newMember) {
	string temp;
	
	cout << "Enter Member's fields" << endl;
	cout << "ID : ";		cin >> temp; newMember.setId(temp);
	cout << "Name : ";		getline(cin, temp); getline(cin, temp); newMember.setName(temp);
	cout << "phoneNumber : "; cin >> temp; newMember.setPhoneNumber(temp);
	cout << "address : ";	cin >> temp; newMember.setAddress(temp);
	cout << "birthday : ";	cin >> temp; newMember.setBirthday(temp);
	cout << "email : ";		cin >> temp; newMember.setEmail(temp);
}

void getNewClass(Stock &newStock) {
	string temp;
	
	cout << "Enter Stock's fields" << endl;
	cout << "ID : ";		cin >> temp;	newStock.setId(temp);
	cout << "Category : ";	cin >> temp;	newStock.setCategory(temp);
	cout << "Material : ";	cin >> temp;	newStock.setMaterial(temp);
	cout << "Price : ";		cin >> temp;	newStock.setPrice(temp);
	cout << "Stock : ";		cin >> temp;	newStock.setStock(temp);
	cout << "Washing Info : ";	cin >> temp;newStock.setWashingInfo(temp);
	cout << "Size : ";		cin >> temp;	newStock.setSize(temp);
}

void getNewClass(Purchase &newPurchase) {
	string temp;
	
	cout << "Enter Purchase's fields" << endl;
	cout << "PurchaseId : ";cin >> temp;	newPurchase.setPurchaseId(temp);
	cout << "StockId : ";	cin >> temp;	newPurchase.setStockId(temp);
	cout << "MemberId : ";	cin >> temp;	newPurchase.setMemberId(temp);
	cout << "Quantity : ";	cin >> temp;	newPurchase.setQuantity(temp);
}

void recordInsertMain(Environment &env) {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: Member " << endl;
	cout << "2: Ticket " << endl;
	cout << "3: Purchase " << endl;
	cout << "4: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	string filename = "../built/fileOf";
	switch (menuNum) {
		case 1:
			filename = filename + "Member.dat";
			recordInsert(env.memberData, filename);
			break;
		case 2:
			filename = filename + "Stock.dat";
			recordInsert(env.stockData, filename);
			break;
		case 3: 
			filename = filename + "Purchase.dat";
			recordInsert(env.purchaseData, filename);
			break;
		case 4: break;
	}
}


#endif
