//
// Created by Rodrigo Martínez on 04-04-2018.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int n;
    struct node* next;
}node;

node* first1 = NULL;
node* first2 = NULL;

void QUEUE(int n, int lista) {
    node *ptrnew = (node *) malloc(sizeof(node));
    ptrnew->n = n;
    ptrnew->next = NULL;
    if (lista == 1) {
        if (first1 == NULL) {
            first1 = ptrnew;
        } else if (ptrnew->n < first1->n) {
            ptrnew->next = first1;
            first1 = ptrnew;
        } else {
            node *ptr = first1;
            node *tmp = first1;
            for (;;) {
                if (ptr->next == NULL) {
                    tmp = ptr;
                    ptr->next = ptrnew;
                    break;
                } else if (ptr->next->n > ptrnew->n) {
                    ptrnew->next = ptr->next;
                    ptr->next = ptrnew;
                    break;
                }
                ptr = ptr->next;
            }
        }
    }
    else
        if(lista == 2){
            if (first2 == NULL) {
                first2 = ptrnew;
            } else if (ptrnew->n < first2->n) {
                ptrnew->next = first1;
                first2 = ptrnew;
            } else {
                node *ptr = first2;
                node *tmp = first2;
                for (;;) {
                    if (ptr->next == NULL) {
                        tmp = ptr;
                        ptr->next = ptrnew;
                        break;
                    } else if (ptr->next->n > ptrnew->n) {
                        ptrnew->next = ptr->next;
                        ptr->next = ptrnew;
                        break;
                    }
                    ptr = ptr->next;
                }
            }}
    else printf("\nOpcion invalida\n");
}

int DEQUEUE(int lista) {
    if (lista == 1) {
        if (first1 != NULL) {
            int n;
            node *tmp = first1;
            first1 = tmp->next;
            n = tmp->n;
            free(tmp);
            return n;
        } else
            return 0;
    }
    else
        if(lista == 2){
            if (first2 != NULL) {
                int n;
                node *tmp = first2;
                first2 = tmp->next;
                n = tmp->n;
                free(tmp);
                return n;
            } else
                return 0;
        }
}

void PEEK(int lista){
    if(lista == 1){
    if(first1 != NULL)
        printf("%i\n", first1->n);
    else
        printf("Fila vacía\n");
    }
    else
        if(lista == 2){
            if(first2 != NULL)
                printf("%i\n", first2->n);
            else
                printf("Fila vacía\n");
        }
}

void ISEMPTY(node* first){
    if(first == NULL){
        printf("Fila vacía\n");
    }
    else{
        printf("Fila no vacía\n");
    }
}

node* INVERTIR_LISTA(node* first){
    if (first != NULL) {
        node *last = first;
        while (last->next != NULL) {
            last = last->next;
        }
        node *lasttmp = last;
        while (lasttmp != first) {
            node *tmp = first;
            while (tmp->next != lasttmp) {
                tmp = tmp->next;
            }
            lasttmp->next = tmp;
            lasttmp = tmp;
        }
        lasttmp->next = NULL;
        first = last;
        return first;
    }
    else printf("\nLista vacia\n"); return NULL;
}

void MOSTRAR_LISTA(node* first){
    printf("\nLista: ");
    node* ptr = first;
    while (ptr != NULL)
    {
        printf("%i ", ptr->n);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void ELIMINA_REPETIDOS(node* first){
    node* tmp = first;
    node* tmp2;
    if(tmp == NULL) printf("\nLista vacia");
    else{
        if(tmp->next == NULL) printf("\nSolo hay un elemento en la lista\n");
        else
        if(tmp->next->n == tmp->n) tmp->next = NULL;
        else {
            for (;;) {
                int numero_buscado = tmp->n;
                tmp2 = tmp->next;
                while(tmp2!=NULL){
                    if(numero_buscado == tmp2->n){
                        tmp->next = tmp2->next;
                        tmp2 = tmp->next;
                    }
                    else{
                        tmp2 = tmp2->next;
                    }
                }
                tmp = tmp->next;
                if(tmp->next == NULL) break;
            }
        }
    }
}

int k_antes_del_ultimo(int k, node* first){
    node* last = first;
    node* tmp = first;
    if(first == NULL) printf("\nLista vacia\n");
    else
        if(first->next == NULL) printf("\nSolo hay un elemento en la lista\n");
    else{
            while(last->next != NULL) last=last->next;
            for(int i = 0; i<k; i++){
                while(tmp->next != last) tmp = tmp->next;
                last = tmp;
                tmp = first;
            }
            return last->n;
        }
}


