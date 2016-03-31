#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// FUNÇÃO QUE MOSTRA O TABULEIRO (SENDO AS PERMISSÕES OU MOVIMENTOS)
void fun_tabuleiro(char movimento[8][8]){
    int i,j;
    printf ("\n\n\n  0 1 2 3 4 5 6 7 ");
    for (i=0;i<8;i++){
        printf ("\n%d ",i);
        for (j=0;j<8;j++){
            printf ("%c ",movimento[i][j]);
        }
    }
}


int main (){
    setlocale (LC_ALL,"Portuguese");
    char tabuleiro[8][8];
    char movimento[8][8]= {' '};
    int i,j,linha,coluna,aux=1,decisao;
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
                movimento[i][j] = 'P';
            }
            else if ((i>4)&&(aux %2 == 0)){
                movimento[i][j] = 'B';
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
        printf ("Desejas mover a peça para esquerda(1) ou para direita(2)? ");
        scanf ("%d",&decisao);
        switch(movimento[linha][coluna]){
        case 'P':
            if (decisao == 1){
                i = linha + 1;
                j = coluna -1;
            }
            else{
               i = linha +1;
               j = coluna +1;
            }
            if ((movimento[i][j] == 'P') || i <0 && (j <0 || j >7)){
                system("cls");
                printf ("\n\nErro!! A Peça não pode sair do tabuleiro ou sobrepor uma peça de mesma cor.\nTente outra jogada.\n");
            }
            else{
                movimento[linha][coluna] = ' ';
                movimento[i][j] = 'P';
            }
            break;
        case 'B':
            if (decisao == 1){
                i = linha - 1;
                j = coluna -1;
            }
            else{
               i = linha -1;
               j = coluna +1;
            }
            if ((movimento[i][j] == 'B') || i <0 && (j <0 || j >7)){
                system("cls");
                printf ("\n\nErro!! A Peça não pode sair do tabuleiro ou sobrepor uma peça de mesma cor.\nTente outra jogada.\n");
            }
            else{
                movimento[linha][coluna] = ' ';
                movimento[i][j] = 'B';
            }
            break;
        default:
            printf ("\nVocê selecionou um espaço vazio\n");
            break;
        }
        printf ("Continuar? (1) Sim - (2) Não : ");
        scanf ("%d",&decisao);
        if (decisao !=1){
            decisao = 9999;
        }
        system("cls");
    }while(decisao != 9999);
}
