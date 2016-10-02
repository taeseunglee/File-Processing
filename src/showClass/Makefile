SRC_DIR = ../..
CLASS_DIR = ../classes
PART_NAME = showClass
TARGET = showMember showStock showPurchase


SHOW_MEMBER = showMember
SHOW_STOCK = showStock
SHOW_PURCHASE = showPurchase

build: $(addsuffix .o, $(TARGET))

$(SHOW_MEMBER): build.class .mkdir.o
	g++ -c $(SHOW_MEMBER).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_MEMBER).o -D test_$(SHOW_MEMBER)
	g++ -o $(BUILT_DIR)/$(SHOW_MEMBER) $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_MEMBER).o 

$(SHOW_STOCK): build.class .mkdir.o
	g++ -c $(SHOW_STOCK).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_STOCK).o -D test_$(SHOW_STOCK)
	g++ -o $(BUILT_DIR)/$(SHOW_STOCK)  $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_STOCK).o


$(SHOW_PURCHASE): build.class .mkdir.o
	g++ -c $(SHOW_PURCHASE).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_PURCHASE).o -D test_$(SHOW_PURCHASE)
	g++ -o $(BUILT_DIR)/$(SHOW_PURCHASE) $(OBJS_DIR)/classes/*.o $(OBJS_DIR)/$(PART_NAME)/$(SHOW_PURCHASE).o


.PHONY: build.class
build.class:
	make -C $(CLASS_DIR)

include $(SRC_DIR)/rules.mk
