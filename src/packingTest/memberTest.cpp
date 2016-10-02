#ifndef __MEMBER_TEST__
#define __MEMBER_TEST__

#include "../classes/class_member.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

void memberTest () {
	ifstream ifs ("../resources/listOfMember.txt");
	char filename[ ] = "fileOfMember.dat";

	int n;
	ifs >> n;
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Member> memberFile (buffer);

	// Write test
	memberFile.Create (filename, ios::out | ios::trunc);
	for (int i = 0; i < n; i++) {
		Member m;
		ifs >> m;
		
		int recAddr;
		if ((recAddr = memberFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
		else { cout << "Write at " << recAddr << endl; }
	}
	memberFile.Close ();


	// Read Test
	memberFile.Open (filename, ios::in);
	for (int i = 0; i < n; i++) {
		Member m;
		memberFile.Read(m);
		cout << m;
	}
	memberFile.Close();
};

#ifdef test_memberTest
int main() {
	memberTest();

	return 0;
}
#endif

#endif
