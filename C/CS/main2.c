#include <stdio.h>

int main(){
    FILE* fp = fopen("hello.txt","w");

    fputs("hello,B1129055",fp);




    return 0;
}