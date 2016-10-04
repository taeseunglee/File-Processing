#ifndef __ENVIRONMENT__
#define __ENVIRONMENT__

#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"
#include <vector>

// TODO : RECADDR 도 같이 mapping 하는 것으로 바꿔야 Delete할 수 있다. 왜냐하면 delete 할 위치를
// 알아야하기 때문에 이것은 프로젝트 2에서 하는 것으로... delete는 실패.

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
vector<Member>::iterator findFromEnv (vector<Member>& memberData, string id, bool isPrint = true) {
	std::vector<Member>::iterator it = memberData.begin();
	for (; it != memberData.end(); ++it) {
		if ((*it).getId() == id) { break; }
	}

	if (it != memberData.end()) {
		if (isPrint){ cout << "Element found in memberData" << *it << endl; }
	}
	else {
		if (isPrint) { cout << "Element not found memberData" << endl; }
	}
	return it;
}

vector<Stock>::iterator findFromEnv (vector<Stock>& stockData, string id, bool isPrint = true) {
	std::vector<Stock>::iterator it = stockData.begin();
	for (; it != stockData.end(); ++it) {
		if ((*it).getId() == id) { break; }
	}

	if (it != stockData.end()) {
		if (isPrint) { cout << "Element found in stockData" << *it << endl; }
	}
	else { 
		if (isPrint) {cout << "Element not found in stockData" << endl; }
	}
	return it;
}
vector<Purchase>::iterator findFromEnv (vector<Purchase>& purchaseData, string id, int flag, bool isPrint = true) {
	std::vector<Purchase>::iterator it = purchaseData.begin();
	switch (flag) {
		case 1: // Member
			for (; it != purchaseData.end(); ++it) {
				if ((*it).getMemberId() == id) { break; }
			}
			break;
		case 2: // Stock
			for (; it != purchaseData.end(); ++it) {
				if ((*it).getStockId() == id) { break; }
			}
			break;
		case 3: // Purchase
			for (; it != purchaseData.end(); ++it) {
				if ((*it).getPurchaseId() == id) { break; }
			}
			break;
	}

	if (it != purchaseData.end()) { 
		if (isPrint) { cout << "Element found in purchaseData" << *it << endl; }
	}
	else {
		if (isPrint) {cout << "Element not found in purchaseData" << endl; }
	}
	return it;
}

#endif
