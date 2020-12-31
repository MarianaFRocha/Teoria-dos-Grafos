
#include <stdio.h>
#include <stdlib.h>
#include "grafos_mat.h"



Grafo* floydWarshall(Grafo *g){

	Grafo *d = criaGrafo(g->vertice);
	int *pai = (int *)malloc(sizeof(int)*(g->vertice));

	//int **m = malloc((g->V)* sizeof(int *));
	
	for (int i = 0; i < g->vertice; ++i)
	{
		for (int j = 0; j < g->vertice; ++j)
		{
			d->adj[i][j] = g->adj[i][j];
		}
		pai[i] = -1;
	}

	int k = -1, minimo = INFINITO;
	for (int k = 0; k < g->vertice; ++k)
	{
		for (int i = 0; i < g->vertice; ++i)
		{
			for (int j = 0; j < g->vertice; ++j)
			{
				printf("--%d %d\n", d->adj[i][j], (d->adj[i][k] + d->adj[k][j]));
				if(d->adj[i][j]>d->adj[i][k] + d->adj[k][j]){
					d->adj[i][j] = (d->adj[i][k] + d->adj[k][j]);	
					pai[i] = i;
				}

			}
		}
	}

	return d;

}


int main(int argc, char *argv[]){

	int v, e, w, peso;

	scanf("%d %d", &v, &e);
	printf("%d %d\n", v, e);

	Grafo *g = criaGrafo(v);

	for (int i = 0; i < e; ++i)
	{
		scanf("%d %d %d", &v, &w, &peso);
		v--;
		w--;
		insereAresta(g, v, w, peso);
	}

	imprimiGrafo(g);

	g=floydWarshall(g);

	printf("floyd Warshall\n");
	imprimiGrafo(g);

	return 0;

}