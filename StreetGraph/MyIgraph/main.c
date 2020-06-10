#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mygraph.h"
#include "fields.h"
int readFile(Graph *graph, char *fileName){
    IS is = new_inputstruct(fileName);
    get_line(is);
    int n;
    n = atoi(is->fields[0]);
    for(int i = 0; i < n; i++){
        get_line(is);
        addVertex(graph->vertex, atoi(is->fields[0]), is->fields[1]);
    }
    int m;
    get_line(is);
    m = atoi(is->fields[0]);
    for(int i = 0; i < m; i++){
        get_line(is);
        addEdge(graph->edges,atoi(is->fields[0]), atoi(is->fields[1]), NULL,0);
    }

    jettison_inputstruct(is);
}
int main(){
    printf("Minh thu");
    Graph graph;
    graph.edges = graph.vertex = NULL;
    createGraph(&graph);
    readFile(&graph, "input.txt");
    printGraph(&graph,0);

}
