#include <stdio.h>
#include <stdlib.h>


//Grafo Direcionado (Ida diferente da Volta)

typedef struct vertice{

	int no;
	struct vertice *prox;

}Vertice; 

typedef struct grafo{

	int V;
	int E;
	Vertice *adj;

}Grafo; 

typedef struct custoAresta{
	int v;
	int w;
	int peso;
}CustoAresta; 

Grafo *criaGrafo(int V){

	Grafo *G = (Grafo *)malloc(sizeof(Grafo));
	G->V= V;
	G->E=0;
	G->adj = (Vertice *)calloc(V, sizeof(Vertice));

	return G;

}

Vertice *novoVertice(int x){

	Vertice *novo = (Vertice *)malloc(sizeof(Vertice));
	if(novo == NULL){
		printf("Erro.\n");
		exit(1);
	}
	novo->no = x;
	novo->prox = NULL;
	
	return novo;
}

void insereAresta(Grafo *G, int v, int w){

	if(v != w){

		//insere em w
		Vertice *p = G->adj[v].prox;
		while(p != NULL){
			if(p->no == w)
				break;
			p = p->prox;
		}
		if(p==NULL){  //a aresta (v, w) não existe

			Vertice *novo = novoVertice(w);
			novo->prox = G->adj[v].prox;
			G->adj[v].prox = novo;
			G->E++;

		}

	}

}

void removeAresta(Grafo *G, int v, int w){

	if(G->adj[v].prox != NULL){
		Vertice *aux = G->adj[v].prox;
		Vertice *preaux = &(G->adj[v]);
		while(aux != NULL){
			if(aux->no == w)
				break;
			preaux = aux;
			aux = aux->prox;
		}
		if(aux != NULL){
			G->E--;
			preaux->prox = aux->prox;
			free(aux);
		}

	}

}

void imprimeGrafo(Grafo *G){

	int i;
	Vertice *aux;
	printf("\nRepresentacao do Grafo por Lista de Adjacencias\n\n");
	for(i=0; i< G->V; i++){
		aux= G->adj[i].prox;
		printf("%d = ", i);
		while(aux!= NULL){
			printf("%d -> ", (aux->no));
			aux= aux->prox;
		}
		printf("||\n");
	}
	printf("\n");

}

int grauVertice(Grafo *G, int V){

	int cont=0;
	Vertice *aux;
	aux= G->adj[V].prox;

	while(aux!= NULL){
		cont ++;
		aux= aux->prox;
	}
	
	return cont;

}

//retorna 0 se o grau dos vertices dos grafos forem diferentes
//retorna 1 se forem iguais 
int compararGrauGrafos(Grafo *G1, Grafo *G2){

	if(G1->E != G2->E || G1->E != G2->E){
		return 0;
	}

	int i, v1, v2;

	for (i = 0; i < G1->E; ++i)
	{
		v1 = grauVertice(G1, i);
		v2 = grauVertice(G2, i);
		if (v1 != v2)
		{
			return 0;
		}
	}

	return 1;
}

void imprimeCusto(CustoAresta *c, int e){
	printf("\nPeso das Arestas do Grafo\n\n");
	for(int i=0; i<e; i++){
		printf("v:%d - w:%d p:%d \n", (c[i].v), (c[i].w), c[i].peso);
	}

	printf("\n");
}

