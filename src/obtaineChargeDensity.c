#include "../include/obtaineChargeDensity.h"

int obtaineChargeDensity(struct super_particle particles, struct mesh_node *nodes, char **msg){
    strcpy(*msg, "");  
    strcat (*msg, __func__);    

    double width_mesh = fabs(nodes[1].coord-nodes[0].coord);
    int number_nearestNodes = (int)  

    strcat (*msg, "\n\t\tOK!");   
    return 0;
}