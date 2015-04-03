COMPILER=G++
FLAGS=-Wall -pedantic -ansi

LEXER_SOURCE=lexer.cpp
LEXER_HEADER=lexer.h
LEXER_OBJECT=lexer.o

PARSER_SOURCE=parser.cpp
PARSER_HEADER=parser.h
PARSER_OBJECT=parser.o

MAIN_SOURCE=main.cpp

SOURCES=$(LEXER_SOURCE) $(PARSER_SOURCE) $(MAIN_SOURCE)
HEADERS=$(LEXER_HEADER) $(PARSER_HEADER)
OBJECTS=$(LEXER_OBJECT) $(PARSER_OBJECT)

EXECUTABLE=kaleidoscope

TESTFILE=fibo.k

all: go

$(LEXER_OBJECT): $(LEXER_SOURCE) $(LEXER_HEADER)
	$(COMPILER) -c $(FLAGS) $(LEXER_SOURCE) -o $(LEXER_OBJECT)

$(PARSER_OBJECT): $(PARSER_SOURCE) $(PARSER_HEADER)
	$(COMPILER) -c $(FLAGS) $(PARSER_SOURCE) -o $(PARSER_OBJECT)

compileall: $(OBJECTS) $(HEADERS) $(MAIN_SOURCE)
	$(COMPILER) $(FLAGS) $(OBJECTS) $(MAIN_SOURCE) -o $(EXECUTABLE)

go: compileall
	./$(EXECUTABLE)

test: clean compileall
	cat $(TESTFILE) | ./$(EXECUTABLE)

clean :
	rm -rf $(EXECUTABLE) $(OBJECTS)
