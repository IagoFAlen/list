#pragma once
#include <iostream>

namespace ds_list {

    typedef struct block {
        int value;
        int index;

        block* next;
        block* previous;

        block() {
            value = 0;
            index = -1;
            next = NULL;
            previous = NULL;
        }

        ~block() {
            value = 0;
            index = -1;
            delete next;
            delete previous;
        }

    } BLOCK;

    typedef struct list_info {
        int size;
        BLOCK* list;
        BLOCK* lastBlock;

        list_info() {
            size = 0;
            list = NULL;
            lastBlock = NULL;
        }

        ~list_info() {
            size = -1;
            delete list;
            delete lastBlock;
        }

    } LIST_INFO;

    bool is_empty(LIST_INFO* listInfo);
    bool push(LIST_INFO* listInfo, int value);
    bool pop(LIST_INFO* listInfo);
    void erase_block(LIST_INFO* listInfo, BLOCK* erase);
    void update_block_index(BLOCK* list);
    bool pop_by_index(LIST_INFO* listInfo, int index);
    bool pop_by_value(LIST_INFO* listInfo, BLOCK* list, int value);
    bool empty(LIST_INFO* listInfo);
    void show_block(BLOCK* list);
    void show(LIST_INFO* listInfo);

}
