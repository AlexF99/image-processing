#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"

#define MAXV 255
#define MINV 0

t_pgm *pgm_limiar(t_pgm *nova_img, float limiar)
{
    int i, j;
    float limiar_byte = MAXV * limiar;

    for (i = 0; i < nova_img->linhas; i++)
    {
        for (j = 0; j < nova_img->colunas; j++)
        {
            if (nova_img->matriz_img[i][j] <= limiar_byte)
                nova_img->matriz_img[i][j] = (unsigned char)(MAXV);
            else
                nova_img->matriz_img[i][j] = (unsigned char)(MINV);
        }
    }
    return nova_img;
}