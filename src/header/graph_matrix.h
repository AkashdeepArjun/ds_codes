#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

struct Graph {

    int VERTICES;
    int EDGES;
    int** matrix;
     
};

struct Edge {
    int SRC;
    int DEST;
};

struct Graph* create_graph(int);
struct Edge* create_edge(int,int); 
int addEdge(struct Graph*,struct Edge*,int);
int removeEdge(struct Graph*,struct Edge*,int);
void dfs(struct Graph*);
void bfs(struct Graph*);
void print_graph(struct Graph*);


#endif // ! HEADER_ H_INCLUDED
