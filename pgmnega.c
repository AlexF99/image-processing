#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

int main(int argc, char *argv[]) {

    FILE *img;
    char pixeltype[2];
    int i, l=0;
    char line[LINESIZE+1] ;

    for (i=0; i<argc; i++)
        printf ("argv[%d]: %s\n", i, argv[i]);

    img = fopen("lena.pgm", "r");
    if (!img)
    {
        perror("erro ao abrir arquivo") ;
        exit(1);
    }


    while (!feof(img) && l<10)
    {
        if (l == 0) {
            strcpy(pixeltype, line);
        }
        printf("%s", pixeltype);
        // printf("%d: %s", l, line);
        // fgets(line, LINESIZE, img);
        // l++;
    }

    printf("\n\n");
    fclose(img);
    return 0;
}