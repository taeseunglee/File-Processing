#include <iostream>
#include <string>


using namespace std;

class Member {
	string	ID;
	string	name;
	string	phoneNumber;
	string	address;
	char	birthday[8];
	string	eMail;
	
	public:
		Member();
};

Member::Member(void)
{
	cout << "Object is being created" << endl;
}

int main ()
{
	Member student;

	return 0;
}
