/****************************************************************************************
 2. Elabore um programa que lê valores inteiros para uma matriz a[6][6]. Ordene, a seguir,
   os valores da matriz, de forma que o menor valor esteja armazenado na primeira posição
   da matriz e o maior na última. Escreva a matriz ordenada.
 ****************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>

 int main ()
 {
  int i,j; //variaveis do laço
  int var; //variavel usada para trocas
  int matriz[6][6]= { 12,13,10,80,95,07,    //inicializando a matriz com valores aleatórios
                      04,05,01,11,88,03,
                      75,84,65,32,15,79,
                      54,65,31,97,12,14,
                      04,06,78,54,36,87,
                      45,25,61,89,78,14, };

  printf("Matriz [6][6]: \n");

  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
     printf("%2d ", matriz[i][j]);
    }
  printf("\n");

  }

  for (i=0;i<6;i++) //percorrendo as linhas da matriz
  {
    for (j=0;j<6;j++) //percorrendo as colunas da matriz
    {
      if(matriz[0][0]>matriz[i][j]) //se o valor que o laco esta lendo for menor que o primeiro valor da matriz-
      {                             //então trocaremos os valores de posição.
        var = matriz[i][j];              // joga na variavel var o valor sendo lido no momento
        matriz[i][j] = matriz[0][0] ;    //joga neste valor, o valor presente na posição zero
        matriz[0][0]= var;               //pega o valor 0 e atribui ao valor da variavel var
      }

      if(matriz[5][5]<matriz[i][j]) // se o valor que o laço esta lendo for MAIOR que o ultimo valor da matriz...
      {
        var = matriz[i][j];
        matriz[i][j] = matriz[5][5];
        matriz[5][5] = var;
      }
    }
  }

  printf("\nMatriz com os valores ordenados: \n");

  for(i=0;i<6;i++)
  {
    for(j=0;j<6;j++)
    {
     printf("%2d ", matriz[i][j]);
    }
   printf("\n");

  }

  printf("\n");
  system("pause");

  }
