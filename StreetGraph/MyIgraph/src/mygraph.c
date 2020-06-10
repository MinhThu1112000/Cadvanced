#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mygraph.h"
#include "queue.h"
#include "jval.h"
#include "jrb.h"
#include "dllist.h"
/*
 * tag == 0 khong trong so
 */
void createGraph(Graph *graph){
    graph->vertex = make_jrb();//cây chứa id và tên đỉnh
    graph->edges = make_jrb();//chưa id và cay con lien ket moi node trong cay con bao gom id cua node lien ket va trong so(neu khong co thì trong so là null)
    return ;
}
/*
 *
 */
void addEdge(Graph *graph,int edge_1,int edge_2,int *weight,int tag){
    JRB p = jrb_find_int(graph->edges,edge_1);
    JRB tree = (JRB)jval_v(p->val);
    if(tree == NULL) {
        tree = make_jrb();
        if(tag == 0) jrb_insert_int(tree,edge_2,new_jval_v(NULL));
        else jrb_insert_int(tree,edge_2,new_jval_i(*weight));
        p->val = new_jval_v(tree);
    }else{
        JRB s = jrb_find_int(tree,edge_2);
        if(s != NULL) return ;
        if(tag == 0) jrb_insert_int(tree,edge_2,new_jval_v(NULL));
        else jrb_insert_int(tree,edge_2,new_jval_i(*weight));
    }
}
void addVertex(Graph *graph,int key,char *mark){
    JRB p = jrb_find_int(graph->vertex,key);
    if(p != NULL) return ;
    //them node voi value la du lieu doc trong file
    jrb_insert_int(graph->vertex,key,new_jval_s(strdup(mark)));
    //them lien ket rong
    jrb_insert_int(graph->edges,key,new_jval_v(NULL));
}
void printGraph(const Graph *graph,int tag){
    printf("\nDanh sach cac id va ten dinh : \n");
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) printf("%-5d : %s\n",jval_i(p->key),(char*)jval_s(p->val));
    printf("Danh sach cac lien ket : \n");
    JRB s,tree;
    jrb_traverse(s,graph->edges){
        int id = jval_i(s->key);
        printf("%-3s : ",jval_s(jrb_find_int(graph->vertex,id)->val));
        tree = (JRB)jval_v(s->val);
        if(tree != NULL) jrb_traverse(p,tree)
            if(p != NULL && tag == 0) printf("%-3s",getName(graph,jval_i(p->key)));
            else printf("%-3s (%d)  ",getName(graph,jval_i(p->key)),getweight(graph,id,jval_i(p->key)));
        printf("\n");
    }
}
void dropGraph(Graph *graph){
    JRB p,tree;
    if(graph->vertex != NULL) {
        jrb_traverse(p, graph->vertex) if (p != NULL) free(jval_s(p->val));
        jrb_free_tree(graph->vertex);
    }
    if(graph->edges != NULL) jrb_free_tree(graph->edges);
}
char* getName(const Graph *graph,int id){
    JRB s = jrb_find_int(graph->vertex,id);
    return jval_s(s->val);
}
int  outDegree(const Graph *graph,int id){
    int t = 0;
    JRB p = jrb_find_int(graph->edges,id);
    JRB tree = (JRB)jval_v(p->val);
    JRB s;
    if(tree != NULL) jrb_traverse(s,tree)
            ++t;
    return t;

}
int inDegree(const Graph *graph,int id){
    int t = 0;
    JRB p,tree,s;
    jrb_traverse(p,graph->edges){
        tree = (JRB)jval_v(p->val);
        if(tree != NULL) jrb_traverse(s,tree)
                if(id == jval_i(s->key)){
                    ++t;
                    break;
                }
    }
    return t;
}
int getVertexCount(const Graph *graph){
    int t = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        if(p != NULL) ++t;
    return t;
}
int getEdgesCount(const Graph *graph){
    int t = 0;
    JRB s,p,tree;
    jrb_traverse(s,graph->edges){
        int id = jval_i(s->key);
        tree = (JRB)jval_v(s->val);
        if(tree != NULL) jrb_traverse(p,tree)
                if(p != NULL) ++t;
    }
    return t;
}
void printArr(const Graph *graph,int *arr,int total,int tag){
    JRB p;
    if(tag == 0)
        for (int i = 0; i < total; ++i) {
            p = jrb_find_int(graph->vertex,arr[i]);
            if(p != NULL) printf("%-3s",jval_s(p->val));
         }
    else
        for (int i = total - 1; i >= 0; --i) {
            p = jrb_find_int(graph->vertex,arr[i]);
            if(p != NULL) printf("%-3s",jval_s(p->val));
        }
}
int checkTopo(const Graph *graph,int *arr){
    int ck[1000] = {-1};
    int connect[1000] = {-1};
    int total = 0;
    int to = 0;
    int t = 0;
    JRB p;
    jrb_traverse(p,graph->vertex)
        ck[jval_i(p->key)] = inDegree(graph,jval_i(p->key));
    do{
        t = 0;
        jrb_traverse(p,graph->vertex)
            if(ck[jval_i(p->key)] == 0){
                arr[total++] = jval_i(p->key);
                to = getConnected(graph,jval_i(p->key),connect);
                for (int i = 0; i < to; ++i) --ck[connect[i]];
                ++t;
                break;
            }
    }while(t!=0);
    if(total == getVertexCount(graph)) return total;
    else return -1;
}
int getweight(const Graph *graph,int edge_1,int edge_2){
    JRB p = jrb_find_int(graph->edges,edge_1);
    JRB tree = (JRB)jval_v(p->val);
    JRB s = jrb_find_int(tree,edge_2);
    return jval_i(s->val);
}
int getConnected(const Graph *graph,int v1,int *arr){
    JRB node = jrb_find_int(graph->edges,v1);
    if(node == NULL) return -1;
    int total = 0;
    JRB tree = (JRB)jval_v(node->val);
    JRB p;
    if(tree != NULL) jrb_traverse(p,tree)
            if(p!= NULL) arr[total++] = jval_i(p->key);

    return total;
}

int DFS(const Graph *graph,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag){
    /*
     * start là đỉnh bắt đầu
     *  end là đỉnh kết thúc ( nếu muốn duyệt toàn bộ thì end = - 1)
     *  weight với trọng số này thì đi được những đỉnh nào ( nếu khoong thì truyền null)
     *  arr là mảng chưa những đỉnh đi qua
     *  time_s là mảng chưa thời gian bắt đầu duyệt 1 đỉnh ( thời gian được thêm vào stack)
     *  time_e là mảng chưá thời gian kết thúc duyệt 1 đỉnh (thời gian đi ra khỏi stack)
     */
    int time = 1;
    int to = 0;
    int x;
    unsigned int w = 3000000000; // trong so là 1 so lon bất kỳ
    if(weight != NULL) w = *weight;// chinh bang trong so
    int vertex[1000];
    int ck[1000] = {0}; // danh
    int c[1000] = {0};
    int total,t;
    Dllist stack = new_dllist(); // tao mang st
    Dllist node;
    dll_append(stack,new_jval_i(start));// them vao cuoi stack
    ck[start] = 2; //
    /*
     * ck == 0  tức là chưa đươcj
     * ck == 1 là đã duyệt xong
     * ck == 2 đang duyệt
     */
    if(time_s != NULL) time_s[start] = time++;
    while(!dll_empty(stack)) {
        node = dll_last(stack);// lay node cuoinod// laays b c[ib] > w
        t = jval_i(node->val); // lay ra gia tri cua node
        dll_delete_node(node);
        if (ck[t] != 1) {
            if (c[t] <= w) {
                if(time_e != NULL) time_e[t] = time++;
                arr[to++] = t;
            }
            ck[t] = 1;
            if (t == end) break;
            total = getConnected(graph, t, vertex);
            for (int i = 0; i < total; ++i) {
                x = 1;// để tăng trọng số
                if (tag != 0) x = getweight(graph, t, vertex[i]);
                if (ck[vertex[i]] == 0) {
                    ck[vertex[i]] = 2;
                    if(time_s != NULL) time_s[vertex[i]] = time++;
                    dll_append(stack, new_jval_i(vertex[i]));
                    c[vertex[i]] = x + c[t];
                }
                if(c[vertex[i]] > c[t] + x) c[vertex[i]] = x + c[t];
            }
        }
    }
    if(weight != NULL){
        JRB s;
        int i;
        jrb_traverse(s,graph->vertex){
            if(c[jval_i(s->key)] <= *weight) {
                for (i = 0; i < to; ++i)//arr
                    if (arr[i] == jval_i(s->key)) break;
                if (i == to) arr[to++] = jval_i(s->key);
            }
        }
    }
    free_dllist(stack);
    return to;
}
int BFS(const Graph *graph,int start,int end,int *weight,int *arr,int *time_s,int *time_e,int tag){
    int time = 1;
    int to = 0;
    int x;
    unsigned int w = 3000000000;
    if(weight != NULL) w = *weight;
    int vertex[1000];
    int ck[1000] = {0};
    int ck2[1000] = {0};
    int c[1000] = {0};
    int total,t;
    Dllist queue = new_dllist();
    Dllist node;
    dll_prepend(queue,new_jval_i(start));
    ck2[start] = 2;
    if(time_s != NULL) time_s[start] = time++;
    while(!dll_empty(queue)) {
        node = dll_last(queue);
        t = jval_i(node->val);
        dll_delete_node(node);
        if (ck[t] != 1) {
            if (c[t] <= w) {
                if(time_e != NULL) time_e[t] = time++;
                arr[to++] = t;
            }
            ck[t] = 1;
            if (t == end) break;
            total = getConnected(graph, t, vertex);
            for (int i = 0; i < total; ++i) {
                x = 1;
                if (tag != 0) x = getweight(graph, t, vertex[i]);
                if (ck[vertex[i]] == 0) {
                    ck[vertex[i]] = 2;
                    if(time_s != NULL ) time_s[vertex[i]] = time++;
                    dll_prepend(queue, new_jval_i(vertex[i]));
                    c[vertex[i]] = x + c[t];
                }
                if (c[vertex[i]] > c[t] + x) c[vertex[i]] = x + c[t];
            }
        }
    }
    if(weight != NULL){
        JRB s;
        int i;
        jrb_traverse(s,graph->vertex){
            if(c[jval_i(s->key)] <= *weight) {
                for (i = 0; i < to; ++i)
                    if (arr[i] == jval_i(s->key)) break;
                if (i == to) arr[to++] = jval_i(s->key);
            }
        }
    }
    free_dllist(queue);
    return to;
}
int checkID(int *idDuong,int id,int total){
    for (int i = 0; i < total; ++i) if(idDuong[i] == id) return i;
    return -1;
}
int timDuong(int *ghiDuong,int end,int *arr){
    int to = 0;
    while(1){
        if(end == -1) break;
        arr[to++] = end;
        end = ghiDuong[end];
    }
    return to;
}
int tinhTien(const Graph *graph,int *ghiDuong,int *idDuong,int total,int end){
    int money = 0;
    while(1){

        if(end == -1) break;
        int d = ghiDuong[checkID(idDuong,end,total)];
        money+= getweight(graph,d,end);
        end = d;
    }
    return money;
}
int dijkstra1(const Graph *graph,int start,int end,int *money,int *arr,int tag_1){
    int ck[1000] = {0};// bang 1 tuc la da duyet,bang 2 tuc la dang duyet
    int weight[1000] = {0};// trong so hay so tien can de di tu start den dinh hien tai
    int ghiDuong[1000] = {-1};
    int idDuong[1000] = {-1};
    int connect[1000] = {0};
    int total_c = 0;
    int total_d = 0;
    Queue queue;
    createQueue(&queue);
    inQueue(&queue,start,0,tag_1);
    weight[start] = 0;
    ck[start] = 2;
    ghiDuong[start] = -1;
    while(!isEmpty(&queue)){
        Data_q *data = deQueue(&queue);
        if(ck[data->id] != 1){
            ck[data->id] = 1;
            if(data->id == end) break;
            total_c = getConnected(graph,data->id,connect);
            for (int i = 0; i < total_c; ++i) {
                if(ck[connect[i]] == 1) continue;
                if(ck[connect[i]] == 2){
                    if(tag_1 == 0 && compare(weight[connect[i]],weight[data->id] + getweight(graph,data->id,connect[i])) > 0){
                        weight[connect[i]] =  weight[data->id] + getweight(graph,data->id,connect[i]);
                        ghiDuong[connect[i]] = data->id;
                    }
                    if(tag_1 != 0 && compare(weight[connect[i]],weight[data->id] + getweight(graph,data->id,connect[i])) < 0){
                        weight[connect[i]] =  weight[data->id] + getweight(graph,data->id,connect[i]);
                        ghiDuong[connect[i]] = data->id;
                    }
                }
                if(ck[connect[i]] == 0){
                    inQueue(&queue,connect[i],getweight(graph,data->id,connect[i]) + weight[data->id],tag_1);
                    ck[connect[i]] = 2;
                    ghiDuong[connect[i]] = data->id;
                    weight[connect[i]] = getweight(graph,data->id,connect[i]) + weight[data->id];
                }
            }
            free(data);
        }
    }
    *money = weight[end];
    int t = -1;
    if(arr != NULL) t = timDuong(ghiDuong,end,arr);
    freeQueue(&queue);
    return t;
}
int dijkstra2(const Graph *graph,int start,int end,int edge,int *money,int *arr,int tag_1){
    int array[100] = {-1};
    int total = dijkstra1(graph,start,end,money,array,tag_1);
    for (int i = 0; i < total; ++i) if(array[i] == edge){
            for (int j = 0; j < total; ++j) arr[j] = array[j];
            return total;
    }
    int t = 0;
    int ax[100];
    for (int k = 0; k < total; ++k)
        ax[k] = arr[k];
    int a_12[100] = {-1};
    int a_23[100] = {-1};
    int a_32[100] = {-1};
    int t_12 = -1;
    int t_23 = -1;
    int t_13 = -1;
    int t_32 = -1;
    int m_12 = 0;
    int m_23 = 0;
    int m_13 = *money;
    int m_32 = 0;
    t_12 = dijkstra1(graph,start,edge,&m_12,a_12,tag_1);
    t_23 = dijkstra1(graph,edge,end,&m_23,a_23,tag_1);
    t_32 = dijkstra1(graph,end,edge,&m_32,a_32,tag_1);
    if(tag_1 == 0){
        if((m_12 + m_23) <= (m_13 + m_32)){
            *money = m_12 + m_23;
            for (int j = 0; j < t_23; ++j)
                arr[t++] = a_23[j];
            for (int i = 1; i < t_12; ++i)
                arr[t++] = a_12[i];

        }else{
            *money = m_13 + m_32;
            for (int j = 0; j < t_23; ++j)
                arr[t++] = a_23[j];
            for (int i = 1; i < total; ++i)
                arr[t++] = ax[i];
        }
    }else{
        if((m_12 + m_23) > (m_13 + m_32)){
            *money = m_12 + m_23;
            for (int j = 0; j < t_23; ++j)
                arr[t++] = a_23[j];
            for (int i = 1; i < t_12; ++i)
                arr[t++] = a_12[i];
        }else{
            *money = m_12 + m_23;
            t = total;
            for (int j = 0; j < t_23; ++j)
                arr[t++] = a_23[j];
            for (int i = 1; i < total; ++i)
                arr[t++] = ax[i];
        }
    }
    return t;
}
int dijkstra(const Graph *graph,int start,int end,int *edge,int *money,int *arr,int tag_1){
    int total ;
    if(edge == NULL)    total = dijkstra1(graph,start,end,money,arr,tag_1);
    else if(edge != NULL) total = dijkstra2(graph,start,end,*edge,money,arr,tag_1);
    return total;
}