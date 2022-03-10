#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

t_pgm *pgm_media(t_pgm *nova_img)
{
    int i, j;
    int media_vizinhos = (int)0;
    int max_linhas = nova_img->linhas - 1;
    int max_colunas = nova_img->colunas - 1;
    int num_vizinhos = 0;

    for (i = 0; i < nova_img->linhas; i++)
    {
        for (j = 0; j < nova_img->colunas; j++)
        {
            num_vizinhos = 0;
            if (i < max_linhas)
            {
                if (j < max_colunas)
                {
                    media_vizinhos += (int)nova_img->matriz_img[i + 1][j + 1];
                    num_vizinhos++;
                }
                if (j > 0)
                {
                    media_vizinhos += (int)nova_img->matriz_img[i + 1][j - 1];
                    num_vizinhos++;
                }
                media_vizinhos += (int)nova_img->matriz_img[i + 1][j];
                num_vizinhos++;
            }
            if (i > 0)
            {
                if (j < max_colunas)
                {
                    media_vizinhos += (int)nova_img->matriz_img[i - 1][j + 1];
                    num_vizinhos++;
                }
                if (j > 0)
                {
                    media_vizinhos += (int)nova_img->matriz_img[i - 1][j - 1];
                    num_vizinhos++;
                }
                media_vizinhos += (int)nova_img->matriz_img[i - 1][j];
                num_vizinhos++;
            }

            if (j < max_colunas)
            {
                media_vizinhos += (int)nova_img->matriz_img[i][j + 1];
                num_vizinhos++;
            }
            if (j > 0)
            {
                media_vizinhos += (int)nova_img->matriz_img[i][j - 1];
                num_vizinhos++;
            }

            // proprio pixel
            media_vizinhos += (int)nova_img->matriz_img[i][j];

            media_vizinhos = (unsigned char)(media_vizinhos / num_vizinhos);

            nova_img->matriz_img[i][j] = (unsigned char)(media_vizinhos);
        }
    }

    return nova_img;
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