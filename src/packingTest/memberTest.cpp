#ifndef __MEMBER_TEST__
#define __MEMBER_TEST__

#include "../classes/class_member.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>

// If you want to execute memberTest, call memberTest(), that is, you stop doing parameter passing.
// If you just want to make .dat file from .txt, call memberTest(arg) and this argument must not be 10. I recomend call memberTest(-1);
void memberTest (int flag = 10) {
	ifstream ifs ("../resources/listOfMember.txt");
	char filename[ ] = "../built/fileOfMember.dat";

	int n = 0;

	if (flag != 10) { ifs >> n; }
	else			{ n = 10; }
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
		else if (flag == 10) { cout << "Write at " << recAddr << endl; }
	}
	memberFile.Close ();


	if (flag == 10) {
		// Read Test
		memberFile.Open (filename, ios::in);
		for (int i = 0; i < n; i++) {
			Member m;
			memberFile.Read(m);
			cout << m;
		}
		memberFile.Close();
	}
};

#ifdef test_memberTest
int main() {
	memberTest();

	return 0;
}
#endif

#endif
