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
#include <map>

#ifdef test_recordInsert
int main() {

	return 0;
}
#endif

template<class T>
void recordInsert(const Environment &env, std::map<string, int>& tData, string strfilename, T newTemp) {
	char *filename = new char [strfilename.length() + 1];
	std::strcpy (filename, strfilename.c_str());
	ifstream ifs (filename);
	
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	bool checkIntegrity = getNewClass(env, newTemp);

	if (!checkIntegrity) {
		cout << "You cannot Insert this information since informations are not matching." << endl;
	}
	else { // Insert Element.
		DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
		RecordFile <T> tFile (buffer);
		tFile.Open (filename, ios::out);

		int recAddr;
		if ((recAddr = tFile.Append(newTemp)) == -1) {
			cout << "Append fail!" << endl;
		}
		else {
			tData[newTemp.getId()] = recAddr;
			cout << "Insert Success!" << endl;
		}
		tFile.Close ();
	}

	delete [] filename;
}



/* getNewClass
 * make new class object by input.
 * Check new object passes referential integrity.
 * If new object is generated without any problem, return true,
 * otherwise return false.
*/
bool getNewClass(const Environment env, Member &newMember, bool isModify = false) {
	string temp;
	cout << "Enter Member's fields" << endl;

	if (!isModify) {
		cout << "ID : "; cin >> temp;
		if (env.memberData.find(temp) != env.memberData.end()) { return false; }
		newMember.setId(temp);
	}

	cout << "Name : ";		getline(cin, temp); getline(cin, temp); newMember.setName(temp);
	cout << "phoneNumber : "; cin >> temp; newMember.setPhoneNumber(temp);
	cout << "address : ";	cin >> temp; newMember.setAddress(temp);
	cout << "birthday : ";	cin >> temp; newMember.setBirthday(temp);
	cout << "email : ";		cin >> temp; newMember.setEmail(temp);

	return true;
}

// isModify is used for recordModify
bool getNewClass(const Environment env, Stock &newStock, bool isModify = false) {
	string temp;
	
	cout << "Enter Stock's fields" << endl;

	if (!isModify) {
		cout << "ID : "; cin >> temp;
		if (env.stockData.find(temp) != env.stockData.end()) {
			return false;
		}
		newStock.setId(temp);
	}

	cout << "Category : ";	cin >> temp;	newStock.setCategory(temp);
	cout << "Material : ";	cin >> temp;	newStock.setMaterial(temp);
	cout << "Price : ";		cin >> temp;	newStock.setPrice(temp);
	cout << "Stock : ";		cin >> temp;	newStock.setStock(temp);
	cout << "Washing Info : ";	cin >> temp;newStock.setWashingInfo(temp);
	cout << "Size : ";		cin >> temp;	newStock.setSize(temp);

	return true;
}

bool getNewClass(const Environment env, Purchase &newPurchase, bool isModify = false) {
	string temp;
	
	cout << "Enter Purchase's fields" << endl;

	if (!isModify) {
		cout << "PurchaseId : ";cin >> temp;
		if (env.purchaseData.find(temp) != env.purchaseData.end()) {
			return false;
		}
		newPurchase.setPurchaseId(temp);
	}

	cout << "StockId : ";	cin >> temp;
	if (env.stockData.find(temp) == env.stockData.end()) {
		return false;
	}
	newPurchase.setStockId(temp);

	cout << "MemberId : ";	cin >> temp;
	if (env.memberData.find(temp) == env.memberData.end()) {
		return false;
	}
	newPurchase.setMemberId(temp);

	cout << "Quantity : ";	cin >> temp;	newPurchase.setQuantity(temp);
	
	return true;
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
			{
				Member mt;
				filename = filename + "Member.dat";
				recordInsert(env, env.memberData, filename, mt);
			}
			break;
		case 2:
			{
				Stock st;
				filename = filename + "Stock.dat";
				recordInsert(env, env.stockData, filename, st);
			}
			break;
		case 3: 
			{
				Purchase pt;
				filename = filename + "Purchase.dat";
				recordInsert(env, env.purchaseData, filename, pt);
			}
			break;
		case 4: break;
	}
}

#endif
