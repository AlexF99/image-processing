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
    int max_linhas = original->linhas - 1;
    int max_colunas = original->colunas - 1;

    int valor_lbp = 0;

    unsigned char **matriz_aux = aloca_matriz(original->linhas, original->colunas);

    for (i = 0; i < original->linhas; i++)
    {
        for (j = 0; j < original->colunas; j++)
        {
            valor_lbp = 0;
            if (i < max_linhas)
            {
                if (j < max_colunas)
                {
                    if (original->matriz_img[i + 1][j + 1] >= original->matriz_img[i][j])
                        valor_lbp = (valor_lbp + 128);
                }
                if (j > 0)
                {
                    if (original->matriz_img[i + 1][j - 1] >= original->matriz_img[i][j])
                        valor_lbp = (valor_lbp + 32);
                }
                if (original->matriz_img[i + 1][j] >= original->matriz_img[i][j])
                    valor_lbp = (valor_lbp + 64);
            }

            if (i > 0)
            {
                if (j < max_colunas)
                {
                    if (original->matriz_img[i - 1][j + 1] >= original->matriz_img[i][j])
                        valor_lbp = (valor_lbp + 4);
                }
                if (j > 0)
                {
                    if (original->matriz_img[i - 1][j - 1] >= original->matriz_img[i][j])
                        valor_lbp = (valor_lbp + 1);
                }
                if (original->matriz_img[i - 1][j] >= original->matriz_img[i][j])
                    valor_lbp = (valor_lbp + 2);
            }

            if (j < max_colunas)
            {
                if (original->matriz_img[i][j + 1] >= original->matriz_img[i][j])
                    valor_lbp = (valor_lbp + 16);
            }
            if (j > 0)
            {
                if (original->matriz_img[i][j - 1] >= original->matriz_img[i][j])
                    valor_lbp = (valor_lbp + 8);
            }
            matriz_aux[i][j] = valor_lbp;
        }
    }
    original->matriz_img = matriz_aux;
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