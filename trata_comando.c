#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parser(int argc, char *argv[], char **arquivo_entrada, char **arquivo_saida, float *limiar)
{
    int option;
    extern char *optarg;

    while ((option = getopt(argc, argv, "l:i:o:")) != -1)
        switch (option)
        {
        case 'l':
            printf("%s   ", optarg);
            *limiar = strtof(optarg, NULL);
            break;
        case 'i':
            *arquivo_entrada = malloc(strlen(optarg) * sizeof(char) + 1);
            strcpy(*arquivo_entrada, optarg);
            break;
        case 'o':
            *arquivo_saida = malloc(strlen(optarg) * sizeof(char) + 1);
            strcpy(*arquivo_saida, optarg);
            break;
        default:
            perror("falta parametros para as flags");
            exit(1);
        }
}

void free_args(char **arquivo_entrada, char **arquivo_saida)
{
    if (*arquivo_entrada != NULL)
        free(*arquivo_entrada);

    if (*arquivo_saida != NULL)
        free(*arquivo_saida);
}