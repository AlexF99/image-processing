#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"

#define LINESIZE 1024

int main(int argc, char *argv[])
{
    int **matriz_img = NULL;
    t_pgm *pgm = NULL;    
    int i, j;

    init_pgm("lena.pgm", pgm);

    for (i = 0; i < pgm->linhas; i++)
        for (j = 0; j < pgm->colunas; j++)
            printf("%d ", matriz_img[i][j]);

    libera_pgm(pgm);

    // delete this later
    // char line[LINESIZE + 1];
    // int l = 0;
    // while (!feof(img) && l < 10)
    // {
    //     fgets(line, LINESIZE, img);
    //     printf("%d: %s", l, line);
    //     l++;
    // }

    printf("\n\n");
    return 0;
}