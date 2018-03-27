#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
}node;

node* first = NULL;

void QUEUE(int n){
    node* ptrnew = (node*)malloc(sizeof(node));
    ptrnew->n= n;
    ptrnew->next=NULL;
    if(first == NULL){
        first = ptrnew;
    }
    else{
        node* tmp = first;
        while(1>0){
            if(tmp->next != NULL){
                tmp = tmp->next;
            }
            if(tmp->next == NULL){
                tmp->next=ptrnew;
                break;
            }
        }}
}

int DEQUEUE(){
    if(first != NULL){
    int n;
    node *tmp=first;
    first = tmp->next;
    n = tmp->n;
    free(tmp);
    return n;}
    else
    return 0;
    
    
}

void PEEK(){
    if(first != NULL)
    printf("%i\n", first->n);
    else
    printf("Fila vacía\n");
}

void isEmpty(){
    if(first == NULL){
        printf("Fila vacía\n");
    }
    else{
        printf("Fila no vacía\n");
    }
}

