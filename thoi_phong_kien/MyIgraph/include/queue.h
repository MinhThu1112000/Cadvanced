#ifndef UNTITLED5_QUEUE_H
#define UNTITLED5_QUEUE_H

#include "dllist.h"

typedef struct Data_q{
    int id;
    int weight;
    struct Data_q *pNext;
}Data_q;
typedef struct Queue{
    Data_q *pHead;
    Data_q *pTail;
}Queue;


Data_q* newData_q(int id,int weight);
void createQueue(Queue *);
int isEmpty(const Queue *);
Data_q* deQueue(Queue *);
void inQueue(Queue *,int id,int weight,int tag);
void freeQueue(Queue *);
int compare(int,int);
int compare_(int,int);
void printQueue(const Queue);
#endif
