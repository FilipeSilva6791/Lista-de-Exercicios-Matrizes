/**
 5. Na teoria dos sistemas, define-se como elemento minimax de uma matriz o menor elemento
    da linha onde se encontra o maior elemento da matriz. Elabore um programa que lê valores
    inteiros para uma matriz a[6][6] e escreve o seu minimax juntamente com sua posição.
*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>


int main ()
{

  setlocale(LC_ALL,"");

  int i,j; //variaveis de laço
  int a[6][6]= { 1,1,1,1,1,8,
                 1,1,1,1,8,1,
                 1,1,1,8,1,1,
                 1,1,8,1,1,1,
                 1,8,1,1,1,1,
                 8,1,1,1,1,1 };
  int minimax=0;
  int posicao[2];


  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
      printf("%2d ", a[i][j]);
    }
   printf("\n");
  }


  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
      if(a[i][j]>=minimax)
      {
        minimax= a[i][j];
        posicao[0]=i;
        posicao[1]=j;

        if(j<posicao[1])
        {
          posicao[0]=i;
          posicao[1]=j;
        }
      }
    }
  }


  printf("\nO minimax da matriz é: %d  e se encontra na posição [%d][%d] \n\n", minimax,posicao[0],posicao[1]);

  system("pause");
}
