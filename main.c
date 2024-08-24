#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/batalha_naval.h"

int main(){
	srand(time(NULL));

	tabuleiro ataques_jogador, ataques_bot, navios_jogador, navios_bot;
	gerar_tabuleiro(&ataques_jogador);
	gerar_tabuleiro(&ataques_bot);
	gerar_tabuleiro(&navios_jogador);
	gerar_tabuleiro(&navios_bot);

	posicionar_navios(navios_jogador, navios_bot);
	while(verificar_vitoria(ataques_jogador, navios_jogador, ataques_bot, navios_bot) == 3){
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

	if(verifica_vitoria() == 1){
		puts("Parabéns. Você ganhou!");
	}
	else{
		puts("A máquina ganhou!");
		puts("Game over!");
	}
}