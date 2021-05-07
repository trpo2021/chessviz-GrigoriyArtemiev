CXXFLAGS = -Wall -Werror -Wextra -I src
CXX = g++

CHESSVIZ_SCR = src/chessviz/
LIBCHESSVIZ_SCR = src/libchessviz/

CHESSVIZ_OBJ = obj/src/chessviz/
LIBCHESSVIZ_OBJ = obj/src/libchessviz/
CHESSVIZ_BIN = bin/

TEST = test/
TEST_OBJ = obj/test/

.PHONY: chessviz

$(CHESSVIZ_BIN)chessviz.exe: $(CHESSVIZ_OBJ)main.o $(LIBCHESSVIZ_OBJ)libchessviz.a
	$(CXX) $(CXXFLAGS) -o $@ $^
$(LIBCHESSVIZ_OBJ)libchessviz.a: $(CHESSVIZ_OBJ)const.o $(LIBCHESSVIZ_OBJ)BoardPrint.o $(CHESSVIZ_OBJ)BoardRead.o $(LIBCHESSVIZ_OBJ)move.o $(CHESSVIZ_OBJ)colorcheck.o
	ar rcs $@ $^
$(CHESSVIZ_OBJ)const.o: $(CHESSVIZ_SCR)const.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)colorcheck.o: $(CHESSVIZ_SCR)colorcheck.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(LIBCHESSVIZ_OBJ)BoardPrint.o: $(LIBCHESSVIZ_SCR)BoardPrint.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)main.o: $(CHESSVIZ_SCR)main.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(LIBCHESSVIZ_OBJ)move.o: $(LIBCHESSVIZ_SCR)move.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)BoardRead.o: $(CHESSVIZ_SCR)BoardRead.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: test

test: $(CHESSVIZ_BIN)test.exe

$(CHESSVIZ_BIN)test.exe: $(TEST_OBJ)main.o $(TEST_OBJ)testlibchessviz.a
	$(CXX) $(CXXFLAGS) -o $@ $^
$(TEST_OBJ)main.o: $(TEST)main.cpp
	$(CXX) -c $(CXXFLAGS) -I thirdparty -o $@ $<
$(TEST_OBJ)testlibchessviz.a: $(TEST_OBJ)const.o $(TEST_OBJ)BoardPrint.o $(TEST_OBJ)BoardRead.o $(TEST_OBJ)move.o $(TEST_OBJ)colorcheck.o
	ar rcs $@ $^
$(TEST_OBJ)const.o: $(CHESSVIZ_SCR)const.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(TEST_OBJ)colorcheck.o: $(CHESSVIZ_SCR)colorcheck.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(TEST_OBJ)BoardPrint.o: $(LIBCHESSVIZ_SCR)BoardPrint.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(TEST_OBJ)move.o: $(LIBCHESSVIZ_SCR)move.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(TEST_OBJ)BoardRead.o: $(CHESSVIZ_SCR)BoardRead.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

-include main.d BoardPrint.d move.d BoardRead.d const.d colorcheck.d

.PHONY: clean-test

clean-test:
	rm $(TEST_OBJ)*.o
	rm $(TEST_OBJ)*.a
	rm $(CHESSVIZ_BIN)*.exe

.PHONY: clean

clean:
	rm $(CHESSVIZ_OBJ)*.o
	rm $(LIBCHESSVIZ_OBJ)*.o
	rm $(LIBCHESSVIZ_OBJ)*.a
	rm $(CHESSVIZ_BIN)*.exe