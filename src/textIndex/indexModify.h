#ifndef __INDEX_MODIFY__
#define __INDEX_MODIFY__
#include "../classes/class_member.h"
#include "../classes/class_stock.h"
#include "../classes/class_purchase.h"

#include "../../include/packing/recfile.h"
#include "../../include/index/textind.h"
#include "../../include/index/tindbuff.h"
#include "../../include/index/indfile.h"

#define LEN_ID 20

void modifyMemberTextIndex (Environment& env, Member newMember) {
	DelimFieldBuffer buf ('|', MEM_MAX_BUF);
	TextIndexedFile <Member> memIndexedFile (buf, LEN_ID, env.memberSize);
	char filename[] = "../built/fileOfMember";
	memIndexedFile.Open (filename);

	int dRef = memIndexedFile.Update(newMember.Key(), newMember);

	if (dRef == -1)
		cout << "Memeber Deletion Error" << endl;
	else
		cout << "Member Deleted" << endl;
	memIndexedFile.Close();
}

void modifyStockTextIndex (Environment& env, Stock newStock) {
	DelimFieldBuffer buf ('|', STK_MAX_BUF);
	TextIndexedFile <Stock> stkIndexedFile (buf, LEN_ID, env.stockSize);
	char filename[] = "../built/fileOfStock";
	stkIndexedFile.Open (filename);
	
	int dRef = stkIndexedFile.Update(newStock.Key(), newStock);

	if (dRef == -1)
		cout << "Stock Deletion Error" << endl;
	else
		cout << "Stock Deleted" << endl;

	stkIndexedFile.Close();
}

#endif
