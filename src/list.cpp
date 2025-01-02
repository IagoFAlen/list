#ifndef LIST_FUNCTIONS_DEFINED
#define LIST_FUNCIONS_DEFINED

#include "list.hpp"

using namespace std;
using namespace ds_list;

bool ds_list::is_empty(LIST_INFO* listInfo){
    if(listInfo->list == NULL)
        return true;
    
    return false;
}

bool ds_list::push(LIST_INFO* listInfo, int value){
    BLOCK* list = new BLOCK();

    if(listInfo->list == NULL){
        list->value = value;
        list->index = 0;

        listInfo->list = list;
        listInfo->lastBlock = list;
        listInfo->size++;
        
        return true;
    }

    if(listInfo->lastBlock != NULL){
        list->value = value;
        list->index = listInfo->lastBlock->index + 1;
        list->previous = listInfo->lastBlock;
        listInfo->size++;

        listInfo->lastBlock->next = list;
        listInfo->lastBlock = listInfo->lastBlock->next;
        return true;
    }

    return false;
}

bool ds_list::pop(LIST_INFO* listInfo) {
    if (ds_list::is_empty(listInfo)) {
        return false;
    }

    BLOCK* erase = listInfo->lastBlock;

    if (erase->previous) {
        listInfo->lastBlock = erase->previous;
        listInfo->lastBlock->next = NULL;
    } else {
        listInfo->list = NULL;
        listInfo->lastBlock = NULL;
    }

    listInfo->size--;

    erase->next = NULL;
    erase->previous = NULL;
    delete erase;
    return true;
}


void ds_list::show_block(BLOCK* list){
    cout << "\tA[" << list->index << "]: " << list->value << endl;
}

void ds_list::show(LIST_INFO* listInfo){
    if(!ds_list::is_empty(listInfo)){
        cout << "LIST INFO (" << listInfo->size << "): " << endl;

        for(BLOCK* list = listInfo->list; list != NULL; list = list->next){
            ds_list::show_block(list);
        }

        cout << endl;
    }else{
        cout << "EMPTY LIST!!" << endl;
    }
}

#endif