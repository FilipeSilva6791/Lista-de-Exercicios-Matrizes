/********************************************************************************************
 8. Elabore um programa que l� valores inteiros para uma matriz a[6][6]. Embaralhe os valores
 da matriz da seguinte forma: os valores da coluna 1 s�o armazenados na coluna dois, os da 2
 s�o armazenados na 3 e assim por diante at� os valores da coluna 6 serem armazenados na
 coluna 1.Este procedimento deve ser realizado tr�s vezes. Ap�s, repita o procedimento das
 colunas para as linhas. Escreva a matriz lida e a resultante.
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

  int a[6][6]={ 1, 2, 3, 4, 5, 6,
                7, 8, 9,10,11,12,
               13,14,15,16,17,18,
               19,20,21,22,23,24,
               25,26,27,28,29,30,
               31,32,33,34,35,36, };

  int b[6];   //!vetor para auxiliar nas trocas
  int i,j,k;  //vari�veis dos la�os


//!EXIBINDO A MATRIZ LIDA

  printf("Matriz lida:\n");

  for(i=0;i<6;i++)
   {
      for(j=0;j<6;j++)
      {
          printf("%2d ", a[i][j]);
      }
      printf("\n");
   }


//!FAZENDO AS TROCAS DE COLUNA TR�S VEZES

  k=0;
  while(k<3)
{

   for(i=0;i<6;i++)
   {
    //passando os valores da linha para um vetor uma posi��o a frente
        for(j=0;j<6;j++)
        {
            if(j==5) //quando o la�o estiver no �ltimmo valor da linha
                b[0]=a[i][j]; //atribui o ultimo valor da linha ao primeiro valor do vetor
            else
                b[j+1]=a[i][j];
        }

     //passando os valores do vetor j� organizado de volta a linha da matriz
        for(j=0;j<6;j++)
            a[i][j]=b[j];
    }

   k++;
}


//!FAZENDO AS TROCAS DE LINHAS 3 VEZES

   k=0;

   while(k<3)
{
   for(i=0;i<6;i++) //i->indice da coluna
   {
        for(j=0;j<6;j++)//j->indice da linha
        {
           //!passando uma coluna inteira para o vetor b

           if(j==5)           //na ultima posi��o
                b[0]=a[5][i]; //passa o ultimo valor da coluna para a primeira posi��o do vetor
           else
                b[j+1]=a[j][i];
        }

       //! passando a coluna, j� organizada, de volta para a matriz

        for(j=0;j<6;j++)
            a[j][i]=b[j];
    }

    k++;
}

//!EXIBINDO A RESULTANTE

   printf("\nMatriz resultante:\n");

   for(i=0;i<6;i++)
{
      for(j=0;j<6;j++)
        printf("%2d ", a[i][j]);

   printf("\n");
}

  printf("\n");
  system("pause");
}
