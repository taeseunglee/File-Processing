#ifndef __GEN_VAR_MEMBER__
#define __GEN_VAR_MEMBER__

#include <cstdlib>
#include <cstdio>
#include <ctime>

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

char* generateRandomMemberName (void) {

	
};

#endif
