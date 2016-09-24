#include <iostream>
#include <cstring>
#include <string.h>
#include "class_member.h"

using namespace std;

// an copy constructor of class "Member"
Member::Member(string pID, string pName, string pPhoneNumber, string pAddress, char pBirthday[9], string pEMail)
{
	ID			= pID;
	name		= pName;
	phoneNumber = pPhoneNumber;
	address		= pAddress;
	strcpy(birthday, pBirthday);
	eMail		= pEMail;
}

// an assignment operator
Member&  Member::operator = (const Member &M) {
   ID			= M.ID;
   name			= M.name;
   phoneNumber	= M.phoneNumber;
   address		= M.address;
   eMail		= M.eMail;
   strcpy(birthday, M.birthday);

   return *this;
}

bool Member::operator ==(const Member &M) {
	if (ID == M.ID) return true;
	else			return false;
}

bool Member::operator !=(const Member &M) {
	if (ID != M.ID) return true;
	else			return false;
}

void Member::setID (string ID) {
	this->ID = ID;
}
void Member::setName (string name) {
	this->name = name;
}

void Member::setPhoneNumber (string address) {
	this->address = address;
}

void Member::setAddress (string address) {
	this->address = address;
}

void Member::setBirthday (char birthday[9]) {
	strcpy(this->birthday, birthday);
}

void Member::setEmail (string eMail) {
	this->eMail = eMail;
}

// testing main function
int main ()
{
	char birthday[9] = "19950320";
	Member me("supernova", "Taeseung", "010-4455-5887", "Seoul", birthday, "dlxotmd125@gmail.com")
		   , you("you", "Taeseung", "010-4455-5887", "Seoul", birthday, "dlxotmd125@gmail.com")
		   , hello(me)
		   , nyang("SGsupernova", "Taeseung", "010-4455-5887", "Seoul", birthday, "dlxotmd125@gmail.com");


	// test overloaded operator =
	you = me;
	
	if (you == me) {
		cout << "I'm you!" << endl;
	}
	if (you != me) {
		cout << "I'm not you" << endl;
	}

	if (hello == me) {
		cout << "hello!" << endl;
	}
	if (nyang != me) {
		cout << "I'm not nyang" << endl;
	}
	return 0;
}

