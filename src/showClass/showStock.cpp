#ifndef __SHOW_STOCK__
#define __SHOW_STOCK__

#include "../../src/classes/class_stock.h"

void showStock () {
	Stock st;
	ifstream is;
	int count;
	string str;

	is.open("../../resources/listOfStock.txt");
	
	is >> count;
	getline (is, str);

	for (int i = 0; i < 10; i++) {
		is >> st;
		cout << st << endl;
	}
}

#ifdef test_showStock
int main() {
	showStock ();

	return 0;
}
#endif

#endif
