#include "../include/LList.h"

void Print(LNode *phead){
    LNode *cur = phead;
    while(cur){
        printf("%c : %d\n",cur->data,cur->count);
        cur = cur->next;
    }
    printf("NULL\n");
}

LNode* CreateNode(LListDataType ch){
    LNode* newnode = (LNode*)malloc(sizeof(LNode));
    if(newnode == NULL){
        perror("malloc fail");
    }
    newnode->count = 1;
    newnode->data = ch;
    return newnode;
}

void LListPushBack(LNode** pphead, LListDataType ch){
    LNode* newnode = CreateNode(ch);
    
    // 如果是插入頭節點
    if(*pphead == NULL){
        *pphead = newnode;
    }
    // 找尾
    else{
       LNode* tail = *pphead;
       while(tail->next != NULL){
        tail = tail->next;
       } 
       tail->next = newnode;
    }
}