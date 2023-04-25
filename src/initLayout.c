#include "../include/initLayout.h"

int initLayout(double border_start, enum boundary_types type_border_start,
    double border_end, enum boundary_types type_border_end,
    struct boundary *borders, char **msg){
  strcpy(*msg, "");  
  strcat (*msg, __func__);    

  if (border_start >= border_end) {
    strcat (*msg, ": Wrong values of boundaryies! Check if condition (border_start <= border_end) carries out."); 
    return -1;
  } 
  borders[0].value = border_start;
  borders[0].type = type_border_start;

  borders[1].value = border_end;
  borders[1].type = type_border_end;

  strcat (*msg, "\n\t\tOK!\tBorders have been created!");
  return 0;
}
