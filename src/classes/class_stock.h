#ifndef __CLASS_STOCK__
#define __CLASS_STOCK__

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../../include/packing/delim.h"

using namespace std;

#define STK_MAX_BUF 256

class Stock {
	private:
		string	id;
		string	category;
		string	material;
		string	price;
		string	stock;
		string	washingInfo;
		string	size;

	public:
		Stock() {};
		// constructor
		Stock (const string& id, const string& category, const string& material, const string& price, const string& stock, const string& washingInfo, const string& size);

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
		void setStock		(const string&	stock);
		void setWashingInfo (const string&	washingInfo);
		void setSize		(const string&	size);
		
		string getId() const { return id; };

		// iostream operators
		friend istream& operator >> (istream& is, Stock& S);
		friend ostream& operator << (ostream& os, const Stock& S);

		bool Pack (IOBuffer & Buffer) const;
		bool Unpack (IOBuffer & Buffer);
};

#endif
