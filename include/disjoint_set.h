#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

struct disjoint_set_item{
    unsigned int parent;
    int size;
};

typedef struct disjoint_set{
    struct disjoint_set_item *items;
} disjoint_set;

disjoint_set *make_disjoint_set(int size);
unsigned int disjoint_set_find(disjoint_set *set, unsigned int index);
unsigned int disjoint_set_union(disjoint_set *set, unsigned int a, unsigned int b);
void destroy_disjoint_set(disjoint_set *set);

#endif // __DISJOINT_SET_H__
