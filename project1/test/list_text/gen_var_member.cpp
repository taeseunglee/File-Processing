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

#endif

int main() {
	string * people = generateRandomMemberName(130);


	for (int i = 0; i < 130; i++) {
		cout << people[i] << endl;
	}
	
	delete [] people;

	return 0;
}
