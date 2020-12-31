
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{

	int vertice;
	int aresta;
	int **adj;

}Grafo;


//cria e aloca a matriz de grafos a matriz dos grafos
int **alocagrafo(int r, int c, int val){

	int i, j;
	int **m = malloc(r* sizeof(int *));
	for(i = 0; i< r; i++){
		m[i]=malloc(c* sizeof(int));
	}
	for(i = 0; i< r; i++){
		for(j = 0; j< c; j++)
			m[i][j]=val;	
	}
	
	return m;
}

Grafo *criaGrafo(int V){

	Grafo *G = malloc(sizeof(Grafo));
	G->vertice=V;
	G->aresta=0;
	G->adj=alocagrafo(V,V,0);
	
	return G;

}

void insereAresta(Grafo *G, int v, int w){

	if(v != w && G->adj[v][w] == 0){
		G->adj[v][w] = 1;
		G->adj[w][v] = 1;
		G->aresta++;
	}

}

void removeAresta(Grafo *G, int v, int w){

	if(G->adj[v][w] == 1){
		G-> aresta--;
		G->adj[v][w] = 0;
		G->adj[w][v] = 0;
	}
}


void imprimiGrafo(Grafo *G){
	int v, w;
	for (v = 0; v< G->vertice; v++){
		printf("%2d:", v);
		for(w = 0; w< G->vertice; w++){
			if(G->adj[v][w] == 1)
				printf(" %2d", w);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]){

	int v, e, w;
	Grafo *g = malloc(sizeof(Grafo));

	FILE *arq = fopen(argv[1], "r");
	fscanf(arq,"%d %d", &v, &e);
	
	g = criaGrafo(v);

	for (int i = 0; i < e; ++i)
	{
		fscanf(arq,"%d %d", &v, &w);
		insereAresta(g, v-1, w-1);
	}

	imprimiGrafo(g);
	fclose(arq);	

	return 0;

}


