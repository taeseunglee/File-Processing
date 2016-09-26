#include <iostream>
#include "class_stock.h"

// an constructor of class "Stock"
Stock::Stock (const string& id, const string& category, const string& material, const string& price, const int& stock, const string& washingInfo, const string& size)
	:id(id), category(category), material(material), price(price), stock(stock), washingInfo(washingInfo), size(size) { }
Stock::Stock(const Stock& S) :id(S.id), category(S.category), material(S.material), price(S.price), stock(S.stock), washingInfo(S.washingInfo), size(S.size) { }

// an assignment operator
Stock&  Stock::operator = (const Stock &S) {
	id			= S.id;
	category	= S.category;
	material	= S.material;
	price		= S.price;
	stock		= S.stock;
	washingInfo = S.washingInfo;
	size		= S.size;

   return *this;
}

bool Stock::operator ==(const Stock &S) {
	if (id == S.id) return true;
	else			return false;
}

bool Stock::operator !=(const Stock &S) {
	if (id == S.id) return true;
	else			return false;
}

void Stock::setId		(const string& id)		{ this->id = id; }
void Stock::setCategory (const string& category){ this->category = category; }
void Stock::setMaterial (const string& material){ this->material = material; }
void Stock::setPrice	(const string& price)	{ this->price = price; }
void Stock::setStock	(const int& stock)		{ this->stock = stock; }
void Stock::setWashingInfo (const string& washingInfo) { this->washingInfo = washingInfo; }
void Stock::setSize		(const string& size) { this->size = size; }


// testing main function
int main ()
{
	char category[9] = "Pants"
		,price[7] = "35,000"
		,size[3] = "X"
		,ID[13] = "012345678900";

	Stock me("012345678900", "Pants", "Denim", "35,000", 96, "Dry Cleaning", "X")
		   , you("012345678900", "Pants", "Denim", "35,000", 96, "Dry Cleaning", "XL")
		   , hello(me);

	if (you == me) {
		cout << "GWWWWWWWWWWWWWWWWWW" << endl;
	}

	// test overloaded operator =
	you = me;
	
	if (you == me) {
		cout << "I'm you!" << endl;
	}
	if (hello == me) {
		cout << "hello!" << endl;
	}

	return 0;
}

