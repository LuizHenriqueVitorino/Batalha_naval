
typedef struct
{
    char **data;
    size_t len_x;
    size_t len_y;
} tabuleiro;

void gerar_tabuleiro(tabuleiro *t);
void imprimir_tabuleiro(tabuleiro *t);
char verifica_casa(int i, int j, int player);
int numero_coluna(char coluna);
int posiciona_navio();
int verifica_vitoria();