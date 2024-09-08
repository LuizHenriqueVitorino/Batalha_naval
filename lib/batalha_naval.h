
typedef struct
{
    char **data;
    size_t len_x;
    size_t len_y;
} tabuleiro;

void gerar_tabuleiro(tabuleiro*);
void imprimir_tabuleiro_navios(tabuleiro);
void imprimir_tabuleiro_ataques(tabuleiro);
char verificar_casa(int i, int j, tabuleiro);
int numero_coluna(char coluna);
void posicionar_navios(tabuleiro, tabuleiro);
int verificar_vitoria(tabuleiro, tabuleiro, tabuleiro, tabuleiro);