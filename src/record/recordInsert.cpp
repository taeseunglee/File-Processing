#ifndef __RECORD_INSERT__
#define __RECORD_INSERT__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void recordInsertMain() {
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

	switch (menuNum) {
		case 1: recordInsertMember(); break;
		case 2: recordInsertStock(); break;
		case 3: recordInsertPurchase(); break;
		case 4: break;
	}
}

void recordInsertMember() {
	char filename[ ] = "../resources/fileOfMember.dat";
	ifstream ifs (filename);

	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Member> memberFile (buffer);

	// Write test
	memberFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Member m;
		ifs >> m;
		
		if (newMember)

		int recAddr;
		if ((recAddr = memberFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
		else { cout << "Write at " << recAddr << endl; }
	}
	memberFile.Close ();


	// Read Test
	memberFile.Open (filename, ios::in);
	for (int i = 0; i < n; i++) {
		Member m;
		memberFile.Read(m);
		cout << m;
	}
	memberFile.Close();
}

void recordInsertStock() {
	
}

void recordInsertPurchase() {

}

void getNewClass(Member &newMember) {
	string temp;
	
	cout << "Enter Member's fields" << endl;
	cout << "ID : ";		cin >> temp; newMember.setId(temp);
	cout << "Name : ";		getline(cin, temp); newMember.setName(temp);
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
	cout << "Purchase's Id" 
}

#ifdef test_recordInsert
int main() {

	return 0;
}
#endif

#endif
