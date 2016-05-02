/*
*
* Criado por: Vanderson Lucio Rodrigues e adaptado por Mario Damião Caparroz.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 9999
#define PathOff -1
#define VERTICES 10


typedef struct{
        char nome[20];
    } registro;

void listarbairros (registro *bairros){
    int i;
    strcpy((bairros+0)->nome, "VICENTE FIALHO");
    strcpy((bairros+1)->nome, "COHAMA");
    strcpy((bairros+2)->nome, "BEQUIMAO");
    strcpy((bairros+3)->nome, "VINHAIS");
    strcpy((bairros+4)->nome, "RECANTO VINHAIS");
    strcpy((bairros+5)->nome, "QUITANDINHA");
    strcpy((bairros+6)->nome, "COHAFUMA");
    strcpy((bairros+7)->nome, "CALHAU");
    strcpy((bairros+8)->nome, "RENASCENÇA");
    strcpy((bairros+9)->nome, "SAO FRANCISCO");
    printf ("\n       LISTA DOS BAIRROS\n\n");
    for (i=0;i<10;i++){
        printf ("%d - ",i+1);
        puts (bairros+i);
    }
}


void dijkstra(int vertices,int origem,int destino,float *quilometros, registro *bairros){
   int i,v, cont = 0;
   int *precedente, *rota; //amt guarda os precedenteecedentes e o rota guarda o "rota dos nós"
   int *z;     /* vertices para os quais se conhece o caminho minimo */
   float min; // guardara o valor minimo de um nó a outro, para testar qual é o menor.
   float dist[vertices]; /* vetor com os quilometros dos caminhos */

   /* aloca as linhas da matriz */
   precedente = calloc (vertices, sizeof(int *));
   rota = calloc (vertices, sizeof(int *));
   z = calloc (vertices, sizeof(int *));
   if (precedente == NULL || z == NULL) {
      printf ("** Erro: Memoria Insuficiente **");
      exit(-1);
   }
 /* Esse laço tem por objetivo descobrir quais são os caminhos possiveis que o nó de origem pode fazer, quando for -1 el entende que não a conexao. */
   for (i = 0; i < vertices; i++) {
      if (quilometros[(origem - 1) * vertices + i] !=- 1) {
         precedente[i] = origem - 1;
         dist[i] = quilometros[(origem-1)*vertices+i];

      }
      else {
         precedente[i]= -1;
         dist[i] = MAX;
      }
      z[i]=0;
   }
   z[origem-1] = 1;
   dist[origem-1] = 0;

   /* Laco principal */
   do {
      /* Encontrando o vertice que deve entrar em z */
      min = MAX;
      for (i=0;i<vertices;i++)
         if (!z[i])
            if (dist[i]>=0 && dist[i]<min) {
               min=dist[i];
               v=i;
            }
      /* Calculando as distancias dos novos vizinhos de z */
      if (min != MAX && v != destino - 1) {
         z[v] = 1;
         for (i = 0; i < vertices; i++)
            if (!z[i]) {
               if (quilometros[v*vertices+i] != -1 && dist[v] + quilometros[v*vertices+i] < dist[i]) {
                     dist[i] = dist[v] + quilometros[v*vertices+i];
                  precedente[i] =v;
                  }
              }
      }
   } while (v != destino - 1 && min != MAX);
   /* Mostra o Resultado da busca */
   printf("\n\n DE: %s, PARA: %s.\n\n MELHOR ROTA:  ",(bairros+(origem-1))->nome,(bairros+(destino-1))->nome);
   if (min == MAX) {
      printf("Nao Existe\n");
      printf("\tDistancia: \t- \n");
   }
   else {
      i = destino;
      i = precedente[i-1];
      while (i != -1) {
        // printf(" %d",precedente[i]);
         rota[cont] = i+1;
         cont++;
         i = precedente[i];
      }
      for (i = cont; i > 0 ; i--) {
         printf("%s -> ", (bairros+(rota[i-1]))->nome);
      }
    printf("%s", (bairros+(destino-1))->nome);
    printf("\n    DISTANCIA:  %.2f Km\n",dist[destino-1]);
    printf ("\n\n OBS: Rota sujeita à engarrafamentos em horários de pico\n");
   }
}

void main (void){
    setlocale(LC_ALL, "Portuguese");
    registro bairros[10];
    float pesos[100]= {-1,1.3,-1,-1,-1,-1,-1,-1,-1,-1,1.3,-1,1.9,1.6,-1,-1,-1,-1,-1,-1,-1,1.9,-1,-1,2.7,-1,-1,-1,-1,-1,-1,1.6,-1,-1,-1,2.2,-1,-1,-1,-1,-1,-1,2.7,
    -1,-1,-1,2.2,-1,-1,5.1,-1,-1,-1,2.2,-1,-1,4.0,3.1,-1,-1,-1,-1,-1,-1,2.2,4.0,-1,-1,1.9,3.8,-1,-1,-1,-1,-1,3.1,-1,-1,2.5,-1,-1,-1,-1,-1,-1,
    -1,1.9,2.5,-1,2.2,-1,-1,-1,-1,5.1,-1,3.8,-1,2.2,-1};
    int origem,destino,decisao;
    do{
        system("cls");
        listarbairros(&bairros);
        printf ("\nInforme o vértice de origem: ");
        scanf ("%d",&origem);
        printf ("Informe o vértice de destino: ");
        scanf ("%d",&destino);
        system("cls");
        dijkstra(VERTICES, origem, destino, pesos,&bairros);
        system("PAUSE");
        printf ("\n\nDesejas calcular uma nova rota? 1- Sim. 2- Não\n");
        decisao = getch();
        if (decisao != 49){
            exit(-1);
        }
    }while (decisao == 49);
}
