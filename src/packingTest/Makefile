SRC_DIR = ../..
PACKING_DIR = ../../include/packing
CLASS_DIR = ../classes
TARGET = memberTest stockTest purchaseTest
PART_NAME = classTest


TEST_MEMBER = memberTest
TEST_STOCK = stockTest
TEST_PURCHASE = purchaseTest

build: $(addsuffix .o, $(TARGET))

$(TEST_MEMBER): build.packing build.class .mkdir.o
	g++ $(GPPFLAG) -c $(TEST_MEMBER).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(TEST_MEMBER).o -D test_$(TEST_MEMBER)
	g++ $(GPPFLAG) -o $(BUILT_DIR)/$(TEST_MEMBER) $(OBJS_DIR)/packing/*.o $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(TEST_MEMBER).o


$(TEST_STOCK): build.packing build.class .mkdir.o
	g++ $(GPPFLAG) -c $(TEST_STOCK).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(TEST_STOCK).o -D test_$(TEST_STOCK)
	g++ $(GPPFLAG) -o $(BUILT_DIR)/$(TEST_STOCK) $(OBJS_DIR)/packing/*.o $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(TEST_STOCK).o


$(TEST_PURCHASE): build.packing build.class .mkdir.o
	g++ $(GPPFLAG) -c $(TEST_PURCHASE).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(TEST_PURCHASE).o -D test_$(TEST_PURCHASE)
	g++ $(GPPFLAG) -o $(BUILT_DIR)/$(TEST_PURCHASE) $(OBJS_DIR)/packing/*.o $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(TEST_PURCHASE).o



.PHONY: build.packing
build.packing:
	make -C $(PACKING_DIR)

.PHONY: build.class
build.class:
	make -C $(CLASS_DIR)

include $(SRC_DIR)/rules.mk
