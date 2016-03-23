#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define CRIADOR "Mario D."


// FUNÇÃO DE CALULO \\

int calculo_primo (int numero){
    int i,primo=1,contador=1;  // variavel primo utilizada como teste lógico; i = divisor; contador = dividendo.
    do{
        contador ++; // dividendo recebe +1 a cada ciclo, enquanto numero for diferente de 0;
        primo =1;     // variavel de teste é resetada no inicio de cada ciclo.
        for (i = 2;i < contador;i++){
            if (contador % i ==0){     // Se qualquer numero (contador)for divisivel por i então não é primo
                primo = 0;              // primo == 0, ENTÃO NÃO É PRIMO;
            }
        }
        if (primo == 1){            //SE primo == 1, ENTÃO É PRIMO.
            numero --;      // A cada numero primo encontrado é decrementado 1 de numero,
        }                  // pois assim falta menos uma posição a ser calculada até o n-ésimo soliciado pelo usuario.
    }while (numero != 0);   // Quando zerar a varaivel numero, sairá do laço, pois o n-ésimo primo foi descoberto
    return contador;        // retorna contador que cocntem o valor do n-ésimo primo.
}

 // FUNÇÃO PRINCIPAL \\
 
void main (void){
    setlocale (LC_ALL, "Portuguese");   //Permitir Acentuação
    int numero,nesimo_primo;
    printf ("\n Informe o n-ésimo número primo que desejas saber: ");
    scanf ("%d",&numero);
    nesimo_primo = calculo_primo(numero);
    printf ("\n O %dº número primo é: %d.\n",numero,nesimo_primo);
    system ("PAUSE");
}
