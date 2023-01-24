/****************************************************************************************************
 10. Elaborar um programa que leia a ordem de uma matriz quadrada (mínimo de 3 e máximo de 10)
 e leia valores inteiros e positivos para ela (pode utilizar a função aleatório). Após a leitura
 dos valores desta matriz, escrever na tela de maneira centralizada um menu de opções:
 a. Diagonal principal (DP)
 b. Diagonal secundária (DS)
 c. Elementos acima das diagonais
 d. Elementos abaixo das diagonais
 e. Elementos acima da DP e abaixo da DS
 f. Elementos abaixo da DP e acima da DS
 g. Todos os elementos da matriz
 h. Sair do programa
 Para cada uma destas opções, apresentar a soma dos elementos conforme a opção
 selecionada.
 Após o cálculo, escrever a matriz, a soma correspondente e voltar ao menu para selecionar
 uma nova opção. O algoritmo deve ser encerrado quando a opção for 8.
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
    srand(time(NULL));        //alimentando a funcção rand com o tempo docomputador

    char opcao=0;             //armazena a opcao do usuario
    int  controlador;         //variavel de apoio
    int i,j;                  //variaveis do laço
    int matriz[var][var];
    int soma;                 //armazena o valor que o usuário desejar somar


    //!PREENCHENDO A MATRIZ COM NÚMEROS ALEATÓRIOS
    for(i=0;i<var;i++)
    {
        for(j=0;j<var;j++)
        matriz[i][j]=rand()%99;
    }


    //!MENU DE OPÇÕES

    do
    {

        printf("\nMatriz : \n");

        for(i=0;i<var;i++)
       {
        for(j=0;j<var;j++)
        printf("%2d ",matriz[i][j]);

        printf("\n");
       }

        printf("\n**************** MENU DE OPÇÕES *******************\n\n");
        printf("a. Diagonal Principal (DP)\n");
        printf("b. Diagonal Secundária (DS)\n");
        printf("c. Elementos acima das diagonais\n");
        printf("d. Elementos abaixo das diagonais\n");
        printf("e. Elementos acima da DP e abaixo da DS\n");
        printf("f. Elementos abaixo da DP e acima da DS\n");
        printf("g. Todos os elementos da matriz\n");
        printf("h. Sair do programa\n");
        printf("\nPara cada uma destas opções, o programa apresentará \na soma dos elementos conforme a opção selecionada.\n");

        printf("\nDigite sua opção: ");
        fflush(stdin);
        opcao=getche();

        //!corrigindo se o usuário digitar maiusculo

        if(opcao<'a')
        opcao+=('a'-'A');

        //!fazendo a soma de acordo com a opção do usuário

        soma=0;

        switch(opcao)
        {

                case 'a':

                for(i=0;i<var;i++)
                soma+=matriz[i][i]; //só percorre os valores onde a linha e a coluna tem o mesmo índice
                                    //+--> (Diagonal Principal)
                break;



                case 'b':

                for(i=0;i<var;i++)
                soma+=matriz[i][var-1-i]; //percorre as linhas em ordem crescente, e passa em apenas uma coluna por linha
                                        //de forma decrescente (diagonal secundária)
                break;



                case 'c':


                for(i=0;i<var;i++)
                {
                    if(i<(var-1-i))                     //Só executa até uma linha antes das diagonais se cruzarem
                    {                                    // +---> quando (var-1-i)=i, as diagonais se cruzam
                        for(j=(i+1);j<(var-1-i);j++)      //vai estreitando o intervalo do laço
                        soma+=matriz[i][j];
                    }
                }

                break;



                case 'd':

                for(i=0;i<var;i++)
                {
                    if(i>(var-1-i))                    //Só executa a partir da linha onde as diagonais se cruzam
                    {                                   // +---> quando (var-1-i)=i, as diagonais se cruzam
                        for(j=(var-i);j<=(i-1);j++)     //vai abrindo o intervalo do laço
                        soma+=matriz[i][j];
                    }
                }

                break;



                case 'e':

                /** ideia:
                    o laço percorre a matriz pela diagonal principal (já começando A PARTIR da metade dela)

                    no caso da matriz ser de ordem par:

                    soma os dois valores que estão nas duas linhas acima do primeiro valor que estaremos (coluna é a mesma ) e o laço pode passar para o proximo valor da diagonal
                    dai soma os valores das 4 linhas acima (coluna na mesma posição) e assim por diante (adicionando 2), até chegar no fim da diagonal.

                    no caso da matriz ser de ordem impar:

                    o que vai mudar é que quando estivermos na posicao que definimos como inicial, precisaremos somar apenas um valor acima, e não dois.
                    (quantos valores acima serão somados depende da variavel "controlador").

                */

                if(var %2 ==0) //se a matriz for de ordem par
                {
                    controlador=2;  //delimita até qual linha o programa terá que voltar para somar os valores acima da diagonal principal



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
                a ideia desta parte do código é igual a do caso 'e', com excessão de que, aqui iremos percorrer a diagonal secundária
                e não a principaL.
                */

                if(var %2 ==0) //se a matriz for de ordem par
                {
                    controlador=2;  //delimita até qual linha o programa terá que voltar para somar os valores acima da diagonal principal



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
                printf("\n\nVocê digitou uma opção inexistente, digite novamente.");
                break;

        }

        if(opcao >= 'a' && opcao <= 'g')
        printf("\n\nsoma: %d",soma);


        char controle=0;
        printf("\n\nTecle enter para continuar.");

        while(controle!='\n')
        controle=getchar();

        system("cls"); //limpa toda a tela

    }while(opcao!='h');  //enquanto o usuario não escolher sair do programa ele roda todo o laço novamente


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
