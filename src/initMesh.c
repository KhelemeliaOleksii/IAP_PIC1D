#include <stdio.h>
#include <string.h>
#include <math.h>

#include "../include/initMesh.h"

int initMesh(const int number_nodes, const double length_mesh_cell, struct mesh_node *nodes, char **msg){
  strcpy(*msg, "");  
  strcat (*msg, __func__);  

  if (length_mesh_cell <= 0) {
    strcat (*msg, ": Wrong values of length_mesh_cell! Check if condition (length_mesh_cell > 0) carries out."); 
    return -1;
  } 

  for (int i = 0; i < number_nodes; i++){
    nodes[i].coord = i*length_mesh_cell; 
  }

  strcat (*msg, "\n\t\tOK!\tThe mesh have been created"); 
  return 0;
}

void countNodes(const double length_mesh_cell, const struct boundary borders[], int *number){
    *number = (int)round((borders[1].value - borders[0].value) / length_mesh_cell)+1;
}