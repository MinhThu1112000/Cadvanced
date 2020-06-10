#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jval.h"
#include "jrb.h"
#include "mygraph.h"
#include "dllist.h"
void createGraph(Graph *graph){
    graph->vertex = make_jrb();
    graph->edges = make_jrb();
    return;
}
void addVertex(Graph *graph, int key, char *mark){
    JRB p = jrb_find_int(graph->vertex, key);
    if(p != NULL) return;
    jrb_insert_int(graph->vertex, key, new_jval_s(strdup(mark)));
    jrb_insert_int(graph->edges, key, new_jval_v(NULL));
}
void addEgdes(Graph )

