#ifndef __STOCK_TEST__
#define __STOCK_TEST__

#include "../classes/class_stock.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void stockTest (int flag = 10) {
	ifstream ifs ("../resources/listOfStock.txt");
	char filename[ ] = "../built/fileOfStockdat";

	int n = 0;
	if (flag != 10) { ifs >> n;	}
	else			{ n = 10; }
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', STK_MAX_BUF);
	RecordFile <Stock> stockFile (buffer);

	// Write test
	stockFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Stock m;
		ifs >> m;

		int recAddr;
		if ((recAddr = stockFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
		else if (flag == 10) { cout << "Write at " << recAddr << endl; }
	}
	stockFile.Close ();

	if (flag == 10) {
		// Read Test
		stockFile.Open (filename, ios::in);
		for (int i = 0; i < n; i++) {
			Stock m;
			stockFile.Read(m);
			cout << m;
		}
		stockFile.Close();
	}
};

#ifdef test_stockTest
int main() {
	stockTest();

	return 0;
}
#endif

#endif
