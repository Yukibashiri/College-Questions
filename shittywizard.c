#include <stdio.h>
#include <locale.h>

typedef struct node{
    int val;
    struct node *ant;
    struct node *sae;
    struct node *sad;
}node;

void menuApresentacao(){
	printf ("1- Criar Arvore\n2- Inserir Nó\n3- Pré-Ordem\n4- Remover nó\n5 - Peso\n6 - In-Ordem\n7 - Nós com filho\n8 - Altura da Arvore\n10 - Pós Ordem\n11- Contar os nós folhas\n9-Sair\n R: ");
}

void criarArvore(node **raiz){
	*raiz = NULL;
}

void inserirNode(node **pai,node **raiz, int numero){
    if(*raiz == NULL){
        *raiz = (node*)malloc(sizeof(node));
        (*raiz)->ant = &(*pai);
        (*raiz)->sae = NULL;
        (*raiz)->sad = NULL;
        (*raiz)->val = numero;
    }else{
        if(numero < (*raiz)->val)
            inserirNode(&(*raiz),&(*raiz)->sae, numero);
        if(numero > (*raiz)->val)
            inserirNode(&(*raiz),&(*raiz)->sad, numero);
    }
}

void emOrdem(node **raiz) {
	if((*raiz)->sae != NULL){
		visualizarArvore(&(*raiz)->sae);
	}
    printf ("%d  ", (*raiz)->val);
	if((*raiz)->sad != NULL){
		visualizarArvore(&(*raiz)->sad);
	}
}

void removerNode(node **raiz, int numero){
    if((*raiz) == NULL){
        printf ("\nNó não existe ou já foi removido!");
    }else if(numero < (*raiz)->val){
        removerNode(&(*raiz)->sae, numero);
    }else if(numero > (*raiz)->val){
        removerNode(&(*raiz)->sad, numero);
    }else{
        if((*raiz)->sae == NULL && (*raiz)->sad == NULL) { // SE FOLHA
           free(*raiz);
           *raiz = NULL;
        }else if((*raiz)->sae == NULL){         // SE POSSUIR FILHO A DIREITA
            node *aux = &(*raiz);
            (*raiz) = (*raiz)->sad;
            (*raiz)->ant = (aux)->ant;
            free(aux);
        }else if((*raiz)->sad == NULL){       // SE POSSUIR FILHO A ESQUERDA
            node *aux = &(*raiz);
            (*raiz) = (*raiz)->sae;
            (*raiz)->ant = (aux)->ant;
            free(aux);
        }else {/* nó tem os dois filhos: busca o sucessor */
            node *sucessor = (*raiz)->sad;
            while (sucessor->sae != NULL){
                sucessor = &sucessor->sae;
            }
            (*raiz)->val = (sucessor)->val; /* troca as chaves */
            (sucessor)->val = numero;
            /* liga o filho do sucessor e o avo */
            node **antecessor = sucessor->ant;
            if ((*antecessor)->sae == (sucessor)){
                printf ("\nala 1,");
                sucessor->ant->sae = (sucessor)->sad; /* se sucessor for filho à esquerda */
             }else{
                (*antecessor)->sad = (sucessor)->sad; /* se sucessor for filho à direita */
            }
            if (sucessor->sad!=NULL){
                printf ("\nala 3");
                (sucessor)->sad->ant = (sucessor)->ant;
            }
            free(sucessor);
            free(*antecessor);
        }

 }
}

void visualizarArvore(node **raiz){
	printf ("%d  ", (*raiz)->val);
	if((*raiz)->sae != NULL){
		visualizarArvore(&(*raiz)->sae);
	}
	if((*raiz)->sad != NULL){
		visualizarArvore(&(*raiz)->sad);
	}
}

void pesoArvore(node **raiz,int *x){
    *x += (*raiz)->val;
	if((*raiz)->sae != NULL){
		pesoArvore(&(*raiz)->sae, x);
	}
	if((*raiz)->sad != NULL){
		pesoArvore(&(*raiz)->sad, x);
	}
}

void nosComfilho(node **raiz,int *x){
    if (((*raiz)->sae != NULL) || ((*raiz)->sad != NULL))
        (*x)++;
	if((*raiz)->sae != NULL){
		nosComfilho(&(*raiz)->sae, x);
	}
	if((*raiz)->sad != NULL){
		nosComfilho(&(*raiz)->sad, x);
	}
}

int alturaArv (node **raiz) {
   if (*raiz == NULL)
      return -1; // altura da árvore vazia
   else {
      int he = alturaArv (&(*raiz)->sae);
      int hd = alturaArv (&(*raiz)->sad);
      if (he < hd)
        return hd + 1;
      else
        return he + 1;
   }
}

void posArvore(node **raiz){
	if((*raiz)->sae != NULL){
		posArvore(&(*raiz)->sae);
	}
	if((*raiz)->sad != NULL){
		posArvore(&(*raiz)->sad);
	}
    printf ("%d  ", (*raiz)->val);
}

void nosFolhas(node **raiz,int *x){
    if (((*raiz)->sae == NULL) && ((*raiz)->sad == NULL))
        (*x)++;
	if((*raiz)->sae != NULL){
		nosFolhas(&(*raiz)->sae, x);
	}
	if((*raiz)->sad != NULL){
		nosFolhas(&(*raiz)->sad, x);
	}
}

void main (void){
	setlocale(LC_ALL,"Portuguese");
    int numero,escolha;
    int x;
    do{
    	system("cls");
		menuApresentacao();
		scanf("%d",&escolha);
		system("cls");
		switch(escolha){
			case 1:
                    printf ("\nCriando nó raiz\n");
                    node raiz,*principal;
                    principal = malloc(sizeof(node));
                    principal = &raiz;
                    criarArvore(principal);
					break;
			case 2:
					printf ("\nInforme a chave do nó:  ");
    				scanf ("%d",&numero);
    				inserirNode(principal,principal,numero);
    				printf ("\n Nó inserido!\n");
    				break;
    		case 3:
    				printf ("Mostrando Arvore: \n");
    				visualizarArvore(principal);
    				break;
            case 4:
                    printf ("\nInforme a chave do nó que deseja remover: ");
                    scanf ("%d",&numero);
                    removerNode(principal,numero);
                    break;
    		case 5:
                    x = 0;
                    pesoArvore(principal,&x);
    				printf ("\nPeso é: %d", x);
    				break;
            case 6:
    				printf ("Mostrando Arvore: \n");
    				emOrdem(principal);
    				break;
    		case 7:
                    x = 0;
                    nosComfilho(principal,&x);
    				printf ("\nnumero de nós com filhos é: %d", x);
    				break;
            case 8:
                    printf ("\nAltura da arvore é: %d",alturaArv(principal));
                    break;
    		case 9:
    				printf ("\nEncerrando o Programa!");
    				break;
            case 10:
    				printf ("Mostrando Arvore: \n");
    				posArvore(principal);
    				break;
    		case 11:
                    x = 0;
                    nosFolhas(principal,&x);
    				printf ("\nExistem %d nós folhas na arvore", x);
    				break;
        }
		getch();
    }while(escolha != 9);
}

