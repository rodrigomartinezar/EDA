#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 80

void encrypt();
void decrypt();
void menu();
int main() {
    menu();
}

void menu(){
    int ch;
    do {
        printf("\nMENU:\n\n1.- ENCRYPT\n2.-DENCRYPT\n0.-EXIT\n");
        printf("\nChoose an option: ");
        scanf(" %d",&ch);
        switch(ch){
            case 1: encrypt(); break;
            case 2: decrypt(); break;
        }
    }while(ch!=0);
}

void encrypt(){
    char text[MAX_STRING_LEN];
    int check;
    int new_text[strlen(text)+1];
    do {
        int errores[MAX_STRING_LEN];
        check=0;
        printf("\nType the text that's going to be encrypted: ");
        scanf(" %[^\t\n]",text);
        text[strlen(text)]='\0';
       // printf("%s\n", text);
        int i =0;
        while(i<strlen(text)){
            if((int)text[i]==32){ ; }
            new_text[i] = (int)text[i];
          if (new_text[i] < 65 && new_text[i] != 32) {
                check++;
              printf("\nInvalid character in position %d\n", i+1);
            } else if (new_text[i] > 90 && new_text[i] < 97){
                check++;
            }
            if(new_text[i]>122) {
                check++;
                printf("\nInvalid character in position %d\n", i+1);
            }
            i++;
        }
    } while (check!=0);
    /*for(int i=0; i<strlen(text); i++){
        printf("%d ", new_text[i]);
    }*/
    int key;
    printf("\nType the shift value that's going to be used to encrypt the text: ");
    do{
        scanf(" %d", &key);
        if(key<-26 || key>26) printf("\nInvalid key. Try a number between -26 and 26\n");
    } while(key<-26 || key>26);
    int i=0;
    while(i<strlen(text)){
        if(new_text[i]==32) i++;
        if(new_text[i]>96 && new_text[i]<123) new_text[i] = new_text[i]-32;
            new_text[i]=new_text[i]+key;
            if(new_text[i]<65) new_text[i]=new_text[i]+26;
            if(new_text[i]>90) new_text[i]=new_text[i]-26;
        i++;
    }
    char encrypted[MAX_STRING_LEN];
    for(int z=0; z<(strlen(text));z++){
        encrypted[z]=(char)new_text[z];
    }
    int j=0;
    while(j<(strlen(encrypted))){
        if((int)encrypted[j]==32){
            printf("");
            j++;
        }
        printf("%c", encrypted[j]);
        j++;
    }
}

void decrypt(){
    char text[MAX_STRING_LEN];
    int old_text[strlen(text)];
    int check=0;
    int i;
    do{
        i=0;
        check=0;
        printf("\nType the text that's going to be decrypted: ");
        scanf(" %[^\t\n]",text);
        text[strlen(text)]='\0';
        while(i<strlen(text)){
            old_text[i]=(int)text[i];
            if((int)text[i]==32){
                check++;
                printf("\nBlank space in position %d. Invalid text, try again\n", i+1);
            }
            i++;
        }
    }while(check != 0);
    int key;
    printf("\nType shift value: ");
    scanf(" %d", &key);
    for(int i =0; i<strlen(text); i++){
        printf("\nText: %d", old_text[i]);
        old_text[i]=old_text[i]-key;
        printf("+ %d = %d", key, old_text[i]);
        if(old_text[i]<65) old_text[i]=old_text[i]+26;
        if(old_text[i]>90) old_text[i]=old_text[i]-26;
        printf("%d\n", old_text[i]);
    }
    char decrypted[MAX_STRING_LEN];
    for(int i=0; i<strlen(text); i++){
        decrypted[i]=(char)old_text[i];
    }
    decrypted[strlen(decrypted)]='\0';
    printf("\nDecrypted text:\n");
    for(int i=0; i<strlen(decrypted); i++){
        printf("%c", decrypted[i]);
    }
}