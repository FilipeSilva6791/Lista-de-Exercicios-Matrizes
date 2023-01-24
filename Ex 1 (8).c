/********************************************************************************************
1. Elabore um programa que lê valores inteiros para uma matriz a[6][6]. Calcule, a seguir, a
   soma dos elementos das colunas e linhas, escrevendo estes resultados num vetor. Escreva o
   vetor resultante.
********************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<locale.h>


 int main ()
{
 setlocale(LC_ALL,"");

 int i,j; // variaveis dos laços
 int vetor[1]={};
 int matriz[6][6]= { 1,1,1,1,1,1,        //!inicializando a matriz
                     2,2,2,2,2,2,
                     3,3,3,3,3,3,
                     4,4,4,4,4,4,
                     5,5,5,5,5,5,
                     6,6,6,6,6,6, };

 for (i=0; i<6; i++) //percorre as linhas
  {
     for (j=0; j<6; j++) //percorre as colunas
     {
       vetor[0]+= matriz[i][j]; //soma cada valor da matriz ao vetor
     }

  }

  printf ("A soma de todos os elementos da matriz 6x6 representada a baixo é: %d \n", vetor[0]);

 for (i=0; i<6; i++)
 {
     for (j=0; j<6; j++)
     {
       printf("%d ",matriz[i][j]);
     }
  printf("\n");
 }

 system("pause");

}
