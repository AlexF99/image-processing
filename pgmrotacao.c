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

    int nova_nlinhas = nova_img->colunas;
    int nova_ncolunas = nova_img->linhas;

    nova_mat = aloca_matriz(nova_nlinhas, nova_ncolunas);

    for (i = 0; i < nova_nlinhas; i++)
        for (j = 0; j < nova_ncolunas; j++)
            nova_mat[j][i] = nova_img->matriz_img[i][j];

    for (i = 0; i < nova_nlinhas; i++)
    {
        k = 0;
        for (j = nova_ncolunas - 1; j >= 0; j--)
        {
            nova_img->matriz_img[i][k] = nova_mat[i][j];
            k++;
        }
    }

    // libera_matriz(nova_img->matriz_img, nova_img->linhas);
    // nova_img->matriz_img = aloca_matriz(nova_nlinhas, nova_ncolunas);
    // nova_img->matriz_img = nova_mat;

    // criar funcao separada depois
    libera_matriz(nova_mat, nova_nlinhas);

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