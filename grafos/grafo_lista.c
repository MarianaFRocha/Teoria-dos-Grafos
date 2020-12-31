#include <stdio.h>
#include <stdlib.h>


//Adicionar Inserir e Remover

typedef struct vertice{

	int no;
	struct vertice *prox;

}Vertice; 

typedef struct grafo{

	int vertice;
	int aresta;
	Vertice *verticeAdjacente;

}Grafo; 

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
		p = G->verticeAdjacente[w].prox;

		while(p != NULL){
			p = p->prox;
		}

		//insere em v
		if(p==NULL){  //a aresta (v, w) não existe

			Vertice *novo = novoVertice(v);
			novo->prox = G->verticeAdjacente[w].prox;
			G->verticeAdjacente[w].prox = novo;
			
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
	if(G->verticeAdjacente[w].prox != NULL){

		Vertice *aux = G->verticeAdjacente[w].prox;
		Vertice *preaux = &(G->verticeAdjacente[w]);
		while(aux != NULL){
			if(aux->no == v)
				break;
			preaux = aux;
			aux = aux->prox;
		}
		if(aux != NULL){
			preaux->prox = aux->prox;
			free(aux);
		}
	}
}

void imprimeGrafo(Grafo *G){

	int i;
	Vertice *aux;
	printf("\nRepresentacao do Grafo por Lista de Adjacencias\n");
	for(i=0; i< G->vertice; i++){
		aux= G->verticeAdjacente[i].prox;
		printf("%d = ", i);
		while(aux!= NULL){
			printf("%d -> ", aux->no);
			aux= aux->prox;
		}
		printf("||\n");
	}

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


int main(){ 

	int i, v, e, w;
	printf("\nGrafo 1\n");
	scanf("%d %d", &v , &e);
	Grafo *g = (Grafo *)malloc(sizeof(Grafo));

	g = criaGrafo(v);

	for(i = 0; i<e; i++){
		scanf("%d %d", &v, &w);
		insereAresta(g, v, w);
	}
	imprimeGrafo(g);

	//******Testes***********


	//scanf("%d %d", &v, &w);
	//removeAresta(g, v, w);

	//imprimeGrafo(g);

/*
	for (int i = 0; i < e; ++i)
	{
			w = grauVertice(g, i);
			printf("Grau do vertice %d : %d\n", i, w);
	}*/

/*	printf("\nGrafo 2\n");
	scanf("%d %d", &v , &e);
	Grafo *g2 = (Grafo *)malloc(sizeof(Grafo));

	g2 = criaGrafo(v);

	for(i = 0; i<e; i++){
		scanf("%d %d", &v, &w);
		insereAresta(g2, v, w);
	}
	imprimeGrafo(g2);

	int c = compararGrauGrafos(g, g2);
	if(c == 0){
		printf("A sequencia de graus dos vertices dos dois grafos sao diferentes\n");
	}else{
		printf("A sequencia de graus dos vertices dos dois grafos sao iguais\n");
	}
*/

	return 0;


}
