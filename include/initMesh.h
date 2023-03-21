#ifndef INITMESH_H
  #define INITMESH_H

  #include "types.h"

  int initMesh(const int number_cells,const float length_mesh_cell, struct mesh_node *nodes, char **msg);

  void countMeshCells (const float length_mesh_cell, const struct boundary borders[], int *number);

#endif //INITMESH_H
