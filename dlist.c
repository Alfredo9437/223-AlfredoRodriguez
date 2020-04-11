#include "dlist.h"
#include <stdlib.h>

dnode* dnode_create(int data, dnode* prev, dnode* next){
    dnode*temp = (dnode*)malloc(sizeof(dnode));
    temp->next = next;
    temp->prev = prev;
    temp->data = data;
    return temp;
}
dlist* dlist_create(void){
    dlist*temp = (dlist*)malloc(sizeof(dlist));
    temp->head = NULL;
    temp->tail = NULL;
    temp->size = 0;
    return temp;
}

bool dlist_empty(dlist* list){ return (list->size == 0);}
size_t dlist_size(dlist* list){return list->size;}

void dlist_popfront(dlist* list){
    if(list->size == 0){ printf("list is empty..."); return;}
    dnode*temp = list->head;
    list->head = list->head->next;
    if(list->size != 1){list->head->prev = NULL;}
    free(temp);
    --list->size;
}
void dlist_popback(dlist* list){
    if(list->size == 0){ printf("list is empty..."); return;}
    dnode*temp = list->tail->prev;
    free(list->tail);
    list->tail = temp;
    list->tail->next = NULL;
   --list->size; 
}

void dlist_pushfront(dlist* list, int data){
    dnode*newhead = dnode_create(data,NULL,list->head);
    if(list->size != 0) { list->head->prev = newhead;}
    list->head = newhead;
    if(list->size == 0) { list->tail = newhead;}
    ++list->size;
}
void dlist_pushback(dlist* list, int data){
    if(list->size == 0){dlist_pushfront(list, data); return;}
    dnode*newtail = dnode_create(data, list->tail, NULL);
    list->tail->next = newtail;
    list->tail = newtail;
    ++list->size;
}
void dlist_clear(dlist* list){
    while (list->size != 0){
        dlist_popfront(list);
    }
    
}
void dlist_print(dlist* list, const char* msg){
    dnode*temp = list->head;
    printf("%s\n", msg);
    while(temp != NULL){
        printf("%14p --> %3d %14p <-- %p\n", temp->prev, temp->data, temp, temp->next);
        temp = temp->next;
    }
}

int dlist_front(dlist* list){return list->head->data;}
int dlist_back(dlist* list){return list->tail->data;}