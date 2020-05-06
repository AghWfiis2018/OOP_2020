CXX = g++
EXEC = test
CXXFLAGS = -MMD -MP -Wall -pedantic $(flag) -std=c++14
LIBS = -lm

SRC=$(wildcard *.cpp)
OBJS=$(SRC:.cpp=.o)
DEPS=$(SRC:.cpp=.d)

$(EXEC): $(OBJS) 
	$(CXX) $+ $(LIBS) -o $@

error1: $(EXEC)
error1: flag=-DERROR1

error2: $(EXEC)
error2: flag=-DERROR2

.PHONY: clean

clean:
	rm -f *.o
	rm -f *.txt
	rm -f *.d
	rm -f $(EXEC)

-include $(DEPS)