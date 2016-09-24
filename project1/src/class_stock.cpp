#include <iostream>
#include "class_stock.h"

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
	if (!strcmp(ID, S.ID)) return true;
	else			return false;
}

bool Stock::operator !=(const Stock &S) {
	if (strcmp(S.ID, ID)) return true;
	else			return false;
}

void Stock::setID (char ID[13]) {
	strcpy(this->ID, ID);
}

void Stock::setCategory (char category[9]) {
	strcpy(this->category, category);
}

void Stock::setMaterial (string material) {
	this->material = material;
}

void Stock::setPrice (char price[7]) {
	strcpy(this->price, price);
}

void Stock::setStock (int stock) {
	this->stock = stock;
}

void Stock::setWashingInfo (string washingInfo) {
	this->washingInfo = washingInfo;
}

void Stock::setSize (char size[3]) {
	strcpy(this->size, size);
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
	
	if (you == me) {
		cout << "I'm you!" << endl;
	}
	if (hello == me) {
		cout << "hello!" << endl;
	}

	return 0;
}

