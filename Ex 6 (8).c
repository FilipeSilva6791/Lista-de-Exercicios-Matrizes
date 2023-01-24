/*********************************************************************************************
 6. Elabore um programa que lê valores inteiros para uma matriz M[5][5]. Crie, a seguir, dois
 vetores SL[5] e SC[5] que armazenarão o somatório dos elementos das linhas e das colunas
 da matriz M. Escrever a matriz lida e os vetores

 ********************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>
 #include<time.h>
 #include<math.h>
 #include<ctype.h>
 #include<conio.h>

 int main ()
{
  setlocale(LC_ALL,"");

  int M[5][5]={  0, 1, 2, 3, 4,
                 5, 6, 7, 8, 9,
                10,11,12,13,14,
                15,16,17,18,19,
                20,21,22,23,24 };

  int SL[5]={};   //vetor para soma das linhas
  int SC[5]={};   //vetor para soma das colunas

  int i,j;     //variáveis dos laços

//! FAZENDO OS CÁLCULOS

  for(i=0;i<5;i++)
  {
      for(j=0;j<5;j++)
      {
         SL[i]+= M[i][j]; //soma toda a linha em uma posição e depois troca de posição
         SC[j]+= M[i][j]; //percoorre a linha junto com a matriz, somando os elementos da coluna na posição 1 do vetor
      }                  //e as outras da mesma forma
  }

//!EXIBINDO A MATRIZ

  printf("Matriz: \n\n");

  for(i=0;i<5;i++)
  {
      for(j=0;j<5;j++)
      {
         printf("%2d ",M[i][j]);
      }
    printf("\n");
  }

//!EXIBINDO OS VALORES DAS SOMAS

  printf("\nValores das somas: \n");

  for(i=0;i<5;i++)
    printf("linha %d: %d \n",i+1,SL[i]);

  for(i=0;i<5;i++)
    printf("coluna %d: %d \n",i+1,SC[i]);



  printf("\n");
  system("pause");
}
