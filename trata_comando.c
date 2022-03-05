#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void parser(int argc, char *argv[], char **arquivo_entrada, char **arquivo_saida)
{
    int option;
    extern char *optarg;

    while ((option = getopt(argc, argv, "i:o:")) != -1)
        switch (option)
        {
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

    if (!*arquivo_entrada)
    {
        printf("escreva o nome do arquivo de entrada: ");
        scanf("%s", *arquivo_entrada);
    }
    if (!*arquivo_saida)
    {
        printf("escreva o nome do arquivo de saida: ");
        scanf("%s", *arquivo_saida);
    }
}

void free_args(char **arquivo_entrada, char **arquivo_saida) {
    free(*arquivo_entrada);
    free(*arquivo_saida);
}