COMPILER=G++
FLAGS=-Wall -pedantic -ansi

SOURCE=lexer.cpp
EXECUTABLE=lex

TESTFILE=fibo.k

all: go

compile: $(SOURCE)
	$(COMPILER) $(FLAGS) $(SOURCE) -o $(EXECUTABLE)

go: compile
	./$(EXECUTABLE)

test: compile
	cat $(TESTFILE) | ./$(EXECUTABLE)

clean :
	rm $(EXECUTABLE)
