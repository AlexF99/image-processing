#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024
#define MAXV 255

t_pgm *pgm_rotacao_simples(t_pgm *nova_img)
{
    int i, j, k;
    unsigned char **nova_mat = NULL;

    int imax = nova_img->linhas;
    int jmax = nova_img->colunas;

    // 90 graus
    nova_mat = aloca_matriz(jmax, imax);

    for (i = 0; i < jmax-1; i++)
    {
        for (j = 0; j < imax-1; j++)
        {
            nova_mat[i][j] = nova_img->matriz_img[imax - j - 1][i];
        }
    }

    free(nova_img->matriz_img);
    nova_img->matriz_img = NULL;
    nova_img->matriz_img = aloca_matriz(jmax, imax);

    nova_img->linhas = jmax;
    nova_img->colunas = imax;
    nova_img->matriz_img = nova_mat;

    return nova_img;
}

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;
    int angulo = 90;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, NULL, &angulo);

    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtro
    pgm_filtrado = pgm_rotacao_simples(pgm);
    cria_pgm(pgm_filtrado, arquivo_saida);

    libera_pgm(pgm);
    free_args(&arquivo_entrada, &arquivo_saida);

    return 0;
}