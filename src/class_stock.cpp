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

istream& operator >> (istream& is, Stock& S) {
	string str;

	is.exceptions(istream::failbit | istream::badbit);

	try {
		getline(is, str);
	} catch (istream::failure e) {
		return is;
	}

	istringstream iss (str);
	string token;

	
	getline (iss, token, '|');
	S.setId (token);

	getline (iss, token, '|');
	S.setCategory (token);

	getline (iss, token, '|');
	S.setMaterial (token);
	
	getline (iss, token, '|');
	S.setPrice (token);

	getline (iss, token, '|');
	S.setStock (stoi(token));

	getline (iss, token, '|');
	S.setWashingInfo (token);

	getline (iss, token, '|');
	S.setSize (token);

	return is;
}

ostream& operator << (ostream& os, const Stock& S) {
	os << "Stock(ID, Category, Material, Price, Stock, WashingInfo, Size) : " << "(" << S.id;
	os << ", " << S.category;
	os << ", " << S.material;
	os << ", " << S.price;
	os << ", " << S.stock;
	os << ", " << S.washingInfo;
	os << ", " << S.size;
	os << ")";

	return os;
}
