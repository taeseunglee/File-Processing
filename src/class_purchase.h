#ifndef __CLASS_PURCHASE__
#define __CLASS_PURCHASE__

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Purchase {
	string	purchaseId;
	string	stockId;
	string	memberId;
	int		quantity;

	public:
		Purchase () {};
		// copy constructor
		Purchase (const Purchase& P);

		// operators (assignment, comparison)
		Purchase& operator = (const Purchase& P);
		bool operator == (const Purchase &P);
		bool operator != (const Purchase &P);

		// make member functions that set member variables.
		void setPurchaseId	(const string& purchaseID);
		void setStockId		(const string& stockID);
		void setMemberId	(const string& memberID);
		void setQuantity	(const int& quantity);

		friend istream& operator >> (istream& is, Purchase& P);
		friend ostream& operator << (ostream& os, const Purchase& P);
};

#endif
