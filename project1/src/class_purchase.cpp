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


int main () {

	return 0;
}
