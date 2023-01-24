/*********************************************************************************************
7. Elabore um programa que lê valores inteiros para uma matriz M[5][5]. Localize, a seguir, os
valores repetidos, substituindo-os pelo valor –1. Escrever a matriz lida, a matriz resultante
(sem os valores –1) e quantos valores repetidos foram localizados.
**********************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>
 #include<time.h>
 #include<math.h>
 #include<ctype.h>
 #include<conio.h>

 //! função para identificar se um número X aparece mais de uma vez em uma matriz Y
 int repeticoes (int matriz[5][5], int numero, int qtd_repeticoes);

 int main ()
{
  setlocale(LC_ALL,"");

  int M[5][5]={  0, 1, 0, 2, 0,
                 3, 0, 4, 0, 5,
                 0, 6, 0, 7, 0,
                 8, 0, 9, 0,10,
                 0,11, 0,12, 0 };

 int i,j; //variáveis do laço
 int qtd; //quantidade de números repetidos

 //! EXIBINDO A MATRIZ

 printf("Matriz lida: \n");

  for(i=0;i<5;i++)
 {
     for(j=0;j<5;j++)
     {
       printf("%2d ",M[i][j]);
     }

  printf("\n");
 }



 //!IDENTIFICANDO OS Nºs REPETIDOS E TROCANDO POR -1

 for(i=0;i<5;i++)
 {
     for(j=0;j<5;j++)
     {
        repeticoes(M,M[i][j],qtd);
     }

 }



 //!EXIBINDO A MATRIZ COM OS VALORES REPETIDOS= -1

 printf("\nMatriz com os valores repetidos igual a -1: \n");

   for(i=0;i<5;i++)
 {
     for(j=0;j<5;j++)
     {
       printf("%2d ",M[i][j]);
     }

  printf("\n");
 }

 //!EXIBINDO A MATRIZ SEM OS VALORES "-1"

  printf("\nMatriz sem os valores -1:\n");

  for(i=0;i<5;i++)
 {
     for(j=0;j<5;j++)
     {
       if(M[i][j]!=-1)
        printf("%2d ",M[i][j]);
       else
        printf("   ");
     }

  printf("\n");
 }


  printf("\n");
  system("pause");
}



 int repeticoes (int matriz[5][5], int numero, int qtd_repeticoes)
 {
   int x,y;
   int repeticao=0;

//! percorre a matriz e soma 1 a variavel 'repeticao' a cada vez que o numero aparece

   for(x=0;x<5;x++)
   {
       for(y=0;y<5;y++)
       {
         if(numero==matriz[x][y])
            repeticao++;
       }
   }

   if(repeticao>1) //! se o número aparece mais de uma vez (é repetido)
   {
   //! soma dois a qtd de nºs repetidos, percorre a matriz e troca o valor repetido por -1

    qtd_repeticoes+=2;

       for(x=0;x<5;x++)
      {
         for(y=0;y<5;y++)
        {
           if(numero==matriz[x][y])
             matriz[x][y]=-1;
        }
      }
   }

}
