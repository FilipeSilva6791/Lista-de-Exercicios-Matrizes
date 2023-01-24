/**************************************************************
 9. Considerando uma matriz quadrada, identificar sua diagonal
    principal e sua diagonal secundária
 **************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>
 #include<time.h>
 #include<math.h>
 #include<ctype.h>
 #include<conio.h>

 #define var 5//tam. da matriz

 int main ()
{
    setlocale(LC_ALL,"");

//! declarando e inicializando a matriz e outras variáveis

   int matriz[var][var];

   srand(time(NULL)); //função que gera números pseudo-aleatórios a partir do tempo do computador

   int i,j; //variaveis do laço

   for(i=0;i<var;i++)
   {
       for(j=0;j<var;j++)
        matriz[i][j]=rand()%99; //preeenchendo a matriz com valores aleatórios (no intervalo de 0 a 99)

   }



//! exibindo a matriz inteira

   printf("Matriz quadrada %d x %d:\n",var,var);

   for(i=0;i<var;i++)
   {
       for(j=0;j<var;j++)
         printf("%2d ", matriz[i][j]);

     printf("\n");
   }


//! exibindo a diagonal principal

   printf("\nDiagonal principal:\n");

   for(i=0;i<var;i++)
      printf("%d ", matriz[i][i]); //só imprime valores onde o indice da coluna é igual
                                   //ao índice da linha, ou seja, a diagonal principal.

//! exibindo a diagonal secundaria

    printf("\n\nDiagonal secundária:\n");

    for(i=0;i<var;i++)
        printf("%d ", matriz[i][var-i-1]); //percorre e imprime apenas um valor de cada linha;
                                           //a coluna é definida de modo a pegar os valores
                                           //de trás para frente.


//! finalizando

    printf("\n\n");
    system("pause");


}
