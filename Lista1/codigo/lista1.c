#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"

#define INFINITO 2147483646

Grafo* prim(Grafo *g, int raiz){


     Grafo *AGM = (Grafo *)malloc(sizeof(Grafo));
     AGM = criaGrafo(g->vertice);

     int *distancia = (int*) calloc (g->vertice,sizeof(int));
     int *pai = (int*) calloc (g->vertice,sizeof(int));
     int *explorado = (int*) calloc (g->vertice,sizeof(int));

     int i, menor = INFINITO, auxpai, novoVertice, flag;

     Vertice *verticeAdj;

     for (int i = 0; i < g->vertice; i++) {
          distancia[i] = INFINITO;
          explorado[i] = 0;
          pai[i] = -1;
    }

     distancia[raiz] = 0;
     pai[raiz] = 0;

     int q = g->vertice;

     while(q != 0){

          for (i = 0; i < g->vertice; i++) {
               flag=1;
               //o vertice ja se encontra na arvore
               if (pai[i] != -1) {
                    //exite ainda vertices adjacentes que ainda nao foram explorados
                    if (explorado[i]==0) {
                         verticeAdj = g->verticeAdjacente[i].prox;
                         while(verticeAdj != NULL){
                              //Verifica se o vertice adjacente ja nao esta na arvore
                              //printf("vertice: %d  verticeAdj:%d peso:%d menor %d\n", i,  verticeAdj->no, verticeAdj->peso, menor );
                              if(pai[verticeAdj->no] == -1) {
                                   flag=0;
                                   //printf("%d\n", );
                                   //Procura a menor distancia entre os vertices
                                   if(menor> verticeAdj->peso){
                                        menor=verticeAdj->peso;
                                        auxpai = i;
                                        novoVertice = verticeAdj->no;
                                   }
                              }

                              verticeAdj = verticeAdj->prox;
                         }
                         explorado[i] = flag;
                    }
               }
          }
          pai[novoVertice] = auxpai;
          distancia[novoVertice] = menor;
          insereAresta(AGM, auxpai, novoVertice, menor);
          //imprimeGrafo(AGM);
          menor = INFINITO;
          q--;
     }

     return AGM;

}

int main(int argc, char const *argv[]) {

     int i, v, e, w, p;
	scanf("%d %d", &v , &e);
     //printf("v:%d e:%d\n", v, e);

	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	g = criaGrafo(v);

	for(i = 0; i<e; i++){
		scanf("%d %d %d", &v, &w, &p);
          printf("%d %d %d\n", v, w, p);

          //GRAFO NAO DIRECIONADO
		insereAresta(g, v, w, p);

	}
	imprimeGrafo(g);

     g=prim(g, 0);

     printf("ARVORE GERADORA MINIMA - ALGORITMO PRIM\n");
     imprimeGrafo(g);

     return 0;
}
