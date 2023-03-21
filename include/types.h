#ifndef TYPE_H 
  #define TYPE_H

  enum boundary_types{mirror = 0, absorb = 1, period = 2};

  struct boundary
  {
    float value;
    enum boundary_types type;
  };
  
#endif //TYPE_H