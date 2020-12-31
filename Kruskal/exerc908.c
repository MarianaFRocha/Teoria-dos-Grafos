#include <stdio.h>
#include <stdlib.h>
#include "grafo_lista.h"



int cmpfunc (const CustoAresta * a, const CustoAresta * b) {
   return ( a->peso - b->peso);
}


Grafo *kruskal(Grafo *g, CustoAresta *c){

    printf("DEBUG 1\n");

	int i;

    //Arvore geradora minima
	Grafo *a = (Grafo *)malloc(sizeof(Grafo));   

    //vetor que indica a qual conjunto cada vertice pertence
	int *v = (int *)malloc(sizeof(int)*(g->vertice));  

    printf("DEBUG 2\n");

    //Cria o vetor que indica o conjunto de cada vertice
	for (i = 0; i < g->vertice; ++i) 
	{
		v[i]=i;
	}

    printf("DEBUG 3\n");

    imprimeCusto(c, g->aresta);

    //Ordena de forma crescente o vetor de arestas de g em relacao ao peso
	qsort(c, g->aresta, sizeof(int), cmpfunc);  //-----------------------------------------------------------------ERRO AQUI !!!!!

    printf("DEBUG 4\n");

    for(i=0; i< g->aresta; i++){
        printf("%d", c[i].peso);
    }
    
	for (i = 0; i < g->vertice; ++i)
	{
        //confere se as arestas ja pertecem ao mesmo conjunto
		if(v[c[i].x] != v[c[i].y]){
            //Union
			insereAresta(a, c[i].x, c[i].y);  
			v[c[i].y] = v[c[i].x];
		}
	}

	return a; //retorna arvore geradora minima de g

}



int main(int argc, char *argv[]){ 

   	int i, v, e, w, p;
	//scanf("%d %d", &v , &e);


//***************************Leitura Arquivo***************************************
	FILE *arq = fopen(argv[1], "r");
	fscanf(arq,"%d %d", &v, &e);

	Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    CustoAresta *c = (CustoAresta *)malloc(e*sizeof(CustoAresta));

	g = criaGrafo(v);

	for(i = 0; i<e; i++){
		fscanf(arq,"%d %d %d", &v, &w, &p);
		insereAresta(g, v-1, w-1);
         
        c[i].x = v;
        c[i].y = w;
        c[i].peso = p;
	}

	imprimeGrafo(g);
    imprimeCusto(c, e);
	fclose(arq);

//************************Executa Kruskal*******************************************
    Grafo *k = (Grafo *)malloc(sizeof(Grafo));

    k = kruskal(g,c);

    imprimeGrafo(k);

	return 0;


}
