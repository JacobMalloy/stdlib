#include"map.h"

#include"stdlib.h"

map* make_map(){
    map* return_value = malloc(sizeof(map));
    return_value->sentinel = NULL;
    return_value->count=0;
    return return_value;
}

struct map_node* map_insert(map* map_internal, int key, int value){
    struct map_node* return_value = malloc(sizeof(struct map_node));
    struct map_node *current, *last;
    return_value->key=key;
    return_value->value=value;
    return_value->left=NULL;
    return_value->right=NULL;
    last = NULL;
    current=map_internal->sentinel;
    while(current != NULL){
        last = current;
        if(key<current->key){
            current=current->left;
        }else{
            current=current->right;
        }
    }
    return_value->parent=last;
    map_internal->count++;
    if(last==NULL){
        map_internal->sentinel=return_value;
    }
    else if(key<last->key){
        last->left=return_value;
    }else{
        last->right=return_value;
    }
    return return_value;
}

struct map_node* map_find(map* map_internal, int key){
    struct map_node* current = map_internal->sentinel;
    while(current != NULL){
        if(current->key == key){
            return current;
        }
        if(key<current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return NULL;
}
