#ifndef __SHOW_MEMBER__
#define __SHOW_MEMBER__

#include "../../src/classes/class_member.h"

void showMember () {
	Member me;
	ifstream is;
	int count;
	string ll;

	is.open("../../resources/listOfMember.txt");

	is >> count;
	getline(is, ll);
	for (int i = 0; i < 10 ; i++) {
		is >> me;
		cout << me << endl;
	}
};

#ifdef test_showMember
int main() {
	showMember();

	return 0;
}
#endif

#endif
