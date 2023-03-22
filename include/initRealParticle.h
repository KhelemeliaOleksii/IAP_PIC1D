#ifndef INITREALPARTICLE_H
  #define INITREALPARTICLE_H

  #include <string.h>
  #include "types.h"
  
  int initRealParticle (const int charge, const double charge_unit, 
      const double mass, const double mass_unit,  
      struct particle_type *particle, char** msg);    

#endif //INITREALPARTICLE_H