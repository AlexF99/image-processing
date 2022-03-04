#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024

int main(int argc, char *argv[])
{
    char *arquivo_entrada;

    // t_pgm *pgm = NULL;
    // int i, j;
    // FILE *img;

    parser(argc, argv, &arquivo_entrada);

    // img = fopen("lena.pgm", "r");
    // init_pgm(&img, pgm);

    // printf("%s\n", pgm->tipo_pixel);
    // printf("%d\n", pgm->linhas);
    // printf("%d\n", pgm->colunas);
    // printf("%d\n", pgm->maxgray);

    // for (i = 0; i < pgm->linhas; i++)
    //     for (j = 0; j < pgm->colunas; j++)
    //         printf("%d ", 12);
            // printf("%d ", matriz_img[i][j]);

    // libera_pgm(&img, pgm);

    printf("\n\n");
    return 0;
}