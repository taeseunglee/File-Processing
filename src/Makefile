SRC_DIR = ..

PACKING_DIR = ../include/packing
INDEX_DIR = ../include/index

CLASS_DIR = classes
SHOW_DIR = showClass
TEST_DIR = packingTest
PART_NAME = onlineShoppingSystem
TARGET = onlineShoppingSystem

build: build.packing build.index build.class .mkdir.o
	g++ $(GPPFLAG) -c $(TARGET).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(TARGET).o
	g++ $(GPPFLAG) -o $(BUILT_DIR)/$(TARGET) $(OBJS_DIR)/**/*.o


.PHONY: build.packing
build.packing:
	make -C $(PACKING_DIR)

.PHONY: build.index
build.index:
	make -C $(INDEX_DIR)

.PHONY: build.class
build.class:
	make -C $(CLASS_DIR)

.PHONY: build.show
build.show:
	make -C $(SHOW_DIR)

.PHONY: build.test
build.test:
	make -C $(TEST_DIR)

include $(SRC_DIR)/rules.mk
