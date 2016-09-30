#include "../../src/classes/class_member.cpp"

int main() {
	Member me;
	ifstream is;
	int count;
	string ll;

	is.open("../../resources/listOfMember.txt");

	is >> count;
	getline(is, ll);
	for (int i = 0; i < 10 ; i++) {
		is >> me;
		cout << me << endl;
	}

	return 0;
}
