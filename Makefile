COMPILER=G++
FLAGS=-Wall -pedantic -ansi

LEXER_SOURCE=lexer.cpp
LEXER_OBJECT=lexer.o
MAIN_SOURCE=main.cpp
SOURCES=$(LEXER_SOURCE) $(MAIN_SOURCE)
EXECUTABLE=kaleidoscope

TESTFILE=fibo.k

all: go

$(LEXER_OBJECT) : $(LEXER_SOURCE)
	$(COMPILER) -c $(FLAGS) -o $(LEXER_OBJECT)

compileall: $(SOURCES)
	$(COMPILER) $(FLAGS) $(SOURCES) -o $(EXECUTABLE)

go: compileall
	./$(EXECUTABLE)

test: compileall
	cat $(TESTFILE) | ./$(EXECUTABLE)

clean :
	rm $(EXECUTABLE)
