BIN := chess

SRCS = $(shell find src -name *.cpp)

CXX := g++

CXXFLAGS := -std=c++1z -Wconversion -Wall -Wextra -pedantic -DNDEBUG -O3

DEBUG := -std=c++1z -Wconversion -Wall -Wextra -pedantic -DDEBUG -g3

all: $(BIN) debug

$(BIN): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

debug: $(SRCS)
	$(CXX) $(DEBUG) $^ -o $(BIN)_$@

.PHONY: clean all
clean:
	rm -rvf *.out *.exe chess *_debug