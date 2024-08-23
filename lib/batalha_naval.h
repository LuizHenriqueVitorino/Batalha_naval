
typedef struct
{
    char **data;
    size_t len_x;
    size_t len_y;
} tabuleiro;

void gerar_tabuleiro(tabuleiro *t);
// int tabuleiro(int linha, char coluna, int linha_bot, int coluna_bot);
char verifica_casa(int i, int j, int player);
int numero_coluna(char coluna);
int posiciona_navio();
int verifica_vitoria();