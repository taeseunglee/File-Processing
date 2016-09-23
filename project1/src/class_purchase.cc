#include <iostream>
#include <string>

using namespace std;

class Purchase {
	long long int	purchaseID;
	long long int	stockID;
	string			memberID;
	int				quantity;
	public:
		Purchase();
};

Purchase::Purchase(){
	cout << "Purchase" << endl;
}

int main() {
	Purchase pur;

	return 0;
}
