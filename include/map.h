#ifndef __MAP_H__
#define __MAP_H__

//I am just prototyping a int to int map...
struct map_node{
  int key, value;
  struct map_node *left, *right, *parent;
};

typedef struct map{
    struct map_node* sentinel;
    unsigned int count;
} map;

map* make_map();
struct map_node* map_find(map* map_internal, int key);
struct map_node* map_insert(map* map_internal, int key,int value);
struct map_node* map_remove(map* map_internal, struct map_node *node);
#endif //__MAP_H__
