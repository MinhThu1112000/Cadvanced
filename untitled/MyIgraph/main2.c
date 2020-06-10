#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fields.h"
#include "mygraph.h"
void readFile(char *fileName, Graph *graph)
{
    int id = 1;
    IS is = new_inputstruct(fileName);
    if(is->name == NULL) return ;
    get_line(is);
    int n = atoi(is->fields[0]);
    for(int i = 0; i < n; i++){
        get_line(is);
        addVertex(graph,id++,is->fields[0]);
    }
    get_line(is);
    int m = atoi(is->fields[0]);
    for(int i = 0; i < m; i++){
        get_line(is);
        addEdge(graph,atoi(is->fields[0]), atoi(is->fields[1]),NULL,0);
    }
    jettison_inputstruct(is);
}
int main(){
    Graph graph;
    createGraph(&graph);
    readFile("graph.txt",&graph);
    printGraph(&graph,0);
    dropGraph(&graph);

    return 0;
}

