#include <stdio.h>
#include <stdlib.h>

void menu();
int busquedaBinaria(int arr[], int clave, int bajo, int alto, int l);
void ingresarDatos(int l, int arr[]);
void bubbleSort(int l, int arr[]);
void busqueda(int l, int arr[]);
int repetido_antes, repetido_despues;

int main() {
  menu();
}



void menu(){
  int largo;
  int ch;
  do{
  printf("Elija el largo del arreglo: ");
  scanf(" %i", &largo);
  if(largo<1)
    printf("Elección inválida\n");
  }while(largo<1);
  int numeros[largo];
  
  printf("Ingrese los datos en el arreglo ");
  ingresarDatos(largo, numeros);
  bubbleSort(largo, numeros);
  
  while(1){  
    printf("\nElija una de las opciones:\n");
    printf("1.Buscar un numero en el arreglo\n2.Exit\n");
    printf("Elija (1 o 2):\n");
    scanf("%d",&ch);
    switch(ch){
      case 1: repetido_antes = 0;
              repetido_despues=0;
              busqueda(largo, numeros);
              break;
      case 2: exit(0);
      default: printf("\nElección invalida, elija del 1-2.");
    }
  }
}


void busqueda(int l, int arr[]){ 
  int llave; //valor a localizar en el arreglo a
  int resultado; //variable para almacenar la ubicación de la llave o -1
  
  printf("Introduzca un numero para buscar en el arreglo: ");
  scanf("%d", &llave );
  
  resultado = busquedaBinaria(arr, llave, 0, (l - 1), l);

  if (resultado == -1 ) {
    printf("\n%d no se encuentra en el arreglo\n", llave);
  } 
  else {
   printf( "\n%d se encuentra en el elemento %d del arreglo\n", llave, resultado);
   if(repetido_antes!=0)
   printf("\nEl número se repite en la posición %d del arreglo\n", resultado-1);
   if(repetido_despues!=0)
   printf("\nEl número se repite en la posición %d del arreglo\n", resultado+1);
  } 
} 

int busquedaBinaria(int arr[], int clave, int bajo, int alto, int l ) {
    int central = ( bajo + alto ) / 2;
    if(bajo>alto){
        return -1;
    }
    if(clave == arr[central] ) {
      if(central>0){
        if(clave == arr[central-1]){
          repetido_antes++;
        }
      }
      if(central<l-1){
        if(clave== arr[central+1]){
          repetido_despues++;
        }
      }
      return central;
    }

    if(clave < arr[central] ) {
        return busquedaBinaria(arr, clave, bajo, central - 1, l);
    }
    if(clave > arr[central] ) {
        return busquedaBinaria (arr, clave, central + 1, alto, l);
    }
    return 0;  //tiraba error de non-void function
}    

void ingresarDatos(int l, int arr[]){
  int i;
  for (i = 0; i < l; i++ ) {
    scanf("%i", &arr[i]);
  }
  printf("Todos los datos ingresados\n" );
}

void bubbleSort(int l,int arr[]){
  int i, j, temp;
 
  for (i = 0 ; i < (l - 1 ); i++){
    for (j = 0 ; j < l - i - 1; j++){
      if (arr[j] > arr[j+1]){
        temp     = arr[j];
        arr[j]   = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}