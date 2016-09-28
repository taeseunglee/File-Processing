#include "./class_stock.cpp"

int main() {
	Stock st;
	ifstream is;
	int count;
	string str;

	is.open("../data/listOfStock.txt");
	
	is >> count;
	getline (is, str);

	for (int i = 0; i < 10; i++) {
		is >> st;
		cout << st << endl;
	}

	return 0;
}
