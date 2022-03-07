#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"
#include "pgmnega.h"

#define LINESIZE 1024

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    int i, j;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtros
    pgm_filtrado = pgm_negativo(pgm);

    cria_pgm(pgm_filtrado, arquivo_saida);
    libera_pgm(pgm);

    free_args(&arquivo_entrada, &arquivo_saida);

    printf("\n\n");
    return 0;
}