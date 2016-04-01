
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// FUNÇÃO QUE MOSTRA O TABULEIRO (SENDO AS PERMISSÕES OU MOVIMENTOS)
void fun_tabuleiro(int movimento[8][8]){
    int i,j;
    printf ("\n\n\n  0 1 2 3 4 5 6 7 ");
    for (i=0;i<8;i++){
        printf ("\n%d ",i);
        for (j=0;j<8;j++){
            switch (movimento[i][j]){
                case 1:
                    printf ("p ");
                    break;
                case 2:
                    printf ("b ");
                    break;
                case 3:
                    printf ("P ");
                    break;
                case 4:
                    printf ("Q ");
                    break;
                default:
                    printf ("  ");
                    break;
            }
        }
    }
}

int fun_movimentacao (int peca){
    int opcao;
    switch (peca){
        case 1:
        case 2:
            do{
            printf ("Desejas mover a peça para esquerda(1) ou para direita(2)? ");
            scanf ("%d",&opcao);
        }while (opcao!= 1 && opcao !=2);
        break;
        case 3:
        case 4:
            do{
                printf ("Desejas mover a peça para cima(1) ou para baixo(2)? ");
                scanf ("%d",&opcao);
            }while (opcao!= 1 && opcao !=2);
            break;
    }
    return opcao;
}


int main (){
    setlocale (LC_ALL,"Portuguese");
    char tabuleiro[8][8];
    int movimento[8][8]= {'0'};
    int i,j,linha,coluna,aux=1,decisao,direcao;
    char bloco = 'X';
    for (j=0;j<8;j++){
        for (i=0;i<8;i++){
            if (bloco == 'X'){
                tabuleiro[i][j] = ' ';
                bloco = ' ';
            }
            else{
                tabuleiro[i][j] = 'X';
                bloco = 'X';
            }
        }
        if (bloco == 'X'){
            bloco = ' ';
        }
        else{
            bloco = 'X';
        }
    }
    //fun_tabuleiro(tabuleiro);
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if ((i<3) && (aux % 2 == 0)){
                movimento[i][j] = 1;
            }
            else if ((i>4)&&(aux %2 == 0)){
                movimento[i][j] = 2;
            }
        aux++;
        }
        aux++;
    }
    decisao =0;
    do{
        fun_tabuleiro(movimento);
        printf ("\n\n\nInforme a linha da peça que desejas mover: ");
        scanf ("%d",&linha);
        printf ("e a coluna dessa mesma peça:  ");
        scanf ("%d",&coluna);
        decisao = fun_movimentacao(movimento[linha][coluna]);
        switch(movimento[linha][coluna]){
        case 1:
            if (decisao == 1){
                i = linha + 1;
                j = coluna -1;
            }
            else{
               i = linha +1;
               j = coluna +1;
            }
            if ((movimento[i][j] == 1) || i <0 || (j <0 || j >7)){
                system("cls");
                printf ("\n\nErro!! A Peça não pode sair do tabuleiro ou sobrepor uma peça de mesma cor.\nTente outra jogada.\n");
            }
            else{
                movimento[linha][coluna] = 0;
                movimento[i][j] = 1;
            }
            break;
        case 2:
            if (decisao == 1){
                i = linha - 1;
                j = coluna -1;
            }
            else{
               i = linha -1;
               j = coluna +1;
            }
            if ((movimento[i][j] == 2) || i <0 || (j <0 || j >7)){
                system("cls");
                printf ("\n\nErro!! A Peça não pode sair do tabuleiro ou sobrepor uma peça de mesma cor.\nTente outra jogada.\n");
            }
            else{
                movimento[linha][coluna] = 0;
                movimento[i][j] = 2;
            }
            break;
        case 3:
            printf ("\n Quantas casas(linhas) deseja ");
            if (decisao == 1){
                printf ("Subir ? ");
            }else{
                printf ("Descer ? ");
            }
            scanf ("%d",&aux);
            printf ("\nPela esquerda<1> ou pela direita<2>? ");
            scanf ("%d",&direcao);
            if(direcao == 1){
                i = linha - (1*aux);
                j = coluna -(1*aux);
            }
            else{
               i = linha +1*aux;
               j = coluna +1*aux;
            }
            if ((movimento[i][j] == 1 ||movimento[i][j] == 3) || i <0 || (j <0 || j >7)){
                system("cls");
                printf ("\n\nErro!! A Peça não pode sair do tabuleiro ou sobrepor uma peça de mesma cor.\nTente outra jogada.\n");
            }
            else{
                movimento[linha][coluna] = 0;
                movimento[i][j] = 3;
            }
            break;
        case 4:
            break;
        default:
            printf ("\nVocê selecionou um espaço vazio\n");
            break;
        }
        if (i == 7 && movimento[i][j] == 1){
            movimento[i][j] = 3;
        }
        else if (i == 0 && movimento[i][j] == 2){
            movimento[i][j] = 4;
        }
        printf ("Continuar? (1) Sim - (2) Não : ");
        scanf ("%d",&decisao);
        if (decisao !=1){
            decisao = 9999;
        }
        system("cls");
    }while(decisao != 9999);
}
