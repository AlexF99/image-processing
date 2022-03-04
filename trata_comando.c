#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parser(int argc, char *argv[], char **arquivo_entrada)
{
    char *value_o = NULL;
    int option;

    extern char *optarg;

    while ((option = getopt(argc, argv, "i:o:")) != -1)
        switch (option)
        {
        case 'i':
            arquivo_entrada = malloc(strlen(optarg)*sizeof(char));
            strcpy(*arquivo_entrada, optarg);
            break;
        case 'o':
            value_o = optarg;
            break;
        default:
            fprintf(stderr, "Usage: %s -a -b -c value\n", argv[0]);
            exit(1);
        }

    printf("arquivo_entrada = %s\nvalue_o = %s\n", *arquivo_entrada, value_o);
}