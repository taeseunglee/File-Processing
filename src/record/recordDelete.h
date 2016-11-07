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
#include <iostream>

template<class T>
bool recordDeleteDat(int recAddr, string strfilename, T t) {
	char *filename = new char [strfilename.length() + 1];
	std::strcpy (filename, strfilename.c_str());
	bool isSuccess = true;

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);

	RecordFile <T> tFile (buffer);
	tFile.Open (filename, ios::in | ios::out);

	if (tFile.Delete(recAddr) == -1) {
		cout << "Delete fail!" << endl;
		isSuccess = false;
	}
	else {
		cout << "Delete Success!" << endl;
	}
	tFile.Close ();

	delete [] filename;

	return isSuccess;
}

void recordDeletePurchaseMID(
		std::map<string, int> &purchaseData,
		vector<Purchase>& purchaseList, 
		string mid) {
	for (std::vector<Purchase>::iterator it = purchaseList.begin();
			it != purchaseList.end(); ++it) {
		if ((*it).getMemberId() == mid) {
			bool isDeleted = false;
			string purchaseId = (*it).getId();

			Purchase p;
			isDeleted = recordDeleteDat(
					purchaseData[purchaseId],
					"../built/fileOfPurchase.dat", p);

			if (isDeleted) {
				purchaseData.erase(purchaseId);
				purchaseList.erase(it);
				--it;
			}
		}
	}
}

void recordDeletePurchaseSID(
		std::map<string, int> &purchaseData,
		vector<Purchase>& purchaseList,
		string sid) {
	for (std::vector<Purchase>::iterator it = purchaseList.begin();
			it != purchaseList.end(); ++it) {
		if ((*it).getStockId() == sid) {
			bool isDeleted = false;
			string purchaseId = (*it).getId();

			Purchase p;
			isDeleted = recordDeleteDat(
					purchaseData[purchaseId],
					"../built/fileOfPurchase.dat", p);


			if (isDeleted) {
				purchaseData.erase(purchaseId);
				purchaseList.erase(it);
				--it;
			}
		}
	}

}

void recordDeletePurchasePID(
		std::map<string, int>& purchaseData,
		vector<Purchase>& purchaseList,
		vector<Purchase>::iterator it) {
	purchaseData.erase((*it).getId());
	purchaseList.erase(it);
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
				if (env.memberData.find(id) == env.memberData.end()) { 
					cout << "Element not found" << endl;
					break;
				} // not found
				Member mtemp;
				recordDeletePurchaseMID(env.purchaseData,
						env.purchaseList, id);
				recordDeleteDat(env.memberData[id], "../built/fileOfMember.dat", mtemp);
				env.memberData.erase(id);
			}
			break;

		case 2: 
			{	
				cout << "Enter Id what you want to delete." << endl << ">> ";
				cin >> id;
				if (env.stockData.find(id) == env.stockData.end()) {
					cout << "Element not found" << endl;
					break;
				} // not found
				Stock stemp;
				recordDeletePurchaseSID(env.purchaseData,
						env.purchaseList, id);
				recordDeleteDat(env.stockData[id], "../built/fileOfStock.dat", stemp);
				env.stockData.erase(id);
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

				vector<Purchase>::iterator it = findFromEnv(env.purchaseList, id, flag);
				// not Found
				if (it == env.purchaseList.end()) { break; }

				switch (flag) {
					case 1: // Member
						recordDeletePurchaseMID(env.purchaseData,
								env.purchaseList, id);
						break;
					case 2: // StockId
						recordDeletePurchaseSID(env.purchaseData, 
								env.purchaseList, id);
						break;
					case 3: // Purchase
						recordDeletePurchasePID(env.purchaseData,
								env.purchaseList, it);
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
