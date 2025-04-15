#include "../header/graph_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
struct Graph* create_graph(int vertices){

    struct Graph*new_graph=(struct Graph*)malloc(sizeof(struct Graph));

    assert(new_graph!=NULL);
    new_graph->VERTICES=vertices;
    new_graph->EDGES=0;


       new_graph->matrix = malloc(sizeof(int *)*new_graph->VERTICES);
        for (int index=0; index<vertices;index++) {
        
            new_graph->matrix[index]=calloc(new_graph->VERTICES,sizeof(int));
            assert(new_graph->matrix[index]!=NULL);
        }

    return new_graph;
  }

struct Edge* create_edge(int src,int dest){

struct Edge* new_edge= (struct Edge*)malloc(sizeof(struct Edge));

assert(new_edge!=NULL);
new_edge->SRC=src;
new_edge->DEST=dest;

return new_edge;

}

int removeEdge(struct Graph *g, struct Edge *e,int is_directed){

   assert(g!=NULL || e!=NULL);
    int src=e->SRC;
    int dest=e->DEST;
    assert(src<g->VERTICES || dest <g->VERTICES);

    g->matrix[src][dest]=0;
    g->matrix[dest][src]=is_directed?g->matrix[dest][src]:0;
    
    return 1;

}


int addEdge(struct Graph *g, struct Edge *e,int is_directed){
    assert(g!=NULL || e!=NULL);
    int src=e->SRC;
    int dest=e->DEST;
    assert(src<g->VERTICES || dest <g->VERTICES);
    g->matrix[src][dest]=1;
  g->matrix[dest][src]=is_directed?0:1; 
    g->EDGES++;

    return 1;

}

void print_graph(struct Graph*g){

    assert(g!=NULL);
    for (int row=0; row<g->VERTICES; row++) {

        for(int col=0;col<g->VERTICES;col++){

            if (g->matrix[row][col]==1) {
                
                printf("\n%d => %d",row,col);

            }    


        }
        printf("\n");


            
    }


}
