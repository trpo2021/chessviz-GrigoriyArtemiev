CXXFLAGS = -Wall -Werror -Wextra -I src -I thirdparty
CXX = g++

CHESSVIZ_SCR = src/chessviz/
LIBCHESSVIZ_SCR = src/libchessviz/

CHESSVIZ_OBJ = obj/src/chessviz/
LIBCHESSVIZ_OBJ = obj/src/libchessviz/
CHESSVIZ_BIN = bin/

.PHONY: chessviz

$(CHESSVIZ_BIN)chessviz.exe: $(CHESSVIZ_OBJ)main.o $(LIBCHESSVIZ_OBJ)libchessviz.a
	$(CXX) $(CXXFLAGS) -o $@ $^
$(LIBCHESSVIZ_OBJ)libchessviz.a: $(CHESSVIZ_OBJ)const.o $(LIBCHESSVIZ_OBJ)BoardPrint.o $(CHESSVIZ_OBJ)BoardRead.o $(LIBCHESSVIZ_OBJ)move.o $(CHESSVIZ_OBJ)colorcheck.o
	ar rcs $@ $^
$(CHESSVIZ_OBJ)const.o: $(CHESSVIZ_SCR)const.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)colorcheck.o: $(CHESSVIZ_SCR)colorcheck.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)main.o: $(CHESSVIZ_SCR)main.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(LIBCHESSVIZ_OBJ)BoardPrint.o: $(LIBCHESSVIZ_SCR)BoardPrint.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(LIBCHESSVIZ_OBJ)move.o: $(LIBCHESSVIZ_SCR)move.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<
$(CHESSVIZ_OBJ)BoardRead.o: $(CHESSVIZ_SCR)BoardRead.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

-include main.d BoardPrint.d move.d BoardRead.d const.d colorcheck.d

.PHONY: clean
clean:
	rm -rf $(CHESSVIZ_OBJ)*.o 
	rm -rf $(LIBCHESSVIZ_OBJ)*.o
	rm $(LIBCHESSVIZ_OBJ)*.a
	rm -rf $(CHESSVIZ_BIN)*.exe