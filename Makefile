COMPILER=G++
FLAGS=-Wall -pedantic -ansi

SOURCE=lexer.cpp
EXECUTABLE=lex

all: go

compile: $(SOURCE)
	$(COMPILER) $(FLAGS) $(SOURCE) -o $(EXECUTABLE)

go: compile
	./$(EXECUTABLE)

clean :
	rm $(EXECUTABLE)
