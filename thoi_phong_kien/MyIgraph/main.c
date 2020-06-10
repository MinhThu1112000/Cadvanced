#include <stdio.h>
#include <stdlib.h>
#include "fields.h"
#include "mygraph.h"
int matranke[100][100];
int n, m;
void readFile(Graph *graph, char *fileName){
   IS is = new_inputstruct(fileName);
   get_line(is);
   n = atoi(is->fields[0]);
   m = atoi(is->fields[1]);
   for(int i = 0 ; i < m; i++){
       get_line(is);
       addVertex(graph, atoi(is->fields[0]),is->fields[0] );
       addVertex(graph, atoi(is->fields[1]),is->fields[1] );
       int c = atoi(is->fields[2]);
       //addEdge(graph, atoi(is->fields[1]), atoi(is->fields[0]), &c, 1);
       //matranke[atoi(is->fields[1])][atoi(is->fields[0])] = 1;
       addEdge(graph, atoi(is->fields[0]), atoi(is->fields[1]), &c, 1);
       matranke[atoi(is->fields[0])][atoi(is->fields[1])] = 1;
   }
   jettison_inputstruct(is);

}
int arr[20];
void layDinh(Graph *graph, int *k) {
    for (int i = 0; i < 15; i++) {
        arr[i] = 0;
    }
    int j = 1;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if(max < inDegree(graph,i)){
            max = inDegree(graph,i);
            *k = i;
        }
        if (inDegree(graph, i) == 1) {
            arr[i] = i;
        }
    }

}


int main(int argc,char *argv[]){
    Graph graph;
    createGraph(&graph);
    readFile(&graph, "dothi.txt");
    for(int i = 1; i <= n; i++ ){
        for(int j = 1; j <=n ; j++){
            printf("a[%d][%d] : %d\t", i,j,matranke[i][j]);
        }
        printf("\n");
    }
    int k;
    printGraph(&graph,1);
    layDinh(&graph, &k);
    for(int i = 1; i <=n; i++){
        if(arr[i] != 0){
            for(int j = 1; j <= n; j++){
                if(matranke[j][arr[i]] == 1 && getweight(&graph,j, arr[i]) >= 50){
                    printf("Go From %d  to %d \n", j, arr[i]);
                }
            }
        }
    }
    printf("Dinh co bac cao nhat : %d\n",k);
    int id1, id2, time;
    int duongdi[20];
    printf("Nhap id1 : ");
    scanf("%d", &id1);
    printf("Nhap id2 : ");
    scanf("%d", &id2);
    int total = dijkstra(&graph,id1,id2,NULL,&time,duongdi,0);
    printf("So tien : %d\n ",time);
    printArr(&graph,arr,total,1);

    dropGraph(&graph);

    return 0;
}





