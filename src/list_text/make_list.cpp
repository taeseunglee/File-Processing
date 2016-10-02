#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "stockmaker.cpp"
#include "gen_var_member.cpp"

#define NUM_OF_MEMBERS		1300
#define NUM_OF_STOCKS		1400
#define NUM_OF_PURCHASES	12500

#define FILENAME_MEMBER		"listOfMember.txt"
#define FILENAME_STOCK		"listOfStock.txt"
#define FILENAME_PURCHASE	"listOfPurchase.txt"

string* makeListMember();
void makeListPurchase(string* memberIdList,string* stockIdList);

int main () {
	int listCase = 0;

	string* memberIdList = makeListMember()
		,* stockIdList = makeListStock();

	makeListPurchase(memberIdList, stockIdList);


	delete [] memberIdList;
	delete [] stockIdList;

	return 0;
}

string* makeListMember() {
	FILE* fpMember = fopen("listOfMember.txt", "w");

	if ((fpMember = fopen(FILENAME_MEMBER, "w")) == NULL) {
		fprintf(stderr, "An error occurs during making a text file - listOfMembers");
	}

	printf("Make a listofMembers\n");

	fprintf(fpMember, "%d\n", NUM_OF_MEMBERS);

	string* idList		= generateRandomMemberId(NUM_OF_MEMBERS)
		,** nameList	= generateRandomMemberName(NUM_OF_MEMBERS)
		,* phoneList	= generateRandomPhoneNumber(NUM_OF_MEMBERS)
		,* addressList	= generateRandomAddress()
		,* birthdayList	= generateRandomBirthday(NUM_OF_MEMBERS);

	for (int i = 0; i < NUM_OF_MEMBERS; i++) {
		string fullName = nameList[i][0]+ " " + nameList[i][1],
			   fullEmail = nameList[i][0] + "@sogang.ac.kr";

		fprintf(fpMember, "%s|%s|%s|%s|%s|%s\n"
				,idList[i].c_str()							// ID
				,fullName.c_str()							// Name
				,phoneList[i].c_str()						// Phone Number
				,addressList[i%NUM_CITY].c_str()						// Address
				,birthdayList[i].c_str()					// Birthday
				,fullEmail.c_str()							// E-mail
				);
	}
	
	delete [] phoneList;
	delete [] addressList;
	delete [] birthdayList;

	fclose(fpMember);
	return idList;
}


void makeListPurchase(string* memberIdList,string* stockIdList) {
	FILE* fp = fopen("listOfPurchase.txt", "w");

	srand(time(NULL));
	for (int i = 0; i < NUM_OF_PURCHASES; i++) {
		long long int purchaseId = rand() % 100000000;
		int quantity = rand() % 100;
		
		fprintf(fp, "%016lld|%s|%s|%02d\n",
				purchaseId
				, stockIdList[i%NUM_OF_STOCKS].c_str()
				, memberIdList[i%NUM_OF_MEMBERS].c_str()
				, quantity);
	}

	fclose(fp);

}
