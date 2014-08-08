#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int hour;
    int minute;
} TIME;

TIME add(TIME t1,TIME t2);
void display(TIME t);
char** splitChar(int n,char* str,const char delim);
int getNombreMots(char* str, const char delim);
int toInt(char* str);
void titre();


int main(){
    char* chiffre = "12";
    printf("%d",chiffre);

    return 0;
}

int toInt(char* str){
    int thisInt = 0, i = 0;
    while (str[i]){

        i++;
    }
    return thisInt;
}

char** splitChar(int n, char* str,const char delim){
    char** t = NULL;
    int i = 0,ligne = 0,colonne = 0;

    t = malloc(n*sizeof(char*));

    t[0] = malloc(sizeof(char));

    while(str[i]){
        if(str[i] == delim){
            t[ligne][colonne] = '\0';
            ligne++;
            colonne = 0;
            t[ligne] = malloc(sizeof(char));
        }
        else {
            t[ligne][colonne] = str[i];
            colonne++;
        }
        i++;
    }
    t[ligne][colonne] = '\0';

    return t;

}

int getNombreMots(char* str,const char delim){
    int i,n = 0;
    for(i = 0;i < strlen(str);i++){
        if(str[i] == delim) n++;
    }
    return n + 1;
}

TIME add(TIME t1,TIME t2){
    TIME t;
    if (t1.minute + t2.minute >= 60){
        t.minute = (t1.minute + t2.minute)%60;
        if (t1.hour + t2.hour + 1 >= 24){
            t.hour = (t1.hour + t2.hour + 1)%24;
        }
        else t.hour = t1.hour + t2.hour + 1;
    }
    else t.minute = t1.minute + t2.minute;
    return t;
}

void display(TIME t){
    printf("%i : %i",t.hour,t.minute);
}

void titre(){
    printf("******************************************\n");
    printf("*          Aritmethique horaire          *\n");
    printf("******************************************\n\n");
}
