#include "../classes/class_purchase.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

int main() {
	ifstream ifs ("../../resources/listOfPurchase.txt");
	char filename[ ] = "fileOfPurchase.dat";

	int n;
	ifs >> n;
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', PUR_MAX_BUF);
	RecordFile <Purchase> purchaseFile (buffer);

	// Write test
	purchaseFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Purchase m;
		ifs >> m;
		
		int recAddr;
		if ((recAddr = purchaseFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
		else { cout << "Write at " << recAddr << endl; }
	}
	purchaseFile.Close ();


	// Read Test
	purchaseFile.Open (filename, ios::in);
	for (int i = 0; i < n; i++) {
		Purchase m;
		purchaseFile.Read(m);
		cout << m;
	}
	purchaseFile.Close();

	return 0;
}
