# Generic makefile for VLP

CXX = g++
EXEC = test
CXXFLAGS = -MMD -MP -Wall -pedantic -std=c++14
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $+ $(LIBS) -o $@

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.txt
	rm -f *.d
	rm -f $(EXEC)

-include $(DEPS)