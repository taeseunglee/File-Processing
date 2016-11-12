#ifndef __INDEX_SEARCH__
#define __INDEX_SEARCH__
#include "../classes/class_member.h"
#include "../classes/class_stock.h"
#include "../classes/class_purchase.h"

#include "../../include/packing/recfile.h"
#include "../../include/index/textind.h"
#include "../../include/index/tindbuff.h"
#include "../../include/index/indfile.h"

#define LEN_ID 20

void searchMemberTextIndex (Environment& env, string id) {
	DelimFieldBuffer buf ('|', MEM_MAX_BUF);
	TextIndexedFile <Member> memIndexedFile (buf, LEN_ID, env.memberSize);
	char filename[] = "../built/fileOfMember";
	memIndexedFile.Open (filename);

	Member m;
	
	int ref = memIndexedFile.Read((char*)id.c_str(), m);
	if (ref == -1) {
		cout << "Member not Found" << endl;
	}
	else {
		cout << "Member Found" << endl << m << endl;
	}
	memIndexedFile.Close();
}

void searchStockTextIndex (Environment& env, string id) {
	DelimFieldBuffer buf ('|', STK_MAX_BUF);
	TextIndexedFile <Stock> stkIndexedFile (buf, LEN_ID, env.stockSize);
	char filename[] = "../built/fileOfStock";
	stkIndexedFile.Open (filename);

	Stock s;
	
	int ref = stkIndexedFile.Read((char*)id.c_str(), s);
	if (ref == -1) {
		cout << "Stock not Found" << endl;
	}
	else {
		cout << "Stock Found" << endl << s << endl;
	}

	stkIndexedFile.Close();
}

#endif
