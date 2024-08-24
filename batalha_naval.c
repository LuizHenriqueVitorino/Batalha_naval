#include <stdio.h>
#include <stdlib.h>
#include "lib/batalha_naval.h"

void gerar_tabuleiro(tabuleiro *t){
	t->data = malloc(t->len_x*sizeof(char*));
	if(!(t->data)){
		perror("FALTA DE MEMÓRIA.");
		exit(1);
	}
	for(int i = 0; i < t->len_x; i++){
		if(!(t->data[i] = calloc(t->len_y, sizeof(char)))){
			perror("FALTA DE MEMÓRIA.");
			exit(1);
		}
	}
}

void imprimir_tabuleiro(tabuleiro t){
	puts("-\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ");
	for(int i = 0; i < t.len_x; i++){
		printf("%d\t", i + 1);
		for(int j = 0; j < t.len_y; j++){
			printf("%c\t", t.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void posicionar_navios(tabuleiro t_jogador, tabuleiro t_bot){
	char linha_navio_jogador, linha_navio_bot, coluna_navio_jogador, coluna_navio_bot;
	
	puts("Insira três navios de uma casa.");
	for(int i = 0; i < 3; i++){
		do{
			printf("Digite a linha do navio %d de uma casa:\n", i + 1);
			scanf("%hhd", &linha_navio_jogador);
			printf("Digite a coluna do navio %d de uma casa:\n", i + 1);
			scanf("%c", &coluna_navio_jogador);
			if(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] == 1){
				puts("Esta casa já está ocupada por outro navio, tente outra casa!");
			}
		}while(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)]==1);

		t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] = 1;

		do{
			linha_navio_bot = rand() % 10;
			coluna_navio_bot = rand() % 10;
		}while(t_bot.data[linha_navio_bot][coluna_navio_bot] == 1);

		t_bot.data[linha_navio_bot][coluna_navio_bot] = 1;
	}
	
	imprimir_tabuleiro(t_jogador);
	puts("Insira dois navios de duas casas.");
	for(int i = 0; i < 2; i++){
		do{
			do{
				printf("Digite a linha do navio %d de duas casas:\n", i + 1);
				scanf("%hhd", &linha_navio_jogador);
				printf("Digite a coluna do navio %d de duas casas:\n", i + 1);
				scanf("%c", &coluna_navio_jogador);
				if(numero_coluna(coluna_navio_jogador) == 8){
					puts("Escolha um valor entre A e I");
				}
			}while(numero_coluna(coluna_navio_jogador) == 8);
			if(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] == 1 || t_jogador.data[linha_navio_jogador][numero_coluna(coluna_navio_jogador) + 1] == 1){
				puts("Este navio irá sobrepor outro navio, tente outra vez.");
			}
		}while(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)]==1 || t_jogador.data[linha_navio_jogador][numero_coluna(coluna_navio_jogador) + 1] == 1);
		t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] = 1;
		t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador) + 1] = 1;

		do{
			linha_navio_bot = rand() % 10;
			coluna_navio_bot = rand() % 9;
		}while(t_bot.data[linha_navio_bot][coluna_navio_bot] == 1 || t_bot.data[linha_navio_bot][coluna_navio_bot+1] == 1);
		t_bot.data[linha_navio_bot][coluna_navio_bot] = 1;
		t_bot.data[linha_navio_bot][coluna_navio_bot+1] = 1;
	}
	
	imprimir_tabuleiro(t_jogador);
	puts("Insira um navio de três casas.");
	do{
		do{
			printf("Digite a linha do navio de três casas:\n");
			scanf("%hhd", &linha_navio_jogador);
			printf("Digite a linha do navio de duas casas:\n");
			scanf("%c", &coluna_navio_jogador);
			if(numero_coluna(coluna_navio_jogador) > 7){
				puts("Escolha um valor entre A e H\n");
			}
		}while(numero_coluna(coluna_navio_jogador) > 7);
		if(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] == 1 || t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador) + 1] == 1 || t_jogador.data[linha_navio_jogador][numero_coluna(coluna_navio_jogador) + 2] == 1){
			puts("Este navio irá sobrepor outro navio, tente outra vez.");
		}
	}while(t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] == 1 || t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador) + 1] == 1 || t_jogador.data[linha_navio_jogador][numero_coluna(coluna_navio_jogador) + 2] == 1);
	t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador)] = 1;
	t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador) + 1] = 1;
	t_jogador.data[linha_navio_jogador - 1][numero_coluna(coluna_navio_jogador) + 2] = 1;

	do{
		linha_navio_bot = rand() % 10;
		coluna_navio_bot = rand() % 8;
	}while(t_bot.data[linha_navio_bot][coluna_navio_bot] == 1 || t_bot.data[linha_navio_bot][coluna_navio_bot + 1] == 1 || t_bot.data[linha_navio_bot][coluna_navio_bot + 2] == 1);
	t_bot.data[linha_navio_bot][coluna_navio_bot]=1;
	t_bot.data[linha_navio_bot][coluna_navio_bot + 1]=1;
	t_bot.data[linha_navio_bot][coluna_navio_bot + 2]=1;
	
	imprimir_tabuleiro(t_jogador);
}

int numero_coluna(char coluna){
	switch(coluna){
		case 'A':
		case 'a':
			return 0;
		case 'B':
		case 'b':
			return 1;
		case 'C':
		case 'c':
			return 2;
		case 'D':
		case 'd':
			return 3;
		case 'E':
		case 'e':
			return 4;
		case 'F':
		case 'f':
			return 5;
		case 'G':
		case 'g':
			return 6;
		case 'H':
		case 'h':
			return 7;
		case 'I':
		case 'i':
			return 8;
		case 'J':
		case 'j':
			return 9;
		default:
			return 10;
	}
}

char verificar_casa(int i, int j, tabuleiro t_atacando, tabuleiro t_navios){
	if(t_navios.data[i][j] == 1){
		return 'x';
	}
	return 'a';
}

int verificar_vitoria(tabuleiro t_ataque_jogador, tabuleiro t_navios_jogador, tabuleiro t_ataque_bot, tabuleiro t_navios_bot){
	int pontuacao_jogador = 0, pontuacao_bot = 0;
	for(int i = 0; i < t_ataque_jogador.len_x; i++){
		for(int j = 0; j < t_ataque_jogador.len_y; j++){
			if(t_ataque_jogador.data[i][j] == 'a'){
				pontuacao_jogador+=1;
			}
			if(t_ataque_jogador.data[i][j] == 'a'){
				pontuacao_bot+=1;
			}
		}
	}
	if(pontuacao_jogador == 10){
		return 1;
	}
	if(pontuacao_bot==10){
		return 2;
	}
	else{
		return 3;
	}
}