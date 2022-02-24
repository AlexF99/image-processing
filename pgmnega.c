#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

void get_parametros(char *filename, FILE **img, char *pixeltype, int *numlinhas, int *numcolunas, int *maxgray)
{
    *img = fopen(filename, "r");
    if (!img)
    {
        perror("erro ao abrir arquivo");
        exit(1);
    }

    fscanf(*img, "%s", pixeltype);
    fscanf(*img, "%d", numlinhas);
    fscanf(*img, "%d", numcolunas);
    fscanf(*img, "%d", maxgray);
}

void aloca_matriz_img(FILE **img, int **matriz_img, int numlinhas, int numcolunas)
{
    int *pixel;
    int i, j;

    matriz_img = malloc(numlinhas * sizeof(int *));

    for (i = 0; i < numlinhas; i++)
        matriz_img[i] = malloc(numcolunas * sizeof(int));

    for (i = 0; i < numlinhas; i++)
        for (j = 0; j < numcolunas; j++) {
            fscanf(img, "%d", pixel);
            matriz_img[i][j] = pixel;
        }

    for (i = 0; i < numlinhas; i++)
        free(matriz_img[i]);
    free(matriz_img);
}

int main(int argc, char *argv[])
{

    FILE *arquivo_pgm;
    int **matriz_img;
    char *pixeltype;
    int i, j, l = 0;
    int numlinhas, numcolunas, maxgray;
    char line[LINESIZE + 1];

    get_parametros("lena.pgm", &arquivo_pgm, pixeltype, &numlinhas, &numcolunas, &maxgray);

    aloca_matriz_img(&arquivo_pgm, matriz_img, numlinhas, numcolunas);

    // while (!feof(arquivo_pgm) && l < 10)
    // {
    //     fgets(line, LINESIZE, arquivo_pgm);
    //     printf("%d: %s", l, line);
    //     l++;
    // }

    printf("\n\n");
    fclose(arquivo_pgm);
    return 0;
}