#ifndef __CLASS_STOCK__
#define __CLASS_STOCK__

#include <cstring>

using namespace std;

class Stock {
	private:
		char			ID[13];
		char			category[9];
		string			material;
		char			price[7];
		int				stock;
		string			washingInfo;
		char			size[3];

	public:
		// copy constructor
		Stock (char _ID[13], char _category[9], string _material, char _price[7], int _stock, string _washingInfo, char _size[3]);

		// operators (assignment, comparison)
		Stock& operator = (const Stock &S);
		bool operator ==(const Stock &S);
		bool operator !=(const Stock &S);

		// make member functions that set member variables.
		void setID (char ID[13]);
		void setCategory (char category[9]);
		void setMaterial (string material);
		void setPrice (char price[7]);
		void setStock (int stock);
		void setWashingInfo (string washingInfo);
		void setSize (char size[3]);
};

#endif
