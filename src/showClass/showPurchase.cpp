#ifndef __SHOW_PURCHASE__
#define __SHOW_PURCHASE__

#include "../../src/classes/class_purchase.h"

void showPurchase () {
	Purchase p;
	ifstream is;
	int count;
	string ll;

	is.open("../../resources/listOfPurchase.txt");

	is >> count;
	getline(is, ll);

	for (int i = 0; i < 10; i++) {
		is >> p;
		cout << p << endl;
	}
}

#ifdef test_showPurchase
int main () {
	showPurchase();

	return 0;
}
#endif


#endif
