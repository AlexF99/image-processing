all:
	gcc -c trata_comando.c -o trata_comando.o
	gcc -c abre_pgm.c -o abre_pgm.o
	gcc -c trata_pgm.c -o trata_pgm.o
	gcc -g pgmnega.c trata_comando.o abre_pgm.o trata_pgm.o -o pgmnega
	gcc -g pgmlimiar.c trata_comando.o abre_pgm.o trata_pgm.o -o pgmlimiar
	gcc -g pgmmedia.c trata_comando.o abre_pgm.o trata_pgm.o -o pgmmedia