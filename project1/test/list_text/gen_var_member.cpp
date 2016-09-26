#ifndef __GEN_VAR_MEMBER__
#define __GEN_VAR_MEMBER__

#define NUM_FIRST_NAME		500
#define NUM_LAST_NAME		1000

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string*  generateRandomMemberId (int num) {
	srand(time(NULL));
	const char alphaNum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	string* idArr = new string [num];

	for (int i = 0; i < num; i++) {
		const int lenStr = rand() % 9 + 5,		// the max length of ID
			  lenAlphaNum = sizeof(alphaNum);
		char* genStr = new char[lenStr + 1];

		for (int i = 0; i < lenStr; ++i) {
			genStr[i] = alphaNum[rand() % lenAlphaNum];
		}
		genStr[lenStr] = '\0';

		idArr[i] = string(genStr);

		delete [] genStr;
	}

	return idArr;
};

string** generateRandomMemberName (int num) {
	ifstream maleFirstFile,
			 femaleFirstFile,
			 allLastFile;

	// file open
	maleFirstFile.open	("name_list/word_male_first.txt");
	femaleFirstFile.open("name_list/word_female_first.txt");
	allLastFile.open	("name_list/word_all_last.txt");

	// get first and last names.
	string firstName[2][NUM_FIRST_NAME];
	string lastName[NUM_LAST_NAME];

	for (int i = 0; i < NUM_FIRST_NAME; i++) {
		maleFirstFile >> firstName[0][i];
		femaleFirstFile >> firstName[1][i];
	}
	for (int i = 0; i < NUM_LAST_NAME; i++) {
		allLastFile >> lastName[i];
	}

	// generate random names.
	string** peopleName = new string*[num];
	for (int i = 0; i < num; i++) {
		peopleName[i] = new string[2]; // 0 : last name / 1 : first name
	}

	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		int firstNameNumber = rand() % (NUM_FIRST_NAME),
			lastNameNumber	= rand() % (NUM_LAST_NAME);

		peopleName[i][0] = firstName[i%2][firstNameNumber];
		peopleName[i][1] = lastName[lastNameNumber];
//		peopleName[i] = firstName[i%2][firstNameNumber] + " " + lastName[lastNameNumber];
	}


	return peopleName;
};

string* generateRandomPhoneNumber (int num) {
	string frontPhoneNumber[ ] = { "010", "010", "010", "010", "010", "011", "016", "017", "018", "019", "010" },
		   middlePhoneNumber[10000],
		   lastPhoneNumber[10000];

	char fourNumber[5] = {0,};

	for (int i = 0; i < 10000; i++) {
		sprintf(fourNumber, "%04d", i);
		middlePhoneNumber[i] = lastPhoneNumber[i] = string(fourNumber);
	}

	string* phoneNumbers = new string [num];

	srand(time(NULL));

	for (int i = 0; i < num; i++) {
		int frontNumber	= rand() % 11,
			middleNumber= rand() % 10000,
			lastNumber	= rand() % 10000;

		phoneNumbers[i] = frontPhoneNumber[frontNumber]
			+ "-" + middlePhoneNumber[middleNumber]
			+ "-" + lastPhoneNumber[lastNumber];
		cout << phoneNumbers[i] << endl;
	}

	return phoneNumbers;
}

string* generateRandomAddress() {
	const int NUM_CITY = 135;
	ifstream cityFile;
	cityFile.open("cityName.txt");

	string* addressList = new string[NUM_CITY];

	for (int i = 0; i < NUM_CITY; i++) {
		cityFile >> addressList[i];
	}

	return addressList;
}

string* generateRandomBirthday(int num) {
	srand(time(NULL));

	char birthday[9] = {0,};
	string* birthdayArr = new string [num];

	for (int i = 0; i < num; i++) {
		int year = rand() % 65 + 1950, month = rand()%12 + 1, day = 0;

		switch (month) {
			case 1: case 3: case 5:
			case 7: case 8: case 10:
			case 12:
				day = rand() % 31 + 1; break;
			case 2: 
				day = rand() % 28 + 1; break;
			case 4: case 6: case 9:
			case 11:
				day = rand() % 30 + 1; break;
		}

		sprintf(birthday, "%04d%02d%02d", year, month, day);
		birthdayArr[i] = string(birthday);

		cout << birthdayArr[i] << endl;
	}

	return birthdayArr;
}



#endif

/*
// test
int main() {
*/	/*
	   string * people = generateRandomMemberName(130);


	// Member :: ID

	for (int i = 0; i < 130; i++) {
	cout << people[i] << endl;
	}
	*/	

	// string* phone = generateRandomPhoneNumber(10);
	
//	string* arr = generateRandomBirthday(50);


/*
	return 0;
}
*/
