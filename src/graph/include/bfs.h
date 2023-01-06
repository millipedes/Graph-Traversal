#ifndef BFS_H
#define BFS_H

#include "node.h"

typedef struct NODE_Q_T {
  node * value;
  struct NODE_Q_T * prev;
} queue;

queue * init_queue(void);
queue * enqueue(queue * the_queue, node * value);
void debug_queue(queue * the_queue);
queue * dequeue(queue * the_queue);
void free_queue(queue * the_queue);
void init_bfs(node * root);

#endif
