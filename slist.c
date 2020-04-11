#include "slist.h"
#include <stdlib.h>
snode* snode_create(int data, snode* next){
    snode*temp = (snode*)malloc(sizeof(snode));
    temp->data = data;
    temp->next = next;
    return temp;
}
slist* slist_create(void){
    slist*temp = (slist*)malloc(sizeof(slist));
    temp->head = NULL;
    temp->tail = NULL;
    temp->size = 0;
    return temp;
}

bool slist_empty(slist* list){ return (list->size == 0); }
size_t slist_size(slist* list){ return list->size; }

void slist_popfront(slist* list){
    if(list->size == 0){ printf("list is empty..."); return;}
    snode*oldhead = list->head;
    list->head = list->head->next;
    free(oldhead);
    --list->size;
}
void slist_popback(slist* list){
    if(list->size == 0){ printf("list is empty..."); return;}
    snode*newtail = list->head;
    while(newtail->next != list->tail){newtail = newtail->next;}
    newtail->next = NULL;
    free(list->tail);
    list->tail = newtail;
    --list->size;
}

void slist_pushfront(slist* list, int data){
    snode*newhead = snode_create(data, list->head);
    list->head = newhead;
    if(list->size ==  0){ list->tail = newhead; }
    ++list->size;
}
void slist_pushback(slist* list, int data){
    snode*newtail = snode_create(data, NULL);
    list->tail->next = newtail;
    list->tail = newtail;
    if(list->size == 0){list->head = newtail;}
    ++list->size;
}

void slist_clear(slist* list){
    while(list->size != 0){
        slist_popfront(list);
    }
}

void slist_print(slist* list, const char* msg){
    snode*reader=list->head;
    printf("%s\n", msg);
    while(reader != NULL){
        printf("%d --> %p\n", reader->data, reader->next);
        reader = reader->next;
    }
}

int slist_front(slist* list){ return list->head->data; }
int slist_back(slist* list){ return list->tail->data; }