all:
	gcc -c trata_comando.c -o trata_comando.o
	gcc -c abre_pgm.c -o abre_pgm.o
	gcc -c trata_pgm.c -o trata_pgm.o
	gcc -c pgmnega.c -o pgmnega.o
	gcc -g main.c trata_comando.o abre_pgm.o trata_pgm.o pgmnega.o -o main.o