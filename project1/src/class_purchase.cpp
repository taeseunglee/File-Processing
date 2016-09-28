#include <iostream>
#include "class_purchase.h"

using namespace std;

Purchase::Purchase (const Purchase& P)
	:purchaseId(P.purchaseId), stockId(P.stockId), memberId(P.memberId), quantity(P.quantity) { }

Purchase& Purchase::operator = (const Purchase& P) {
	purchaseId	= P.purchaseId;
	stockId		= P.stockId;
	memberId	= P.memberId;
	quantity	= P.quantity;

	return *this;
}

bool Purchase::operator == (const Purchase &P) {
	if (purchaseId == P.purchaseId) return true;
	else							return false;
}

bool Purchase::operator != (const Purchase &P) {
	if (purchaseId != P.purchaseId) return true;
	else							return false;
}

void Purchase::setPurchaseId(const string& purchaseId)	{ this->purchaseId = purchaseId; }
void Purchase::setStockId	(const string& stockId)		{ this->stockId = stockId; }
void Purchase::setMemberId	(const string& memberId)	{ this->memberId = memberId; }
void Purchase::setQuantity	(const int& quantity)		{ this->quantity = quantity; }

istream& operator >> (istream& is, Purchase& P) {
	string str;
	
	is.exceptions(istream::failbit | istream::badbit);

	try {
		getline (is, str);
	} catch (istream::failure e) {
		return is;
	}

	istringstream iss (str);
	string token;


	getline (iss, token, '|');
	P.setPurchaseId (token);

	getline (iss, token, '|');
	P.setStockId (token);

	getline (iss, token, '|');
	P.setMemberId (token);

	getline (iss, token, '|');
	P.setQuantity (stoi(token));
	
	return is;
}

ostream& operator << (ostream& os, const Purchase& P) {
	os << "Purchase(PurchaseId, StockId, MemberId, Quantity) : " << "(" << P.purchaseId;
	os << ", " << P.stockId;
	os << ", " << P.memberId;
	os << ", " << P.quantity;
	os << ")";

	return os;
}


int main () {
	Purchase p;
	ifstream is;
	int count;
	string ll;

	is.open("../data/listOfPurchase.txt");

	is >> count;
	cout << count << endl;
	getline(is, ll);
	is >> p;
	cout << p << endl;
	is >> p;
	cout << p << endl;


	return 0;
}
