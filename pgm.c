#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"

void init_pgm(char *filename, t_pgm *pgm)
{
    FILE *img;
    img = fopen(filename, "r");
    if (!img)
    {
        perror("erro ao abrir arquivo");
        exit(1);
    }

    fscanf(img, "%s", pgm->tipo_pixel);
    fscanf(img, "%d", &pgm->linhas);
    fscanf(img, "%d", &pgm->colunas);
    fscanf(img, "%d", &pgm->maxgray);
    aloca_matriz_img(&img, pgm);
}

void aloca_matriz_img(FILE **img, t_pgm *pgm)
{
    int i, j;

    pgm->matriz_img = malloc(pgm->linhas * sizeof(int *));

    if (pgm->matriz_img == NULL)
    {
        printf("erro de malloc");
        perror("erro de malloc");
        exit(1);
    }

    for (i = 0; i < pgm->linhas; i++)
        pgm->matriz_img[i] = malloc(pgm->colunas * sizeof(int));

    for (i = 0; i < pgm->linhas; i++)
        for (j = 0; j < pgm->colunas; j++)
        {
            fscanf(*img, "%d", &pgm->matriz_img[i][j]);
            printf("%d", pgm->matriz_img[i][j]);
        }

    fclose(*img);
}

void libera_pgm(t_pgm *pgm)
{
    int i;
    for (i = 0; i < pgm->linhas; i++)
        free(pgm->matriz_img[i]);
    free(pgm->matriz_img);

    free(pgm);
}