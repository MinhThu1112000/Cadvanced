#include <stdio.h>
#include <stdlib.h>
#include "fields.h"
#include "mygraph.h"
int docFile(char *fileName, Graph *graph){
    IS is = new_inputstruct(fileName);
    int n;
    if(is->line == 1) n = atoi(is->fields[0]);
    for(int i = 0; i < n; i++){
        get_line(is);
        addVertex(graph, atoi(is->fields[0]), is->fields[1]);
    }
    getline(is);
    n = atoi(is->fields[0]);
    for(int i = 0 ; i < n; i++){
        get_line(is);
        if(){

        }
    }
}