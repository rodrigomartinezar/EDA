#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LEN 80

typedef struct circular{
    char nombre[MAX_STRING_LEN];
    struct circular* next;
}circular;

typedef struct lineal{
    char nombre_playlist[MAX_STRING_LEN];
    int total_canciones;
    struct circular* next;
    struct lineal* pre;
    struct lineal* next_lineal;
}lineal;

void AGREGAR_CANCION();
void MOSTRAR_PLAYLIST();
void MENU();
void ELIMINAR_CANCION();
void CREAR_PLAYLIST();
lineal* BUSCA_PLAYLIST(char playlist[MAX_STRING_LEN]);
circular* BUSCA_CANCION(char cancion[MAX_STRING_LEN], lineal* tmp);
//void ELIMINAR_PLAYLIST();
//void MOSTRAR_PLAYLISTS();
////LAS FUNCIONES COMENTADAS NO SE UTILIZAN PARA LOGRAR EL OBJETIVO DEL EJERCICIO. SON EXTRAS


lineal* first_lineal = NULL;
lineal* last_lineal = NULL;

int main() {
    MENU();
}

void MENU() {
    int ch;
    for(;;){
        printf("MENU:\n1.- CREAR PLAYLIST\n2.- MOSTRAR ORDEN REPRODUCCION PLAYLIST\n3.- AGREGAR CANCION\n4.- ELIMINAR CANCION\n0.- EXIT\n");
        scanf(" %d", &ch);
        scanf("%*c");
        if(ch == 1) CREAR_PLAYLIST();
        if(ch == 2) MOSTRAR_PLAYLIST();
        if(ch == 3) AGREGAR_CANCION();
        if(ch == 4) ELIMINAR_CANCION();
        if(ch == 0) break;
    }
}

void CREAR_PLAYLIST() {
    lineal *ptrnew = (lineal *) malloc(sizeof(lineal));
    ptrnew->total_canciones = 0;
    ptrnew->next_lineal = NULL;
    ptrnew->pre = NULL;
    ptrnew->next = NULL;
    char nombre_playlist[MAX_STRING_LEN];
    if (first_lineal == NULL) {
        first_lineal = ptrnew;
        last_lineal = ptrnew;
        printf("\nDa un nombre a la playlist: ");
        fgets(nombre_playlist, MAX_STRING_LEN, stdin);
        nombre_playlist[strlen(nombre_playlist)] = '\0';
        for(int i = 0; i<strlen(nombre_playlist); i++){
            ptrnew->nombre_playlist[i] = nombre_playlist[i];
        }
    }
    else {
    if (first_lineal->next_lineal == NULL && first_lineal != NULL) {
        first_lineal->next_lineal = ptrnew;
        ptrnew->pre = first_lineal;
        last_lineal = ptrnew;
    }
    else {
        lineal *tmp = first_lineal;
        while (tmp->next_lineal != NULL) tmp = tmp->next_lineal;
        tmp->next_lineal = ptrnew;
        ptrnew->pre = tmp;
        last_lineal = ptrnew;
    }
        lineal* tmp2 = NULL;
        printf("\nDa un nombre a la playlist: ");
        do{
            fgets(nombre_playlist, MAX_STRING_LEN, stdin);
            nombre_playlist[strlen(nombre_playlist)] = '\0';
            tmp2 = BUSCA_PLAYLIST(nombre_playlist);
            if(tmp2 != NULL) printf("\nEsa playlist ya existe. Ingresa otro nombre\n");
        }while(tmp2 != NULL);
        for(int j = 0; j<strlen(nombre_playlist);j++){
            ptrnew->nombre_playlist[j]=nombre_playlist[j];
        }
    }

}

/*void MOSTRAR_PLAYLISTS(){
  if(first_lineal != NULL) {
      lineal *tmp = first_lineal;
      while (tmp != NULL) {
          for (int i = 0; i < strlen(tmp->nombre_playlist); i++) {
              printf("%c", tmp->nombre_playlist[i]);
          }
          if(tmp->total_canciones>1)printf(" %d canciones\n", tmp->total_canciones);
          else
          if(tmp->total_canciones == 1) printf(" %d cancion\n", tmp->total_canciones);
          else printf("\nNo hay canciones\n");
          tmp = tmp->next_lineal;
      }
  }
  else printf("\nNo hay playlists\n");
}*/
void AGREGAR_CANCION() {
    if (first_lineal != NULL) {
        circular *ptrnew = (circular *) malloc(sizeof(circular));
        circular* last_circular;
        char playlist[MAX_STRING_LEN];
        printf("\nA que playlist deseas agregar una nueva cancion?\n");
        fgets(playlist, MAX_STRING_LEN, stdin);
        playlist[strlen(playlist)]='\0';
        char cancion[MAX_STRING_LEN];
        lineal* tmp = BUSCA_PLAYLIST(playlist);
        if(tmp != NULL){
            if(tmp->next == NULL){
                ptrnew->next = ptrnew;
                last_circular=ptrnew;
                tmp->next = last_circular->next;
            }
            else{
                last_circular = tmp->next;
                while(last_circular->next != tmp->next) last_circular = last_circular->next;
                ptrnew->next = last_circular->next;
                last_circular->next = ptrnew;
                last_circular = ptrnew;
                tmp->next = last_circular->next;
            }
            printf("\nQue cancion deseas agregar?\n");
            fgets(cancion, MAX_STRING_LEN, stdin);
            cancion[strlen(cancion)] = '\0';
            for(int i = 0; i<strlen(cancion); i++){
                ptrnew->nombre[i] = cancion[i];
            }
            ptrnew->nombre[strlen(cancion)]='\0';
            tmp->total_canciones++;
        }
        else printf("\nNo existe esa playlist\n");
    }
    else printf("\nNo hay playlists creadas!\n");
}

void MOSTRAR_PLAYLIST(){
    printf("\nQue playlist deseas ver?\n");
    char playlist[MAX_STRING_LEN];
    fgets(playlist, MAX_STRING_LEN, stdin);
    playlist[strlen(playlist)]='\0';
    lineal* tmp = BUSCA_PLAYLIST(playlist);
    if (tmp != NULL) {
        if(tmp->next == NULL){
            printf("\nLista vacia\n");
        }
        else {
            circular* last_circular = tmp->next;
            while(last_circular->next != tmp->next) last_circular = last_circular->next;
            circular *tmp2 = NULL;
            tmp2 = last_circular->next;
            if (tmp2 == NULL) printf("\nPlaylist vacia\n");
            else if (tmp2 == last_circular) {
                for (int i = 0; i < strlen(tmp2->nombre); i++) {
                    printf("%c", tmp2->nombre[i]);
                }
                printf("\n");
            } else {
                while (tmp2->next != last_circular->next) {
                    for (int i = 0; i < strlen(tmp2->nombre); i++) {
                        printf("%c", tmp2->nombre[i]);
                    }
                    printf("\n");
                    tmp2 = tmp2->next;
                }
                for (int i = 0; i < strlen(tmp2->nombre); i++) {
                    printf("%c", last_circular->nombre[i]);
                }
                printf("\n");
            }
        }
    }
    else printf("\nNo existe esa playlist\n");
}

lineal* BUSCA_PLAYLIST(char playlist[MAX_STRING_LEN]){
    lineal* tmp = first_lineal;
    int verificador;
    for(;;){
        verificador = 0;
        for(int i=0; i<strlen(playlist); i++){
            if(tmp->nombre_playlist[i] == playlist[i]) verificador++;
        }
        if(verificador == strlen(playlist)) break;

        tmp = tmp->next_lineal;
        if(tmp == NULL) break;
    }
    return tmp;
}

circular* BUSCA_CANCION(char cancion[MAX_STRING_LEN], lineal* tmp){
    circular* tmp2 = tmp->next;
    int verificador;
    if (tmp->total_canciones>1){
        for(;;){
            verificador = 0;
            for(int i = 0; i<strlen(cancion); i++){
                if(tmp2->nombre[i] == cancion[i]) verificador++;
            }
            if(verificador == strlen(cancion)) break;
            tmp2 = tmp2->next;
            if(tmp2 == tmp->next){
                tmp2 = NULL;
                break;
            }
        }
    }
    else{
        verificador = 0;
        for(int i = 0; i<strlen(cancion); i++){
            if(tmp2->nombre[i] == cancion[i]) verificador++;
        }
        if(verificador != strlen(cancion)) tmp2 = NULL;
    }
    return tmp2;
}



void ELIMINAR_CANCION() {
    if (first_lineal != NULL) {
        char playlist[MAX_STRING_LEN];
        printf("\nDe que playlist?: ");
        fgets(playlist, MAX_STRING_LEN, stdin);
        playlist[strlen(playlist)]='\0';
        lineal* tmp = BUSCA_PLAYLIST(playlist);
        if (tmp != NULL) {
            if(tmp->next == NULL) printf("\nPlaylist vacia\n");
            else{
                printf("\nQue cancion quieres eliminar?: ");
                char cancion[MAX_STRING_LEN];
                fgets(cancion, MAX_STRING_LEN, stdin);
                cancion[strlen(cancion)] = '\0';
                circular* tmp2 = BUSCA_CANCION(cancion, tmp);
                if(tmp2 == NULL) printf("\nCancion no encontrada en la playlist\n");
                else{
                    circular* curr = tmp->next;
                    circular* prev = tmp->next;
                    while(curr != tmp2){
                        prev = curr;
                        curr = curr->next;
                    }
                    if(curr->next == curr){
                        tmp->next = NULL;
                        free(curr);
                    }
                    else{
                        if(curr == tmp->next){
                            while(prev->next != curr) prev = prev->next;
                            tmp->next = tmp->next->next;
                            prev->next = tmp->next;
                            free(curr);
                        }
                        else
                        if(curr->next == tmp->next){
                            prev->next = tmp->next;
                            free(curr);
                        }
                        else{
                            prev->next = curr->next;
                            free(curr);
                        }
                    }
                    tmp->total_canciones--;
                }
            }
        }
        else printf("\nNo existe esa playlist\n");
    }
    else printf("\nNo hay playlists!\n");
}

/*void ELIMINAR_PLAYLIST(){
    if (first_lineal!=NULL) {
        printf("\nQue playlist deseas eliminar?: ");
        char playlist[MAX_STRING_LEN];
        fgets(playlist, MAX_STRING_LEN, stdin);
        playlist[strlen(playlist)]='\0';
        lineal* tmp = BUSCA_PLAYLIST(playlist);
        if(tmp == first_lineal){
            first_lineal = tmp->next_lineal;
        }
        if(tmp->next_lineal != NULL){
            tmp->next_lineal->pre = tmp->pre;
        }
        if(tmp->pre != NULL){
            tmp->pre->next = tmp->next;
        }
        free(tmp);
    }
    else printf("\nNo hay playlists!\n");
}*/


