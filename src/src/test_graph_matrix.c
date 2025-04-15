#include <stdio.h>
#include <stdlib.h>
#include "../header/graph_matrix.h"
#define EXIT_SUCCESS 0

void take_log(char*);

int main(int argc, char *argv[])
{
    printf("welcome to world of problem solving");

    struct Graph*g=create_graph(4);
    struct Edge*z1=create_edge(1,2);
    addEdge(g, z1,0);
    print_graph(g);

    take_log("now testing remove edge ....");

    return EXIT_SUCCESS;
}
