#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

t_pgm *pgm_media(t_pgm *original)
{
    int i, j;
    unsigned char media_vizinhos = 0;
    int max_linhas = original->linhas - 1;
    int max_colunas = original->colunas - 1;
    int num_vizinhos = 0;

    unsigned char **mat_aux = NULL;

    mat_aux = aloca_matriz(original->linhas, original->colunas);

    for (i = 0; i < original->linhas; i++)
    {
        for (j = 0; j < original->colunas; j++)
        {
            num_vizinhos = 0;
            media_vizinhos = 0;
            if (i < max_linhas)
            {
                if (j < max_colunas)
                    media_vizinhos = ((original->matriz_img[i + 1][j + 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
                if (j > 0)
                    media_vizinhos = ((original->matriz_img[i + 1][j - 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
                media_vizinhos = ((original->matriz_img[i + 1][j] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
            }
            if (i > 0)
            {
                if (j < max_colunas)
                    media_vizinhos = ((original->matriz_img[i - 1][j + 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
                if (j > 0)
                    media_vizinhos = ((original->matriz_img[i - 1][j - 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
                media_vizinhos = ((original->matriz_img[i - 1][j] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
            }

            if (j < max_colunas)
                media_vizinhos = ((original->matriz_img[i][j + 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
            if (j > 0)
                media_vizinhos = ((original->matriz_img[i][j - 1] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);

            media_vizinhos = ((original->matriz_img[i][j] + (media_vizinhos * num_vizinhos)) / ++num_vizinhos);
            mat_aux[i][j] = media_vizinhos;
        }
    }

    original->matriz_img = mat_aux;
    return original;
}

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, NULL, NULL);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtro
    pgm_filtrado = pgm_media(pgm);
    cria_pgm(pgm_filtrado, arquivo_saida);

    libera_pgm(pgm);
    free_args(&arquivo_entrada, &arquivo_saida);

    return 0;
}