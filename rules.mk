BUILT_DIR = $(SRC_DIR)/built
OBJS_DIR = $(BUILT_DIR)/objs
GPPFLAG = -std=c++11

.PHONY: clean
clean:
	@rm -rf $(BUILT_DIR)
	@echo "Cleaned."

$(addsuffix .o, $(TARGET)): %.o: .mkdir.o
	g++ $(GPPFLAG) -c $(basename $@).cpp -o $(OBJS_DIR)/$(PART_NAME)/$(basename $@).o

.PHONY: .mkdir.o
.mkdir.o:
	@mkdir -p $(OBJS_DIR)/$(PART_NAME)
