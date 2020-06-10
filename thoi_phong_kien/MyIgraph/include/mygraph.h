#ifndef UNTITLED5_MYGRAPH_H
#define UNTITLED5_MYGRAPH_H

#include "jrb.h"
#include "jval.h"
typedef struct Graph{
    JRB vertex; //dinh
    JRB edges;  //lien ket
}Graph;

void  createGraph(Graph *); // tao cay
void addEdge(Graph *,int edge_1,int edge_2,int *weight,int tag); //them lien ket giua hai dinh
void addVertex(Graph *,int key,char *mark); //them dinh bang id va chua ten
void printGraph(const Graph *,int tag); // in graph
int inDegree(const Graph *,int key); //  dinh vao
int outDegree(const Graph *,int key); // dinh ra
int getVertexCount(const Graph *);// dem so dinh
int getEdgesCount(const Graph *); // dem so lien ket
int checkTopo(const Graph *,int *arr); // kiem tra topo
int dijkstra(const Graph *,int start,int end,int *edge,int *money,int *arr,int tag_1); // tim duong ngan nhat
int DFS(const Graph *,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag);
int BFS(const Graph *,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag);
void printArr(const Graph *,int *arr,int total,int tag);
int getweight(const Graph *,int edge_1,int edge_2);
char* getName(const Graph *,int id);
int getConnected(const Graph *graph,int v1,int *arr);
void dropGraph(Graph *graph);

#endif
