CXX=g++
CXXFLAGS=-Wall
CXXFLAGS+=--pedantic
CXXFLAGS+=-g


NAME = main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXLAGS) $? -o $@

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $*.cpp -o $@

.PHONY: clean

clean:
	rm -f $(NAME) $(OBJ)
	
run: $(NAME)
	./$(NAME)