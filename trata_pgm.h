typedef struct t_pgm
{
    char *tipo_pixel;
    int linhas, colunas, maxgray;
    int **matriz_img;
} t_pgm;

void init_pgm(FILE **img, t_pgm *pgm);

void aloca_matriz_img(FILE **img, t_pgm *pgm);

void libera_pgm(FILE **img, t_pgm *pgm);
