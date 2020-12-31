#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"

#define INFINITO 2147483646


//Menor Peso de um no incial até todo os outros 
int dijkstra(Grafo *g, CustoAresta *c){

	printf("\n******DIJKSTRA*****\n");

	int i, j, v, cont=0;

	int *dist = (int *)malloc(sizeof(int)*(g->vertice));
	int *pi = (int *)malloc(sizeof(int)*(g->vertice));

	for(i=0; i<g->vertice; i++){

		dist[i]=INFINITO; 	
        pi[i]=0;
	}
}


int main(){

	int i, v, e, w, p;
	scanf("%d %d", &v , &e);
	Grafo *g = (Grafo *)malloc(sizeof(Grafo));
	CustoAresta *c = (CustoAresta *)malloc(sizeof(CustoAresta)*e);

	g = criaGrafo(v);

	for(i = 0; i<e; i++){
		scanf("%d %d %d", &v, &w, &p);
		insereAresta(g, v, w);
		c[i].verticeV=v;
		c[i].verticeW=w;
		c[i].peso=p;
		
	}
	imprimeGrafo(g);
	imprimeCusto(c,e);

	i = dijkstra(g, c);
	printf("dijkstra: %d", i);
	       
	return 0;

}

