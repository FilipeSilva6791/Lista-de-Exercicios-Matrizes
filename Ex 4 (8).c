/**
 4. Faça um programa que leia uma matriz mat 2 x 5 de inteiros e imprima os
    elementos de mat na ordem inversa.
*/

#include<stdio.h>
#include<stdlib.h>

int main ()
{
  int i,j; //variaveis dos laços

  int mat[2][5]= {1,2,3,4,5,
                  6,7,8,9,10};

  printf("Matriz original:\n");

  for(i=0;i<2;i++)
  {
    for(j=0;j<5;j++)
    {
      printf("%2d ", mat[i][j]);
    }
   printf("\n");
  }

  printf("\nMatriz na ordem invertida:\n");

  for(i=1;i>=0;i--)
  {
    for(j=4;j>=0;j--)
    {
      printf("%2d ", mat[i][j]);
    }
   printf("\n");
  }


  printf("\n");
  system("pause");

}
