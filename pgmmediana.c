#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

static int cmpfunc(const void *a, const void *b)
{
    return (*(unsigned char *)a - *(unsigned char *)b);
}

t_pgm *pgm_mediana(t_pgm *original, int limite_mediana)
{
    int lim = limite_mediana / 2;
    int i, j;
    int k, l;
    int z = 0;
    unsigned char *array_vizinhos = NULL;
    unsigned char novo_pixel;
    int num_vizinhos = lim * lim;

    unsigned char **matriz_aux = aloca_matriz(original->linhas, original->colunas);
    array_vizinhos = malloc((num_vizinhos * 2) * sizeof(unsigned char));

    for (i = 0; i < original->linhas; i++)
        for (j = 0; j < original->colunas; j++)
            matriz_aux[i][j] = original->matriz_img[i][j];

    for (i = lim; i < original->linhas - lim; i++)
    {
        for (j = lim; j < original->colunas - lim; j++)
        {
            z = 0;
            for (k = i - lim; k <= i + lim; k++)
            {
                for (l = j - lim; l <= j + lim; l++)
                {
                    if ((k >= 0) && (k < original->linhas) && (l >= 0) && (l < original->colunas))
                    {
                        array_vizinhos[z] = matriz_aux[k][l];
                        z += 1;
                    }
                }
            }

            qsort(array_vizinhos, num_vizinhos, sizeof(unsigned char), cmpfunc);
            novo_pixel = array_vizinhos[(num_vizinhos / 2) + 1];
            original->matriz_img[i][j] = novo_pixel;
        }
    }

    return original;
}

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;
    int limite_mediana = 3;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, NULL, NULL, &limite_mediana);

    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtro
    pgm_filtrado = pgm_mediana(pgm, limite_mediana);
    cria_pgm(pgm_filtrado, arquivo_saida);

    libera_pgm(pgm);
    free_args(&arquivo_entrada, &arquivo_saida);

    return 0;
}