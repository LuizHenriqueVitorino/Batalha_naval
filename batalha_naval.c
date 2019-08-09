#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j;
char tabuleiro_jogador[10][10], tabuleiro_bot[10][10];
int navios_jogador[10][10], navios_bot[10][10];

int tabuleiro(int linha, char coluna, int linha_bot, int coluna_bot);
char verifica_casa(int i, int j);
int numero_coluna(char coluna);
int posiciona_navio();

int main(){
	srand(time(NULL));
	int linha, linha_bot, coluna_bot;
	char coluna;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			tabuleiro_jogador[i][j]='-';
			tabuleiro_bot[i][j]='-';
		}
	}
	tabuleiro(10, 'K', 10, 10);
	posiciona_navio();
	while(1){
		do{
			printf("Coluna: ");
			scanf("%s", &coluna);
			if(numero_coluna(coluna)==10){
				printf("Valor inválido, digite apenas os valores no intervalo de A a J\n");
			}
		}while(numero_coluna(coluna)==10);
		do{
			printf("Linha: ");
			scanf("%d", &linha);
			if(linha<0 || linha>9){
				printf("Valor inválido, digite apenas os valores no intervalo de 0 a 9\n");
			}
		}while(linha<0 || linha>9);
		coluna_bot=rand()%10;
		linha_bot=rand()%10;
		tabuleiro(linha, coluna, linha_bot, coluna_bot);

	}
}
int posiciona_navio(){
	int linha_navio, coluna_navio;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			navios_jogador[i][j]=0;
			navios_bot[i][j]=0;
		}
	}
	for(i=0;i<3;i++){
		printf("Linha do navio %d: ", i);
		scanf("%d", &linha_navio);
		printf("Coluna do navio %d: ", i);
		scanf("%d", &coluna_navio);
		navios_jogador[linha_navio][coluna_navio]=1;
		navios_bot[rand()%9][rand()%9]=1;
	}
	
}
int numero_coluna(char coluna){
	switch(coluna){
		case 'A': return 0;
			break;
		case 'B': return 1;
			break;
		case 'C': return 2;
			break;
		case 'D': return 3;
			break;
		case 'E': return 4;
			break;
		case 'F': return 5;
			break;
		case 'G': return 6;
			break;
		case 'H': return 7;
			break;
		case 'I': return 8;
			break;
		case 'J': return 9;
			break;
		default: return 10;
			break;
	}
}
int tabuleiro(int linha, char coluna, int linha_bot, int coluna_bot){
	tabuleiro_bot[linha][numero_coluna(coluna)]=verifica_casa(linha, numero_coluna(coluna));
	tabuleiro_jogador[linha_bot][coluna_bot]=verifica_casa(linha_bot, coluna_bot);
	printf("   A  B  C  D  E  F  G  H  I  J\n");
	for(i=0; i<10; i++){
		if(i<9){
			printf("%d ", i+1);
		}
		else{
			printf("%d", i+1);
		}
		for(j=0; j<10; j++){
			printf(" %c ", tabuleiro_jogador[i][j]);
			if(j==9){
				printf("\n");
			}
		}
	}
	printf("   A  B  C  D  E  F  G  H  I  J\n");
	for(i=0; i<10; i++){
		if(i<9){
			printf("%d ", i+1);
		}
		else{
			printf("%d", i+1);
		}
		for(j=0; j<10; j++){
			printf(" %c ", tabuleiro_bot[i][j]);
			if(j==9){
				printf("\n");
			}
		}
	}
}
char verifica_casa(int i, int j){
	if(navios_bot[i][j]==1){
		return 'x';
	}
	else{
		return 'a';
	}
}
int verifica_vitoria(){
}
