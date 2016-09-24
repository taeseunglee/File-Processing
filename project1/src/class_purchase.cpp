#include <iostream>
#include <cstring>
#include "class_purchase.h"

using namespace std;

Purchase::Purchase (long long int _purchaseID, long long int _stockID, string _memberID, int _quantity) {
	purchaseID	= _purchaseID;
	stockID		= _stockID;
	memberID	= _memberID;
	quantity	= _quantity;
}

Purchase& Purchase::operator = (const Purchase &P) {
	purchaseID	= P.purchaseID;
	stockID		= P.stockID;
	memberID	= P.memberID;
	quantity	= P.quantity;

	return *this;
}

bool Purchase::operator == (const Purchase &P) {
	if (purchaseID == P.purchaseID) return true;
	else							return false;
}

bool Purchase::operator != (const Purchase &P) {
	if (purchaseID != P.purchaseID) return true;
	else							return false;
}

void Purchase::setPurchaseID(long long int purchaseID) {
	this->purchaseID = purchaseID;
}

void Purchase::setStockID (long long int stockID) {
	this->stockID = stockID;
}

void Purchase::setMemberID (string memberID) {
	this->memberID = memberID;
}

void Purchase::setQuantity (int quantity) {
	this->quantity = quantity;
}

int main () {

	return 0;
}
