#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

#define NUM_OF_MEMBERS		1300
#define NUM_OF_STOCKS		1400
#define NUM_OF_PURCHASES	12500

#define FILENAME_MEMBER		"listOfMember.txt"
#define FILENAME_STOCK		"listOfStock.txt"
#define FILENAME_PURCHASE	"listOfPurchase.txt"

void makeListMember();
void makeListStock();
void makeListPurchase();
void generateRandomString()

int main () {
	int listCase = 0;

	printf("");
	scanf("%d", &listCase);
	
	switch (listCase) {
		case 1: makeListMember()
	}

	return 0;
}

void makeListMember() {
	FILE* fpList = NULL;

	if ((fpList = fopen(FILENAME_MEMBER, "w")) == NULL) {
		fprintf(stderr, "An error occurs during making a text file - listOfMembers");
	}

	printf("Make a listofMembers");

	fprintf(fpList, "%d\n", NUM_OF_MEMBERS);

	for (int i = 0; i < NUM_OF_MEMBERS; i++) {
		int lenID = (rand() % 4) + 5;

		

		fprintf(fpMember, "%s|%s|%s|%s|%8d|%s\n"
				,							// ID
				,							// Name
				,							// Phone Number
				,							// Address
				,							// Birthday
				,							// E-mail
				);
	}

	fclose(fpList);
}

void makeListStock() {
	printf("Make a list of Stocks");


}

void makeListPurchase() {
	printf("Make a list of Purchases");


}


