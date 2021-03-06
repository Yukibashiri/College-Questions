// Derivative of a polynomial
#include <stdio.h>              //
#include <stdlib.h>             //
#include <locale.h>             // bibliotecas utilizadas.
#include <math.h>               //
int main (void)
{
     setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    printf ("CASE:\nTECNOLOGIA: PARA DADOS, MATERIAIS E PROCESSOS\n");
    printf ("\n Professor: José Wilson Silva Costa");
    printf ("\n Aluno: Mario Damião Caparroz Remistico Junior\n");
    printf ("\n\n\n\n--------------Pressione qualquer tecla para começar o programa---------------");
    getch();
    system("cls");
     int grau,contador=0;
     printf ("\nInforme o valor do polinomio de maior grau:  "); // Mensagem mostrada ao usuario, assim ele entenderá o que é para fazer.
     scanf ("%d",&grau);             // guarda o valor fornecio pelo usuario.
     int exp[grau],coe[grau],res[grau];
     char operacao[grau];
     do{
        exp[contador] = (grau - contador); // Ira derivar o grau de 1 em 1 até ter o valor de todos os polinomios.
        (contador = contador + 1);     // poderia ser utilizado contador++, mas para facilitar o entendimento contador receberá ele mesmo mais 1.
     }
     while (contador <= grau);       //quando contador chegar a um numero maior que o grau ele sairá do laço.
     contador = 0;                   // Resete do contador para que não seja necessario a criação de outra variavel.
     do{
        system("cls");
            if (contador < grau){
                printf ("\nInforme a operação do monomio x^%d (se é negativo ou positivo). \n + = soma.\n - = subtração.\n Qualquer outro valor será entendido como soma.\n Digite:  ",exp[contador]);
                fflush(stdin);      // Limpa a entrada para não salvar o dado errado.
                scanf ("%s",&operacao[contador]); //Pedirá ao usuario a operação do polinomio podendo ser apenas subtracao ou soma.
                printf (" \n\nInforme o coeficiente do monomio [_].x^%d. :  ",exp[contador]); // Mensagem mostrada ao usuario solicitando o coeficinete do monomio, a %d ali ira mostrar o expoente já armazenado.
                scanf ("%d",&coe[contador]);
            }
            else {
                    printf ("\nInforme a operação da Constante (se é negativo ou positivo). \n + = soma.\n - = subtração.\n Qualquer outro valor será entendido como soma.\n Digite:  ");
                scanf ("%s",&operacao[contador]); //Pedirá ao usuario a operação da constante podendo ser apenas subtracao ou soma.
                printf (" \n\nInforme a constante. :  "); // Mensagem mostrada ao usuario solicitando a constante.
                scanf ("%d",&coe[contador]);
                printf ("\n%s",operacao);

            }
        contador = (contador + 1);     // mesma função utiliza anteriormente.
      }
     while (contador <= grau);      // Fim do segundo laço.
     contador = 0;                  // Resete do contador, pois sera utilizado novamente.
     system("cls");
     do{                            // Nesse laço ira arrumar as operações caso o usario tenha digitado errado.
        if  (operacao[contador] == '-' ){ //se a operacao for diferente ira receber o simbolo da soma.
            operacao[contador] = ('-');
            }
        else{
            operacao[contador] = ('+');
        }
        contador = (contador+1);
     }
     while (contador <= grau);
     contador = 0;                  // Ainda usaremos o contador, então ele sera resetado novamente.
     printf ("\n Reescrevendo: f(x):  ");
     do{
        if (exp[contador] > 0){       // Ele ira escrever o polinomio completo para o usuario ler.
                if ((contador == 0) && (operacao[contador] == '+')){  //quando o monomio de maior grau for positivo ele escondera o sinal
                    printf ("%d.x^%d ",coe[contador],exp[contador]);
                }
                else{
                    printf ("%c %d.x^%d ",operacao[contador],coe[contador],exp[contador]);
                }
        }
        else{
            printf("%c %d.\n",operacao[contador],coe[contador]);
        }
        contador = (contador + 1);
       }
    while (contador <= grau);
    contador = 0;                                        //Contador resetado novamente.
    printf ("\nPressione Enter para derivar.\n");
    getch();
    do{                                                    //Laço da derivada
        coe[contador] = (coe[contador] * exp[contador]);  // coeficiente x expoente.
        exp[contador] = (exp[contador] -1);                  // expoente - 1.
        contador = (contador + 1);
    }
    while (contador <= grau);
    contador = 0;                                           // mais um resete.
    printf ("\n     Derivado:  f'(x):  ");
    do{
        if (exp[contador] > 0){       // Ele ira escrever o polinomio completo para o usuario ler, só que agora derivado.
                if (operacao[contador] == '+'&& contador == 0){  //quando o monomio de maior grau for positivo ele escondera o sinal
                    printf ("%d.x^%d ",coe[contador],exp[contador]);
                }
                else{
                    printf ("%c %d.x^%d ",operacao[contador],coe[contador],exp[contador]); // depois do primeiro ele sempre irá colocar os sinais
                }
        }
        else{
            printf("%c %d ",operacao[contador],coe[contador]); // Quando o exp registrado for menor ou igual a zero ele vira para ca.
        }
        contador = (contador + 1);
       }
    while (contador <= grau);
    int decisao;                // variavel criada para guardar 3 caracteres, sera utilizado para guardar a resposta do usuario sobre a continuidade do alg.
    printf ("\n\n Gostaria de aplicar o valor de X?\n Escreva 1 - sim ou 2 - nao:  ");
    fflush(stdin);
    scanf ("%d",&decisao);
    if (decisao == 1){
        system("cls");
        int x;                      // Criar a variavel para guardar o valor X.
        printf ("Insira o valor de X:  ");
        scanf ("%d",&x);
        contador = 0;                   // Mais um resete no nosso contador.
        do{
            if (exp[contador] > 0){       // Ele ira escrever o polinomio completo para o usuario ler, só que agora derivado.
                    if (operacao[contador] == '+'&& contador == 0){  //quando o monomio de maior grau for positivo ele escondera o sinal
                        printf ("%d.%d^%d ",coe[contador],x,exp[contador]);
                    }
                    else{
                        printf ("%c %d.%d^%d ",operacao[contador],coe[contador],x,exp[contador]); // depois do primeiro ele sempre irá colocar os sinais
                    }
            }
            else{
                printf("%c %d ",operacao[contador],coe[contador]); // Quando o exp registrado for menor ou igual a zero ele vira para ca.
            }
            contador = (contador + 1);
        }
       while (contador <= grau);
       contador = 0;                    // OK Agora definitivamente é a ultima vez (eu acho).
       int resfinal=0;                   // uma variavel para o resultado final.
       do{
            if (exp[contador] >= 0){    // ele não utilizara os expoentes menores que zero.
                res[contador] = (pow(x,exp[contador])); // X que é nossa variavel elevado a exp[contador], essa função é parte da biblioteca math.h
                res[contador] = (res[contador] * coe[contador]);// Essa conta poderia ter sido feita na linha de cima, mas dividi para facil entendimento.
            }
            contador = contador + 1;
       }
       while (contador <= grau);
       contador = 0;                            // Ultimo resete.
       do{
            if (exp[contador] >= 0){            // Dessa forma ele não utilizara os expoentes negativos.
                if (operacao[contador] == '+' ){           // Processo da soma e subtração começa.
                    resfinal = (resfinal + res[contador]);
                }
                else{
                    resfinal = (resfinal - res[contador]);
                }
            }
            contador = contador + 1;
       }
       while (contador <= grau);
       printf ("\n\n O resultado é: f'(%d): %d\n\n",x,resfinal);   // Mostra o resultado final ao usuario.
    }
return 0;
}
