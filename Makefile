CFLAGS = -Wall

common_o = trata_comando.o abre_pgm.o trata_pgm.o

all: pgmnega pgmlimiar pgmmedia pgmrotacao pgmlbp pgmmediana

common:
	gcc -c trata_comando.c -o trata_comando.o
	gcc -c abre_pgm.c -o abre_pgm.o
	gcc -c trata_pgm.c -o trata_pgm.o

pgmnega: ${common_o} pgmnega.c
	gcc -g ${common_o} pgmnega.c -o pgmnega

pgmlimiar: ${common_o} pgmlimiar.c
	gcc -g ${common_o} pgmlimiar.c -o pgmlimiar

pgmmedia: ${common_o} pgmmedia.c
	gcc -g ${common_o} pgmmedia.c -o pgmmedia

pgmrotacao: ${common_o} pgmrotacao.c
	gcc -g ${common_o} pgmrotacao.c -o pgmrotacao

pgmlbp: ${common_o} pgmlbp.c
	gcc -g ${common_o} pgmlbp.c -o pgmlbp

pgmmediana: ${common_o} pgmmediana.c
	gcc -g ${common_o} pgmmediana.c -o pgmmediana

clean:
	-rm -f *~ *.o

purge:
#	-rm -f *.pgm
	-rm -f pgmnega
	-rm -f pgmlimiar
	-rm -f pgmmedia
	-rm -f pgmrotacao
	-rm -f pgmlbp
	-rm -f pgmmediana