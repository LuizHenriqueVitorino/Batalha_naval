#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/batalha_naval.h"

int i, j;
char tabuleiro_jogador[10][10], tabuleiro_bot[10][10];
int navios_jogador[10][10], navios_bot[10][10];

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
	tabuleiro(10, 'K', 10, 10);
	while(verifica_vitoria()==3){
		do{
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
				linha-=1;
				if(linha<0 || linha>9){
					printf("Valor inválido, digite apenas os valores no intervalo de 0 a 9\n");
				}
			}while(linha<0 || linha>9);
			if(tabuleiro_bot[linha][numero_coluna(coluna)]!='-'){
				printf("Casa já revelada, tente outra vez!\n");
			}
		}while(tabuleiro_bot[linha][numero_coluna(coluna)]!='-');
		do{
			coluna_bot=rand()%10;
			linha_bot=rand()%10;
		}while(tabuleiro_jogador[linha_bot][coluna_bot]!='-');
		tabuleiro(linha, coluna, linha_bot, coluna_bot);

	}
	if(verifica_vitoria()==1){
		printf("Parabéns. Você ganhou!\n");
	}
	if(verifica_vitoria()==2){
		printf("A máquina ganhou!\n");
		printf("Game over!\n");
	}
}