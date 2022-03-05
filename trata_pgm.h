typedef struct t_pgm
{
    char *tipo_pixel;
    int linhas, colunas, maxgray;
    int **matriz_img;
} t_pgm;

t_pgm *init_pgm(FILE **img);

// void aloca_matriz_img(FILE **img, t_pgm *pgm);

void libera_pgm(t_pgm *pgm);
