#include <stdio.h>
#include <stdlib.h>
#include "fields.h"
#include "mygraph.h"
void readFile(Graph *graph){
    IS is = new_inputstruct("graph_weight.txt");
    int n;
    int id = 1;
    get_line(is);
    n = atoi(is->fields[0]);
    for (int i = 0; i < n; ++i){
        get_line(is);
        addVertex(graph,id++,is->fields[0]);
    }
    get_line(is);
    n = atoi(is->fields[0]);
    for (int j = 0; j < n; ++j) {
        get_line(is);
        int c = atoi(is->fields[2]);
        addEdge(graph,atoi(is->fields[0]),atoi(is->fields[1]),&c,1);
        addEdge(graph,atoi(is->fields[1]),atoi(is->fields[0]),&c,1);
    }
    jettison_inputstruct(is);
}

int main(int argc,char *argv[]){
    Graph graph;
    graph.edges = graph.vertex = NULL;
    createGraph(&graph);
    readFile(&graph);
    printGraph(&graph, 0);
    int money;
    int arr[100];
    int total;
    int edge = 6;
    total = dijkstra(&graph,1,11,&edge,&money,arr,0);
    printf("Tong tien : %d\n",money);
    printf("Duong di ngan nhat tu A den K phai di qua F : ");
    printArr(&graph,arr,total,1);
    total = dijkstra(&graph,1,11,NULL,&money,arr,0);
    printf("\nTong tien : %d\n",money);
    printf("Duong di ngan nhat tu A den K : ");
    printArr(&graph,arr,total,1);
    dropGraph(&graph);
    return 0;
}
/*
 * /// in do thi doc duoc
    printf("\n----- GRAPH -----\n");
    printGraph(&graph,0);

   // in bac vao cua cac dinh
    printf("\n------- INDEGREE ------\n");
    JRB s;
    jrb_traverse(s,graph.vertex)
        printf("%-3s : %d\n",jval_s(s->val),inDegree(&graph,jval_i(s->key)));


  //  in bac ra cua cac dinh
    printf("\n------- OUTDEGREE -------\n");
    jrb_traverse(s,graph.vertex)
        printf("%-3s : %d\n",jval_s(s->val),outDegree(&graph,jval_i(s->key)));


  //  in so luong canh
    printf("\n------- EDGESCOUNT -------\n");
    printf("So canh : %d\n",getEdgesCount(&graph));

  //  in so luong dinh
    printf("\n------- VERTEXCOUNT ------\n");
    printf("So dinh : %d\n",getVertexCount(&graph));

   // duyet DFS khong lay thoi gian bat dau va ket thuc
    printf("\n------- DFS -------(khong lay thoi gian:\n");
    int arr[100] = {-1};
    int total = DFS(&graph,1,-1,NULL,arr,NULL,NULL,0);
    printf("Duyet DFS tu dinh A : ");
    printArr(&graph,arr,total);


   // duyet DFS lay thoi gian bat dau va ket thuc
    printf("\n------- DFS -------(co lay thoi gian:\n");
    int time_s[100] = {-1};
    int time_e[100] = {-1};
    total = DFS(&graph,1,-1,NULL,arr,time_s,time_e,0);
    printf("Duyet DFS tu dinh A :\n");
    for (int i = 0; i < total; ++i) {
        printf("\t%-3s : %-3d - %-3d\n",getName(&graph,arr[i]),time_s[arr[i]],time_e[arr[i]]);
    }

      //  Duyet BFS lay ra cach dinh den tu start co tong trong so khong qua mot luong cho truoc (tuong tu voi BFS)
    printf("\n------- DFS -------\n");
    int arr[100] = {-1};
    int weight = 3;
    int total = DFS(&graph,1,-1,&weight,arr,NULL,NULL,0);
    printf("Duyet DFS tu dinh A : ");
    printArr(&graph,arr,total);

    //lay ra cach dinh lien ke cua mot dinh
    printf("\n---- CAC DINH LIEN KE CUA DINH A ------\n");
    int total;
    int connect[100] = {0};
    total = getConnected(&graph,1,connect);
    printArr(&graph,connect,total);
 */