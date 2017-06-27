#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include "conio.h"
#include "conio.c"

#define PlayerUm 1
#define PlayerDois 2
int PontuacaoPlayerUm=0, PontuacaoPlayerDois=0, turno, CasasLivres=9;
int Tabuleiro[3][3];

void ImprimeGrade(){
    printf("     1   2   3  \n");
    printf("   +---+---+---+\n");
    printf(" 1 |   |   |   |\n");
    printf("   +---+---+---+\n");
    printf(" 2 |   |   |   |\n");
    printf("   +---+---+---+\n");
    printf(" 3 |   |   |   |\n");
    printf("   +---+---+---+\n");
}

void ImprimePlacar(){
  	gotoxy(40, 0);
	printf("\n+-----------------+\n");
        printf("|  ");
        textbackground(RED);
        printf(" UM ");
        textbackground(BLACK);
        printf(" X ");
        textbackground(GREEN);
        printf(" DOIS ");
        textbackground(BLACK);
        printf("  |\n");
        printf("|   %02d      %02d    |\n",PontuacaoPlayerUm,PontuacaoPlayerDois);
        printf("+-----------------+\n");
}

void MarcarGrade(int * linha, int * coluna){
    gotoxy(5+(4*(*coluna-1)), 3+(2*(*linha-1)));
	if (turno == PlayerUm)
	{
  	  textbackground(RED);
   	  printf(" X ");
	}
	else {
       textbackground(GREEN);
 	   printf(" O ");
 	}
}

int Ganhador(){
	int Ganhador=0;

	// linha um
	if ((Tabuleiro[0][0] == Tabuleiro[0][1]) && (Tabuleiro[0][1] == Tabuleiro[0][2]) && (Tabuleiro[0][0] != 0))
      	  Ganhador=Tabuleiro[0][0];

    	// linha dois
	if ((Tabuleiro[1][0] == Tabuleiro[1][1]) && (Tabuleiro[1][1] == Tabuleiro[1][2]) && (Tabuleiro[1][0] != 0))
      	  Ganhador=Tabuleiro[1][0];

    	// linha tres
	if ((Tabuleiro[2][0] == Tabuleiro[2][1]) && (Tabuleiro[2][1] == Tabuleiro[2][2]) && (Tabuleiro[2][0] != 0))
      	  Ganhador=Tabuleiro[2][0];

    	// coluna um
	if ((Tabuleiro[0][0] == Tabuleiro[1][0]) && (Tabuleiro[1][0] == Tabuleiro[2][0]) && (Tabuleiro[0][0] != 0))
      	  Ganhador=Tabuleiro[0][0];

    	// coluna dois
	if ((Tabuleiro[0][1] == Tabuleiro[1][1]) && (Tabuleiro[1][1] == Tabuleiro[2][1]) && (Tabuleiro[0][1] != 0))
     	   Ganhador=Tabuleiro[0][1];

    	// coluna tres
	if ((Tabuleiro[0][2] == Tabuleiro[1][2]) && (Tabuleiro[1][2] == Tabuleiro[2][2]) && (Tabuleiro[0][2] != 0))
     	   Ganhador=Tabuleiro[0][2];

    	// diagonal esquerda para direita
	if ((Tabuleiro[0][0] == Tabuleiro[1][1]) && (Tabuleiro[1][1] == Tabuleiro[2][2]) && (Tabuleiro[0][0] != 0))
     	   Ganhador=Tabuleiro[0][0];

    	// diagonal direita para esquerda
	if ((Tabuleiro[2][0] == Tabuleiro[1][1]) && (Tabuleiro[1][1] == Tabuleiro[0][2]) && (Tabuleiro[2][0] != 0))
      	  Ganhador=Tabuleiro[0][2];

    if (Ganhador != 0){
        if (Ganhador==PlayerUm){
            gotoxy(0,13);
            textbackground(RED);
            PontuacaoPlayerUm++;
            printf("\n\nJogador UM venceu!");
        }
        else if (Ganhador==PlayerDois){
            gotoxy(0,13);
            textbackground(GREEN);
            PontuacaoPlayerDois++;
            printf("\n\nJogador DOIS venceu!!");
        }
	return 1;
    }
    else
        return 0;
}

void LimpaTextos()
{
	gotoxy(16, 13);
	textbackground(BLACK);
    printf("\n\n\n                                                                      ");
	printf("                                                                       ");
	printf("\n                                                                     ");
	printf("\n                                                                     ");
	printf("\n                                                                     ");
	printf("\n                                                                     ");
	printf("\n                                                                     ");
	printf("\n                                                                     ");
}

void PedirJogada(int * linha, int * coluna){
	LimpaTextos();
	gotoxy(16, 13);
	if (turno == PlayerUm)
	{
	  textbackground(RED);
	  printf("\n\n\n X ");
	  textbackground(BLACK);
	  printf("\nJogador UM, escolha uma Linha   ");
        scanf("%d",linha);
		if (!((*linha>=1) && (*linha<=3))){
            LimpaTextos();
            return PedirJogada(linha, coluna);
		}

	  printf("\n\nJogador UM, escolha uma Coluna   ");
        scanf("%d",coluna);
		if (!((*coluna>=1) && (*coluna<=3))) {
            LimpaTextos();
            return PedirJogada(linha, coluna);
		}
	}
	else {
	  textbackground(GREEN);
	  printf("\n\n\n O ");
	  textbackground(BLACK);
	  printf("\nJogador DOIS, escolha uma Linha   ");
        scanf("%d",linha);
		if (!((*linha>=1) && (*linha<=3))){
            LimpaTextos();
            return PedirJogada(linha, coluna);
		}

	  printf("\n\nJogador DOIS, escolha uma Coluna   ");
        scanf("%d",coluna);
		if (!((*coluna>=1) && (*coluna<=3))) {
            LimpaTextos();
            return PedirJogada(linha, coluna);
		}
	}
	LimpaTextos();
}

int main(){
int linha, coluna, verificador, i, j;

	while (1)
	{
	    linha = 0, coluna = 0, turno = 1, CasasLivres = 9;

		textbackground(BLACK);
		system("cls");
	    ImprimeGrade();
	    ImprimePlacar();

	    for (i=0;i<3;i++)
			for (j=0;j<3;j++)
				Tabuleiro[i][j]=0;

		do
		    {
		    do
			{
			verificador = 0;
			PedirJogada(&linha, &coluna);
				if (Tabuleiro[linha-1][coluna-1] != 0){
                    gotoxy(16, 13);
				    printf("\n\n\n\nCasa ja foi marcada! Escolha outra");
				    verificador = 1;
				    Sleep(3000);
				}
			} while (verificador == 1);
		    Tabuleiro[linha-1][coluna-1] = turno;
		    MarcarGrade(&linha, &coluna);
		    CasasLivres--;

				if (turno == 1)
					turno = 2;
				else
					turno = 1;

			if (Ganhador() == 1)
				CasasLivres = 0;
			else if (CasasLivres == 0)
			{
				gotoxy(3, 14);
				printf("Deu velha!");
			}
		} while (CasasLivres != 0);
	Sleep(5000);
	}
}
