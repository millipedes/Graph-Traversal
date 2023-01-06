#include "include/bfs.h"

queue * init_queue(void) {
  queue * the_queue = calloc(1, sizeof(struct NODE_Q_T));
  the_queue->value = NULL;
  the_queue->prev = NULL;
  return the_queue;
}

queue * enqueue(queue * the_queue, node * value) {
  queue * tmp = NULL;
  if(!the_queue->value) {
    the_queue->value = value;
    return the_queue;
  } else {
    tmp = init_queue();
    tmp->prev = the_queue;
    tmp->value = value;
    return tmp;
  }
  fprintf(stderr, "[ENQUEUE]: Something Went Wrong\nExiting\n");
  exit(1);
}

void debug_queue(queue * the_queue) {
  if(!the_queue)
    printf("NULL\n");
  queue * tmp = the_queue;
  while(tmp) {
    debug_node(tmp->value);
    tmp = tmp->prev;
  }
  printf("---\n");
}

queue * dequeue(queue * the_queue) {
  queue * tmp = NULL;
  if(!the_queue->value) {
    return the_queue;
  } else {
    if(the_queue->prev) {
      tmp = the_queue->prev;
      free(the_queue);
      return tmp;
    } else {
      the_queue->value = NULL;
      return the_queue;
    }
  }
}

void free_queue(queue * the_queue) {
  if(the_queue) {
    while(the_queue->value)
      the_queue = dequeue(the_queue);
    free(the_queue);
  }
}

void init_bfs(node * root) {
  queue * the_queue = init_queue();
  ((bfs_req *)(root->trav_req))->the_color = GRAY;
  ((bfs_req *)(root->trav_req))->distance = 0;
  the_queue = enqueue(the_queue, root);
  while(the_queue->value) {
    node * tmp = the_queue->value;
    the_queue = dequeue(the_queue);
    if(tmp) {
      for(int i = 0; i < tmp->qty_neighbors; i++)
        if(((bfs_req *)(tmp->neighbors[i]->trav_req))->the_color == WHITE) {
          ((bfs_req *)(tmp->neighbors[i]->trav_req))->the_color = GRAY;
          ((bfs_req *)(tmp->neighbors[i]->trav_req))->distance
            = ((bfs_req *)(tmp->trav_req))->distance
            + 1;
          ((bfs_req *)(tmp->neighbors[i]->trav_req))->prev = tmp;
          the_queue = enqueue(the_queue, tmp->neighbors[i]);
        }
      ((bfs_req *)(tmp->trav_req))->the_color = BLACK;
    }
  }
  free_queue(the_queue);
}
