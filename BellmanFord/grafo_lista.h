#include <stdio.h>
#include <stdlib.h>


//Grafo Direcionado (Ida diferente da Volta)

typedef struct vertice{

	int no;
	struct vertice *prox;

}Vertice; 

typedef struct grafo{

	int vertice;
	int aresta;
	Vertice *verticeAdjacente;

}Grafo; 

typedef struct custoAresta{
	int verticeV;
	int verticeW;
	int peso;
}CustoAresta; 

Grafo *criaGrafo(int V){

	Grafo *G = (Grafo *)malloc(sizeof(Grafo));
	G->vertice= V;
	G->aresta=0;
	G->verticeAdjacente = (Vertice *)calloc(V, sizeof(Vertice));

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
		Vertice *p = G->verticeAdjacente[v].prox;
		while(p != NULL){
			if(p->no == w)
				break;
			p = p->prox;
		}
		if(p==NULL){  //a aresta (v, w) não existe

			Vertice *novo = novoVertice(w);
			novo->prox = G->verticeAdjacente[v].prox;
			G->verticeAdjacente[v].prox = novo;
			G->aresta++;

		}

	}

}

void removeAresta(Grafo *G, int v, int w){

	if(G->verticeAdjacente[v].prox != NULL){
		Vertice *aux = G->verticeAdjacente[v].prox;
		Vertice *preaux = &(G->verticeAdjacente[v]);
		while(aux != NULL){
			if(aux->no == w)
				break;
			preaux = aux;
			aux = aux->prox;
		}
		if(aux != NULL){
			G->aresta--;
			preaux->prox = aux->prox;
			free(aux);
		}

	}

}

void imprimeGrafo(Grafo *G){

	int i;
	Vertice *aux;
	printf("\nRepresentacao do Grafo por Lista de Adjacencias\n\n");
	for(i=0; i< G->vertice; i++){
		aux= G->verticeAdjacente[i].prox;
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
	aux= G->verticeAdjacente[V].prox;

	while(aux!= NULL){
		cont ++;
		aux= aux->prox;
	}
	
	return cont;

}

//retorna 0 se o grau dos vertices dos grafos forem diferentes
//retorna 1 se forem iguais 
int compararGrauGrafos(Grafo *G1, Grafo *G2){

	if(G1->aresta != G2->aresta || G1->aresta != G2->aresta){
		return 0;
	}

	int i, v1, v2;

	for (i = 0; i < G1->aresta; ++i)
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
		printf("v:%d - w:%d p:%d \n", (c[i].verticeV), (c[i].verticeW), c[i].peso);
	}

	printf("\n");
}

