#ifndef __CLASS_PURCHASE__
#define __CLASS_PURCHASE__

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../../include/packing/delim.h"


using namespace std;

#define PUR_MAX_BUF 256

class Purchase {
	string	purchaseId;
	string	stockId;
	string	memberId;
	string	quantity;

	public:
		Purchase () {};
		// copy constructor
		Purchase (const Purchase& P);

		// operators (assignment, comparison)
		Purchase& operator = (const Purchase& P);
		bool operator == (const Purchase &P);
		bool operator != (const Purchase &P);

		// make member functions that set member variables.
		void setPurchaseId	(const string& purchaseID); // Purchase id
		void setStockId		(const string& stockID);
		void setMemberId	(const string& memberID);
		void setQuantity	(const string& quantity);
		
		string getId()			const { return purchaseId; };
		string getStockId()		const { return stockId; };
		string getMemberId()	const { return memberId; };

		friend istream& operator >> (istream& is, Purchase& P);
		friend ostream& operator << (ostream& os, const Purchase& P);
		
		bool Pack (IOBuffer & Buffer) const;
		bool Unpack (IOBuffer & Buffer);
};

#endif
