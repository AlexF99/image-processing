CFLAGS = -Wall

common_o = trata_comando.o abre_pgm.o trata_pgm.o

all: common filtros

common:
	gcc -c trata_comando.c -o trata_comando.o
	gcc -c abre_pgm.c -o abre_pgm.o
	gcc -c trata_pgm.c -o trata_pgm.o

filtros: ${common_o}
	gcc -g ${common_o} pgmnega.c -o pgmnega
	gcc -g ${common_o} pgmlimiar.c -o pgmlimiar
	gcc -g ${common_o} pgmmedia.c -o pgmmedia
	gcc -g ${common_o} pgmrotacao.c -o pgmrotacao
	gcc -g ${common_o} pgmlbp.c -o pgmlbp

clean:
	-rm -f *~ *.o

purge:
#	-rm -f *.pgm
	-rm -f pgmnega
	-rm -f pgmlimiar
	-rm -f pgmmedia
	-rm -f pgmrotacao
	-rm -f pgmlbp