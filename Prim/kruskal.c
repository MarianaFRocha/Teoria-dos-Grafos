#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grafo_lista.h"

// int compare (const void *a, const void *b) {
//         if (((int *)a)->peso > ((int *)b)->peso) {
//             return -1;
//         } else if (((int *)a)->peso < ((int *)b)->peso) {
//             return 1;
//         } else {
//             return 0;
//         }
//     }

//MODIFICAR TIREI O CUSTO ARESTA !!!!!!!!!!!!!!
Grafo *kruskal(Grafo *g, CustoAresta *c){

	int i;

    //Arvore geradora minima
	Grafo *a = (Grafo *)malloc(sizeof(Grafo));

    //vetor que indica a qual conjunto cada vertice pertence
	int *v = (int *)malloc(sizeof(int)*(g->vertice));

    //Cria o vetor que indica o conjunto de cada vertice
	for (i = 0; i < g->vertice; ++i)
	{
		v[i]=i;
	}

	////////////////////////////AINDA NAO CONSEGUI FAZER ESSA FUNCAO FUNCIONAR////////////////////////

    //Ordena de forma crescente o vetor de arestas de g em relacao ao peso
//	qsort(c,  g->E, sizeof(CustoAresta), compare);

	imprimeCusto(c, g->aresta);

    	printf("DEBUG\n");

	for (i = 0; i < g->vertice; ++i)
	{
        	//confere se as arestas ja pertecem ao mesmo conjunto
		if(v[c[i].v] != v[c[i].w]){
            	//Union
			insereAresta(a, c[i].v, c[i].w, c[i].peso);
			v[c[i].w] = v[c[i].v];
		}
	}

	return a; //retorna arvore geradora minima de g

}


int main(int argc, char *argv[]){

   	int i, v, e, w, p;
	scanf("%d %d", &v, &e);

	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	g = criaGrafo(v);

	for(i = 0; i<e; i++){
		scanf("%d %d %d", &v, &w, &p);
		insereAresta(g, v, w, p);

	}

	imprimeGrafo(g);

//************************Executa Kruskal*******************************************
    //	Grafo *k = (Grafo *)malloc(sizeof(Grafo));

   // 	k = kruskal(g,c);

    //	imprimeGrafo(k);

	return 0;
}
