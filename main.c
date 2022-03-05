#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;

    t_pgm *pgm = NULL;
    int i, j;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    printf("%s\n", pgm->tipo_pixel);
    printf("%d\n", pgm->linhas);
    printf("%d\n", pgm->colunas);
    printf("%d\n", pgm->maxgray);

    for (i = 0; i < pgm->linhas; i++)
        for (j = 0; j < pgm->colunas; j++)
            printf("%d ", pgm->matriz_img[i][j]);

    // libera_pgm(&img, pgm);

    free_args(&arquivo_entrada, &arquivo_saida);

    printf("\n\n");
    return 0;
}