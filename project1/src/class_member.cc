#include <iostream>
#include <string>
#include <string.h>

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
		Member () {};
		Member (string pID, string pName, string pPhoneNumber, string pAddress, char pBirthday[8], string pEMail);
		void operator = (const Member &M);
		bool operator ==(const Member &M);
		bool operator !=(const Member &M);
		void print();
};

// the constructor of class "Member"
Member::Member(string pID, string pName, string pPhoneNumber, string pAddress, char pBirthday[8], string pEMail)
{
	ID			= pID;
	name		= pName;
	phoneNumber = pPhoneNumber;
	address		= pAddress;
	strcpy(birthday, pBirthday);
	eMail		= pEMail;
}
void Member::operator= (const Member &M) {
   ID			= M.ID;
   name			= M.name;
   phoneNumber	= M.phoneNumber;
   address		= M.address;
   eMail		= M.eMail;
   strcpy(birthday, M.birthday);
}

bool operator ==(const Member &M) {
	if (ID == M.ID) return true;
	else			return false;
}

bool operator !=(const Member &M) {
	if (ID != M.ID) return true;
	else			return false;
}

// test member variable
void Member::print() {
	cout  << ID << endl;
}


// testing main function
int main ()
{
	char birthday[9] = "19950320";
	Member me("supernova", "Taeseung", "010-4455-5887", "Seoul", birthday, "dlxotmd125@gmail.com"), you;

	// test overloaded operator =
	you = me;
	you.print();
	
	if (you == me) {
		cout << "I'm you!" << endl;
	}
	if (you != me) {
		cout << "I'm not you" << endl;
	}
	return 0;
}
