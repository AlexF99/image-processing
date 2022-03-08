#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"
#include "pgmnega.h"
#include "pgmlimiar.h"

#define LINESIZE 1024

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;
    float limiar = 0.0;
    int i, j;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, &limiar);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtros
    pgm_filtrado = pgm_negativo(pgm);

    // pgm_filtrado = pgm_limiar(pgm, limiar);

    cria_pgm(pgm_filtrado, arquivo_saida);
    libera_pgm(pgm);

    free_args(&arquivo_entrada, &arquivo_saida);

    printf("\n\n");
    return 0;
}