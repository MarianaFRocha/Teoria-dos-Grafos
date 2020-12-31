#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"

#define INFINITO 2147483646


//Menor Peso de um no incial até todo os outros 
int bellmanFord(Grafo *g, CustoAresta *c){

	printf("\n******BELLMANFORD*****\n");

	int i, j, v, cont=0;

	int *dist = (int *)malloc(sizeof(int)*(g->V));
	int *pi = (int *)malloc(sizeof(int)*(g->V));

	for(i=0; i<g->V; i++){

		dist[i]=INFINITO; 	
        pi[i]=0;
	}

    //vertice inicial
    dist[0]=0;
    pi[0]=-1;   

	for(i=0; i<g->V-1; i++)
	{
		printf("Interacao %d: \n", i+1);
		for (j = 0; j < g->aresta; j++)
		{
			if( dist[c[j].verticeV] != INFINITO && dist[c[j].verticeW] > (dist[c[j].verticeV] + c[j].peso)) 
			{

				printf("v:%d w:%d  dist: %d pai:%d\n\n", c[j].verticeV, c[j].verticeW, (dist[c[j].verticeV] + c[j].peso), c[j].verticeV);

                		dist[c[j].verticeW] = (dist[c[j].verticeV] + c[j].peso);
                		pi[j]= c[j].verticeV;	
			}
		}
	}

	printf("Vetor dist: ");
    for(j=0; j<g->aresta; j++){
    		if (j<g->V)
    		{
    			printf("%d ", dist[j]);
    		}
            if(dist[c[j].verticeW] > (dist[c[j].verticeV] + c[j].peso)){
                return 1;                
            }            
        }
    printf("\n");

    return 0;
        
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

	i = bellmanFord(g, c);
	printf("bf: %d", i);
	
       
	return 0;

}
