#ifndef __CLASS_PURCHASE__
#define __CLASS_PURCHASE__

#include <cstring>

using namespace std;

class Purchase {
	long long int	purchaseID;
	long long int	stockID;
	string			memberID;
	int				quantity;
	public:
		// copy constructor
		Purchase(long long int purchaseID, long long int stockID, string memberID, int quantity);

		// operators (assignment, comparison)
		Purchase& operator = (const Purchase &P);
		bool operator == (const Purchase &P);
		bool operator != (const Purchase &P);

		// make member functions that set member variables.
		void setPurchaseID (long long int purchaseID);
		void setStockID (long long int stockID);
		void setMemberID (string memberID);
		void setQuantity (int quantity);
};

#endif
