#ifndef __CLASS_MEMBER__
#define __CLASS_MEMBER__

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Member {
	private:
		string	id;
		string	name;
		string	phoneNumber;
		string	address;
		string	birthday;
		string	email;

	public:
		// defualt 
		Member (const string& id, const string& name, const string& phoneNumber, const string& address, const string& birthday, const string& email);
		// copy constructor
		Member (const Member& M);

		// operators (assignment, comparision)
		Member& operator = (const Member &M);
		bool	operator ==(const Member &M);
		bool	operator !=(const Member &M);

		// iostream operators
		friend istream& operator >> (istream& is, const Member& M);
		friend ostream& operator << (ostream& is, const Member& M);

		// make member functions that set member variables.
		void setId			(const string& id);
		void setName		(const string& name);
		void setPhoneNumber (const string& address);
		void setAddress		(const string& address);
		void setBirthday	(const string& birthday);
		void setEmail		(const string& email);
};


#endif
