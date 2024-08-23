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

int posiciona_navio(){
	int linha_navio, linha_navio_bot, coluna_navio_bot;
	char coluna_navio;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			navios_jogador[i][j]=0;
			navios_bot[i][j]=0;
		}
	}
	tabuleiro(10, 'K', 10, 10);
	/*No seguinte for, a função irá adicionar os 3 navios de uma casa.*/
	for(i=0;i<3;i++){
		do{
			printf("Linha do navio %d de uma casa: ", i+1);
			scanf("%d", &linha_navio);
			printf("Coluna do navio %d de uma casa: ", i+1);
			scanf("%s", &coluna_navio);
			linha_navio-=1;
			if(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1){
				printf("Esta casa já está ocupada por outro navio, tente outra vez!\n");
			}
		}while(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1);
		navios_jogador[linha_navio][numero_coluna(coluna_navio)]=1;
		do{
			linha_navio_bot=rand()%9;
			coluna_navio_bot=rand()%9;
		}while(navios_bot[linha_navio_bot][coluna_navio_bot]==1);
		navios_bot[linha_navio_bot][coluna_navio_bot]=1;
	}
	/*No seguinte for, a função irá adionar os 2 navios de duas casas.*/
	tabuleiro(10, 'K', 10, 10);
	for(i=0;i<2;i++){
		do{
			do{
				printf("Linha do navio %d de duas casas: ", i+1);
				scanf("%d", &linha_navio);
				printf("Coluna do navio %d de duas casas: ", i+1);
				scanf("%s", &coluna_navio);
				linha_navio-=1;
				if(numero_coluna(coluna_navio)<=0 || numero_coluna(coluna_navio)>=8){
					printf("Escolha um valor entre A e I\n");
				}
			}while(numero_coluna(coluna_navio)<=0 && numero_coluna(coluna_navio)>=8);
			if(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1 && navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1){
				printf("Este navio irá sobrepor outro navio, tente outra vez.\n");
			}
		}while(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1 || navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1);
		navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1;
		navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1;
		do{
			linha_navio_bot=rand()%9;
			coluna_navio_bot=rand()%8;
		}while(navios_bot[linha_navio_bot][coluna_navio_bot]==1 || navios_bot[linha_navio_bot][coluna_navio_bot+1]==1);
		navios_bot[linha_navio_bot][coluna_navio_bot]=1;
		navios_bot[linha_navio_bot][coluna_navio_bot+1]=1;
	}
	tabuleiro(10, 'K', 10, 10);
	do{
		do{
			printf("Linha do navio de três casas: ");
			scanf("%d", &linha_navio);
			printf("Coluna do navio de três casas: ");
			scanf("%s", &coluna_navio);
			linha_navio-=1;
			if(numero_coluna(coluna_navio)<=0 || numero_coluna(coluna_navio)>=7){
				printf("Escolha um valor entre A e H\n");
			}
		}while(numero_coluna(coluna_navio)<=0 || numero_coluna(coluna_navio)>=7);
		if(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1 || navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1 || navios_jogador[linha_navio][numero_coluna(coluna_navio)]+2==1){
			printf("Este navio irá sobrepor outro navio, tente outra vez.\n");
		}
	}while(navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1 || navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1 || navios_jogador[linha_navio][numero_coluna(coluna_navio)]+2==1);
	navios_jogador[linha_navio][numero_coluna(coluna_navio)]==1;
	navios_jogador[linha_navio][numero_coluna(coluna_navio)+1]==1;
	navios_jogador[linha_navio][numero_coluna(coluna_navio)+2]==1;
	do{
		linha_navio_bot=rand()%9;
		coluna_navio_bot=rand()%7;
	}while(navios_bot[linha_navio_bot][coluna_navio_bot]==1 || navios_bot[linha_navio_bot][coluna_navio_bot+1]==1 || navios_bot[linha_navio_bot][coluna_navio_bot+2]==1);
	navios_bot[linha_navio_bot][coluna_navio_bot]=1;
	navios_bot[linha_navio_bot][coluna_navio_bot+1]=1;
	navios_bot[linha_navio_bot][coluna_navio_bot+2]=1;
	tabuleiro(10, 'K', 10, 10);
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

char verifica_casa(int i, int j, int player){
	if(player==1){
		if(navios_bot[i][j]==1){
			return 'x';
		}
		else{
			return 'a';
		}
	}
	if(player==2){
		if(navios_jogador[i][j]==1){
			return 'x';
		}
		else{
			return 'a';
		}
	}
}

int verifica_vitoria(){
	int soma_pontos=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			soma_pontos+=navios_bot[i][j];
		}
	}
	if(soma_pontos==14){
		return 1;
	}
	soma_pontos=0;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			soma_pontos+=navios_jogador[i][j];
		}
	}
	if(soma_pontos==14){
		return 2;
	}
	else{
		return 3;
	}
}