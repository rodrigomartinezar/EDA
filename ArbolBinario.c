#include <stdio.h>
#include <stdlib.h>
#define COUNT 10;

typedef struct arbol{
    int n;
    struct arbol* left;
    struct arbol* right;
}arbol;

arbol* root = NULL;

arbol* insertar(arbol* root, int n);
arbol* crearNodo(int n);
void mostrarArbol(arbol* root, int space);
arbol* buscar(arbol* root, int n);
arbol* eliminar(arbol* root, int n);
int alturaAB(arbol* root);

int main(){
    root = insertar(root, 30);
    insertar(root, 20);
    insertar(root, 40);
    insertar(root, 60);
    insertar(root, 100);
    mostrarArbol(root, 0);
    printf("\nAltura: %d\n", alturaAB(root));
    eliminar(root, 60);
    mostrarArbol(root, 0);
    printf("\nAltura: %d\n", alturaAB(root));
}

arbol* crearNodo(int n){
    arbol* ptrnew = (arbol*)malloc(sizeof(arbol));
    ptrnew->n = n;
    ptrnew->right = NULL;
    ptrnew->left = NULL;
    return ptrnew;
}
arbol* insertar(arbol* root, int n){

    if(root == NULL){
        return crearNodo(n);
    }
    if(n <= root->n) root->left = insertar(root->left, n);
    else
    if(n > root->n)  root->right = insertar(root->right, n);
    return root;
}

void mostrarArbol(arbol* root, int space){
    if(root == NULL) return;
    space+= COUNT;
    mostrarArbol(root->right, space);
    printf("\n");
    int i = COUNT;
    while(i<space){
        printf(" ");
        i++;
    }
    printf("%d\n", root->n);

    mostrarArbol(root->left, space);
}

arbol* buscar(arbol* root, int n){
    if(root == NULL || root->n == n) return root;

    if(root->n <= n) return buscar(root->right, n);

    return buscar(root->left, n);
}

arbol* eliminar(arbol* root, int n){
    if(root == NULL) return root; //caso base

    if(n < root->n) root->left = eliminar(root->left, n); //si es n es menor que root
    else
    if(n > root->n) root->right = eliminar(root->right, n);// si n es mayor que root
    else{ //si no se cumple lo anterior es el que hay que eliminar
        if(root->left == NULL){
            arbol* tmp = root->right;
            free(root);
            return tmp;
        }
        else
        if(root->right == NULL){
            arbol* tmp = root->left;
            free(root);
            return tmp;
        }
    }
    return root;
}


int alturaAB(arbol* root)
{
    int AltIzq, AltDer;

    if(root==NULL)
        return 0;
    else
    {
        AltIzq = alturaAB(root->left);
        AltDer = alturaAB(root->right);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}