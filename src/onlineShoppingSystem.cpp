#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"

#include "./showClass/showMember.cpp"
#include "./showClass/showPurchase.cpp"
#include "./showClass/showStock.cpp"

#include "./packingTest/memberTest.cpp"
#include "./packingTest/purchaseTest.cpp"
#include "./packingTest/stockTest.cpp"
#include "environment.h"

#include "./record/recordInsert.h"
#include "./record/recordSearch.h"
#include "./record/recordDelete.h"
#include "./record/recordModify.h"

bool selectMenu (Environment &env);
void loginPurchaseSystem (Environment env);
bool adminModePurchaseSystem (Environment &env);
bool generalUserModePurchaseSystem (Environment &env, string id);


int main() {
	Environment env;
	setEnvironment(env);

	// make .dat from .txt
	memberTest(env, -1);
	stockTest(env, -1);
	purchaseTest(env, -1);

	while(selectMenu(env));

	return 0;
}

bool selectMenu (Environment &env) {
	cout << "=================================================" << endl;
	cout << "\t\tSelect the memu." << endl;
	cout << "1: showMember" << endl;
	cout << "2: showStock" << endl;
	cout << "3: showPurchase" << endl;
	cout << "4: MemberTest" << endl;
	cout << "5: StockTest" << endl;
	cout << "6: PurchaseTest" << endl;
	cout << "7: TicketPurchaseSystem" << endl;
	cout << "8: EXIT" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	bool result = true;
	switch (menuNum) {
		case 1: showMember(); break;
		case 2: showStock(); break;
		case 3: showPurchase(); break;

		case 4: memberTest(env); break;
		case 5: stockTest(env); break;
		case 6: purchaseTest(env); break;

		case 7: loginPurchaseSystem(env); break;
		case 8: default: return result = false;
	}

	return result;
}

// return Member's level. if return -1 then loggin failed.
void loginPurchaseSystem (Environment env) {
	string id, password;
	cout << "=================================================" << endl;
	cout << "\tTicketPurchaseSystem - Login Window -" << endl;
	cout << "=================================================" << endl;
	cout << "Enter ID and Password" << endl;
	cout << "ID : "; cin >> id;
	cout << "PW : "; cin >> password;
	
	// Admin or TestUser only can pass login.
	// Start Admin Mode
	string level;
	bool findFlag = false;
	Member mTemp;

	FINDINDATA(env.memberData, id, findFlag);

	if (findFlag) {
		bool findMember = getMember(env.memberData[id], mTemp);
		if (findMember) {
			if (mTemp.isPassword(password))
				level = mTemp.getLevel();
			else
				level = "-1";
		}
	}
	else {
		level = "-1";
	}

	
	if (!level.compare("1"))
		while(adminModePurchaseSystem(env));
	else if (!level.compare("9"))
		while(generalUserModePurchaseSystem(env, id));
	else
		cout << "Login Failed. Incorrect Username or Password " << endl;
}

bool adminModePurchaseSystem (Environment &env) {
	cout << "=================================================" << endl;
	cout << "\tTicketPurchaseSystem - Admin Mode -" << endl;
	cout << "1: Search record" << endl;
	cout << "2: Insert record" << endl;
	cout << "3: Delete record" << endl;
	cout << "4: Modify record" << endl;
	cout << "5: Close AdminMode" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	bool result = true;
	switch (menuNum) {
		case 1: recordSearchMain(env); break;
		case 2: recordInsertMain(env); break;
		case 3: recordDeleteMain(env); break;
		case 4: recordModifyMain(env); break;
		case 5: default: return result = false;
	}

	return result;
}


bool generalUserModePurchaseSystem (Environment &env, string memberId) {
	cout << "=================================================" << endl;
	cout << "\tTicketPurchaseSystem - General User Mode -" << endl;
	cout << "1: Modify Your record" << endl;
	cout << "2: Unregister Your account" << endl;
	cout << "3: Search Stock List" << endl;
	cout << "4: Search your Purchase List" << endl;
	cout << "5: Insert record in Purchase record" << endl;
	cout << "6: Modify Your Purchase record" << endl;
	cout << "7: Delete Your Purchase record" << endl;
	cout << "8: Close General User Mode" << endl << endl;
	cout << "Please enter the number of the menu." << endl;
	cout << "=================================================" << endl << ">> ";

	int menuNum;
	cin >> menuNum;

	bool result = true;
	switch (menuNum) {
		case 1: recordModifyMember(env, memberId); break;

		case 2: {
					Member mTemp;
					recordDeletePurchaseMID(env, memberId);
					recordDeleteDat(env.memberData[memberId], "../built/fileOfMember.dat", mTemp);
					env.memberData.erase(memberId);
				} return result = false;

		case 3: {
					bool findFlag = false;
					DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
					char *filename = new char [MAX_FILENAME];
					string id;

					cout << "Enter Stock Id that you search" << endl << ">> ";
					cin >> id;

					FINDINDATA(env.stockData, id, findFlag);
					if (findFlag) {
						RecordFile <Stock> stockFile (buffer);
						Stock s;

						strlcpy(filename, "../built/fileOfStock.dat", MAX_FILENAME - 1);
						stockFile.Open(filename, ios::in);
						stockFile.Read(s, env.stockData[id]);
						cout << s << endl;

						stockFile.Close();
						delete [] filename;
					}
				} break;

		case 4: {
					findFromEnv(env.purchaseList, memberId, 1);
				} break;

		case 5: {
					Purchase pt;
					string filename = "../built/fileOfPurchase.dat";
					recordInsert(env, env.purchaseData, filename, pt);
				} break;
		case 6: {
					recordModifyPurchase(env);
				} break;
		case 7: {
					string id;
					cout << "Enter id that you want to delete." << endl << ">> ";
					cin >> id;
					vector<Purchase> pList = env.purchaseList;
					std::vector<Purchase>::iterator it = pList.begin();
					for (; it != pList.end(); ++it) {
						if ((*it).getId() == id)
							break;
					}
					if (it != pList.end())
						recordDeletePurchasePID(env, it);
				} break;

		case 8: default: return result = false;
	}

	return result;
}
