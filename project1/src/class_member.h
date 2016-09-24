#ifndef __CLASS_MEMBER__
#define __CLASS_MEMBER__

#include <cstring>

using namespace std;

class Member {
	private:
		string	ID;
		string	name;
		string	phoneNumber;
		string	address;
		char	birthday[9];
		string	eMail;

	public:
		// copy constructor
		Member (string pID, string pName, string pPhoneNumber, string pAddress, char pBirthday[9], string pEMail);

		// operators (assignment, comparision)
		Member& operator = (const Member &M);
		bool operator ==(const Member &M);
		bool operator !=(const Member &M);

		// make member functions that set member variables.
		void setID (string ID);
		void setName (string name);
		void setPhoneNumber (string address);
		void setAddress (string address);
		void setBirthday (char birthday[9]);
		void setEmail (string eMail);
};

#endif
