#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"

#define MAXV 255

t_pgm *pgm_negativo(t_pgm *nova_img)
{
    int i, j;

    for (i = 0; i < nova_img->linhas; i++)
        for (j = 0; j < nova_img->colunas; j++)
            nova_img->matriz_img[i][j] = (unsigned char)(MAXV - nova_img->matriz_img[i][j]);

    return nova_img;
}