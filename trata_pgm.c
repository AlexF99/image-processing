#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"

t_pgm *init_pgm(FILE **img)
{
    int i, j;
    t_pgm *pgm = NULL;

    pgm = malloc(sizeof(t_pgm));
    if (pgm == NULL)
    {
        printf("erro de malloc");
        perror("erro de malloc");
        exit(1);
    }

    pgm->tipo_pixel = malloc(2 * sizeof(char));
    fscanf(*img, "%s", pgm->tipo_pixel);
    fscanf(*img, "%d", &pgm->linhas);
    fscanf(*img, "%d", &pgm->colunas);
    fscanf(*img, "%d", &pgm->maxgray);

    pgm->matriz_img = malloc(pgm->linhas * sizeof(int *));

    if (pgm->matriz_img == NULL)
    {
        printf("erro de malloc");
        perror("erro de malloc");
        exit(1);
    }

    for (i = 0; i < pgm->linhas; i++)
    {
        pgm->matriz_img[i] = malloc(pgm->colunas * sizeof(int));
        if (pgm->matriz_img[i] == NULL)
        {
            printf("erro de malloc");
            perror("erro de malloc");
            exit(1);
        }
    }

    for (i = 0; i < pgm->linhas; i++)
        for (j = 0; j < pgm->colunas; j++)
            fscanf(*img, "%d", &pgm->matriz_img[i][j]);

    return pgm;
}

void libera_pgm(t_pgm *pgm)
{
    free(pgm->tipo_pixel);

    int i;
    for (i = 0; i < pgm->linhas; i++)
        free(pgm->matriz_img[i]);

    free(pgm->matriz_img);

    free(pgm);
}