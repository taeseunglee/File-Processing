#ifndef __ENVIRONMENT__
#define __ENVIRONMENT__

#include "./classes/class_member.h"
#include "./classes/class_stock.h"
#include "./classes/class_purchase.h"
#include <vector>
#include <map>

#define FINDINDATA (classData, id, findFlag)		\
	do{												\
		if(classData.find(id) == classData.end()) {	\
			findFlag = true;						\
		} else { findFlag = false; }				\
	} while(0);

// key		: Main Id
// value	: record address
typedef struct Environment {
	std::map <string, int> memberData;
	std::map <string, int> stockData;
	std::map <string, int> purchaseData;
} Environment;

#endif
