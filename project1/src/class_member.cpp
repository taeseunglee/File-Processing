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
void Member::setPhoneNumber (const string& phoneNumber)	{ this->phoneNumber = phoneNumber; }
void Member::setAddress		(const string& address)	{ this->address = address; }
void Member::setBirthday	(const string& birthday){ this->birthday = birthday; }
void Member::setEmail		(const string& email)	{ this->email = email; }

istream& operator >> (istream& is, Member& M) {
	string str;
	
	is.exceptions(istream::failbit | istream::badbit);

	try {
		getline (is, str);
	} catch (istream::failure e) {
		return is;
	}

	istringstream iss (str);
	string token;


	getline (iss, token, '|');
	M.setId (token);

	getline (iss, token, '|');
	M.setName (token);

	getline (iss, token, '|');
	M.setPhoneNumber (token);

	getline (iss, token, '|');
	M.setAddress (token);

	getline (iss, token, '|');
	M.setEmail (token);

	getline (iss, token, '|');
	M.setBirthday (token);
	
	return is;
}

ostream& operator << (ostream& os, const Member& M) {
	os << "Member(ID, Name, Phone Number, Address, Birthday, E-mail) : " << "(" << M.id;
	os << ", " << M.name;
	os << ", " << M.phoneNumber;
	os << ", " << M.address;
	os << ", " << M.email;
	os << ", " << M.birthday;
	os << ")";

	return os;
}

int main() {
	Member me("supernova", "Taeseung", "010-4455-5887", "Seoul", "19950320", "dlxotmd125@gmail.com");
	ifstream is;
	int count;
	string ll;

	is.open("../data/listOfMember.txt");

	is >> count;
	cout << count << endl;
	getline(is, ll);
	is >> me;
	cout << me << endl;
	is >> me;
	cout << me << endl;
}
