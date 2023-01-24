/***************************************************************************************
 3. Faça um programa que leia uma matriz mat 3 x 4 de inteiros, substitua seus elementos
    negativos por 0 e imprima a matriz mat original e a modificada.
 ***************************************************************************************/


 #include<stdio.h>
 #include<stdlib.h>


 int main ()
 {
   int i,j; //variaveis dos laços
   int mat[3][4]={ 1,-6,2,-5,
                   3,-4,4,-3,
                   5,-2,6,-1, };


   printf("Matriz original: \n");

   for(i=0;i<3;i++)
   {
     for(j=0;j<4;j++)
     {
       printf("%2d ",mat[i][j]);
     }
    printf("\n");
   }


   for(i=0;i<3;i++)
   {
     for(j=0;j<4;j++)
     {
       if(mat[i][j]<0) // se o valor for negtivo:
            mat[i][j]=0;
     }
   }


   printf("\nMatriz modificada: \n");
   for(i=0;i<3;i++)
   {
     for(j=0;j<4;j++)
     {
       printf("%2d ",mat[i][j]);
     }
    printf("\n");
   }

   printf("\n");
   system("pause");

 }
