#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"

#define INFINITO 2147483646


//Menor Peso de um no incial até todo os outros 
int dijkstra(Grafo *grafo, CustoAresta *custoMinimo){

	printf("\n******DIJKSTRA*****\n");

	int i, j, v, cont=0;

	int *dist = (int *)malloc(sizeof(int)*(grafo->vertice));
	int *pi = (int *)malloc(sizeof(int)*(grafo->vertice));

	for(i=0; i<grafo->vertice; i++){

		dist[i]=INFINITO; 	
        pi[i]=0;
	}
}


int main(){

	int quantVertices, quantArestas, verticeV, verticeW, peso;

	scanf("%d %d", &quantVertices , &quantArestas);
	Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
	CustoAresta *custoAresta = (CustoAresta *)malloc(sizeof(CustoAresta)*quantArestas);

	grafo = criaGrafo(quantVertices);

	for(int i = 0; i<quantArestas; i++){
		scanf("%d %d %d", &verticeV, &verticeW, &peso);
		insereAresta(grafo, verticeV, verticeW);
		custoAresta[i].verticeV=verticeV;
		custoAresta[i].verticeW=verticeW;
		custoAresta[i].peso=peso;
		
	}
	imprimeGrafo(grafo);
	imprimeCusto(custoAresta, quantArestas);

	int custoMinimo = dijkstra(grafo, custoAresta);
	printf("dijkstra: %d /n", custoMinimo);
	       
	return 0;

}

