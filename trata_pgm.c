#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"

void init_pgm(FILE **img, t_pgm *pgm)
{
    if (!img)
    {
        perror("erro ao abrir arquivo");
        exit(1);
    }
    pgm = malloc(1 * sizeof(t_pgm));
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

    printf("%s\n", pgm->tipo_pixel);
    printf("%d\n", pgm->linhas);
    printf("%d\n", pgm->colunas);
    printf("%d\n", pgm->maxgray);

    aloca_matriz_img(img, pgm);
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
}

void libera_pgm(FILE **img, t_pgm *pgm)
{
    free(pgm->tipo_pixel);

    int i;
    for (i = 0; i < pgm->linhas; i++)
        free(pgm->matriz_img[i]);

    free(pgm->matriz_img);

    free(pgm);
    fclose(*img);
}