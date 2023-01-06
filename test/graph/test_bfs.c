#define _POSIX_C_SOURCE 200809L // See platforms in README.md
#include "include/test_bfs.h"

void test_bfs(void) {
  char * name1 = calloc(strnlen("Node 1", MAX_NAME_SIZE), sizeof(char));
  int * value1 = calloc(1, sizeof(int));
  *value1 = 1;
  node * node1 = init_node(value1, name1, INT, BFS, 1, 1);
  char * name2 = calloc(strnlen("Node 2", MAX_NAME_SIZE), sizeof(char));
  int * value2 = calloc(1, sizeof(int));
  *value2 = 2;
  node * node2 = init_node(value2, name2, INT, BFS, 2, 2);
  char * name3 = calloc(strnlen("Node 3", MAX_NAME_SIZE), sizeof(char));
  int * value3 = calloc(1, sizeof(int));
  *value3 = 3;
  node * node3 = init_node(value3, name3, INT, BFS, 3, 3);
  char * name4 = calloc(strnlen("Node 4", MAX_NAME_SIZE), sizeof(char));
  int * value4 = calloc(1, sizeof(int));
  *value4 = 4;
  node * node4 = init_node(value4, name4, INT, BFS, 4, 4);
  char * name5 = calloc(strnlen("Node 5", MAX_NAME_SIZE), sizeof(char));
  int * value5 = calloc(1, sizeof(int));
  *value5 = 5;
  node * node5 = init_node(value5, name5, INT, BFS, 5, 5);
  char * name6 = calloc(strnlen("Node 6", MAX_NAME_SIZE), sizeof(char));
  int * value6 = calloc(1, sizeof(int));
  *value6 = 6;
  node * node6 = init_node(value6, name6, INT, BFS, 6, 6);
  /**
   * Make a graph that looks like (disregarding cartesian space):
   *         n1
   *        /  \
   *       n2   n3
   *      /  \   |
   *     n5  n6  n4
   * Then test the bfs algorithm (via debuging nodes).
   */
  node1 = add_neighbor(node1, node2);
  node1 = add_neighbor(node1, node3);
  node3 = add_neighbor(node3, node4);
  node2 = add_neighbor(node2, node6);
  node2 = add_neighbor(node2, node5);
  init_bfs(node1);
  debug_node(node1);
  free_node(node1);
}
