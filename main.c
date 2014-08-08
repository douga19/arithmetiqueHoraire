#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int hour;
    int minute;
} TIME;

TIME add(TIME t1,TIME t2);
void display(TIME t);
char** splitChar(int n,char* str,const char* delim);
int getNombreMots(char* str, const char delim);


int main(){
    printf("******************************************\n");
    printf("*          Aritmethique horaire          *\n");
    printf("******************************************\n\n");

    //entrée des données
    int i = 0;
    char *str;
    str = "je:suis:rado:et:oui";

    i = getNombreMots(str,':');
    printf("Il y a %d mot(s)\n",i);



    //sortie des résultats
    return 0;
}

/*char** splitChar(int n, char* str,const char* delim){
    char** t = NULL;
    int i = 0;
    t = malloc(n*sizeof(char*));
    for(i = 0;i < n;i++){
        *t[i] = malloc()
    }

}*/

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
