#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 1024

int main(int argc, char *argv[]) {

    FILE *img;
    int i ;
    char line[LINESIZE+1] ;

    img = fopen("lena.pgm", "r");
    if (!img)
    {
        perror("erro ao abrir arquivo") ;
        exit(1);
    }


    while (!feof(img))
    {
        printf ("%d: %s", i, line);
        fgets (line, LINESIZE, img);
        i++ ;
    }

    printf("\n\n");
    fclose(img);
    return 0;
}