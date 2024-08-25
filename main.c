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
	char linha_jogador, coluna_jogador, linha_bot, coluna_bot;
	puts("Escolha casas para atacar.");
	while(verificar_vitoria(ataques_jogador, navios_jogador, ataques_bot, navios_bot) == 3){
		do{
			do{
				puts("Linha:");
				scanf("%hhd", &linha_jogador);
				if(linha_jogador < 1 || linha_jogador > 10){
					puts("Valor inválido, digite apenas os valores no intervalo de 1 a 10");
				}
				while (getchar() != '\n');
			}while(linha_jogador < 1 || linha_jogador > 10);
			do{
				puts("Coluna:");
				scanf("%c", &coluna_jogador);
				while (getchar() != '\n');
				if(numero_coluna(coluna_jogador) < 0 || numero_coluna(coluna_jogador) > 9){
					puts("Valor inválido, digite apenas os valores no intervalo de A a J");
				}
			}while(numero_coluna(coluna_jogador) < 0 || numero_coluna(coluna_jogador) > 9);
			if(ataques_jogador.data[linha_jogador - 1][numero_coluna(coluna_jogador)] != 0){
				puts("Casa já revelada, tente outra vez!");
			}
		}while(ataques_jogador.data[linha_jogador - 1][numero_coluna(coluna_jogador)] != 0);
		ataques_jogador.data[linha_jogador - 1][numero_coluna(coluna_jogador)] = verificar_casa(linha_jogador - 1, numero_coluna(coluna_jogador), navios_bot);
		do{
			coluna_bot = rand()%10;
			linha_bot = rand()%10;
		}while(ataques_bot.data[linha_bot][coluna_bot] != 0);
		ataques_bot.data[linha_bot][coluna_bot] = verificar_casa(linha_bot, coluna_bot, navios_jogador);
		puts("Seu tabuleiro:");
		imprimir_tabuleiro_ataques(ataques_jogador);
		puts("Tabuleiro do seu oponente:");
		imprimir_tabuleiro_ataques(ataques_bot);
	}

	if(verificar_vitoria(ataques_jogador, navios_jogador, ataques_bot, navios_bot) == 1){
		puts("Parabéns. Você ganhou!");
	}
	else{
		puts("A máquina ganhou!");
		puts("Game over!");
	}
}