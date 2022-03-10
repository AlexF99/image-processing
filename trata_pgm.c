#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"

#define LENGTH 1024

unsigned char **aloca_matriz(int linhas, int colunas)
{
    int i, j;
    unsigned char **mat = malloc(linhas * sizeof(unsigned char *));

    if (mat == NULL)
    {
        perror("erro de malloc");
        exit(1);
    }

    for (i = 0; i < linhas; i++)
    {
        mat[i] = malloc(colunas * sizeof(unsigned char));
        if (mat[i] == NULL)
        {
            perror("erro de malloc");
            exit(1);
        }
    }
    return mat;
}

t_pgm *init_pgm(FILE **img)
{
    int i, j;
    t_pgm *pgm = NULL;
    char comentario[LENGTH + 1];

    pgm = malloc(sizeof(t_pgm));
    if (pgm == NULL)
    {
        perror("erro de malloc");
        exit(1);
    }

    pgm->tipo_pixel = malloc(2 * sizeof(char));
    fscanf(*img, "%s", pgm->tipo_pixel);

    // tratando quando imagem tem comentario
    fscanf(*img, "%s", comentario);
    if (comentario[0] == '#')
        fgets(comentario, LENGTH, *img);
    else
        fseek(*img, 2 * sizeof(char), SEEK_SET);

    fscanf(*img, "%d", &pgm->linhas);
    fscanf(*img, "%d", &pgm->colunas);
    fscanf(*img, "%d", &pgm->maxgray);

    pgm->matriz_img = aloca_matriz(pgm->linhas, pgm->colunas);

    if (!strcmp("P2", pgm->tipo_pixel)) // verifica se tipo P2 ou P5
    {
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fscanf(*img, "%hhu", &pgm->matriz_img[i][j]);
    }
    else if (!strcmp("P5", pgm->tipo_pixel))
    {
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fread(&pgm->matriz_img[i][j], sizeof(unsigned char), 1, *img);
    }

    return pgm;
}

void cria_pgm(t_pgm *pgm, char *arquivo_saida)
{
    int i, j;
    FILE *nova_imagem = NULL;
    if (!arquivo_saida)
        nova_imagem = stdout;
    else
        nova_imagem = fopen(arquivo_saida, "w");

    fprintf(nova_imagem, "%s\n", pgm->tipo_pixel);
    fprintf(nova_imagem, "%d\n", pgm->linhas);
    fprintf(nova_imagem, "%d\n", pgm->colunas);
    fprintf(nova_imagem, "%d\n", pgm->maxgray);
    if (!strcmp("P2", pgm->tipo_pixel))
    {
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fprintf(nova_imagem, "%hhu ", pgm->matriz_img[i][j]);
    }
    else if (!strcmp("P5", pgm->tipo_pixel))
    {
        for (i = 0; i < pgm->linhas; i++)
            for (j = 0; j < pgm->colunas; j++)
                fwrite(&pgm->matriz_img[i][j], sizeof(unsigned char), 1, nova_imagem);
    }

    fclose(nova_imagem);
}

void libera_matriz(unsigned char **mat, int linhas)
{
    int i;
    for (i = 0; i < linhas; i++)
        free(mat[i]);

    free(mat);
}

void libera_pgm(t_pgm *pgm)
{
    free(pgm->tipo_pixel);

    libera_matriz(pgm->matriz_img, pgm->linhas);
    pgm->matriz_img = NULL;

    // int i;
    // for (i = 0; i < pgm->linhas; i++)
    //     free(pgm->matriz_img[i]);

    // free(pgm->matriz_img);

    free(pgm);
}