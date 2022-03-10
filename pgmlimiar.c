#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trata_pgm.h"
#include "abre_pgm.h"
#include "trata_comando.h"

#define LINESIZE 1024

#define MAXV 255
#define MINV 0

t_pgm *pgm_limiar(t_pgm *nova_img, float limiar)
{
    int i, j;
    float limiar_byte = MAXV * limiar;

    if (limiar > 1 || limiar < 0)
    {
        perror("O limiar deve estar entre 0 e 1");
        exit(0);
    }

    for (i = 0; i < nova_img->linhas; i++)
    {
        for (j = 0; j < nova_img->colunas; j++)
        {
            if (nova_img->matriz_img[i][j] <= limiar_byte)
                nova_img->matriz_img[i][j] = (unsigned char)(MAXV);
            else
                nova_img->matriz_img[i][j] = (unsigned char)(MINV);
        }
    }
    return nova_img;
}

int main(int argc, char *argv[])
{
    char *arquivo_entrada = NULL;
    char *arquivo_saida = NULL;
    float limiar = 0.0;

    t_pgm *pgm = NULL;
    t_pgm *pgm_filtrado = NULL;
    FILE *img;

    parser(argc, argv, &arquivo_entrada, &arquivo_saida, &limiar);
    img = abre_pgm(arquivo_entrada);
    pgm = init_pgm(&img);
    fecha_pgm(&img);

    // aplica filtro
    pgm_filtrado = pgm_limiar(pgm, limiar);
    cria_pgm(pgm_filtrado, arquivo_saida);

    libera_pgm(pgm);
    free_args(&arquivo_entrada, &arquivo_saida);

    return 0;
}