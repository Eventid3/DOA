CXX=g++
CXXFLAGS=-g -std=c++17
LDFLAGS=-g -std=c++17

BIN = main
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEP)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	-rm test  $(OBJ) $(DEP)

