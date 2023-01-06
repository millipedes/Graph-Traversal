// /**
//  * @file   dijkstra.c
//  * @brief  This file contains the functions relating to the dijkstra_info data
//  * structure.
//  * @author Matthew C. Lindeman
//  * @date   January 04, 2023
//  * @bug    None known
//  * @todo   Nothing
//  */
// #include "include/dijkstra.h"
// 
// dij_info * init_dijkstra_info(node * of_interest) {
//   dij_info * the_dij_info = calloc(1, sizeof(struct DIJ_INFO_T));
//   // for(int i = 0; i < 
//   return the_dij_info;
// }
// 
// void print_dijkstra_info_table(dij_info * the_dij_info) {
//   printf("[DIJ_INFO]\n");
//   printf("Node of Interest:\n");
//   debug_node(the_dij_info->of_interest);
//   printf("---\n");
//   printf("Node | Shortest Dist | Prev. Vertex\n");
//   for(int i = 0; i < the_dij_info->qty_nodes; i++) {
//     printf("| %s |", the_dij_info->nodes[i]);
//     printf(" %f |", the_dij_info->shortest_dist[i]);
//     // If node of interest, no prev vertex
//     printf(" %s |\n", the_dij_info->previous_vertex[i]
//         ? the_dij_info->previous_vertex[i] : "N/a");
//   }
// }
