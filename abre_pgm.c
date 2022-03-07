#include <stdio.h>
#include <stdlib.h>
#include "trata_pgm.h"

FILE *abre_pgm(char *nome_pgm)
{
    FILE *img = NULL;
    if (!nome_pgm) {
        printf("chegou aqui");
        return stdin;
    }
    else
    {
        img = fopen(nome_pgm, "r");
        if (!img)
        {
            perror("erro ao abrir arquivo");
            exit(1);
        }
        return img;
    }
}

void fecha_pgm(FILE **img)
{
    fclose(*img);
}