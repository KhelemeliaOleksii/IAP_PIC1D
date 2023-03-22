#ifndef INITBEAM_H
  #define INITBEAM_H

  #include <string.h>
  #include "types.h"

int initBeam (struct particle_type particle,
  double beam_velocity, enum velocity_distr_function velocity_df, double beam_velocity_spread,
  struct boundary boundaries[], double position_center,
  enum coord_distr_function coord_distr_function, double coord_spread,
  double offset_start, double offset_end, 
  struct beam *beam_ptr, char **msg);
  
#endif // INITBEAM_H