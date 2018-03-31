#include "stdio.h"

//void buscar();
int main(){
    int largo;
    printf("Largo del arreglo: ");
    scanf(" %i", &largo);
    int Numeros[largo];
    int c;
    int n;
    int posicion=0;
    int buscado;
    int encontrado = 0;
    int mitad = largo/2;
    int buscando;
    do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
                "1.- Ingresar número\n"
                "2.- Mostrar arreglo\n"
                "3.- Buscar número\n"
                "0.- Quit\n");
        printf("Elija una opción: ");
        scanf(" %i", &c);
        
        switch(c)
        {
            case 1: 
                if(posicion<largo){printf("Numero: ");
                scanf(" %i", &n);
                Numeros[posicion] = n;
                posicion++;
                }
                else {printf("\n\nARREGLO LLENO\n");}
                //ordena arreglo
                for(int i=0; i<largo; i++){
                    for (int j=0; j<largo; j++){
                        if(Numeros[j]> Numeros[i]){
                            int tmp = Numeros[i];
                            Numeros[i] = Numeros[j];
                            Numeros[j]=tmp;
                        }
                    }
                }
                break;
            case 2:
                if(posicion<largo){
                    printf("\n ARREGLO AUN NO SE LLENA");
                }
                else{
                    printf("\n");
                for(int i = 0; i<largo; i++){
                            printf("%i ", Numeros[i]);
                }}
                break;
            case 3:
                buscando = mitad;
                printf("Numero a buscar: ");
                scanf(" %i", &buscado);
                //busca binaria
                do{
                    if(largo == 1){
                        if(Numeros[0] == buscado){
                        printf("\nNumero buscado es el unico elemento del arreglo\n");
                        encontrado++;
                        }
                        else{
                            printf("\nNumero no se encuentra en el arreglo\n");
                            encontrado++;
                        }
                    }
                    else{
                    if(Numeros[buscando] == buscado){ 
                        printf("Numero buscado: %i en posicion: %i\n", buscado, buscando);
                        encontrado++;}
                    if(Numeros[buscando]> buscado){
                        buscando--;
                        if(buscando == 0){
                            if(Numeros[buscando] == buscado){
                                printf("Numero buscado: %i en posicion: %i\n", buscado, buscando);
                                encontrado++;
                            }
                            if(Numeros[buscando] != buscado){
                                printf("\nEl numero buscado no se encuentra en el arreglo\n");
                                encontrado++;
                            }
                        
                    }
                    }
                    if(Numeros[buscando]<buscado){
                        buscando++;
                        if(buscando == largo){
                        printf("\nEl numero buscado no se encuentra en el arreglo\n");
                        encontrado++;
                    }
                    }
                   
                    
                }}while(encontrado == 0);
                break;
        }
    }
    while(c != 0);
}

