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

char*  generateRandomMemberID (void) {
	srand(time(NULL));
	const char alphaNum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const int lenStr = rand() % 9 + 5,		// the max length of ID
			lenAlphaNum = sizeof(alphaNum);
	char* genStr = new char[lenStr + 1];

	for (int i = 0; i < lenStr; ++i) genStr[i] = alphaNum[rand() % lenAlphaNum];
	genStr[lenStr] = '\0';

	return genStr;
};

string* generateRandomMemberName (int peopleNum) {
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
	string* peopleName = new string[peopleNum];

	srand(time(NULL));
	for (int i = 0; i < peopleNum; i++) {
		int firstNameNumber = rand() % (NUM_FIRST_NAME),
			lastNameNumber	= rand() % (NUM_LAST_NAME);
		
		peopleName[i] = firstName[i%2][firstNameNumber] + " " + lastName[lastNameNumber];
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

#endif


// test
int main() {
/*
	string * people = generateRandomMemberName(130);


	// Member :: ID

	for (int i = 0; i < 130; i++) {
		cout << people[i] << endl;
	}
*/	

	string* phone = generateRandomPhoneNumber(10);


//	delete [] people;

	return 0;
}
