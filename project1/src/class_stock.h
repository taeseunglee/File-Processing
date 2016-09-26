#ifndef __CLASS_STOCK__
#define __CLASS_STOCK__

#include <string>

using namespace std;

class Stock {
	private:
		string	id;
		string	category;
		string	material;
		string	price;
		int		stock;
		string	washingInfo;
		string	size;

	public:
		// constructor
		Stock (const string& id, const string& category, const string& material, const string& price, const int& stock, const string& washingInfo, const string& size);

		// copy constructor
		Stock (const Stock& S);

		// operators (assignment, comparison)
		Stock&	operator = (const Stock &S);
		bool	operator ==(const Stock &S);
		bool	operator !=(const Stock &S);

		// make member functions that set member variables.
		void setId			(const string&	Id);
		void setCategory	(const string&	category);
		void setMaterial	(const string&	material);
		void setPrice		(const string&	price);
		void setStock		(const int&		stock);
		void setWashingInfo (const string&	washingInfo);
		void setSize		(const string&	size);
};

#endif
