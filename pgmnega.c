#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

int main(int argc, char *argv[])
{

    FILE *img;
    char pixeltype[2];
    int i, l = 0;
    char *numlinhas;
    char *numcolunas;
    char imgsize[LINESIZE + 1];
    char line[LINESIZE + 1];

    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);

    img = fopen("lena.pgm", "r");
    if (!img)
    {
        perror("erro ao abrir arquivo");
        exit(1);
    }

    fgets(pixeltype, LINESIZE, img);
    printf("pixeltype: %s", pixeltype);

    fgets(imgsize, LINESIZE, img);
    printf("imgsize: %s", imgsize);

   numlinhas = strtok(imgsize, "  ");
   numcolunas = strtok(imgsize, "  ");
   printf( "linhas: %s\n", numlinhas );
   printf( "colunas: %s\n", numcolunas );
   
//    while( numlinhas != NULL ) {
//       printf( "%s\n", numlinhas );
    
//       numlinhas = strtok(NULL, " ");
//    }
    

    while (!feof(img) && l < 10)
    {
        fgets(line, LINESIZE, img);
        printf("%d: %s", l, line);
        l++;
    }

    printf("\n\n");
    fclose(img);
    return 0;
}