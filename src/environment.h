#ifndef __ENVIRONMENT__
#define __ENVIRONMENT__

#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"
#include <string.h>
#include <vector>
#include <map>

#define FINDINDATA(classData, id, findFlag)			\
	do{												\
		if(classData.find(id) != classData.end()) {	\
			findFlag = true;						\
		} else { findFlag = false; }				\
	} while(0)

#define MAX_FILENAME 40

// key		: Main Id
// value	: record address
typedef struct Environment {
	std::map <string, int> memberData;
	std::map <string, int> stockData;
	std::map <string, int> purchaseData;
	vector <Purchase> purchaseList;
} Environment;

void setEnvironment(Environment &env) {
	/*
	ifstream ifs;
	int count;
	string temp;

	ifs.open("../resources/listOfMember.txt");
	ifs >> count;
	getline(ifs, temp);
	Member memTemp;
	for (int i = 0; i < count; i++) {
		ifs >> memTemp;
		env.memberData[memTemp.getId()];
	}
	ifs.close();


	ifs.open("../resources/listOfStock.txt");
	ifs >> count;
	getline(ifs, temp);
	Stock stkTemp;
	for (int i = 0; i < count; i++) {
		ifs >> stkTemp;
		env.stockData[stkTemp.getId()];
	}
	ifs.close();
*/

	ifstream ifs;
	int count;
	string temp;

	ifs.open("../resources/listOfPurchase.txt");
	ifs >> count;
	getline(ifs, temp);
	Purchase purTemp;
	for (int i = 0; i < count; i++) {
		ifs >> purTemp;
//		env.purchaseData[purTemp.getId()];
		env.purchaseList.push_back(purTemp);
	}
	ifs.close();
}

bool getMember(int recaddr, Member& m) {
	char filename[MEM_MAX_BUF];
	strlcpy (filename, MEM_FILE_DAT, MEM_MAX_BUF - 1);

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Member> memberFile (buffer);

	memberFile.Open (filename, ios::in);
	if (memberFile.Read(m, recaddr) == -1)
		return false;

	return true;
}
/*
bool getStock(int recaddr, Stock& s) {
	char filename[STK_MAX_BUF];
	strlcpy (filename, STK_FILE_DAT, STK_MAX_BUF);

	DelimFieldBuffer buffer ('|', STK_MAX_BUF);
	RecordFile <Stock> stockFile (buffer);

	stockFile.Open (filename, ios::in);
	if (stockFile.Read (s, recaddr) == -1)
		return false;

	return true;
}

bool getPurchase(int recaddr, Purchase& p) {
	char filename[PUR_MAX_BUF];
	strlcpy(filename, PUR_FILE_DAT, PUR_MAX_BUF - 1);

	DelimFieldBuffer buffer ('|', PUR_MAX_BUF);
	RecordFile <Purchase> purchaseFile (buffer);
	purchaseFile.Open (filename, ios::in);

	if (purchaseFile.Read(p, recaddr) == -1)
		return false;

	return true;
}
*/

void findFromEnv (vector<Purchase>& purchaseList, string id, int flag)
{
	std::vector<Purchase>::iterator it = purchaseList.begin();
	switch (flag) {
		case 1: // Member
			{
				for (; it != purchaseList.end(); ++it)  {
					if ((*it).getMemberId() == id) { 
						cout << *it << endl;
					}
				}
			} break;
		case 2: // Stock
			{
				for (; it != purchaseList.end(); ++it)  {
					if ((*it).getStockId() == id) {
						cout << *it << endl;
					}
				}
			} break;
		case 3:
			{ // Purchase
				for (; it != purchaseList.end(); ++it)  {
					if ((*it).getId() == id) {
						cout << *it << endl;
						break;
					}
				}
			} break;
	}
}

#endif
