#include "class_purchase.h"

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
void Purchase::setQuantity	(const string& quantity)		{ this->quantity = quantity; }

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
	P.setQuantity (token);
	
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

bool Purchase::Pack (IOBuffer & Buffer) const {
	int numBytes;

	Buffer.Clear ();

	numBytes = Buffer.Pack (purchaseId.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (stockId.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (memberId.c_str());
	if (numBytes == -1) return false;

	numBytes = Buffer.Pack (quantity.c_str());
	if (numBytes == -1) return false;

	return true;
}

bool Purchase::Unpack (IOBuffer & Buffer) {
	int numBytes;
	char buf[PUR_MAX_BUF];

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	purchaseId = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	stockId = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	memberId = buf;

	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	quantity = buf;

	return true;
}
