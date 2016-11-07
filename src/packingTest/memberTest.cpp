#ifndef __MEMBER_TEST__
#define __MEMBER_TEST__

#include "../classes/class_member.h"
#include "../../include/packing/recfile.h"
#include <fstream>
#include <vector>
#include "../environment.h"

// If you want to execute memberTest, call memberTest(), that is, you stop doing parameter passing.
// If you just want to make .dat file from .txt, call memberTest(arg) and this argument must be negative. I recomend call memberTest(-1);
void memberTest (Environment &env, int flag = 10) {
	char filename[ ] = "../built/fileOfMember.dat";
	ifstream ifs ("../resources/listOfMember.txt");
	if (ifs.fail()) {
		cout << "\"listOfMember.txt\" File open error!" << endl;
		exit(1);
	}


	int n = 0;
	ifs >> n;
	ifs.ignore (numeric_limits<streamsize>::max(), '\n');

	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Member> memberFile (buffer);

	// Write
	if (flag < 0)
	{
		memberFile.Create (filename, ios::out | ios::trunc);
		for (int i = 0; i < n; i++) {
			Member m;
			ifs >> m;

			int recAddr;
			if ((recAddr = memberFile.Write(m)) == -1) { cout << "Write Error!" << endl; }
			else {
				if (i < flag) { 
					cout << "Write at " << recAddr << endl; 
				}
				else {
					env.memberData[m.getId()] = recAddr;
				}
			}
		}
		memberFile.Close ();
	}

	if (!(flag < 0)) {
		// Read Test
		memberFile.Open (filename, ios::in);
		for (int i = 0; i < n; i++) {
			Member m;
			memberFile.Read(m);
			cout << m << endl;
		}
		memberFile.Close();
	}
};

#ifdef test_memberTest
int main() {
	Environment env;
	memberTest(env);

	return 0;
}
#endif

#endif
