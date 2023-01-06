#ifndef NOD_H
#define NOD_H

#include "../../type/include/type.h"

#define MAX_DISTANCE 9999

typedef enum {
  WHITE,
  GRAY,
  BLACK,
} color;

const char * color_to_string(color the_color);

typedef enum {
  BFS,
  DFS,
  DIJKSTRA,
} traversal_type;

const char * traversal_type_to_string(traversal_type the_type);

typedef struct NODE_T {
  struct NODE_T ** neighbors;
  void * trav_req;
  void * the_value;
  int * n_angles;
  char * name;
  traversal_type trav_type;
  type the_type;
  int qty_neighbors;
  int x;
  int y;
} node;

node * init_node(void * the_value, char * name, type the_type,
    traversal_type trav_type, int x, int y);
node * add_neighbor(node * root, node * neighbor);
void debug_node(node * the_node);
void free_node(node * the_node);

typedef struct BFS_REQ_T {
  color the_color;
  double distance;
  node * prev;
} bfs_req;

bfs_req * init_bfs_req(void);
void debug_bfs_req(bfs_req * the_bfs_req);
void free_bfs_req(bfs_req * the_bfs_req);

#endif
