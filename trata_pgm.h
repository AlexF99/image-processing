typedef struct t_pgm
{
    char *tipo_pixel;
    int linhas, colunas, maxgray;
    unsigned char **matriz_img;
} t_pgm;

t_pgm *init_pgm(FILE **img);

void cria_pgm(t_pgm *pgm, char *arquivo_saida);

unsigned char **aloca_matriz(int linhas, int colunas);

void libera_pgm(t_pgm *pgm);

void libera_matriz(unsigned char **mat, int linhas);
