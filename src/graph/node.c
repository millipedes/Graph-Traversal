#include "./include/node.h"

const char * color_to_string(color the_color) {
  switch(the_color) {
    case WHITE: return "White";
    case GRAY:  return "Gray";
    case BLACK: return "Black";
  }
  return NULL;
}

const char * traversal_type_to_string(traversal_type the_type) {
  switch(the_type) {
    case BFS:      return "Bfs";
    case DFS:      return "Dfs";
    case DIJKSTRA: return "Dijkstra";
  }
  return NULL;
}

node * init_node(void * the_value, char * name, type the_type,
    traversal_type trav_type, int x, int y) {
  node * the_node = calloc(1, sizeof(struct NODE_T));
  the_node->neighbors = NULL;
  the_node->trav_type = trav_type;
  switch(the_node->trav_type) {
    case BFS:
      the_node->trav_req = init_bfs_req();
      break;
    case DFS:
      fprintf(stderr, "Oh no\n");
      break;
    case DIJKSTRA:
      fprintf(stderr, "Oh no\n");
      break;
  }
  the_node->the_value = the_value;
  the_node->n_angles = NULL;
  the_node->name = name;
  the_node->the_type = the_type;
  the_node->qty_neighbors = 0;
  the_node->x = x;
  the_node->y = y;
  return the_node;
}

node * add_neighbor(node * root, node * neighbor) {
  root->qty_neighbors++;
  if(root->neighbors)
    root->neighbors = realloc(root->neighbors, root->qty_neighbors
        * sizeof(struct NODE_T *));
  else
    root->neighbors = calloc(1, sizeof(struct NODE_T *));
  root->neighbors[root->qty_neighbors - 1] = neighbor;
  return root;
}

void debug_node(node * the_node) {
  printf("[NODE]\n");
  printf("Qty Neighbors: %d\n", the_node->qty_neighbors);
  if(the_node->trav_req)
    debug_bfs_req(the_node->trav_req);
  if(the_node->n_angles) {
    printf("Angles: ");
    for(int i = 0; i < the_node->qty_neighbors; i++)
      if(i == the_node->qty_neighbors - 1)
        printf("%d\n", the_node->n_angles[i]);
      else
        printf("%d, ", the_node->n_angles[i]);
  }
  if(the_node->the_value) {
    printf("value: ");
    print_value(the_node->the_value, the_node->the_type);
    printf("\n");
  }
  printf("x: %d\n", the_node->x);
  printf("y: %d\n", the_node->y);
  printf("Traversal Type: %s\n", traversal_type_to_string(the_node->trav_type));
  switch(the_node->trav_type) {
    case BFS:
      for(int i = 0; i < the_node->qty_neighbors; i++)
        debug_node(the_node->neighbors[i]);
      break;
    case DFS:
      fprintf(stderr, "Oh no\n");
      break;
    case DIJKSTRA:
      fprintf(stderr, "Oh no\n");
      break;
  }
}

void free_node(node * the_node) {
  if(the_node) {
    if(the_node->the_value)
      free(the_node->the_value);
    if(the_node->n_angles)
      free(the_node->n_angles);
    if(the_node->name)
      free(the_node->name);
    switch(the_node->trav_type) {
      case BFS:
        if(the_node->trav_req) {
          for(int i = 0; i < the_node->qty_neighbors; i++)
            if(the_node->neighbors[i])
              if(((bfs_req *)(the_node->neighbors[i]->trav_req))->distance
                  > ((bfs_req *)(the_node->trav_req))->distance)
                free_node(the_node->neighbors[i]);
          if(the_node->neighbors)
            free(the_node->neighbors);
          free_bfs_req(the_node->trav_req);
        }
        free(the_node);
        break;
    case DFS:
      fprintf(stderr, "Oh no\n");
      break;
    case DIJKSTRA:
      fprintf(stderr, "Oh no\n");
      break;
    }
  }
}

bfs_req * init_bfs_req(void) {
  bfs_req * trav_req = calloc(1, sizeof(struct BFS_REQ_T));
  trav_req->the_color = WHITE;
  trav_req->distance = MAX_DISTANCE;
  trav_req->prev = NULL;
  return trav_req;
}

void debug_bfs_req(bfs_req * trav_req) {
  printf("[BFS_REQ]\n");
  printf("Color: %s\n", color_to_string(trav_req->the_color));
  printf("Distance: %f\n", trav_req->distance);
  printf("Prev: %s\n", trav_req->prev ? trav_req->prev->name : "NULL");
}

void free_bfs_req(bfs_req * trav_req) {
  if(trav_req)
    free(trav_req);
}

