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

    if (!strcmp("P2", pgm->tipo_pixel)) // verifica se tipo P2 ou P5
    {
        printf("entrou no p2\n");
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fscanf(*img, "%d", &pgm->matriz_img[i][j]);
    }
    else if (!strcmp("P5", pgm->tipo_pixel))
    {
        printf("entrou no p5\n");
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fread(&pgm->matriz_img[i][j], 1, 1, *img);
    }

    return pgm;
}

void cria_pgm(t_pgm *pgm, char *arquivo_saida)
{
    int i, j;
    FILE *nova_imagem = fopen(arquivo_saida, "w");

    fprintf(nova_imagem, "%s\n", pgm->tipo_pixel);
    fprintf(nova_imagem, "%d\n", pgm->linhas);
    fprintf(nova_imagem, "%d\n", pgm->colunas);
    fprintf(nova_imagem, "%d\n", pgm->maxgray);
    for (i = 0; i < pgm->linhas; i++)
        for (j = 0; j < pgm->colunas; j++)
            fprintf(nova_imagem, "%d ", pgm->matriz_img[i][j]);

    fclose(nova_imagem);
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