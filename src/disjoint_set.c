#include "disjoint_set.h"

#include <stdlib.h>

disjoint_set *make_disjoint_set(int size){
    disjoint_set *return_value = malloc(sizeof(disjoint_set));
    return_value->items = malloc(sizeof(struct disjoint_set_item)*size);
    for(unsigned int i=0;i<size;i++){
        return_value->items[i].parent=-1;
        return_value->items[i].size=1;
    }
    return return_value;
}

unsigned int disjoint_set_find(disjoint_set *set, unsigned int index){
    unsigned int head;
    if(set->items[index].parent==-1){
        return index;
    }
    head = disjoint_set_find(set,set->items[index].parent);
    set->items[index].parent=head;
    return head;
}

unsigned int disjoint_set_union(disjoint_set *set,unsigned int a, unsigned int b){
    unsigned int real_a,real_b;
    real_a=disjoint_set_find(set,a);
    real_b=disjoint_set_find(set,b);
    if(real_a==real_b){
        return real_a;
    }
    if(set->items[real_a].size>set->items[real_b].size){
        set->items[real_b].parent=real_a;
        set->items[real_a].size+=set->items[real_b].size;
        return real_a;
    }else{
        set->items[real_a].parent=real_b;
        set->items[real_b].size+=set->items[real_a].size;
        return real_b;
    }
}

void destroy_disjoint_set(disjoint_set *set){
    free(set->items);
    free(set);
}
