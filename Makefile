go : lexer.c
	g++ -Wall -pedantic lexer.c -o lex
	./lex

clean :
	rm lex
