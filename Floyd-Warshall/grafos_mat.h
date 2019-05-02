
typedef struct grafo{

	int V;
	int E;
	int **adj;

}Grafo;

#define INFINITO 2147483646

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
	G->V=V;
	G->E=0;
	G->adj=alocagrafo(V,V,INFINITO);
	
	return G;

}

void insereAresta(Grafo *G, int v, int w, int peso){

	if(v != w && G->adj[v][w] == 0){
		G->adj[v][w] = peso;
		G->E++;
	}


}

void removeAresta(Grafo *G, int v, int w){

	if(G->adj[v][w] == 1){
		G-> E--;
		G->adj[v][w] = 0;
	}
}


void imprimiGrafo(Grafo *G){
	int v, w;
	for (v = 0; v< G->V; v++){
		printf("%2d:", v);
		for(w = 0; w< G->V; w++){
			if(G->adj[v][w] >= 1)
				printf(" %2d", w);
		}
		printf("\n");
	}
}

