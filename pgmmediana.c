#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

t_pgm *pgm_mediana(t_pgm *nova_img, int limite_mediana)
{
    int lim = limite_mediana / 2;
    int i, j;
    int k, l;
    int z = 0;
    unsigned char *array_vizinhos = NULL;
    int num_vizinhos = lim * lim;

    array_vizinhos = malloc(num_vizinhos * sizeof(unsigned char));

    for (i = lim; i < nova_img->linhas - lim; i++)
    {
        for (j = lim; j < nova_img->colunas - lim; i++)
        {
            z = 0;
            for (k = i - lim; k < i + lim; k++)
            {
                for (l = j - lim; l < j + lim; l++)
                {
                    array_vizinhos[z] = nova_img->matriz_img[k][l];
                    z++;
                }
            }
            qsort(array_vizinhos, num_vizinhos, sizeof(int), cmpfunc);
            
        }
    }

    return nova_img;
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