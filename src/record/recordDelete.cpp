#ifndef __RECORD_DELETE__
#define __RECORD_DELETE__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../environment.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>
#include <cstring>

void recordDeletePurchaseMID(vector<Purchase>& purchaseData, string mid) {
	for (std::vector<Purchase>::iterator it = purchaseData.begin();
			it != purchaseData.end(); ++it) {
		if ((*it).getMemberId() == mid) {
			purchaseData.erase(it);
			--it;
		}
	}
}

void recordDeletePurchaseSID(vector<Purchase>& purchaseData, string sid) {
	for (std::vector<Purchase>::iterator it = purchaseData.begin();
			it != purchaseData.end(); ++it) {
		if ((*it).getStockId() == sid) {
			purchaseData.erase(it);
			--it;
		}
	}

}

void recordDeletePurchasePID(vector<Purchase>& purchaseData, vector<Purchase>::iterator it) {
	purchaseData.erase(it);
}


void recordDeleteMain(Environment& env) {
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
	string id;

	switch (menuNum) {
		case 1: 
			{
				cout << "Enter Id what you want to delete." << endl << ">> ";
				cin >> id;
				vector<Member>::iterator it = findFromEnv(env.memberData, id);
				if (it == env.memberData.end()) { break; } // not found
				env.memberData.erase(it);
			}
			break;

		case 2: 
			{	
				cout << "Enter Id what you want to delete." << endl << ">> ";
				cin >> id;
				vector<Stock>::iterator it = findFromEnv(env.stockData, id);
				if (it == env.stockData.end()) { break; } // not found
				env.stockData.erase(it);
			}
			break;
		case 3: 
			{
				cout << "Select the type." << endl;
				cout << "1: MemberId" << endl << "2: StockId" << endl << "3: PurchaseId" << endl;

				int flag;
				cin >> flag;
				if (!(flag == 1 || flag == 2 || flag == 3)) { 
					cout << "You must enter the number 1, 2 or 3." << endl; 
					break;
				}

				cout << "Enter Id what you want to delete." << endl << ">> ";
				cin >> id;
				
				vector<Purchase>::iterator it = findFromEnv(env.purchaseData, id, flag);
				// not Found
				if (it == env.purchaseData.end()) { break; }

				switch (flag) {
					case 1: // Member
						recordDeletePurchaseMID(env.purchaseData, id);
						break;
					case 2: // StockId
						recordDeletePurchaseSID(env.purchaseData, id);
						break;
					case 3: // Purchase
						recordDeletePurchasePID(env.purchaseData, it);
						break;
				}
			}
			break;
		case 4: break;
	}
}


#ifdef test_recordDelete
int main() {

	return 0;
}
#endif

#endif
