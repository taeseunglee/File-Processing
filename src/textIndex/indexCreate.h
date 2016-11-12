#ifndef __INDEX_CREATE__
#define __INDEX_CREATE__
#include "../classes/class_member.h"
#include "../classes/class_stock.h"
#include "../classes/class_purchase.h"

#ifndef __INDEX__
#define __INDEX__
#include "../../include/packing/recfile.h"
#include "../../include/index/textind.h"
#include "../../include/index/tindbuff.h"
#include "../../include/index/indfile.h"
#endif

#define LEN_ID 20

void createMemberTextIndex (Environment& env) {
	int size = env.memberSize;
	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Member> memberFile(buffer);
	TextIndex memberIndex (size);
	Member m;

	char datFilename[] = "../built/fileOfMember.dat";
	memberFile.Open (datFilename, ios::in);
	int recAddr;
	while (1) {
		if ((recAddr = memberFile.Read(m)) == -1)
			break;
		char *key = m.Key();
		memberIndex . Insert (key, recAddr); // add index
	}
	memberFile.Close();

	TextIndexBuffer idxbuf (LEN_ID, size);
	BufferFile memberIdxFile (idxbuf);

	char indFilename[] = "../built/fileOfMember.ind";
	memberIdxFile . Create (indFilename, ios::out | ios::trunc);
	memberIdxFile . Rewind();
	idxbuf . Pack (memberIndex);
	int result = memberIdxFile . Write();
	memberIdxFile . Close();
}

void createStockTextIndex (Environment& env) {
	int size = env.stockSize;
	DelimFieldBuffer buffer ('|', MEM_MAX_BUF);
	RecordFile <Stock> stockFile(buffer);
	TextIndex stockIndex (size);
	Stock s;

	char datFilename[] = "../built/fileOfStock.dat";
	stockFile.Open (datFilename, ios::in);
	int recAddr;
	while (1) {
		if ((recAddr = stockFile.Read(s)) == -1)
			break;
		char *key = s.Key();
		stockIndex . Insert (key, recAddr); // add index
	}
	stockFile.Close();

	TextIndexBuffer idxbuf (LEN_ID, size);
	BufferFile stockIdxFile (idxbuf);

	char indFilename[] = "../built/fileOfStock.ind";
	stockIdxFile . Create (indFilename, ios::out | ios::trunc);
	stockIdxFile . Rewind();
	idxbuf . Pack (stockIndex);
	int result = stockIdxFile . Write();
	stockIdxFile . Close();
}


#endif
