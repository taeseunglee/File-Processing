#include "../../src/classes/class_purchase.cpp"

int main () {
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

	return 0;
}
