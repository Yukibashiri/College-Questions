#include <stdio.h>
#include <locale.h>

typedef struct node{
    int val;
    struct node *ant;
    struct node *sae;
    struct node *sad;
}node;

void menuApresentacao(){
	printf ("1- Criar Arvore\n2- Inserir N�\n3- Ver arvore\n4- Remover n�\n5 - Peso\\n6 - em Ordem\n9-Sair\n R: ");
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
        printf ("\nN� n�o existe ou j� foi removido!");
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
        }else {/* n� tem os dois filhos: busca o sucessor */
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
                sucessor->ant->sae = (sucessor)->sad; /* se sucessor for filho � esquerda */
             }else{
                (*antecessor)->sad = (sucessor)->sad; /* se sucessor for filho � direita */
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
    printf ("\nVal de X: %d",*x);
    *x += 1;
    printf ("\nVal de X: %d",*x);
	if((*raiz)->sae != NULL){
		pesoArvore(&(*raiz)->sae, x);
	}
	if((*raiz)->sad != NULL){
		pesoArvore(&(*raiz)->sad, x);
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
						printf ("\nCriando n� raiz\n");
						node *principal;
						principal = malloc(sizeof(node));
						criarArvore(principal);
					break;
			case 2:
					printf ("\nInforme a chave do n�:  ");
    				scanf ("%d",&numero);
    				inserirNode(principal,principal,numero);
    				printf ("\n N� inserido!\n");
    				break;
    		case 3:
    				printf ("Mostrando Arvore: \n");
    				visualizarArvore(principal);
    				break;
            case 4:
                    printf ("\nInforme a chave do n� que deseja remover: ");
                    scanf ("%d",&numero);
                    removerNode(principal,numero);
                    break;
    		case 5:
                    x = 0;
                    pesoArvore(principal,&x);
    				printf ("\nPeso �: %d", x);
    				break;
    		case 7:
                    x = 0;
                    nosComfilho(principal,&x);
    				printf ("\nnumero de n�s com filhos �: %d", x);
    				break;
            case 6:
    				printf ("Mostrando Arvore: \n");
    				emOrdem(principal);
    				break;
    		case 9:
    				printf ("\nEncerrando o Programa!");
    				break;
		}
		getch();
    }while(escolha != 9);
}

