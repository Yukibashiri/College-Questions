#include <stdio.h>
#include <locale.h>
 void popular_matriz (int l, int c, int matriz[l][c]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf ("\nInforme o valor do Elemento[%d][%d]: ",i,j);
            scanf ("%d",&matriz[i][j]);
        }
    }
    system("cls");
}

void mostrar_matriz(int l,int c, int matriz[l][c]){
    int i,j;
    for(i=0;i<l;i++){
        printf ("\n");
        for(j=0;j<c;j++){
            printf ("[%d]   ",matriz[i][j]);
        }
    }
    printf ("\n");
}

void main (void){
    setlocale(LC_ALL,"Portuguese");
    int Alinha,Acoluna,Blinha,Bcoluna;
    int i,j,l,c;
    printf ("\nInforme o numero de linhas da Matriz A: ");
    scanf ("%d",&Alinha);
    printf ("\nInforme o numero de colunas da Matriz A: ");
    scanf ("%d",&Acoluna);
    printf ("\nInforme o numero de linhas da Matriz B: ");
    scanf ("%d",&Blinha);
    printf ("\nInforme o numero de colunas da Matriz B: ");
    scanf ("%d",&Bcoluna);
    system("cls");
    if(Acoluna != Blinha){ /* Regra*/
        printf ("\nErro! O numero de colunas da primeira matriz é diferente do numero de linhas da segunda matriz.");
        system("EXIT");
    }
    int A[Alinha][Acoluna],B[Blinha][Bcoluna];  /*Criação das matrizes de acordo com os valores fornecidos pelo usuario*/
    int m_transposta[Bcoluna][Blinha];          /* Criando Matriz transposta da B*/
    printf ("\n Popule a primeira Matriz: ");
    popular_matriz(Alinha,Acoluna,A);
    printf ("\n Popule a segunda Matriz: ");
    popular_matriz(Blinha,Bcoluna,B);
    for (i=0;i<Blinha;i++){
        for (j=0;j<Bcoluna;j++){
            m_transposta[j][i] = B[i][j];
        }
    }
    mostrar_matriz(Alinha,Acoluna,A);
    mostrar_matriz(Blinha,Bcoluna,B);
    l = Alinha;
    c = Bcoluna;
    int AB[l][c];
    memset(AB, 0, sizeof(AB));
    for (i=0;i<Alinha;i++){
        for (j=0;j<Bcoluna;j++){
            for (l=0;l<Acoluna;l++){
                AB[i][j] += A[i][l] * B[l][j];
            }
        }
    }
    mostrar_matriz(Alinha,Bcoluna,AB);
}
