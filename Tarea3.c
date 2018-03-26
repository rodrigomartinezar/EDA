#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
}node;

node* first = NULL;

void QUEUE(int n);
int DEQUEUE();
void PEEK();
void isEmpty();
int main(){
    int n;
    int m;
    int k;
    isEmpty();
    printf("Ingresa los numeros\n");
    scanf("%i", &n);
    scanf("%i", &m);
    scanf("%i", &k);
    QUEUE(n);
    QUEUE(m);
    QUEUE(k);
    PEEK();
    int x = DEQUEUE();
    printf("%i\n", x);
    
}

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
        if(tmp->next == NULL){
            tmp->next=ptrnew;
            break;
        }
        
    }}
}

int DEQUEUE(){
    int n;
    node *tmp=first;
    first = tmp->next;
    n = tmp->n;
    free(tmp);
    return n;
    
    
}

void PEEK(){
    printf("%i\n", first->n);
}

void isEmpty(){
    if(first == NULL){
        printf("Fila vacía\n");
    }
}

