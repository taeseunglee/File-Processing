#ifndef __RECORD_SEARCH__
#define __RECORD_SEARCH__
#include "../classes/class_member.h"
#include "../classes/class_purchase.h"
#include "../classes/class_stock.h"

#include "../environment.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <string.h>
#include <cstring>
#include <vector>

void recordSearchMain(Environment& env) {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: Search Member" << endl;
	cout << "2: Search Ticket" << endl;
	cout << "3: Search Purchase" << endl;
	cout << "4: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;
	string id;
	bool findFlag = false;

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	char* filename = new char [MAX_FILENAME];

	switch (menuNum) {
		case 1: 
			{
				cout << "Enter Id that you search" << endl << ">> ";
				cin >> id;
				FINDINDATA(env.memberData, id, findFlag);
				if (findFlag) {
					cout << "Element found" << endl;
					RecordFile <Member> memberFile (buffer);
					Member m;

					strlcpy(filename, "../built/fileOfMember.dat", MAX_FILENAME - 1);
					memberFile.Open(filename, ios::in);
					memberFile.Read(m, env.memberData[id]);
					cout << m << endl;
					memberFile.Close();
				}
				else { cout << "Element not found" << endl; }
			}
			break;
		case 2: 
			{
				cout << "Enter Id that you search" << endl << ">> ";
				cin >> id;
				FINDINDATA(env.stockData, id, findFlag);
				if (findFlag) {
					cout << "Element found in stockData" << endl;
					RecordFile <Stock> stockFile (buffer);
					Stock s;

					strlcpy(filename, "../built/fileOfStock.dat", MAX_FILENAME - 1);
					stockFile.Open(filename, ios::in);
					stockFile.Read(s, env.stockData[id]);
					cout << s << endl;
					stockFile.Close();
				}
				else { cout << "Element not found" << endl; }
			}
			break;
		case 3: 
			{
				cout << "Select the ID type that you will find in." << endl;
				cout << "1: MemberId" << endl << "2: StockId" << endl << "3: PurchaseId" << endl;

				int flag;
				cin >> flag;
				if (!(flag == 1 || flag == 2 || flag == 3)) { 
					cout << "You must enter the number 1, 2 or 3" << endl; 
					break;
				}

				cout << "Enter Id what you search" << endl << ">> ";
				cin >> id;
				findFromEnv(env.purchaseList, id, flag);
			}
			break;
		case 4: break;
	}
	delete [] filename;
}

#ifdef test_recordSearch
int main() {

	return 0;
}
#endif

#endif
