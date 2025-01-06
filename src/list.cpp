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

void ds_list::update_block_index(BLOCK* list){
    list->index--;
    if(list->next){
        return update_block_index(list->next);
    }

}

void ds_list::erase_block(LIST_INFO* listInfo, BLOCK* erase){
    cout << "POP ->\tA[" << erase->index << "]: " << erase->value << endl;

    if(erase->previous)
        erase->previous->next = erase->next;
    else{
        listInfo->list = listInfo->list->next;
        listInfo->list->previous = NULL;
    }
    
    if(erase->next)
        erase->next->previous = erase->previous;
    else{
        listInfo->lastBlock = listInfo->lastBlock->previous;
        listInfo->lastBlock->next = NULL;
    }

    erase->next = NULL;
    erase->previous = NULL;
    
    listInfo->size--;

    delete erase;
}

bool ds_list::pop_by_index(LIST_INFO* listInfo, int index){
    if(is_empty(listInfo)){
        return false;
    }

    for(BLOCK* list = listInfo->list; list != NULL; list = list->next){
        if(list->index == index){
            BLOCK* erase = list;
            
            update_block_index(list);
            erase_block(listInfo, erase);

            return true;
        }
    }

    return false;
}

bool ds_list::pop_by_value(LIST_INFO* listInfo, BLOCK* list, int value) {
    if (list == nullptr) {
        return false;
    }

    bool removed = false;

    if (list->value == value) {
        BLOCK* nextBlock = list->next;

        erase_block(listInfo, list); 

        if(nextBlock)
            update_block_index(nextBlock);

        removed = true;

        return pop_by_value(listInfo, nextBlock, value) || removed;
    }

    return pop_by_value(listInfo, list->next, value) || removed;
}

bool ds_list::empty(LIST_INFO* listInfo){
    if(is_empty(listInfo)){
        cout << "EMPTY LIST ALREADY" << endl;
        return false;
    }

    while(!is_empty(listInfo)){
        pop(listInfo);
    }

    return true;
}

int ds_list::get_value_by_index(BLOCK* list, int index){

    int value;
    if(list != NULL){
        if(list->index == index){
            value = list->value;
            return value;
        }

        if(list->next)
            return get_value_by_index(list->next, index);
    }

    return value;
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