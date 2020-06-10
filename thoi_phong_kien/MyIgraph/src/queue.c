#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Data_q* newData_q(int id,int weight){
    Data_q *data = (Data_q*)calloc(1,sizeof(Data_q));
    data->weight = weight;
    data->id = id;
    data->pNext = NULL;
    return data;
}
void createQueue(Queue *queue){
    queue->pTail = NULL;
    queue->pHead = NULL;
}
int isEmpty(const Queue *queue){
    if(queue == NULL) return 2;
    if(queue->pHead == NULL) return 2;
    return 0;
}
Data_q* deQueue(Queue *queue){
    if(isEmpty(queue)) return -1;
    Data_q *data = queue->pHead;
    queue->pHead = data->pNext;
    return data;
}
void insert1(Queue *queue,Data_q *data,int tag){
    Data_q *s = NULL;
    Data_q *p = queue->pHead;
    if(tag == 0)
        while(compare(data->weight,p->weight) >= 0){
            s = p;
            p = p->pNext;
            if(p == NULL) break;
        }
    else
        while(compare(data->weight,p->weight) <= 0){
            s = p;
            p = p->pNext;
            if(p == NULL) break;
        }
    if(s == NULL){
        data->pNext = p;
        queue->pHead = data;
    }else if(p == NULL){
        queue->pTail->pNext = data;
        queue->pTail = data;
    }else{
        s->pNext = data;
        data->pNext = p;
    }
}
void inQueue(Queue *queue,int id,int weight,int tag){
    Data_q *data =newData_q(id,weight);
    if(isEmpty(queue)) queue->pHead = queue->pTail = data;
    else insert1(queue,data,tag);
}
void freeQueue(Queue *queue){
    while(!isEmpty(queue)) free(deQueue(queue));
}
int compare(int a,int b){
    return a - b;
}

void printQueue(const Queue queue){
    Data_q *p;
    for (p = queue.pHead; p != NULL ; p = p->pNext)
        printf("| %-2d : %-2d | ",p->id,p->weight);
}