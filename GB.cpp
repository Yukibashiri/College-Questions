#ifndef _TESTAGRAFO_H_
#define _TESTAGRAFO_H_
#include "matrizadj/Grafo.h" // @{\it vide Programa~\ref{c_7.2}@
//#include "listaadj/autoreferencia/Grafo.h" // @{\it vide Programa~\ref{c_7.4}@
//#include "listaadj/arranjo/Grafo.h" // @{\it vide Programa~\ref{c_7.6}@
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using cap7_matrizadj::Grafo; // @{\it vide Programa~\ref{c_7.2}@
//using cap7_listaadj_autoreferencia::Grafo; // @{\it vide Programa~\ref{c_7.4}@
//using cap7_listaadj_arranjo::Grafo; // @{\it vide Programa~\ref{c_7.6}@
namespace cap7 {
  class TestaGrafo {
  public:
    static Grafo::Aresta *lerAresta ();
    static void main ();    
  };

  Grafo::Aresta *TestaGrafo::lerAresta () {
    cout << "Aresta:" << endl;
    cout << "  V1:"; int v1 = 0;
    cin >> v1;
    cout << "  V2:"; int v2 = 0;
    cin >> v2;
    cout << "  Peso:"; int peso = 0;
    cin >> peso;
    return new Grafo::Aresta (v1, v2, peso);
  }
  void TestaGrafo::main () {
    cout << "No. vertices:"; int nVertices = 0;
    cin >> nVertices;
    cout << "No. arestas:"; int nArestas = 0;
    cin >> nArestas;
    Grafo *grafo = new Grafo (nVertices, nArestas);
//    Grafo *grafo = new Grafo (nVertices);
    for (int i = 0; i < nArestas; i++) {
    	// @{\it Duas chamadas porque o grafo \'e n\~ao direcionado}@    	
      Grafo::Aresta *a = lerAresta ();
      grafo->insereAresta (a->_v1 (), a->_v2 (), a->_peso ()); 
//      grafo->insereAresta (a->_v2 (), a->_v1 (), a->_peso ()); 
      delete a;
    }
    grafo->imprime ();  
//
    Grafo *grafoT = grafo->grafoTransposto();
    cout << "Grafo transposto" << endl;
    grafoT->imprime ();
    delete grafoT; 
    Grafo::Aresta *a1 = lerAresta ();
    if (grafo->existeAresta (a1->_v1 (), a1->_v2 ())) 
      cout << "Aresta ja existe" << endl;
    else {
    	// @{\it Duas chamadas porque o grafo \'e n\~ao direcionado}@    	
      grafo->insereAresta (a1->_v1 (), a1->_v2 (), a1->_peso ());
//      grafo->insereAresta (a1->_v2 (), a1->_v1 (), a1->_peso ());
    }
    delete a1; grafo->imprime (); 
//    
    cout << "Lista adjacentes de: "; int v1 = 0;
    cin >> v1;
    if (!grafo->listaAdjVazia (v1)) {
      Grafo::Aresta *adj = grafo->primeiroListaAdj (v1);
      while (adj != NULL) {
       cout << "  " << adj->_v2 () << " (" << adj->_peso () << ")" << endl;
       delete adj; adj = grafo->proxAdj (v1);       
      }
      cout << endl; 
    }
    cout << "Retira aresta: " << endl;
    Grafo::Aresta *a = lerAresta ();
    Grafo::Aresta *aresta = NULL;
    if (grafo->existeAresta (a->_v1 (), a->_v2 ())) {
    	// @{\it Duas chamadas porque o grafo \'e n\~ao direcionado}@    	
      aresta = grafo->retiraAresta (a->_v1 (), a->_v2 ());
      delete aresta;
  //    aresta = grafo->retiraAresta (a->_v2 (), a->_v1 ());
  //    delete aresta;
    }
    else cout << "Aresta nao existe" << endl;
    delete a;
    grafo->imprime (); 
    cout << "Existe aresta: " << endl; a = lerAresta ();
    if (grafo->existeAresta (a->_v1 (), a->_v2 ())) 
     cout << "  Sim" << endl;
    else cout << "  Nao" << endl;
    delete a; delete grafo;
  }
}

#endif
