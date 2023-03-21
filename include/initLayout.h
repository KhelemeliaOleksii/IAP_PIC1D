#ifndef INITLAYOUT_H
  #define INITLAYOUT_H

  #include "types.h"
  #include <string.h>
  
  //DO:   - create array with structs: border and type
  int initLayout(double border_start, enum boundary_types type_border_start,
    double border_end, enum boundary_types type_border_end,
    struct boundary *borders, char **msg);

#endif //INITLAYOUT_H