CFLAGS = -Wall

common_o = trata_comando.o abre_pgm.o trata_pgm.o

all: pgmnega pgmlimiar pgmmedia pgmrotacao pgmlbp pgmmediana

common:
	gcc -c trata_comando.c -o trata_comando.o
	gcc -c abre_pgm.c -o abre_pgm.o
	gcc -c trata_pgm.c -o trata_pgm.o

pgmnega: ${common_o}
	gcc -g ${common_o} pgmnega.c -o pgmnega

pgmlimiar: ${common_o}
	gcc -g ${common_o} pgmlimiar.c -o pgmlimiar

pgmmedia: ${common_o}
	gcc -g ${common_o} pgmmedia.c -o pgmmedia

pgmrotacao: ${common_o}
	gcc -g ${common_o} pgmrotacao.c -o pgmrotacao

pgmlbp: ${common_o}
	gcc -g ${common_o} pgmlbp.c -o pgmlbp

pgmmediana: ${common_o}
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