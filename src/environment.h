#ifndef __ENVIRONMENT__
#define __ENVIRONMENT__

#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"

#include <vector>

typedef struct Environment {
	vector <Member> memberData;
	vector <Stock>	stockData;
	vector <Purchase> purchaseData;
} Environment;

void setEnvironment(Environment &env) {
	ifstream ifs;
	int count;
	string temp;

	ifs.open("../resources/listOfMember.txt");
	ifs >> count;
	getline(ifs, temp);
	Member memTemp;
	for (int i = 0; i < count; i++) {
		ifs >> memTemp;
		env.memberData.push_back(memTemp);
	}
	ifs.close();


	ifs.open("../resources/listOfStock.txt");
	ifs >> count;
	getline(ifs, temp);
	Stock stkTemp;
	for (int i = 0; i < count; i++) {
		ifs >> stkTemp;
		env.stockData.push_back(stkTemp);
	}
	ifs.close();

	
	ifs.open("../resources/listOfPurchase.txt");
	ifs >> count;
	getline(ifs, temp);
	Purchase purTemp;
	for (int i = 0; i < count; i++) {
		ifs >> purTemp;
		env.purchaseData.push_back(purTemp);
	}
}

bool overlapCheck(vector<Member> memberData, Member m) {
	for (std::vector<Member>::iterator it = memberData.begin();
			it != memberData.end(); ++it) { 
		if (m == *it) { return true; }
	}
	return false;
}

bool overlapCheck(vector<Stock> stockData, Stock s) {
	for (std::vector<Stock>::iterator it = stockData.begin();
			it != stockData.end(); ++it) {
		if (s == *it) { return true; }
	}
	return false;
}

bool overlapCheck(vector<Purchase> purchaseData, Purchase p) {
	for (std::vector<Purchase>::iterator it = purchaseData.begin();
			it != purchaseData.end(); ++it) {
		if (p == *it) { return true; }
	}
	return false;
}

void insertToEnv (vector<Member>& memberData, Member m)	{ memberData.push_back(m); }
void insertToEnv (vector<Stock>& stockData, Stock s)	{ stockData.push_back(s); }
void insertToEnv (vector<Purchase>& purchaseData, Purchase p) { purchaseData.push_back(p); }


// find data using id
void findFromEnv (const vector<Member>& memberData, string id) {
	std::vector<Member>::const_iterator it = memberData.begin();
	for (; it != memberData.end(); ++it) {
		if ((*it).getId() == id) { break; }
	}

	if (it != memberData.end()) { cout << "Element found in memberData" << *it << endl; }
	else { cout << "Element not found memberData" << endl; }
}

void findFromEnv (const vector<Stock>& stockData, string id) {
	std::vector<Stock>::const_iterator it = stockData.begin();
	for (; it != stockData.end(); ++it) {
		if ((*it).getId() == id) { break; }
	}

	if (it != stockData.end()) { cout << "Element found in stockData" << *it << endl; }
	else { cout << "Element not found in stockData" << endl; }
}
void findFromEnv (const vector<Purchase>& purchaseData, string id, bool isMember) {
	std::vector<Purchase>::const_iterator it = purchaseData.begin();
	if (isMember) {
		for (; it != purchaseData.end(); ++it) {
			if ((*it).getMemberId() == id) { break; }
		}
	}
	else {
		for (; it != purchaseData.end(); ++it) {
			if ((*it).getStockId() == id) { break; }
		}
	}
	if (it != purchaseData.end()) { cout << "Element found in purchaseData" << *it << endl; }
	else { cout << "Element not found in purchaseData" << endl; }
}

#endif
