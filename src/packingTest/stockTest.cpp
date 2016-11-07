#ifndef __STOCK_TEST__
#define __STOCK_TEST__

#include "../classes/class_stock.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>
#include "../environment.h"

void stockTest (Environment &env, int flag = 10) {
	ifstream ifs ("../resources/listOfStock.txt");
	char filename[ ] = "../built/fileOfStock.dat";

	if (ifs.fail()) {
		cout << "\"listOfStock.txt\" File open Error!" << endl;
		exit(1);
	}

	int n = 0;
	ifs >> n;
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', STK_MAX_BUF);
	RecordFile <Stock> stockFile (buffer);

	// Write test
	stockFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Stock s;
		ifs >> s;

		int recAddr;
		if ((recAddr = stockFile.Write(s)) == -1) { cout << "Write Error!" << endl; }
		else {
			if (i < flag) {
				cout << "Write at " << recAddr << endl;
			}
			else {
				env.stockData[s.getId()] = recAddr;
			}
		}
	}
	stockFile.Close ();

	if (!(flag < 0)) {
		// Read Test
		stockFile.Open (filename, ios::in);
		for (int i = 0; i < n; i++) {
			Stock s;
			stockFile.Read(s);
			cout << s << endl;
		}
		stockFile.Close();
	}
};

#ifdef test_stockTest
int main() {
	Environment env;
	stockTest(env);

	return 0;
}
#endif

#endif
