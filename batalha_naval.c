#include <stdio.h>
#include <stdlib.h>

int main(){
	char tabuleiro_jogador[10][10];
	char coluna;
	int i, j, linha;
	printf("   A  B  C  D  E  F  G  H  I  J\n");
	for(i=0; i<10; i++){
		if(i<9){
			printf("%d ", i+1);
		}
		else{
			printf("%d", i+1);
		}
		for(j=0; j<10; j++){
			tabuleiro_jogador[i][j]='-';
			printf(" %c ", tabuleiro_jogador[i][j]);
			if(j==9){
				printf("\n");
			}
		}
	}
	printf("Linha: ");
	scanf("%d", &linha);
	printf("Coluna: ");
	scanf("%c", &coluna);
	return 0;
}
int posiciona_navio(){
	
}
int jogada(int linha, char coluna){
	int numero_coluna;
	switch(coluna){
		case "A": numero_coluna=0;
			break;
		case "B": numero_coluna=1;
			break;
		case "C": numero_coluna=2;
			break;
		case "D": numero_coluna=3;
			break;
		case "E": numero_coluna=4;
			break;
		case "F": numero_coluna=5;
			break;
		case "G": numero_coluna=6;
			break;
		case "H": numero_coluna=7;
			break;
		case "I": numero_coluna=8;
			break;
		case "J": numero_coluna=9;
			break;
	}
	tabuleiro_jogador[linha][numero_coluna]=A;
}
int verifica_casa(){

}
int verifica_vitória(){

}
