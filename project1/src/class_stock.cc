#include <iostream>
#include <string>

using namespace std;

class Stock {
	private:
		char			ID[13];
		char			category[9];
		string			material;
		char			price[7];
		int				stock;
		string			washingInfo;
		char			size[3];

	public:
		Stock (char _ID[13], char _category[9], string _material, char _price[7], int _stock, string _washingInfo, char _size[3]);
		Stock& operator = (const Stock &S);
		bool operator ==(const Stock &S);
		bool operator !=(const Stock &S);
		void print();
};

// an copy constructor of class "Stock"
Stock::Stock (char _ID[13], char _category[9], string _material, char _price[7], int _stock, string _washingInfo, char _size[3])
{
	strcpy(ID, _ID);
	strcpy(category, _category);
	material	= _material;
	strcpy(price, _price);
	stock		= _stock;
	washingInfo = _washingInfo;
	strcpy(size, _size);
}

// an assignment operator
Stock&  Stock::operator = (const Stock &S) {
	strcpy(ID, S.ID);
	strcpy(category, S.category);
	material	= S.material;
	strcpy(price, S.price);
	stock		= S.stock;
	washingInfo = S.washingInfo;
	strcpy(size, S.size);

   return *this;
}

bool Stock::operator ==(const Stock &S) {
	if (ID == S.ID) return true;
	else			return false;
}

bool Stock::operator !=(const Stock &S) {
	if (ID != S.ID) return true;
	else			return false;
}

// test member variable
void Stock::print() {
	cout  << ID << endl;
}


// testing main function
int main ()
{
	char category[9] = "Pants"
		,price[7] = "35,000"
		,size[3] = "X"
		,ID[13] = "012345678900";

	Stock me(ID, category, "Denim", price, 96, "Dry Cleaning", size)
		   , you(ID, category, "Denim", price, 96, "Dry Cleaning", size)
		   , hello(me);

	if (you == me) {
		cout << "GWWWWWWWWWWWWWWWWWW" << endl;
	}

	// test overloaded operator =
	you = me;
	you.print();
	
	if (you == me) {
		cout << "I'm you!" << endl;
	}
	if (hello == me) {
		cout << "hello!" << endl;
	}

	return 0;
}

