/****************************************************************************************************
 10. Elaborar um programa que leia a ordem de uma matriz quadrada (m�nimo de 3 e m�ximo de 10)
 e leia valores inteiros e positivos para ela (pode utilizar a fun��o aleat�rio). Ap�s a leitura
 dos valores desta matriz, escrever na tela de maneira centralizada um menu de op��es:
 a. Diagonal principal (DP)
 b. Diagonal secund�ria (DS)
 c. Elementos acima das diagonais
 d. Elementos abaixo das diagonais
 e. Elementos acima da DP e abaixo da DS
 f. Elementos abaixo da DP e acima da DS
 g. Todos os elementos da matriz
 h. Sair do programa
 Para cada uma destas op��es, apresentar a soma dos elementos conforme a op��o
 selecionada.
 Ap�s o c�lculo, escrever a matriz, a soma correspondente e voltar ao menu para selecionar
 uma nova op��o. O algoritmo deve ser encerrado quando a op��o for 8.
 ***************************************************************************************************/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<locale.h>
 #include<time.h>
 #include<math.h>
 #include<ctype.h>
 #include<conio.h>

 #define var 4

 int main ()
{
    setlocale(LC_ALL,"");     //configurando os caracteres da lingua portuguesa
    srand(time(NULL));        //alimentando a func��o rand com o tempo docomputador

    char opcao=0;             //armazena a opcao do usuario
    int  controlador;         //variavel de apoio
    int i,j;                  //variaveis do la�o
    int matriz[var][var];
    int soma;                 //armazena o valor que o usu�rio desejar somar


    //!PREENCHENDO A MATRIZ COM N�MEROS ALEAT�RIOS
    for(i=0;i<var;i++)
    {
        for(j=0;j<var;j++)
        matriz[i][j]=rand()%99;
    }


    //!MENU DE OP��ES

    do
    {

        printf("\nMatriz : \n");

        for(i=0;i<var;i++)
       {
        for(j=0;j<var;j++)
        printf("%2d ",matriz[i][j]);

        printf("\n");
       }

        printf("\n**************** MENU DE OP��ES *******************\n\n");
        printf("a. Diagonal Principal (DP)\n");
        printf("b. Diagonal Secund�ria (DS)\n");
        printf("c. Elementos acima das diagonais\n");
        printf("d. Elementos abaixo das diagonais\n");
        printf("e. Elementos acima da DP e abaixo da DS\n");
        printf("f. Elementos abaixo da DP e acima da DS\n");
        printf("g. Todos os elementos da matriz\n");
        printf("h. Sair do programa\n");
        printf("\nPara cada uma destas op��es, o programa apresentar� \na soma dos elementos conforme a op��o selecionada.\n");

        printf("\nDigite sua op��o: ");
        fflush(stdin);
        opcao=getche();

        //!corrigindo se o usu�rio digitar maiusculo

        if(opcao<'a')
        opcao+=('a'-'A');

        //!fazendo a soma de acordo com a op��o do usu�rio

        soma=0;

        switch(opcao)
        {

                case 'a':

                for(i=0;i<var;i++)
                soma+=matriz[i][i]; //s� percorre os valores onde a linha e a coluna tem o mesmo �ndice
                                    //+--> (Diagonal Principal)
                break;



                case 'b':

                for(i=0;i<var;i++)
                soma+=matriz[i][var-1-i]; //percorre as linhas em ordem crescente, e passa em apenas uma coluna por linha
                                        //de forma decrescente (diagonal secund�ria)
                break;



                case 'c':


                for(i=0;i<var;i++)
                {
                    if(i<(var-1-i))                     //S� executa at� uma linha antes das diagonais se cruzarem
                    {                                    // +---> quando (var-1-i)=i, as diagonais se cruzam
                        for(j=(i+1);j<(var-1-i);j++)      //vai estreitando o intervalo do la�o
                        soma+=matriz[i][j];
                    }
                }

                break;



                case 'd':

                for(i=0;i<var;i++)
                {
                    if(i>(var-1-i))                    //S� executa a partir da linha onde as diagonais se cruzam
                    {                                   // +---> quando (var-1-i)=i, as diagonais se cruzam
                        for(j=(var-i);j<=(i-1);j++)     //vai abrindo o intervalo do la�o
                        soma+=matriz[i][j];
                    }
                }

                break;



                case 'e':

                /** ideia:
                    o la�o percorre a matriz pela diagonal principal (j� come�ando A PARTIR da metade dela)

                    no caso da matriz ser de ordem par:

                    soma os dois valores que est�o nas duas linhas acima do primeiro valor que estaremos (coluna � a mesma ) e o la�o pode passar para o proximo valor da diagonal
                    dai soma os valores das 4 linhas acima (coluna na mesma posi��o) e assim por diante (adicionando 2), at� chegar no fim da diagonal.

                    no caso da matriz ser de ordem impar:

                    o que vai mudar � que quando estivermos na posicao que definimos como inicial, precisaremos somar apenas um valor acima, e n�o dois.
                    (quantos valores acima ser�o somados depende da variavel "controlador").

                */

                if(var %2 ==0) //se a matriz for de ordem par
                {
                    controlador=2;  //delimita at� qual linha o programa ter� que voltar para somar os valores acima da diagonal principal



                    for(i=((var/2)+1); i<var; i++) //ajustando para matriz comecar onde os valores que queremos somar fiquem em cima da diagonal principal
                    {
                        for(j=1; j<=controlador; j++)
                           soma+= matriz[i-j][i];

                         controlador+=2;
                    }

                } else {

                    controlador=1;

                    for(i=((var/2)+1); i<var; i++) //ajustando para matriz comecar onde os valores que queremos somar fiquem em cima da diagonal principal
                    {
                        for(j=1; j<=controlador; j++)
                           soma+= matriz[i-j][i];

                         controlador+=2;
                    }
                }

                break;


                case 'f':
                /**
                Ideia:
                a ideia desta parte do c�digo � igual a do caso 'e', com excess�o de que, aqui iremos percorrer a diagonal secund�ria
                e n�o a principaL.
                */

                if(var %2 ==0) //se a matriz for de ordem par
                {
                    controlador=2;  //delimita at� qual linha o programa ter� que voltar para somar os valores acima da diagonal principal



                    for(i=((var/2)+1); i<var; i++) //ajustando para matriz comecar onde os valores que queremos somar fiquem em cima da diagonal principal
                    {
                        for(j=1; j<=controlador; j++)
                           soma+= matriz[i-j][var-i-1];

                         controlador+=2;
                    }

                } else {

                    controlador=1;

                    for(i=((var/2)+1); i<var; i++) //ajustando para matriz comecar onde os valores que queremos somar fiquem em cima da diagonal principal
                    {
                        for(j=1; j<=controlador; j++)
                           soma+= matriz[i-j][var-i-1];

                         controlador+=2;
                    }
                }

                break;


                case 'g':

                //apenas percorre a matriz e soma os valores a variavel soma
                for(i=0;i<var; i++)
                {
                    for(j=0; j<var; j++)
                    soma+=matriz[i][j];
                }

                break;


                case 'h':
                break;

                default:
                printf("\n\nVoc� digitou uma op��o inexistente, digite novamente.");
                break;

        }

        if(opcao >= 'a' && opcao <= 'g')
        printf("\n\nsoma: %d",soma);


        char controle=0;
        printf("\n\nTecle enter para continuar.");

        while(controle!='\n')
        controle=getchar();

        system("cls"); //limpa toda a tela

    }while(opcao!='h');  //enquanto o usuario n�o escolher sair do programa ele roda todo o la�o novamente


//    printf("\n\n");
//
//    for(i=1;i<(var-1);i++)
//   {
//      for(j=1;j>0;j++)
//      {
//          if(i<(var-i-1))
//         {
//               ++j;
//               printf("%d ",matriz[i][j]);
//
//         }else{
//
//              j--;
//               printf("%d ",matriz[i][j]);
//         }
//
//      }
//    }
//     printf("\n");


}
