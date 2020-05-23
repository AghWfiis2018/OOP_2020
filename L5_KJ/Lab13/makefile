# Generic makefile for VLP

#MY_ERROR_FLAGS

CXX = g++
EXEC = test.exe
CXXFLAGS = -MMD -MP -Wall -pedantic -std=c++14 $(MY_ERROR_FLAGS)
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $+ $(LIBS) $(MY_ERROR_FLAGS) -o $@ 

.PHONY: run valgrind clean

run: $(EXEC)
	./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)

clean:
	rm -f *.o
	rm -f *.txt
	rm -f *.d
	rm -f $(EXEC)

-include $(DEPS)
