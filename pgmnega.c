#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

t_pgm *pgm_negativo(t_pgm *nova_img)
{
    int i, j;

    for (i = 0; i < nova_img->linhas; i++)
        for (j = 0; j < nova_img->colunas; j++)
            nova_img->matriz_img[i][j] = (unsigned char)(MAXV - nova_img->matriz_img[i][j]);

    return nova_img;
}

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, NULL);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtro
    pgm_filtrado = pgm_negativo(pgm);
    cria_pgm(pgm_filtrado, arquivo_saida);

    libera_pgm(pgm);
    free_args(&arquivo_entrada, &arquivo_saida);

    return 0;
}