#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coluna_navio=5, linha_navio=5, i, j;
char tabuleiro_jogador[10][10], tabuleiro_bot[10][10];

int tabuleiro(int linha, char coluna);
char verifica_casa(int i, int j);
int numero_coluna(char coluna);

int main(){
	int linha;
	char coluna;
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			tabuleiro_jogador[i][j]='-';
			tabuleiro_bot[i][j]='-';
		}
	}
	tabuleiro(10, 'K');
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
		tabuleiro(linha, coluna);
	}
}
int posiciona_navio(){
	srand(time(NULL));
	int navio_1[2]={rand()%9, rand()%9};
	int navio_2[2]={rand()%9, rand()%9};
	int navio_3[2]={rand()%9, rand()%9};
	int navio_4[2][2]={{rand()%9, rand()%8}};
	navio_4[1]={{navio_4[0][0], navio_4[1][0]+1}};
	int navio_5[2][2]={{rand()%9, rand()%8}};
	navio_5[1]={{navio_5[0][0], navio_5[1][0]+1}};
	int navio_6[2][2]={{rand()%9, rand()%8}};
	navio_6[1]={{navio_6[0][0], navio_6[1][0]+1}};

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
int tabuleiro(int linha, char coluna){
	tabuleiro_bot[linha][numero_coluna(coluna)]=verifica_casa(linha, numero_coluna(coluna));
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
	if(i==linha_navio && j==coluna_navio){
		return 'x';
	}
	else{
		return 'a';
	}
}
int verifica_vitoria(){
}
