#include "../include/initBeam.h"

int initBeam ( struct particle_type particle,
  double beam_velocity, enum velocity_distr_function velocity_df, double beam_velocity_spread,
  struct boundary boundaries[], double position_center,
  enum coord_distr_function coord_distr_function, double coord_spread,
  double offset_start, double offset_end, 
  struct beam *beam_ptr, char **msg){

  strcpy(*msg, "");  
  strcat (*msg, __func__);    

  double length = (boundaries[1].value - boundaries[0].value);
  beam_ptr->particle.charge = particle.charge;
  beam_ptr->particle.mass = particle.mass;
  beam_ptr->velocity = beam_velocity;
  beam_ptr->velocity_df =velocity_df;
  beam_ptr->velocity_spread = beam_velocity_spread;
  beam_ptr->position_center = length*position_center;
  beam_ptr->coord_df = coord_distr_function;
  beam_ptr->position_spread = coord_spread;
  beam_ptr->start = 0 + length*offset_start;
  beam_ptr->end = length - length*offset_end;

  strcat (*msg, "\n\t\tOK!\tBeam have been created!");

  return 0;
}
