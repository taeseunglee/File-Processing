#include <iostream>
#include "class_member.h"

using namespace std;

// an copy constructor of class "Member"
Member::Member(const string& id, const string& name, const string& phoneNumber, const string& address, const string& birthday, const string& email)
	: id(id), name(name), phoneNumber(phoneNumber), address(address), birthday(birthday), email(email) { }

// copy constructor
Member::Member(const Member& M) : id(M.id), name(M.name), phoneNumber(M.phoneNumber), address(M.address), birthday(M.birthday), email(M.email) { }

// an assignment operator
Member&  Member::operator = (const Member &M) {
   this->id				= M.id;
   this->name			= M.name;
   this->phoneNumber	= M.phoneNumber;
   this->address		= M.address;
   this->email			= M.email;
   this->birthday		= M.birthday;

   return *this;
}

bool Member::operator ==(const Member &M) {
	if (id == M.id) return true;
	else			return false;
}

bool Member::operator !=(const Member &M) {
	if (id != M.id) return true;
	else			return false;
}

void Member::setId			(const string& id)		{ this->id = id; }
void Member::setName		(const string& name)	{ this->name = name; }
void Member::setPhoneNumber (const string& address)	{ this->address = address; }
void Member::setAddress		(const string& address)	{ this->address = address; }
void Member::setBirthday	(const string& birthday){ this->birthday = birthday; }
void Member::setEmail		(const string& email)	{ this->email = email; }

void Member::print() {
	cout << "ID : " << id << endl;
	cout << "name : " << name << endl;
	cout << "phoneNumber : " << phoneNumber << endl;
	cout << "address : " << address << endl;
	cout << "email : " << email << endl;
	cout << "birthday : " << birthday << endl;
}

// test 
int main ()
{
	Member me("supernova", "Taeseung", "010-4455-5887", "Seoul", "19950320", "dlxotmd125@gmail.com")
		   , you("you", "Taeseung", "010-4455-5887", "Seoul", "19950320", "dlxotmd125@gmail.com")
		   , hello(me)
		   , nyang("SGsupernova", "Taeseung", "010-4455-5887", "Seoul", "19950320", "dlxotmd125@gmail.com");


	// test functions that set member variables.
	nyang.setId("nyang");
	nyang.setName("NamKyu");
	nyang.print();

	// comparison
	if (you != me) {
		cout << "I'm you!" << endl;
	}
	
	// test overloaded operator =
	you = me;
	if (you == me) {
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

