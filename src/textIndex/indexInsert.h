#ifndef __INDEX_INSERT__
#define __INDEX_INSERT__
#include "../classes/class_member.h"
#include "../classes/class_stock.h"
#include "../classes/class_purchase.h"

#include "../../include/packing/recfile.h"
#include "../../include/index/textind.h"
#include "../../include/index/tindbuff.h"
#include "../../include/index/indfile.h"

#define LEN_ID 20

void insertMemberTextIndex (Environment& env) {
	DelimFieldBuffer buf ('|', MEM_MAX_BUF);
	(env.memberSize)++;
	TextIndexedFile <Member> memIndexedFile (buf, LEN_ID, env.memberSize);
	char filename[] = "../built/fileOfMember";
	memIndexedFile.Open (filename);

	Member newMember;
	bool isIntegrity = getNewClass(env, newMember);

	if (!isIntegrity) {
		cout << "You cannot Insert this information" << endl;
	}
	else {
		Member m;
		string admin = "admin";
//		memIndexedFile.Read((char*)admin.c_str(), m);
//		cout << admin << endl << m << endl;

//		env.memberSize++;
		int ref = memIndexedFile.Append(newMember);

		/*
		RecordFile<Member> DataFile(buf);
		char datfilename[] = "../built/fileOfMember.dat";
		DataFile.Open(datfilename, ios::in | ios::out);
		int recAddr = DataFile.Append(newMember);
		DataFile.Close();
		cout << "recAddr1 : " << recAddr << endl;
		
		TextIndex memberIndex (env.memberSize);
		recAddr = memberIndex.Insert(newMember.Key(), recAddr);
		cout << "recAddr2 : " << recAddr << endl;

		TextIndexBuffer idxbuf (LEN_ID, env.memberSize);
		BufferFile memIdxFile (idxbuf);
		memIdxFile.Create("../built/fileOfMember.ind", ios::out | ios::trunc);
		memIdxFile.Rewind();
		idxbuf.Pack(memberIndex);
		recAddr = memIdxFile.Write();
		memIdxFile.Close();
		cout << recAddr << endl;
		*/
//		cout << "[Debug] ref : " << ref << endl;
		memIndexedFile.Read(newMember.Key(), m);
		cout << "read : " << m << endl;	
	}
	memIndexedFile.Close();
}

void insertStockTextIndex (Environment& env) {
	DelimFieldBuffer buf ('|', STK_MAX_BUF);
	TextIndexedFile <Stock> stkIndexedFile (buf, LEN_ID, env.stockSize + 1);
	char filename[] = "../built/fileOfStock";
	stkIndexedFile.Open (filename);

	Stock newStock;
	bool isIntegrity = getNewClass(env, newStock);

	if (!isIntegrity) {
		cout << "You cannot Insert this information since informations are not matching." << endl;
	}
	else {
		stkIndexedFile.Append(newStock);
		env.stockSize++;
	}
	stkIndexedFile.Close();
}

#endif
