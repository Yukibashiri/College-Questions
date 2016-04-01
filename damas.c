#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// FUNÇÃO QUE MOSTRA O TABULEIRO (SENDO AS PERMISSÕES OU MOVIMENTOS)
void fun_tabuleiro(char movimento[8][8]){
    int i,j;
    printf ("\n\n\n  0 1 2 3 4 5 6 7 ");
    for (i=0;i<8;i++){                      // não tem muito o que explicar já que só imprime a matriz em um formato 8x8
        printf ("\n%d ",i);
        for (j=0;j<8;j++){
            printf ("%c ",movimento[i][j]);
        }
    }
}


int main (){
    setlocale (LC_ALL,"Portuguese");
    char tabuleiro[8][8];  // matriz do campo de restrição do movimento
    char movimento[8][8]= {' '}; // matriz das peças todos os espaços iniciam em branco.
    int i,j,linha,coluna,aux=1,decisao; // variaveis de auxilio
    char bloco = 'X'; // transformando a matriz babuleiro em um campo de movimento em diagonal (posicao onde tem X)
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
    //fun_tabuleiro(tabuleiro); // codigo para mostrar como esta o tabulero de restrição de movimento
    for (i=0;i<8;i++){ // laço que coloca as peças em lugar P = preta B = branca.
        for (j=0;j<8;j++){
            if ((i<3) && (aux % 2 == 0)){ // restrição utilizada para que as peças Pretas sejam colocadas só até a terceira linha.
                movimento[i][j] = 'P';
            }
            else if ((i>4)&&(aux %2 == 0)){ // restrição utilizada para que as peças Branas sejam colocadas a partir da quinta linha.
                movimento[i][j] = 'B';
            }
        aux++; // utilizado para montar a tabela em diagonal.
        }
        aux++; // mesma função do anterior, um transforma em impar outro volta para par.
    } // fim do laço.
    decisao =0; // zerando a varaivel pois por alguma razão estava com problema no buffer e esqueci o comando.
    do{
        fun_tabuleiro(movimento); // chama a função de mostrar o tabuleiro usando como parametro a matriz movimento, assim serão mostradas as peças.
        printf ("\n\n\nInforme a linha da peça que desejas mover: ");
        scanf ("%d",&linha);        // usuario informa a linha da peça
        printf ("e a coluna dessa mesma peça:  ");
        scanf ("%d",&coluna);       // usuario informa a coluna da peça
        printf ("Desejas mover a peça para esquerda(1) ou para direita(2)? ");
        scanf ("%d",&decisao);
        switch(movimento[linha][coluna]){   //Esse case utiliza da resposta do usuario para mover a peça em diagonal,
        case 'P':                           // uma checagem para ver se é preta ou branca é feita para saber qual operração sera executada
            if (decisao == 1){              // restrições impostaas abaixo servem para que o usuario não mova a peça para fora da tabela,
                i = linha + 1;              // ou seja, tem de ser entre as colunas de 0 e 7, o mesmo vale para as linhas. 
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
        default:                // caso ele digite um valor diferente dos estipulados.
            printf ("\nVocê selecionou um espaço vazio\n");
            break;
        } // fim do laço.
        printf ("Continuar? (1) Sim - (2) Não : "); // condição de parada
        scanf ("%d",&decisao);
        if (decisao !=1){
            decisao = 9999;
        }
        system("cls");
    }while(decisao != 9999); // termina o programa saindo do laço, caso a condição acima seja verdadeira.
}
