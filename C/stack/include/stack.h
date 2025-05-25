#include <stdio.h>
#include <stdlib.h>

typedef int STDatatype;
typedef struct Stack{
    STDatatype* a;
    int capacity;
    int size;
};
// Stack Init

void StackInit(STDatatype x){
    STDatatype* a = (STDatatype*)malloc(sizeof(STDatatype)*4);
    if(a == NULL){
        perror("malloc fail");
        return;
    }
    
}

