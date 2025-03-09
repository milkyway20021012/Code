#include <stdio.h>

int my_strlen(char *s){
    if((*s) == '\0'){
        return 0;
    }
    return 1 + my_strlen(++s);
}

int main(){
    char s[] = "IU is a girl!";
    int ret = my_strlen(s);
    printf("%d\n",ret);

    return 0;
}