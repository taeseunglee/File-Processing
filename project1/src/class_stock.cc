#include <iostream>
#include <string>

using namespace std;

class Stock {
	long long int	ID;
	char			category[8];
	string			material;
	int				price;
	int				stock;
	string			washingInfo;
	char			size[2];

	public:
		Stock();
};

Stock::Stock(void)
{
	cout << "Object is being created" << endl;
}

int main ()
{
	Stock stock;

	return 0;
}
