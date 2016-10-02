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
